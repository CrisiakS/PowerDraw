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
                    Mat DrawingMask;

                    Modyfikator parameters;
                    Point point;
                public:
                    void Capture(VideoCapture &capture);
                    Mat GetCapturedFrame();
                    Mat GetFinalFrame();
                    void LiczXY();
                    int getX();
                    int getY();
           //         void drawAt(int x, int y,int r,int g,int b,int pointsize);


            };
    }
#endif // camera_hpp
