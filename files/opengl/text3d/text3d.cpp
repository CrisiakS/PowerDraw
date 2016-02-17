#include "text3d.hpp"
#include <GL/freeglut.h>
#include <string>

using namespace std;

namespace OpenGL
    {
        void Text3D(const unsigned char tekst[],
                    float x,float y, float z,
                    float r,float g, float b, float a)
                    {
                                    glPushMatrix();
                                        glColor4f(r,g,b,a);
                                        glTranslatef(x,y,z);
                                        glRotatef(180,1,0,0);
                                            glutStrokeString(GLUT_STROKE_MONO_ROMAN,tekst);

                                    glPopMatrix();
                        }


    }

