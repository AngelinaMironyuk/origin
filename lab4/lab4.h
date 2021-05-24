#include <iostream>
#include <cmath>
/**
* \brief Класс фигура
*/
class Figure {

protected:
    /**
    * \brief Деструктор
    */
    ~Figure() {};
    /**
    * \brief Периметр
    */
    double perimeter = 0;
    /**
    * \brief Площадь
    */
    double  area = 0;
    static constexpr double PI = 2 * asin(double(1));
    /**
    * \brief метод проверки ввода
    */
    double checkValue(const double value) const;
public:
    /**
    * \brief виртуальное объявление метода нахождения периметра
    */
    virtual double getPerimeter() = 0;
    /**
    * \brief виртуальное объявление метода нахождения площади
    */
    virtual double getArea() = 0;
    /**
    * \brief Перегруженный оператор вывода
    */
    friend std::ostream& operator<< (std::ostream& out, const Figure& figure);
};

/**
* \brief Класс цилиндр
*/
class  Cilinder : public Figure {
private:
    /**
    * \brief поле - радиус и восота цилиндра
    */
    double r, h;
    static constexpr int CYLINDER_BASES = 2;
    static constexpr double TWO_PI = 4 * asin(double(1));

public:
    /**
    * \brief Деструктор
    */
    ~Cilinder() = default;
    /**
    * \brief Конструктор по умолчанию
    */
    Cilinder() = default;
    /**
    * \brief Конструктор параметризованный
    */
    Cilinder(const double r, const double h);
    /**
    * \brief метод нахождения периметра (основания)
    */
    double getPerimeter() override;
    /**
    * \brief метод нахождения площади
    */
    double getArea() override;
    /**
     * \brief Перегруженный оператор ввода
     */
    friend std::istream& operator>> (std::istream& in, Cilinder& cilinder);
};

/**
* \brief Класс куб
*/
class Cube : public Figure {
private:
    /**
    * \brief  поле - сторона куба
    */
    double a;
    static constexpr int FACES_OF_CUBE = 6;
    static constexpr int ADGES_OF_CUBE = 12;
public:
    /**
    * \brief Деструктор
    */
    ~Cube() = default;
    /**
    * \brief Конструктор по умолчанию
    */
    Cube() = default;
    /**
    * \brief Конструктор параметризованный
    */
    Cube(const double a);
    /**
    * \brief метод нахождения периметра
    */
    double getPerimeter() override;
    /**
    * \brief метод нахождения площади
    */
    double getArea() override;
    /**
     * \brief Перегруженный оператор ввода
     */
    friend std::istream& operator>> (std::istream& in, Cube& cube);
};

/**
* \brief Класс тетраэдр
*/
class Tetrahedron : public Figure {
private:
    /**
    * \brief  поле - сторона тетраэдра
    */
    double a;
    static constexpr int ADGES_OF_TETR = 6;
    static constexpr int FACTOR_AREA_TETR = sqrt(3);
public:
    /**
    * \brief Деструктор
    */
    ~Tetrahedron() = default;
    /**
    * \brief Конструктор по умолчанию
    */
    Tetrahedron() = default;
    /**
    * \brief Конструктор параметризованный
    */
    Tetrahedron(const double a);
    /**
    * \brief метод нахождения периметра
    */
    double getPerimeter() override;
    /**
    * \brief метод нахождения площади
    */
    double getArea() override;
    /**
     * \brief Перегруженный оператор ввода
     */
    friend std::istream& operator>> (std::istream& in, Tetrahedron& tetrahedron);
};
