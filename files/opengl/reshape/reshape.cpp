#include "reshape.hpp"
#include "../ekran/ekran.hpp"
#include<GL/freeglut.h>
#include "../../main/main.hpp"

extern options obraz;
void reshape(int width, int height)
{
        if(width!=obraz.width)
            width=obraz.width;

        if(height!=obraz.height)
            height=obraz.height;

        if(height==0)
            height=1;

        glutReshapeWindow(width,height);


            float ratio = (float)height/width ;

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glViewport(0,0,width,height);



                    gluPerspective(obraz.angle,
                                   ratio,
                                   obraz.near_distanse,
                                   obraz.far_distanse);

                                   glFrustum(0,640,480,0,1,0);


            glMatrixMode(GL_MODELVIEW);
}
