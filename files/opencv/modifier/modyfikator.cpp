 #include "modyfikator.hpp"
 #include "../biblioteki.hpp"
 #include "../../debug/debug.hpp"
 namespace Video
        {
            void Modyfikator::GetFrame(Mat &OriginalFrame)
                    {MainFrame=OriginalFrame;}

            void Modyfikator::GoHSV()
                {
                    if(true==false)
                    {
                        namedWindow("Opcje",WINDOW_AUTOSIZE);
                                cvCreateTrackbar("Hue","Opcje",&HueLow,HueHigh);
                                cvCreateTrackbar("Saturacja","Opcje",&SaturationLow,SaturationHigh);
                                cvCreateTrackbar("Wartosc","Opcje",&ValueLow,ValueHigh);
                    }
                    inRange(MainFrame, Scalar(HueLow, SaturationLow, ValueLow), Scalar(HueHigh, SaturationHigh, ValueHigh), TempFrame);
              //    imshow("Podglad Thresold",TempFrame);
                    flip(TempFrame,MainFrame,0);


                }

            void Modyfikator::ExportFrame(Mat &OriginalFrame)
                {
                    flip(MainFrame,OriginalFrame,0);
                }

            void Modyfikator::Show()
                {
                    imshow("Parametry",MainFrame);
                }

        }
