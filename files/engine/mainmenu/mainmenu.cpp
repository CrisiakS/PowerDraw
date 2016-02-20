#include "mainmenu.hpp"
#include "../../opengl/text/tekst.hpp"
#include "../../opengl/text3d/text3d.hpp"
#include <GL/freeglut.h>
#include <vector>
#include <math.h>


#include "../lines/lines.hpp"
#include "../stars/stars.hpp"


using namespace std;

float retrowave=0;
float showmethatbeauty=2;

float showpowerdraw=0;
float powerdrawz=0;

float presstart=0;

            OpenGL::lines liniaTop(-14075,-600,30,
                           150,25,
                           0.3,1,0.3,1,
                           50);

            OpenGL::lines liniaDown(-14075,1200,30,
                           100,25,
                           0.3,1,0.3,1,
                           50);

        void StartInfo()
        {

                    if(presstart>1000)
                            presstart=0;

                    const unsigned char pdrawpress[]="Wcisnij ENTER by rozpoczac";
                        OpenGL::Text3D(pdrawpress,-920,800,30,1,1,0,sin(presstart));
                            presstart+=0.1;
        }


        void titlescreen()
        {
            liniaTop.Draw();
            liniaDown.Draw();


            if(showmethatbeauty>=0)
                showmethatbeauty-=0.01;
            else
            {
                const unsigned char pdraw[]="PowerDRAW";
                if(powerdrawz<=3)
                    {
                        OpenGL::Text3D(pdraw,-150,275,powerdrawz,1,1,sin(presstart),showpowerdraw);
                        powerdrawz+=0.05;
                        showpowerdraw+=0.5;
                    }
                else
                    {
                        OpenGL::Text3D(pdraw,-150,275,3,1,1,sin(presstart),1);
                        StartInfo();
                    }

            }

            if(retrowave!=1)
                    retrowave+=0.1;

            if(retrowave>0.9)
                    retrowave=0;

            OpenGL::ShootingStars();

            if(showmethatbeauty>0)
            {
                showmethatbeauty-=0.01;
            }

                const unsigned char a[]="Piotr Jagusiak prezentuje...";
                OpenGL::Text3D(a,-1000,300,showmethatbeauty*30,1,1,0,showmethatbeauty);

                            if(showmethatbeauty==0)
                                {
                                    showmethatbeauty=-10;
                                    delete [] a;
                                }

        }
