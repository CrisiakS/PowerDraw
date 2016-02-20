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
#include "../text3d/text3d.hpp"
#include "../inicjalizacja.hpp"
#include "../../engine/fade/fade.hpp"
////////////////////////////////////////
using namespace std;
using namespace cv;

int program=0;      // Zmienna okreslajaca na jakim kroku jest program
bool gumkuj=0;
Video::camera kamera1;
Video::camera kamera2;

VideoCapture cap1;   // Program bedzie dzialal max na 2 kamery - tu ich deklaracje
VideoCapture cap2;   // -||-

Mat GLFrame;        // Ta plaszczyzna bedzie wyswietlana jako obraz kamery w OPENGL
OpenGL::options obraz;
////////////////////////////////////////////
    namespace OpenGL
        {
            void display()
                {
                        glClear(GL_COLOR_BUFFER_BIT);
                        glClear(GL_DEPTH_BUFFER_BIT);
                        glClearColor(0,0,0,0);
                    //////////////////////////////////////////////////////

                    if(program==0)
                        {
                            titlescreen();
                            FadeIn(5);
                        }
                    if(program==1)
                    {
                        kamera1.Capture(cap1,0);
                        GLFrame=kamera1.GetFinalFrame();

                        kamera1.LiczXY();
                        cout<<kamera1.getX()<<"\t"<<kamera1.getY()<<endl;

                        kamera1.drawAt(kamera1.getX(),kamera1.getY(),1,1,1,10);

                            glPushMatrix();
                            glRasterPos3f(kamera1.getX(),kamera1.getY(),20);

                            Mat temp;
                            flip(kamera1.GetCapturedFrame(),temp,0);
                            cvtColor(temp,temp,CV_BGR2RGB);

                            if(!kamera1.GetCapturedFrame().empty())
                            glDrawPixels( temp.size().width, temp.size().height, GL_RGB, GL_UNSIGNED_BYTE, temp.ptr() );  // Rysowanie kamery
                            if(!GLFrame.empty())
                            glDrawPixels( GLFrame.size().width, GLFrame.size().height, GL_RGBA, GL_UNSIGNED_BYTE, GLFrame.ptr() );  // Rysowanie kamery
                            glPopMatrix();
                    }


                    ///////////////////////////////////////////////////////
                    glFlush();
                    glutSwapBuffers();

                }
        }


