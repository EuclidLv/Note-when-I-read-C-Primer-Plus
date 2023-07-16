#include "timecaculator.h"

Time::Time()
{
    hours = minutes = seconds = 0;
}

Time::Time(int h, int m, int s)
{
    hours = h;
    minutes = m;
    seconds = s;
}

void Time::AddSec(int s)
{
    seconds += s;
    minutes += seconds / 60;
    seconds %= 60;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHor(int h)
{
    hours += h;
}

void Time::Reset(int h, int m, int s)
{
    seconds = s;
    minutes = m;
    hours = h;
}

Time Time::operator+(const Time& t) const
{
    Time sum;
    sum.seconds = seconds + t.seconds;
    sum.minutes = minutes + t.minutes + sum.seconds / 60;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.seconds %= 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time& t) const
{
    Time diff;
    long tot1, tot2;
    tot1 = hours * 3600 + minutes * 60 + seconds;
    tot2 = t.hours * 3600 + t.minutes * 60 + t.seconds;
    tot1 -= tot2;
    if (tot1 < 0)
        tot1 *= -1;
    diff.hours = tot1 / 3600;
    diff.minutes = (tot1 - diff.hours * 3600) / 60;
    diff.seconds = tot1 - diff.hours * 3600 - diff.minutes * 60;
    return diff;
}

Time Time::operator*(double mult) const
{
    Time result;
    long totalseconds = hours * mult * 60 * 60 + minutes * mult * 60 + seconds * mult;
    result.hours = totalseconds / 3600;
    result.minutes = (totalseconds - result.hours * 3600) / 60;
    result.seconds = totalseconds - result.hours * 3600 - result.minutes * 60;
    return result;
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
    os << t.hours << " hours," << t.minutes << " minutes," << t.seconds << " seconds.";
    return os;
}