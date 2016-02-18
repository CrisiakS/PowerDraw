#include "reshape.hpp"
#include "../ekran/ekran.hpp"
#include<GL/freeglut.h>

extern OpenGL::options obraz;

void reshape(int width, int height)
{
            float ratio = (float)height/width ;

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glViewport(0,0,width,height);



                    gluPerspective(obraz.angle,
                                   ratio,
                                   obraz.near_distanse,
                                   obraz.far_distanse);

                                   glFrustum(0,width,height,0,1,0);


            glMatrixMode(GL_MODELVIEW);
}
