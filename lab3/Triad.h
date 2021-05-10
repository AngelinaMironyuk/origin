#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
/**
—оздать класс Triad(тройка чисел); 
определить методы увеличени¤ полей на 1.
ќпределить класс - наследник Time с пол¤ми : час, минута, секунда.
ѕереопределить методы увеличени¤ полей на 1 и 
определить методы увеличени¤на и секунд и минут.

*/using namespace std;
/**
* \brief  ласс тройка чисел
*/
class Triad {
protected:
    int data[3];
public:
    /**
     * \brief ѕараметризованный конструктор
     */
    Triad(int first = 0, int second = 0, int third = 0); 
    /**
     * \brief ѕараметризованный конструктор
     */
    Triad(int d[3]);
    /**
     * \brief ћетод увеличени¤ полей на 1
     */
    virtual void Increment();
    /**
     * \brief ћетод возвращает тройку в строковом формате
     */
    virtual string toString();
    /**
     * \brief —еттер универсальный
     */
    virtual void setElement(int index, int d);
    /**
     * \brief √еттер универсальный
     */
    int getElement(int index);
};

/**
* \brief  ласс дл¤ работы со временем
*/
class Time :public Triad {
private:
    /**
    * \brief enum дл¤ временных велечин
    */
    enum TimeEnum {
        HOUR = 0,
        MINUTE = 1,
        SECOND = 2
    };
    /**
    * \brief ћетод проверки корректности временных велечин
    */
    bool isTimeCorrect(TimeEnum type);
    /**
    * \brief ћетод проверки корректности временной велечины
    */
    bool isTimeCorrect();


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
