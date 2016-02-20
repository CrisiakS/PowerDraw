#include "keyboard.hpp"
#include "../../debug/debug.hpp"
#include <GL/freeglut.h>

extern int program;
extern bool titlescreen_end;

    namespace OpenGL
        {
            void keyboard(unsigned char key,int x, int y)
            {
                if(key=='q')
                {
                    exit(0);
                }

                if (key=='z')
                {
                    program=0;

                }
                if (key=='x')
                {
                    program=2;
                }

                if(key=='p')
                {
                    glutFullScreenToggle();
                }

                if(key==GLUT_KEY_BEGIN);
                {
                    if(titlescreen_end) program=1;
                }
            }
        }


