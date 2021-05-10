#include "Triad.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

Triad::Triad(int first, int second, int third)
{
    this->data[0] = first;
    this->data[1] = second;
    this->data[2] = third;
}

Triad::Triad(int d[3])
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

void Triad::setElement(int index, int d)
{
    if (index < 0 && index>2)
        throw invalid_argument("Index must be in interval [0;2]");
    data[index] = d;
}

int Triad::getElement(int index)
{
    if (index < 0 && index>2)
        throw invalid_argument("Index must be in interval [0;2]");
    return data[index];
}

bool Time::isTimeCorrect(TimeEnum type)
{
    switch (type) {
    case HOUR:
        return(data[HOUR] >= 0 && data[HOUR] <= 23);
        break;
    case MINUTE:
        return(data[MINUTE] >= 0 && data[MINUTE] <= 59);
        break;
    case SECOND:
        return(data[SECOND] >= 0 && data[SECOND] <= 59);
        break;
    }
}

bool Time::isTimeCorrect()
{
    return isTimeCorrect(HOUR) && isTimeCorrect(MINUTE) && isTimeCorrect(SECOND);
}


void Time::setElement(int index, int d)
{
    if (index < 0 && index>2)
        throw std::invalid_argument("Index must be in interval [0;2]");
    data[index] = d;
    if (!isTimeCorrect(static_cast<TimeEnum>(index)))
        throw std::invalid_argument("Time is incorrect!");
}

void Time::addNHours(int n)
{
    n %= 24;
    data[HOUR] += n;
    data[HOUR] %= 24;
}

void Time::addNMinutes(int n)
{
    addNHours(n / 60);
    n %= 60;
    data[MINUTE] += n;
    if (data[MINUTE] >= 60) {
        addNHours(1);
        data[MINUTE] %= 60;
    }
}

void Time::addNSeconds(int n)
{
    addNMinutes(n / 60);
    n %= 60;
    data[SECOND] += n;
    if (data[SECOND] >= 60) {
        data[SECOND] %= 60;
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








