#ifndef mainmenu_hpp
#define mainmenu_hpp

    #include <time.h>
    #include <cstdlib>
    void titlescreen();
    void  FadeIn(float speed);
    void FadeOut(float speed);
    void ShootingStars();

    bool FadeOutEnd();
    bool FadeInEnd();

        struct text3d
            {
                float x,y,z;
                float r,g,b,a;

            };

 ////////////////////////////////////////////////////////////


#endif // mainmenu_hpp
