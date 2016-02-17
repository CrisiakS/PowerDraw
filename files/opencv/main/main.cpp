#include <string>
#include <iostream>
#include "main.hpp"
#include "../biblioteki.hpp"                //  Wszystkie biblioteki OpenCV w jednym pliczku
#include "../modifier/modyfikator.hpp"      //  Biblioteka modyfikatora która sluzy do obslugi przeksztalcenia HSV
#include "../point/point.hpp"               //  Biblioteka obslugujaca obiekt 'punkt' i przetrzymujaca wartosci x,y
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
extern VideoCapture cap(0);

    Video::Modyfikator parametry;           // Konstruktor obiektu "parametry" - potrzebengo do obslugi pasków HSV

        Mat TextureFrame;                   // Powierzchnia pobierana przez FreeGlut
        Mat frame(480,640,CV_8UC3);         // Deklaracja zmiennej obrazu przechwytujacej obraz kamery usb

    int VideoMode=0;        // Tryb Wideo - jak na razie sluzy do zmiany z rysowania/wycierania
    Point punkt;            // Konstruktor struktury "punkt" która przetrzymuje wartości x,y punktu laserowego

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    namespace Video                     // Przestrzeń nazw "Video" - w tej przestrzeni nazw znajduja sie funkcje odpowiadajace
        {                               // za obsluge biblioteki OpenCV



        }
