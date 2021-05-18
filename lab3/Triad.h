#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
/**
Cоздать класс Triad(тройка чисел);
определить методы увеличени¤ полей на 1.
Определить класс - наследник Time с полями : час, минута, секунда.
Переопределить методы увеличения полей на 1 и
определить методы увеличения на n секунд и минут.

*/using namespace std;
/**
* \brief  Класс тройка чисел
*/
class Triad {
protected:
    int data[3];
    static constexpr int MAX_INDEX_VALUE = 2;
    static constexpr int MIN_INDEX_VALUE = 0;
    static constexpr int MIN_VALUE = 0;
public:
    /**
     * \brief параметризованный конструктор
     */
    Triad(const int first = 0, const int second = 0, const int third = 0);
    /**
     * \brief параметризованный конструктор
     */
    Triad(const int d[3]);
    /**
     * \brief метод увеличения полей на 1
     */
    virtual void Increment();
    /**
     * \brief метод возвращает тройку в строковом формате
     */
    virtual string toString();
    /**
     * \brief сеттер универсальный
     */
    virtual void setElement(const int index, const int d);
    /**
     * \brief √еттер универсальный
     */
    int getElement(const int index) const;
};

/**
* \brief  ласс дл¤ работы со временем
*/
class Time :public Triad {
private:
    static constexpr int MAX_HOUR_VALUE = 23;
    static constexpr int MAX_MINUTE_VALUE = 59;
    static constexpr int MAX_SECOND_VALUE = 59;
    static constexpr int HOURS_IN_DAY = 24;
    static constexpr int MINUTES_IN_HOUR = 60;
    static constexpr int SECONDS_IN_MINUTE = 60;

    /**
    * \brief enum дл¤ временных велечин
    */
    enum TimeEnum {
        HOUR = 0,
        MINUTE = 1,
        SECOND = 2
    };
    /**
    * \brief метод проверки корректности временных велечин
    */
    bool isTimeCorrect(TimeEnum timeType) const;
    /**
    * \brief метод проверки корректности временной велечины
    */
    bool isTimeCorrect() const ;


public:
    /**
     * \brief ”наследованный ѕараметризованный конструктор
     */
    Time(int hour = 0, int minute = 0, int second = 0) :Triad(hour, minute, second)
    {
        if (!isTimeCorrect()) {
            throw std::invalid_argument("Time is incorrect!");
        }
    }
    /**
     * \brief ”наследованный ѕараметризованный конструктор
     */
    Time(int d[3]) :Triad(d)
    {
        for (int i = 0; i < 3; i++)
            if (!isTimeCorrect(static_cast<TimeEnum>(i)))
                throw std::invalid_argument("Time is incorrect!");
    }
    /**
     * \brief —еттер универсальный переопределенный
     */
    void setElement(int index, int d) override;
    /**
     * \brief ћетод увеличени¤ часов на n
     */
    void addNHours(int n);
    /**
     * \brief ћетод увеличени¤ минут на n
     */
    void addNMinutes(int n);
    /**
     * \brief ћетод увеличени¤ секунд на n
     */
    void addNSeconds(int n);
    /**
     * \brief ћетод увеличени¤ полей на 1 переопределенный
     */
    void Increment() override;
    /**
     * \brief ћетод возвращает врем¤ в строковом формате
     */
    string toString() override;
};
