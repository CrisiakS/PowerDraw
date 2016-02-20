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
#include "../../engine/lines/lines.hpp"
////////////////////////////////////////
using namespace std;
using namespace cv;

int program=0;      // Zmienna okreslajaca na jakim kroku jest program
bool gumkuj=0;
bool once=false;
Video::camera kamera1;
Video::camera kamera2;

VideoCapture cap1;   // Program bedzie dzialal max na 2 kamery - tu ich deklaracje
VideoCapture cap2;   // -||-

Mat GLFrame;        // Ta plaszczyzna bedzie wyswietlana jako obraz kamery w OPENGL
OpenGL::options obraz;

extern bool titlescreen_end;

OpenGL::lines liniaTop(-14075,-600,30,
                        150,25,
                        0.3,1,0.3,1,
                        50);

OpenGL::lines liniaDown(-14075,1200,30,
                        100,25,
                        0.3,1,0.3,1,
                        50);
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
                            if(liniaDown.getY()<3000)
                                liniaDown.moveXYZ(0,50,0);

                            if(liniaTop.getY()>-2400)
                                liniaTop.moveXYZ(0,-50,0);

                            titlescreen();
                        }


                    if(program==2)
                    {
                        if(!once)
                        {
                            once=true;
                        }
                        kamera1.Capture(cap1,0);
                        GLFrame=kamera1.GetFinalFrame();

                //        kamera1.LiczXY();
                //        cout<<kamera1.getX()<<"\t"<<kamera1.getY()<<endl;

                 //       kamera1.drawAt(kamera1.getX(),kamera1.getY(),1,1,1,10);

                            glPushMatrix();
                            glRasterPos3f(-4500,800,20);

                            Mat temp;
                            flip(kamera1.GetCapturedFrame(),temp,0);
                            cvtColor(temp,temp,CV_BGR2RGB);

                       //     temp.resize(100,600);
                            Mat test(240,320,CV_8UC4);
                            resize(temp, test, test.size(), 0, 0,INTER_CUBIC);
                            if(!kamera1.GetCapturedFrame().empty())
                            glDrawPixels( test.size().width, test.size().height, GL_RGB, GL_UNSIGNED_BYTE, test.ptr() );  // Rysowanie kamery
                            if(!GLFrame.empty())
                   //         glDrawPixels( GLFrame.size().width, GLFrame.size().height, GL_RGBA, GL_UNSIGNED_BYTE, GLFrame.ptr() );  // Rysowanie kamery
                            glPopMatrix();
                            titlescreen();
                    }


                    ///////////////////////////////////////////////////////
                    glFlush();
                    glutSwapBuffers();

                }
        }


