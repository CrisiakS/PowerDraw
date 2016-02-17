#ifndef main_hpp
#define main_hpp

#include "opencv2/highgui/highgui.hpp"
using namespace cv;

    namespace Video
        {
            void CaptureIDLE();
            void GotoHSV();
            void GotoRGB();
            void LiczXY();
        }
#endif // main_hpp
