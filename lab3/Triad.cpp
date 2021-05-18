#include "Triad.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

Triad::Triad(const int first, const int second, const int third)
{
    this->data[0] = first;
    this->data[1] = second;
    this->data[2] = third;
}

Triad::Triad(const int d[3])
{
    for (int i = 0; i < 3; i++)
        data[i] = d[i];
}

void Triad::Increment()
{
    for (int i = 0; i < 3; i++)
        data[i]++;
}

string Triad::toString()
{
    string ans = "";
    for (int i = 0; i < 3; i++)
        ans += to_string(data[i]) + " ";
    ans.pop_back();
    return ans;
}

void Triad::setElement(const int index, const int d)
{
    if (index < MIN_INDEX_VALUE && index>MAX_INDEX_VALUE)
        throw invalid_argument("Index must be in interval [0;2]");
    data[index] = d;
}

int Triad::getElement(const int index) const
{
    if (index < MIN_INDEX_VALUE && index>MAX_INDEX_VALUE)
        throw invalid_argument("Index must be in interval [0;2]");
    return data[index];
}

bool Time::isTimeCorrect(TimeEnum timeType) const
{
    switch (timeType) {
    case HOUR:
        return(data[HOUR] >= MIN_VALUE && data[HOUR] <= MAX_HOUR_VALUE);
        break;
    case MINUTE:
        return(data[MINUTE] >= MIN_VALUE && data[MINUTE] <= MAX_MINUTE_VALUE);
        break;
    case SECOND:
        return(data[SECOND] >= MIN_VALUE && data[SECOND] <= MAX_SECOND_VALUE);
        break;
    }
}

bool Time::isTimeCorrect() const
{
    return isTimeCorrect(HOUR) && isTimeCorrect(MINUTE) && isTimeCorrect(SECOND);
}


void Time::setElement(int index, int d)
{
    if (index < MIN_INDEX_VALUE && index>MAX_INDEX_VALUE)
        throw std::invalid_argument("Index must be in interval [0;2]");
    data[index] = d;
    if (!isTimeCorrect(static_cast<TimeEnum>(index)))
        throw std::invalid_argument("Time is incorrect!");
}

void Time::addNHours(int n)
{
    n %= HOURS_IN_DAY;
    data[HOUR] += n;
    data[HOUR] %= HOURS_IN_DAY;
}

void Time::addNMinutes(int n)
{
    addNHours(n / MINUTES_IN_HOUR);
    n %= MINUTES_IN_HOUR;
    data[MINUTE] += n;
    if (data[MINUTE] >= MINUTES_IN_HOUR) {
        addNHours(1);
        data[MINUTE] %= MINUTES_IN_HOUR;
    }
}

void Time::addNSeconds(int n)
{
    addNMinutes(n / SECONDS_IN_MINUTE);
    n %= SECONDS_IN_MINUTE;
    data[SECOND] += n;
    if (data[SECOND] >= SECONDS_IN_MINUTE) {
        data[SECOND] %= SECONDS_IN_MINUTE;
        addNMinutes(1);
    }
}

void Time::Increment()
{
    addNSeconds(1);
    addNHours(1);
    addNMinutes(1);
}

string Time::toString()
{
    string ans = "";
    for (int i = 0; i < 3; i++)
        ans += std::to_string(data[i]) + ":";
    ans.pop_back();
    return ans;
}








