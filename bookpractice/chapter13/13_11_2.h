#ifndef CLASSIC_H_
#define CLASSIC_H_

class Cd
{
private:
    char * performers;
    char * label;
    int selections;
    double playtime;

public:
    Cd(char const * s1, char const * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd();
    virtual void Report() const; // reports all CD data
    virtual Cd & operator=(const Cd & d);
};

class Classic: public Cd
{
private:
    char * major_works;

public:
    Classic(char const * s1, char const * s2, char const * s3, int n = 0, double x = 0.0);
    Classic(char const * s1, const Cd & d);
    Classic(const Classic & c);
    Classic();
    virtual ~Classic();
    virtual void Report() const;
    virtual Classic & operator=(const Classic & c);
};

#endif