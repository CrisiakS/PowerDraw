#include "lines.hpp"
#include <GL/freeglut.h>

    namespace OpenGL
    {
            void lines::Draw()
            {
            glPushMatrix();
            glColor3f(r,g,b);
                glBegin(GL_LINES);
                    glVertex3f(x+(xamount*yamount*yamount),y,z);
                    glVertex3f(x,y,z);
            glEnd();

                    for(float i=yamount;i>0;i--)
                                {
                                    glPushMatrix();
                                    glColor4f(r,g,b,0.02*i);
                                        glBegin(GL_LINES);
                                            glVertex3f(x,y,i-(wave)+(z-25));
                                            glVertex3f(x+40000,y,i-(wave)+(z-25));
                                        glEnd();
                                    glPopMatrix();
                                };

                    for(float i=xamount+z;i>=0;i--)
                                {
                                    glPushMatrix();
                                    glColor4f(r,g,b,1);
                                        glBegin(GL_LINES);
                                            glVertex3f(x+(i*space*10),y,z);
                                    glColor4f(r,g,b,0);
                                            glVertex3f(x+(i*space*10),y,-1);
                                        glEnd();
                                    glPopMatrix();
                                }


                if(wave!=1)
                    wave+=0.1;

                if(wave>0.9)
                        wave=0;
            }

            void lines::moveXYZ(int xx,int yy, int zz)
            {
                x+=xx;
                y+=yy;
                z+=zz;
            }

            void lines::setXYZ(int xx, int yy, int zz)
            {
                x=xx;
                y=yy;
                z=zz;
            }


            lines::lines(int xx,int yy,int zz,
                         int xam,int yam,
                         float rr,float gg, float bb, float aa, int spacee)
            {
                    x=xx;
                    y=yy;
                    z=zz;

                    xamount=xam;
                    yamount=yam;
                    space=spacee;

                    r=rr;
                    g=gg;
                    b=bb;
                    a=aa;


            }
    }
