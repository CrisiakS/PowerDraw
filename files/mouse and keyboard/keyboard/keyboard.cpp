#include "keyboard.hpp"
#include "../../debug/debug.hpp"
#include <GL/glut.h>
#include "../../opencv/main/main.hpp"

extern int VideoMode;

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
                    VideoMode=1;
                }
                if (key=='x')
                {
                    VideoMode=2;
                }
            }
        }


