#include <GL/freeglut.h>
#include <string>

#include "inicjalizacja.hpp"
#include "ekran/ekran.hpp"
#include "../mouse and keyboard/keyboard/keyboard.hpp"
#include "reshape/reshape.hpp"
#include "../debug/debug.hpp"
#include "ekran/ekran.hpp"

extern OpenGL::options obraz;

    namespace OpenGL
    {
        void timer( int extra )
            {
                glutPostRedisplay();
                glutTimerFunc( 30, timer, 0 );
            }

        void init()
            {
                glutDisplayFunc(display);
                glutKeyboardFunc(keyboard);
                glutReshapeFunc(reshape);
                glutTimerFunc(0,timer,0);

                glEnable(GL_BLEND);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

                glEnable(GL_LINE_SMOOTH);
                glHint(GL_LINE_SMOOTH, GL_NICEST);

                glEnable(GL_POINT_SMOOTH);
                glHint(GL_POINT_SMOOTH, GL_NICEST);




            }

    }
