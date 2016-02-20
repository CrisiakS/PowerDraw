#include "keyboard.hpp"
#include "../../debug/debug.hpp"
#include <GL/freeglut.h>

extern int program;

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
                    program=1;
                }

                if(key=='p')
                {
                    glutFullScreenToggle();
                }
            }
        }


