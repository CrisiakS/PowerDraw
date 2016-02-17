#include "ekran.hpp"
#include <GL/freeglut.h>
#include "../../opencv/main/main.hpp"
#include "../text/tekst.hpp"
#include "../../opencv/biblioteki.hpp"
#include "../../opencv/point/point.hpp"
#include "../rysowanie/drawing.hpp"
#include <string>
//#include <time.h>
////////////////////////////////////////
#include "../../engine/mainmenu/mainmenu.hpp"
#include "../../opencv/camera/camera.hpp"
////////////////////////////////////////
using namespace std;

extern int VideoMode;
////////////////////////////////////////////

int program=0;      // Zmienna okreslajaca na jakim kroku jest program
Video::camera kamera1;
Video::camera kamera2;

VideoCapture cap1;   // Program bedzie dzialal max na 2 kamery - tu ich deklaracje
VideoCapture cap2;   // -||-

Mat GLFrame;        // Ta plaszczyzna bedzie wyswietlana jako obraz kamery w OPENGL
////////////////////////////////////////////
/*
void wait(int seconds)
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
}
*/

    namespace OpenGL
        {
            void display()
                {
                        glClear(GL_COLOR_BUFFER_BIT);
                        glClear(GL_DEPTH_BUFFER_BIT);
                        glClearColor(0,0,0,0);

                            if(VideoMode==1)
                                {
                 //               stworz_napis("Teraz Rysujesz",5,31,GLUT_BITMAP_9_BY_15,0,1,0);
                    //            Video::CaptureIDLE();

                    //            drawing::DrawAt(punkt.x,punkt.y,255,255,255,10);

                            glRasterPos3f(-673,1230,10);

                            if(!GLFrame.empty())
                                glDrawPixels( GLFrame.size().width, GLFrame.size().height, GL_RGBA, GL_UNSIGNED_BYTE, GLFrame.ptr() );  // Rysowanie kamery

                                }
                   //     if(program==0)
                    //        {
                                mainmenu();
                     //       }
                    ///////////////////////////////////////////////////////
                    glFlush();
                    glutSwapBuffers();

        }
        }


