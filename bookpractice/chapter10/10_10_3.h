// class definition for the golf
#ifndef GOLF_H_
#define GOLF_H_

// const int len = 40;

class Golf
{
    private:
        static const int len = 40;
        char fullname[len];
        int handicap;
    public:
        Golf(const char * name="", int hc=0);
        int setgolf();
        void handi(int hc);
        void showgolf() const;
}; 

#endif