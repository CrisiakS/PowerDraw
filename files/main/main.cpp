#include "main.hpp"
#include <time.h>
#include <cstdlib>

    int main(int argc,char *argv[])
        {
            glutInit(&argc,argv);
            OpenGL::init();

            srand(time(NULL));
            gluOrtho2D(0,640,480,0);

            glutMainLoop();

        }
