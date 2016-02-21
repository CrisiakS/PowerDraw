#include "config.hpp"
#include "../../opengl/text3d/text3d.hpp"
#include <GL/freeglut.h>

float showconf=0;
config config;
short int config_step=0;

    void configmenu()
    {
        const unsigned char pdraw[]="PowerDRAW";
        const unsigned char konf[]="Konfiguracja";
        const unsigned char ile_kamer[]="Obsluga 2 Kamer :";
        const unsigned char confighsv[]="Konfiguracja HSV";
        const unsigned char configborder[]="Konfiguracja obszaru";
        const unsigned char colors[]="Konfiguracja Palety kolorow";
        const unsigned char cam1[]="Kamera 1";
        const unsigned char cam2[]="Kamera 2";
        const unsigned char campreview[]="Podglad kamery";

        OpenGL::Text3D(konf,-2600,-700,16,1,1,0,showconf);
        OpenGL::Text3D(pdraw,-1400,-300,7.5,1,1,1,showconf);
        OpenGL::Text3D(ile_kamer,-2600,-500,18,1,1,1,showconf);

        OpenGL::Text3D(cam1,-2600,-100,18,1,1,1,showconf);
        OpenGL::Text3D(confighsv,-2600,100,18,1,1,1,showconf);
        OpenGL::Text3D(configborder,-2600,900,18,1,1,1,showconf);
        OpenGL::Text3D(colors,-2600,1200,18,1,1,1,showconf);

        OpenGL::Text3D(campreview,1500,-700,16,1,1,0,showconf);


        if(showconf<1) showconf+=0.1;
    }
