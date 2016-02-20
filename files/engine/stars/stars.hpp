#ifndef stars_hpp
#define stars_hpp

    #include <time.h>
    #include <cstdlib>
    #include <GL/freeglut.h>
    namespace OpenGL
    {
        struct star
            {
                float x=rand()%20000-8000;
                float y=rand()%10000-4000;
                float z=rand()%40+10;
                float alpha=0;

                int pointsize=rand()%3+1;

                float getZ();
                float getY();
                float getX();

                void resetXYZ();
                void Go(float speed);

            };
        /////////////////////////
        void ShootingStars();
    }
#endif // stars_hpp
