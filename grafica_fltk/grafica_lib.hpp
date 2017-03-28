//2016 Alessandro Fabbri, Stefano Sinigardi, BSD

// C++ STL include
#include <vector>
#include <string>


#ifdef __CYGWIN__  
#include <windef.h> 
#endif
#ifdef _WIN32
#include <windows.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
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


using namespace std;

// Global scope variables
double frame_xmin, frame_xmax, frame_ymin, frame_ymax;
bool is_blue = true;
vector<vector <double>> vvx, vvy;

// frame definition
class Frame : public Fl_Gl_Window {
  void draw();
  void init();
public:
  Frame(int x, int y, int w, int h, const char *l = 0) : Fl_Gl_Window(x, y, w, h, l) {}
};

void Frame::draw() {
  if (!valid()) {

    glClearColor(1.0, 1.0, 1.0, 1);							                   // Set background color
    glViewport(0, 0, w(), h());                                    // Make our viewport the whole window
    glMatrixMode(GL_PROJECTION);							                     // Select The Projection Matrix
    glLoadIdentity();										                           // Reset The Projection Matrix
    gluOrtho2D(frame_xmin, frame_xmax, frame_ymin, frame_ymax);		 // Set the graphic window boundaries
    glMatrixMode(GL_MODELVIEW);                                    // Select The Modelview Matrix
    glLoadIdentity();                                              // Reset The Modelview Matrix
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);            // Clear The Screen And The Depth Buffer
    glLoadIdentity();                                              // Reset The View
    glEnable(GL_DEPTH_TEST);

    valid(1);
  }

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //----------------- DRAW AXIS ---------------------
  glColor3d(0. , 0., 0.);
  glBegin(GL_LINE_STRIP); glVertex2d(0, frame_ymin); glVertex2d(0, frame_ymax); glEnd();
  glBegin(GL_LINE_STRIP); glVertex2d(frame_xmin, 0); glVertex2d(frame_xmax, 0); glEnd();
  //-------------------------------------------------

  //----------------- DRAW FUNCTION -----------------
  for (size_t i = 0; i < vvx.size(); i++){
    glColor3d(1.-is_blue, 0., is_blue);
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    for (size_t j = 0; j < vvy[i].size(); j++) glVertex2d(vvx[i][j], vvy[i][j]);
    glEnd();
    glPopMatrix();
  } //-------------------------------------------------
}


// FLTK widget pointers
Fl_Window *form;
Frame *frame;
Fl_Slider *slider;
Fl_Text_Buffer *text_content;
Fl_Text_Display *text_box;
Fl_Button *button;
Fl_Button *play;
Fl_Box *box;


// Slider callback
// 1 - update the displayed value
// 2 - recalculate y0 values vector
// 3 - redraw the plot
void slider_cb(Fl_Widget *w){
  text_content->text(std::to_string(slider->value()).c_str());
  
  text_box->buffer(text_content);

  double omega = slider->value();
  for (size_t i = 0; i < vvx[0].size(); i++) {
    vvy[0][i] = sin(omega * vvx[0][i]);
  }

  frame->redraw();
  return;
}


// Button callback
// 1 - update label
// 2 - update color variable
// 3 - redraw
void button_cb(Fl_Widget *w) {
  if (is_blue) {
    button->label("Blue");
    is_blue = false;
  }
  else {
    button->label("Red");
    is_blue = true;
  }

  frame->redraw();
  
  return;
}


// Play callback
// 1 - update label
// 2 - start/stop drawing loop
// 3 - redraw
int step_counter = 0;
void play_cb(Fl_Widget *w) {
    
}

// Layout parameters
#define SPACING        25
#define FRAME_WIDTH    600
#define FRAME_HEIGHT   600
#define SLIDER_WIDTH   350
#define SLIDER_HEIGHT  40

// Window layout creation function
void CreateMyWindow() {

  // Create main window
  int window_width = SPACING + FRAME_WIDTH + SPACING + FRAME_WIDTH + SPACING;
  int window_height = SPACING + FRAME_WIDTH + SPACING;
  form = new Fl_Window(window_width, window_height, "Test");

  // Create the plot box
  frame = new Frame(SPACING, SPACING, FRAME_WIDTH, FRAME_HEIGHT, 0);

  // Box
  box = new Fl_Box(FL_NO_BOX, frame->x() + frame->w() + SPACING, SPACING, 2*SLIDER_HEIGHT, SLIDER_HEIGHT, "Plotting \t\t y = sin( k x ) \t\t y = cos( x )");
  box->align(FL_ALIGN_RIGHT);

  // Create the slider widget 
  slider = new Fl_Slider(box->x(), box->y() + box->h() + SPACING, SLIDER_WIDTH, SLIDER_HEIGHT, "Frequency slider");
  slider->type((uchar)FL_HORIZONTAL);
  slider->bounds(1.,10.);
  slider->value(1.0);
  slider->callback(slider_cb);

  // Create a textbox to display slider value
  text_content = new Fl_Text_Buffer();
  text_box = new Fl_Text_Display(slider->x() + slider->w() + SPACING, slider->y(), 2*SLIDER_HEIGHT, SLIDER_HEIGHT, "Frequency value");
  text_content->text(std::to_string(slider->value()).c_str());
  text_box->buffer(text_content);

  // Color button
  button = new Fl_Button(slider->x(), slider->y() + slider->h() + SPACING, 2*SLIDER_HEIGHT, SLIDER_HEIGHT, "Red");
  button->callback(button_cb);

  // Play button
  play = new Fl_Button(button->x(), button->y() + button->h() + SPACING, 2 * SLIDER_HEIGHT, SLIDER_HEIGHT, "Play");
  play->callback(play_cb);

  // Start the graphics
  form->end();
  form->show();
  frame->show();
}

void idle_cb(void*) {
  frame->redraw();
}
