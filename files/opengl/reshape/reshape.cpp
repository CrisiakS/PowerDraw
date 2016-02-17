#include "reshape.hpp"
#include<GL/freeglut.h>

void reshape(int width, int height)
{
            float ratio = (float)height/width ;

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glViewport(0,0,640,480);



                    gluPerspective(45,
                                   ratio,
                                   0,
                                   100000);

                                   glFrustum(0,640,480,0,1,0);


            glMatrixMode(GL_MODELVIEW);
}
