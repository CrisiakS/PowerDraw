#include "keyboard.hpp"
#include "../../debug/debug.hpp"
#include <GL/glut.h>

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
            }
        }


