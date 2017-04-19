//2016 Alessandro Fabbri, Stefano Sinigardi, BSD

#ifdef __CYGWIN__  
#include <windef.h> 
#endif
#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __APPLE__
#include <OpenGL/glu.h>
#else
#include <GL/glu.h>
#endif
#include <FL/Fl.H>
#include <FL/gl.h>
#include <FL/Fl_Slider.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Gl_Window.H>

#include <iostream>              
#include <vector>
#include <string>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950
#endif

using namespace std;

// Layout parameters
#define SPACING        25
#define FRAME_WIDTH    600
#define FRAME_HEIGHT   600
#define SLIDER_WIDTH   350
#define SLIDER_HEIGHT  40

class Frame;
