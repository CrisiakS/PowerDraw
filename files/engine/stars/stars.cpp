#include "stars.hpp"
#define STARS_AMOUNT 500
OpenGL::star stars[STARS_AMOUNT];
OpenGL::star *wskStars;

    namespace OpenGL
    {
            float star::getZ()
                {
                    return z;
                }
            float star::getX()
                {
                    return x;
                }
            float star::getY()
                {
                    return y;
                }

            void star::resetXYZ()
                {
                    x=rand()%20000-8000;
                    y=rand()%10000-4000;
                    z=40;
                    alpha=0;
                    pointsize=rand()%3+1;
                }
            void star::Go(float speed)
                {
                    z-=speed;
                    if(alpha<1)
                    {
                        alpha+=speed/10;
                    }
                }

            void ShootingStars()
            {
                for(int i=0;i<STARS_AMOUNT;i++)
                        {
                            wskStars=&stars[i];
                            if(wskStars->getZ()<=0)
                                {
                                    wskStars->resetXYZ();
                                }
                            else
                                {
                                    glColor4f(1,1,1,wskStars->alpha);
                                        glPointSize(wskStars->pointsize);
                                            glBegin(GL_POINTS);
                                                glVertex3f(wskStars->getX(),wskStars->getY(),wskStars->getZ());
                                            glEnd();
                                    wskStars->Go(0.1);
                                }
                        }
            }
    }
