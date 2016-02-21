#include "keyboard.hpp"
#include "../../engine/mainmenu/mainmenu.hpp"
#include "../../debug/debug.hpp"
#include <GL/freeglut.h>

extern int program;
extern bool titlescreen_end;
extern short int menu_step;
extern float showmenu;
extern float showconf;

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
                        showmenu=0;
                        program=1;
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
                    if(program==0)
                    {
                        showmenu=0;
                        program=1;
                    }

                    if(program==1 and menu_step==2)
                        {
                           program=3;
                           showconf=0;
                        }


                    if(program==1 and menu_step==4)
                        exit(0);

                }
                if(key=='r')
                {

                }
                if(key=='f')
                {

                }
                if(key==27)
                {
                    if(program==3)
                    {
                        showmenu=0;
                        program=1;
                    }
                }
            }

            void keyup(unsigned char key,int x, int y)
            {


            }

            void SpecialInput(int key, int x, int y)
            {
                if(key==GLUT_KEY_DOWN)
                {
                    if(menu_step<4 and program==1)menu_step++;
                }
                if(key==GLUT_KEY_UP)
                {
                    if(menu_step>0 and program==1)menu_step--;
                }

            }
        }


