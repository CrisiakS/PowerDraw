#include "mainmenu.hpp"
#include "../../opengl/text/tekst.hpp"
#include "../../opengl/text3d/text3d.hpp"
#include <GL/freeglut.h>
#include <time.h>
#include <cstdlib>
#include <vector>
#include <math.h>

#define STARS_AMOUNT 500

using namespace std;

float retrowave=0;
float showmethatbeauty=2;

float showpowerdraw=0;
float powerdrawz=0;

float presstart=0;



float r=0.3;
float g=1;
float b=0.3;

            float star::getZ()
                {
                    return z;
                }
            float star::getX()
                {
                    return x;
                }
            float star::getY()
                {
                    return y;
                }

            void star::resetXYZ()
                {
                    x=rand()%20000-8000;
                    y=rand()%10000-4000;
                    z=40;
                    alpha=0;
                    pointsize=rand()%3+1;
                }
            void star::Go(float speed)
                {
                    z-=speed;
                    if(alpha<1)
                    {
                        alpha+=speed/10;
                    }
                }

        star stars[STARS_AMOUNT];
        star *wskStars;

        void mainmenu()
        {
            glPushMatrix();
            glColor3f(r,g,b);
                glBegin(GL_LINES);
                    glVertex3f(-20000,-1000,29.9);
                    glVertex3f(20000,-1000,29.9);
                glEnd();

            glColor3f(r,g,b);
                glBegin(GL_LINES);
                    glVertex3f(-20000,1000,29.9);
                    glVertex3f(20000,1000,29.9);
                glEnd();

            for(float i=30;i>0;i--)
            {
                glColor4f(r,g,b,0.02*i);
                    glBegin(GL_LINES);
                        glVertex3f(-20000,1000,i-retrowave*2);
                        glVertex3f(20000,1000,i-retrowave*2);
                    glEnd();

                glColor4f(r,g,b,0.02*i);
                    glBegin(GL_LINES);
                        glVertex3f(-20000,-1000,i-retrowave*2);
                        glVertex3f(20000,-1000,i-retrowave*2);
                    glEnd();
            }
            for(float i=100;i>-50;i-=2)
            {
                glColor4f(r,g,b,1);
                    glBegin(GL_LINES);
                        glVertex3f(i*200-2500,1000,29.9);
                glColor4f(r,g,b,0);
                        glVertex3f(i*200-2500,1000,-1);
                    glEnd();
                ////////////////////////////////////

                glColor4f(r,g,b,1);
                    glBegin(GL_LINES);
                        glVertex3f(i*200-2500,-1000,29.9);
                glColor4f(r,g,b,0);
                        glVertex3f(i*200-2500,-1000,-1);
                    glEnd();
            }
            if(showmethatbeauty>=0)
            {
                glColor4f(0,0,0,showmethatbeauty-0.001);
                    glBegin(GL_POLYGON);
                        glVertex3d(-1000,-1000,1);
                        glVertex3d(1000,-1000,1);
                        glVertex3d(1000,1000,1);
                        glVertex3d(-1000,1000,1);
                    glEnd();
                showmethatbeauty-=0.01;
            }
            else
            {
                const unsigned char pdraw[]="PowerDRAW";
                if(powerdrawz<=3)
                {
                    OpenGL::Text3D(pdraw,-150,250,powerdrawz,1,1,sin(presstart),showpowerdraw);
                    powerdrawz+=0.05;
                    showpowerdraw+=0.5;
                }
                else
                {
                        OpenGL::Text3D(pdraw,-150,250,3,1,1,sin(presstart),1);
                        if(presstart>1000)
                        {
                            presstart=0;
                        }
                        const unsigned char pdrawpress[]="Wcisnij ENTER by rozpoczac";
                        OpenGL::Text3D(pdrawpress,-920,700,30,1,1,0,sin(presstart));
                        presstart+=0.1;

                }

            }


            if(retrowave!=1)
                {
                    retrowave+=0.1;
                }
            if(retrowave>=0.9)
                {
                    retrowave=0;

                }

            for(int i=0;i<STARS_AMOUNT;i++)
            {
                wskStars=&stars[i];
                if(wskStars->getZ()<=0)
                {
                    wskStars->resetXYZ();
                }
                else
                {
                glColor4f(1,1,1,wskStars->alpha);
                    glPointSize(wskStars->pointsize);
                        glBegin(GL_POINTS);
                            glVertex3f(wskStars->getX(),wskStars->getY(),wskStars->getZ());
                        glEnd();
                wskStars->Go(0.1);
                }

            }



                const unsigned char a[]="Piotr Jagusiak prezentuje...";
                OpenGL::Text3D(a,-1000,200,showmethatbeauty*30,1,1,0,showmethatbeauty);

                const unsigned char b[]="PowerDRAW";
                OpenGL::Text3D(b,-700,-500,12,1,1,0,1);

            glPopMatrix();
        }
