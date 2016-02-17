#ifndef camera_hpp
#define camera_hpp

    #include "../biblioteki.hpp"
    #include "../modifier/modyfikator.hpp"
    namespace Video
    {
        class camera
            {
                private:
                    Mat CapturedFrame;
                    Mat TempFrame;
                    Mat FinalFrame;

                    Modyfikator parameters;
                    Point point;
                public:
                    void Capture(VideoCapture &capture);
                    Mat GetCapturedFrame();
                    Mat GetFinalFrame();
                    void LiczXY();
                    int getX();
                    int getY();

            };
    }
#endif // camera_hpp
