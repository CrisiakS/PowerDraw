#include "camera.hpp"

    namespace Video
    {
        void camera::Capture(VideoCapture &capture)
            {
                capture >> CapturedFrame;
                cvtColor(CapturedFrame,TempFrame,CV_BGR2RGBA);
                flip(TempFrame,TempFrame,0);
            }
        Mat camera::GetCapturedFrame()
            {
                return CapturedFrame;
            }

        Mat camera::GetFinalFrame()
            {
                if(!FinalFrame.empty())
                    return FinalFrame;
                else if(!TempFrame.empty())
                    return TempFrame;
                else
                    return CapturedFrame;
            }

        void camera::LiczXY()
                {
                    parameters.GetFrame(CapturedFrame);
                    parameters.GoHSV();

                      Moments oMoments = moments(parameters.MainFrame);

                        double dM01 = oMoments.m01;
                        double dM10 = oMoments.m10;
                        double dArea = oMoments.m00;


                            if (dArea > 1500)
                                {
                                    point.x = dM10 / dArea;
                                    point.y = dM01 / dArea;
                                }
                }
        int camera::getX()
            {
                return point.x;
            }

        int camera::getY()
            {
                return point.y;
            }


    }


