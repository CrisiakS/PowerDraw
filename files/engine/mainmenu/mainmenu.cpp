#include "mainmenu.hpp"
#include "../../opengl/text/tekst.hpp"
#include <GL/freeglut.h>

float retrowave=0;
float showmethatbeauty=2;

        void mainmenu()
        {

            glColor3f(1,1,0);
                glBegin(GL_LINES);
                    glVertex3f(-10000,-1000,29.9);
                    glVertex3f(10000,-1000,29.9);
                glEnd();

            glColor3f(1,1,0);
                glBegin(GL_LINES);
                    glVertex3f(-10000,1000,29.9);
                    glVertex3f(10000,1000,29.9);
                glEnd();

            for(float i=30;i>0;i--)
            {
                glColor4f(1,1,0,0.02*i);
                    glBegin(GL_LINES);
                        glVertex3f(-10000,1000,i-retrowave);
                        glVertex3f(10000,1000,i-retrowave);
                    glEnd();

                glColor4f(1,1,0,1);
                    glBegin(GL_LINES);
                        glVertex3f(i*200-2500,1000,29.9);
                glColor4f(1,1,0,0);
                        glVertex3f(i*200-2500,1000,-1);
                    glEnd();
                ////////////////////////////////////
                glColor4f(1,1,0,0.02*i);
                    glBegin(GL_LINES);
                        glVertex3f(-10000,-1000,i-retrowave);
                        glVertex3f(10000,-1000,i-retrowave);
                    glEnd();

                glColor4f(1,1,0,1);
                    glBegin(GL_LINES);
                        glVertex3f(i*200-2500,-1000,29.9);
                glColor4f(1,1,0,0);
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
                stworz_napis("Menu Glowne",1,1,GLUT_BITMAP_8_BY_13,1,1,0);
                showmethatbeauty-=0.01;
            }

            if(retrowave!=1)
                {
                    retrowave+=0.1;
                }
            if(retrowave>=0.9)
                {
                    retrowave=0;
                }

        }
