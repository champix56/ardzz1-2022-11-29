#ifndef __PFD_
#define __PFD_
#define MAX_HORIZON_VALUE 45.0F
#define MAX_HORIZON_VALUE_RAD (MAX_HORIZON_VALUE*(M_PI/180.0F))
#define FPV_PROFONDEUR 30
#define M_PI 3.1415F
struct position_t {
  unsigned short x, y;
};
struct lineposition_t {
  struct position_t point1, point2;
};
unsigned short getPFDPitch(unsigned int angle, unsigned short height) ;
struct lineposition_t getPFDRoll(unsigned int angle,
                                 unsigned short objectwidth,
                                 unsigned short width,
                                 unsigned short height);

#endif
