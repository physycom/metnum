// based on http://seriss.com/people/erco/fltk/

#include <stdio.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

class MyBox : public Fl_Box {
public:
    int handle(int e) {
        if ( e == FL_PUSH ) {
            fprintf(stdout, "event_x,event_y: %d,%d\n",
                Fl::event_x(),
                Fl::event_y()
            );
        }
        return Fl_Box::handle(e);
    }

    MyBox(int x,int y,int w,int h,const char*l=0) : Fl_Box(x,y,w,h,l) {
        color(FL_BLUE);
        box(FL_FLAT_BOX);
    }
};


int main() {
    Fl_Window win(800, 600);
    MyBox box(0,0,800,600);
    win.end();

    win.show();
    Fl::run();

    return 0;
} 


