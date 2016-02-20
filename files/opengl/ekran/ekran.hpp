#ifndef ekran_hpp
#define ekran_hpp

    namespace OpenGL
        {
            void display();

            struct options
                {
                    int width=1024;
                    int height=768;

                    int angle=45;
                    int near_distanse=0;
                    int far_distanse=10000;

                    bool fullscreen=true;

                };

        }

#endif // ekran_hpp
