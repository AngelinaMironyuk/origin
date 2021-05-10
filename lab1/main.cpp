#include "ATM.h"
#include <iostream>
using namespace std;

int main() {
	auto b = ATM();
	cin >> b;
	cout << b;
	cout << "input: " << b.putMoneyIn(10, 0, 20, 1, 1) << endl;
	cout << b;
	cout << "withdraw: " << b.withdrawMoney(10770) << endl<<b;
}
