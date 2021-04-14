#include "Bankomat.h"
#include <iostream>
#include <string>
using namespace std;

class Bankomat
{
public:
	Bankomat() {};
	Bankomat(int Account = 0, int ID = 0) {};
	Bankomat(const Bankomat& other) {};
	~Bankomat();


	/**
	 * \brief  метод, возвращающий идентификационный номер
	 * \return Идентификационный номер
	 */
	int GetID()
	{
		return ID;
	};


	void setID(int ID) {
		this->ID = ID;
	}

	void addMoney(int i) {
		if ((i < min) || (i > max)) {
			cout << "Mistake!";
			return;
		}
		if ((Account + i) > max) {
			cout << "Please insert max = " << max - Account << endl;
			return;
		}
		Account = i;
	}

	void getMoney(int i) {
		if ((i < min) || (i > max)) {
			cout << "Mistake!";

		}
		if ((Account - i) < 0) {
			cout << "Problem" << endl << "get max: " << Account << endl;
		}
		Account -= i;
	}

	void toString() const {
		cout << "Account: " << Account << endl;
	}


private:
	int ID;
	int Account;
	int max = 1000;
	int min = 10;
};