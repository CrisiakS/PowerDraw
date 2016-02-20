#include "reshape.hpp"
#include "../ekran/ekran.hpp"
#include<GL/freeglut.h>

extern OpenGL::options obraz;

void reshape(int width, int height)
{
            float ratio = (float)width/height ;

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glViewport(0,0,(float)width,(float)height);



                    gluPerspective(obraz.angle+width/60,
                                   ratio,
                                   obraz.near_distanse,
                                   obraz.far_distanse);

                                   glFrustum(0,(float)width,(float)height+30,0,1,0);

            glMatrixMode(GL_MODELVIEW);
}
