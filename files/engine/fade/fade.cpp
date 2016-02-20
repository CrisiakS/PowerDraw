#include "fade.hpp"
#include <GL/freeglut.h>

float fade=1;
        void  FadeIn(float speed)
            {
                if(fade>0)
                {
                     glColor4f(0,0,0,fade);
                        glBegin(GL_POLYGON);
                            glVertex3d(-1000,-1000,1);
                            glVertex3d(1000,-1000,1);
                            glVertex3d(1000,1000,1);
                            glVertex3d(-1000,1000,1);
                        glEnd();
                    fade-=speed/1000;
                }
            }

        void FadeOut(float speed)
            {
                if(fade<1)
                {
                    glColor4f(0,0,0,fade);
                        glBegin(GL_POLYGON);
                            glVertex3d(-1000,-1000,1);
                            glVertex3d(1000,-1000,1);
                            glVertex3d(1000,1000,1);
                            glVertex3d(-1000,1000,1);
                        glEnd();
                    fade+=speed/1000;
                }
            }

        bool FadeOutEnd()
            {
                if(fade>=1)
                    return true;
                else
                    return false;
            }
        bool FadeInEnd()
            {
                if(fade<=0)
                    return true;
                else
                    return false;
            }


