#include <iostream>
#include<math.h>
#include<tchar.h>
using namespace std;

enum constTime {
	SECONDS_IN_HOUR = 3600,
	SECONDS_IN_MINUTE = 60
};

/*
* \brief  Независимый класс с полями-параметрами исключения
*/
class Exeption
{
private:
	string error;
public:
	Exeption(string error) : error(error) {}
	const char* getError() { return error.c_str(); }
};

/*
* \brief время
*/
struct Time
{
	int hour;
	int minute;
	int sec;
	/*
	* \brief 4_1 Спецификация с собственным реализованным исключением
	*/
	Time(int h, int m, int s) : hour(h), minute(m), sec(s)
	{
		if (h > 24) throw Exeption("Incorrect hours");
		if (m > 60) throw Exeption("Incorrect minute");
		if (s > 60) throw Exeption("Incorrect sec");
	}
};

/*
* \brief метод нахождения разницы во времени
*/
int deltaTime(Time& start, Time& end) {
	return (end.hour * SECONDS_IN_HOUR + end.minute * SECONDS_IN_MINUTE + end.sec) - (start.hour * SECONDS_IN_HOUR + start.minute * SECONDS_IN_MINUTE + start.sec);
}

/*
* \brief метод перевода секунд в время стандартного вида
*/
Time& secToTime(int delta) {
	int hour = delta / SECONDS_IN_HOUR;
	delta = delta - hour * SECONDS_IN_HOUR;
	int minute = delta / SECONDS_IN_MINUTE;
	delta = delta - minute * SECONDS_IN_MINUTE;
	int sec = delta;
	Time t(hour, minute, sec);
	return t;
}

/*
* \brief функция 1 без спецификации исключений;
*/
Time& count1(Time& start, Time& end)
{
	int delta = deltaTime(start, end);
	if (delta < 0) throw "End earlier then begining";
	return secToTime(delta);
}

/*
* \brief функция 2 со спецификацией throw();
*/
Time& count2(Time& start, Time& end) throw (double)
{
	int delta = deltaTime(start, end);
	if (delta < 0)  throw "End earlier then begining";
	return secToTime(delta);
}

/*
* \brief функция 3 с конкретной спецификацией с подходящим стандартным исключением;
*/
Time& count3(Time& start, Time& end) throw (invalid_argument)
{
	int delta = deltaTime(start, end);
	if (delta < 0)  throw invalid_argument("End earlier then begining");
	return secToTime(delta);
}

/*
* \brief Пустой класс
*/
class VoidException {};
/*
* \brief 4_2 Спецификация с собственным реализованным исключением
*/
Time& count4_2(Time& start, Time& end) throw(VoidException) {
	int delta = deltaTime(start, end);
	if (delta < 0)  throw VoidException();
	return secToTime(delta);
};

/*
* \brief 4_3 Класс наследник от стандартного исключения с полями
*/
class InCorrectArgument : public exception
{
public:
	const char* what() const throw() {
		return "End earlier then begining";
	}
};
/*
* \brief 4_3 Спецификация с собственным реализованным исключением
*/
Time& count4_3(Time& start, Time& end) throw(VoidException) {
	int delta = deltaTime(start, end);
	if (delta < 0)  throw InCorrectArgument();
	return secToTime(delta);
};

int main()
{
	int h = 6, m = 50, s = 9;
	cout << "Test  normal values: ";
	try {
		Time start(1, 2, 3);
		Time end(1, 3, 4);
		Time sum = count1(start, end);
		cout << sum.hour << "h " << sum.minute << "m " << sum.sec << "s\n";
	}
	catch (...)
	{
		cout << "error1" << endl;
	}
	cout << "Test  error 1: ";
	try {
		Time start(h + 2, m, s);
		Time end(h + 1, m + 3, s + 2);
		Time sum = count1(start, end);
		cout << sum.hour << "h " << sum.minute << "m " << sum.sec << "s\n";
	}
	catch (...)
	{
		cout << "error1" << endl;
	}
	cout << "Test  error 2: ";
	try {
		Time start(h + 2, m, s);
		Time end(h + 1, m + 1, s + 2);
		Time sum = count2(start, end);
		cout << sum.hour << "h " << sum.minute << "m " << sum.sec << "s\n";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	cout << "Test  error 3: ";
	try {
		Time start(h + 2, m, s);
		Time end(h, m, s);
		Time sum = count3(start, end);
		cout << sum.hour << "h " << sum.minute << "m " << sum.sec << "s\n";
	}
	catch (invalid_argument e)
	{
		cout << e.what() << endl;
	}
	cout << "Test  error 4_1: ";
	try {
		Time start(h, m + 50, s);
		Time end(h, m, s);
		Time sum = count3(start, end);
		cout << sum.hour << "h " << sum.minute << "m " << sum.sec << "s\n";
	}
	catch (Exeption exept)
	{
		cout << exept.getError() << endl;
	}
	cout << "Test  error 4_2: ";
	try {
		Time start(h, m + 3, s);
		Time end(h, m, s);
		Time sum = count4_2(start, end);
		cout << sum.hour << "h " << sum.minute << "m " << sum.sec << "s\n";
	}
	catch (VoidException& e) {
		cout << "Error 4_2\n";
	}
	cout << "Test  error 4_3: ";
	try {
		Time start(h, m + 3, s);
		Time end(h, m, s);
		Time sum = count4_3(start, end);
		cout << sum.hour << "h " << sum.minute << "m " << sum.sec << "s\n";
	}
	catch (InCorrectArgument& e) {
		cout << e.what();
	}
}