#include "keyboard.hpp"
#include "../../engine/mainmenu/mainmenu.hpp"
#include "../../debug/debug.hpp"
#include <GL/freeglut.h>

extern int program;
extern bool titlescreen_end;
extern short int menu_step;

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

                if(key==13)
                {
                    program=1;
                }
                if(key=='r')
                {

                }
                if(key=='f')
                {

                }
            }

            void keyup(unsigned char key,int x, int y)
            {


            }

            void SpecialInput(int key, int x, int y)
            {
                if(key==GLUT_KEY_DOWN)
                {
                    if(menu_step<3)menu_step++;
                }
                if(key==GLUT_KEY_UP)
                {
                    if(menu_step>0)menu_step--;
                }
            }
        }


