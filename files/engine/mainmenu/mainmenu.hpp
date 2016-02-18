#ifndef mainmenu_hpp
#define mainmenu_hpp

    #include <time.h>
    #include <cstdlib>
    void mainmenu();

        struct star
            {
                float x=rand()%5000-2000;
                float y=rand()%5000-2000;
                float z=rand()%40+10;
                float alpha=0;

                int pointsize=rand()%3+1;

                float getZ();
                float getY();
                float getX();

                void resetXYZ();
                void Go(float speed);

            };

#endif // mainmenu_hpp
