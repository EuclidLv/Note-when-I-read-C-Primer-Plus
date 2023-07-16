#ifndef TIMECACULATOR_H_
#define TIMECACULATOR_H_
#include <iostream>

class Time
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    Time();
    Time(int h, int m, int s = 0);
    void AddSec(int s);
    void AddMin(int m);
    void AddHor(int h);
    void Reset(int h, int m, int s);
    Time operator+(const Time& t)const;
    Time operator-(const Time& t)const;
    Time operator*(double n)const;
    friend Time operator*(double m, const Time& t) { return t * m; }
    friend std::ostream& operator<<(std::ostream& os, const Time& t);
};

#endif