#include "camera.hpp"
#include "../../main/main.hpp"

extern options obraz;

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

  /*      void camera::drawAt(int x, int y,int r,int g,int b,int pointsize)
            {
                if(point.y>pointsize/2 and point.y<(obraz.height-pointsize/2)and point.x>pointsize/2 and point.x<(obraz.width-pointsize/2))
                        for(int y=(point.y-pointsize/2);y<(point.y+pointsize/2);y++)
                        {
                            for(int x=((point.x-pointsize/2));x<(point.x+(pointsize/2));x++)
                            {
                                   Vec3b color = DrawingMask.at<Vec3b>(Point(x,y));
                                   color[0]=r;
                                   color[1]=g;
                                   color[2]=b;
                                   DrawingMask.at<Vec3b>(Point(x,y)) = color;
                            }
                        }

                  if(punkt.y>5 and punkt.y<475 and punkt.x>5 and punkt.x<635 and VideoMode==2)
                        for(int y=(punkt.y-pointsize/2);y<(punkt.y+pointsize/2);y++)
                        {
                            for(int x=((punkt.x-pointsize/2));x<(punkt.x+(pointsize/2));x++)
                            {
                                   Vec3b color = DrawingMask.at<Vec3b>(Point(x,y));
                                   color[0]=NULL;
                                   color[1]=NULL;
                                   color[2]=NULL;
                                   DrawingMask.at<Vec3b>(Point(x,y)) = color;
                            }
                        }

                        Mat rgbFrame(640, 480, CV_8UC3);
                        cvtColor(DrawingMask, rgbFrame, CV_BGR2RGB);

                        // ...now let it convert it to RGBA
                        Mat newSrc = Mat(rgbFrame.rows, rgbFrame.cols, CV_8UC4);
                            int from_to[] = { 0,0, 1,1, 2,2, 3,3 };
                        mixChannels(&rgbFrame, 2, &newSrc, 1, from_to, 4);

                        TempFrame=newSrc;

            }
    */
    }


