#include "mainmenu.hpp"
#include "../../opengl/text3d/text3d.hpp"
#include <GL/freeglut.h>
#include <math.h>
#include "../lines/lines.hpp"
#include "../stars/stars.hpp"
#include "../titles/title.hpp"
///////////////////////////////////////////
using namespace std;
///////////////////////////////////////////
float retrowave=0;
float showmethatbeauty=2;
float showpowerdraw=0;
float powerdrawz=0;

float showmenu=0;

bool menu_ready=false;
bool titlescreen_end=false;

//////////////////////////////////////////

extern OpenGL::lines liniaDown;
extern OpenGL::lines liniaTop;
extern int program;

        void titlescreen()
        {
            liniaTop.Draw();
            liniaDown.Draw();

            if(showmethatbeauty>=0) showmethatbeauty-=0.01;
            if(retrowave!=1) retrowave+=0.1;
            if(retrowave>0.9) retrowave=0;

            if(showmethatbeauty>0)
                {
                    showmethatbeauty-=0.01;
                }
            else
                {
                    const unsigned char pdraw[]="PowerDRAW";
                    if(powerdrawz<=3)
                        {
                            OpenGL::Text3D(pdraw,-150,275,powerdrawz,1,1,1,showpowerdraw);
                            powerdrawz+=0.05;
                            showpowerdraw+=0.015;
                        }
                    else
                        {
                            if(program==0)
                                {
                                    OpenGL::Text3D(pdraw,-150,275,powerdrawz,1,1,1,1);
                                    StartInfo();
                                }

                            if(program==1)
                                {
                                    if(liniaDown.getY()==3000)
                                    {
                                        if(showmenu<1) showmenu+=0.1;
                                        OpenGL::Text3D(pdraw,-1400,-300,7.5,1,1,1,showmenu);
                                    }
                                }

                            titlescreen_end=true;
                        }
                }

            OpenGL::ShootingStars();

                const unsigned char a[]="Piotr Jagusiak prezentuje...";
                OpenGL::Text3D(a,-1000,300,showmethatbeauty*30,1,1,0,showmethatbeauty);

                            if(showmethatbeauty==0)
                                {
                                    showmethatbeauty=-10;
                                    delete [] a;
                                }

        }
