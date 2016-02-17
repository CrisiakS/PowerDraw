#include "ekran.hpp"
#include <GL/freeglut.h>
#include "../../opencv/main/main.hpp"
#include "../text/tekst.hpp"
#include "../../opencv/biblioteki.hpp"
#include "../../opencv/point/point.hpp"
#include "../rysowanie/drawing.hpp"
#include <string>
#include <time.h>
#include <vector>

/////////////////////////////////////////

#include "../../engine/mainmenu/mainmenu.hpp"
#include "../../opencv/camera/camera.hpp"
////////////////////////////////////////
using namespace std;

extern Mat TextureFrame;
extern Mat frame;

extern int posX;
extern int posY;

extern int VideoMode;
bool once=false;

extern Video::Point punkt;
extern Mat ReadyMask;
VideoCapture cap1(0);
VideoCapture cap2(1);
////////////////////////////////////////////

int program=0;      // Zmienna okreslajaca na jakim kroku jest program
Video::camera kamera1;
Video::camera kamera2;
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
                    //////////////////////////////////////////////////////

                        kamera1.Capture(cap1);
                        imshow("Dupa",kamera1.GetCapturedFrame());
                        frame=kamera1.GetFinalFrame();


                    ///////////////////////////////////////////////////////



                            if(VideoMode==1)
                                {
                 //               stworz_napis("Teraz Rysujesz",5,31,GLUT_BITMAP_9_BY_15,0,1,0);
                    //            Video::CaptureIDLE();

                    //            drawing::DrawAt(punkt.x,punkt.y,255,255,255,10);

                            glRasterPos3f(-673,1230,10);

                            glDrawPixels( frame.size().width, frame.size().height, GL_RGBA, GL_UNSIGNED_BYTE, frame.ptr() );  // Rysowanie kamery
                                }
                        if(program==0)
                            {
                                mainmenu();
                            }
                    ///////////////////////////////////////////////////////
                    glFlush();
                    glutSwapBuffers();

        }
        }


