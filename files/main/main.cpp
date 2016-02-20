#include "main.hpp"
#include "../opengl/ekran/ekran.hpp"
#include <time.h>
#include <cstdlib>

extern OpenGL::options obraz;

    int main(int argc,char *argv[])
        {

            glutInit(&argc,argv);
            glutInitDisplayMode(GLUT_DEPTH and GLUT_DOUBLE and GLUT_RGBA);
            glutInitWindowSize(obraz.width,obraz.height);
            glutInitWindowPosition(0,0);

            glutGameModeString("1366x768:32@60");
            if(obraz.fullscreen)
                glutFullScreenToggle();

            glutCreateWindow("PowerDraw");
            OpenGL::init();

            srand(time(NULL));
            gluOrtho2D(0,640,480,0);

            glutMainLoop();

        }
