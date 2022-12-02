#include "pfd_widget.h"
float degToRad(unsigned int deg) {
  return ((float)deg) * (M_PI / 180.0F);
}
struct lineposition_t getPFDRoll(unsigned int angle,
                                 unsigned short objectwidth,
                                 unsigned short width,
                                 unsigned short height)
{
  struct lineposition_t output;
  struct position_t centerscreen;
  centerscreen.x = (unsigned short)((float)width) / 2.0F;
  centerscreen.y = (unsigned short)((float)height) / 2.0F;
  float rad = degToRad(angle);
  const float halfobjWidth = ((float)objectwidth) / 2.0F;

  output.point1.x = cos(rad) * halfobjWidth + centerscreen.x;
  output.point1.y = sin(rad) * halfobjWidth + centerscreen.y;
  output.point2.x = cos(-rad) * halfobjWidth + centerscreen.x;
  output.point2.y = sin(-rad) * halfobjWidth + centerscreen.y;
  return output;
}


/*
   MIN------------- +45° |               )
                         |                )
                         |origine          )
                         +------------------+-
                         |                 )
                         |                )
  MAX------------- -45°   |               )

*/
unsigned short getPFDPitch(unsigned int angle, unsigned short height) {

  float angleRad = degToRad(angle);
  float y = sin(angleRad);

  //max / min de l'horizon  visible
  if (y >= MAX_HORIZON_VALUE_RAD)return 0;
  else if (y <= -MAX_HORIZON_VALUE_RAD)return height;
  const unsigned short zeroofset = height / 2;
  const float ratioViewBox = 1.0F / MAX_HORIZON_VALUE_RAD;
  y = -y;
  return y * ratioViewBox * (height / 2) + zeroofset;
}
