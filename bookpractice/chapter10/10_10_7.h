#ifndef PLORG_H_
#define PLORG_H_

class Plorg
{
    private:
        static const int LIMIT = 20;
        char name[LIMIT];
        int CI;
    public:
        Plorg(const char * str = "Plorga",const int ci = 50);
        void resetCI(const int ci);
        void show() const;
};

#endif