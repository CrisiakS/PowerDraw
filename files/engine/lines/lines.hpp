#ifndef lines_hpp
#define lines_hpp
    namespace OpenGL
    {
            struct lines
            {
                int x,y,z;
                int xamount,yamount,space;
                float r,g,b,a;

                float wave=0;
            void Draw();
            void setXYZ(int xx,int yy,int zz);
            void moveXYZ(int xx,int yy,int zz);
            int getX();
            int getY();
            int GetZ();
            lines(int xx,int yy,int zz,
                         int xam,int yam,
                         float rr,float gg, float bb, float aa, int spacee);
            };
    }


#endif // lines_hpp
