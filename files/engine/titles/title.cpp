#include "title.hpp"
#include "../../opengl/text3d/text3d.hpp"
#include <math.h>

float presstart=0;
        void StartInfo()
        {
            if(presstart>1000)
                presstart=0;

            const unsigned char pdrawpress[]="Wcisnij ENTER by rozpoczac";
                OpenGL::Text3D(pdrawpress,-920,800,30,1,1,0,sin(presstart));
                presstart+=0.1;
        }
