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

                    bool capturing=false;

                    Modyfikator parameters;
                    Point point;
                public:
                    void Capture(VideoCapture &capture,int id);
                    void StopCapture(VideoCapture &capture);
                    Mat GetCapturedFrame();
                    Mat GetFinalFrame();
                    void LiczXY();
                    int getX();
                    int getY();
                    void drawAt(int x, int y,int r,int g,int b,int pointsize);
                    void eraseAt(int x,int y,int pointsize);
                    camera();
            };
    }
#endif // camera_hpp
