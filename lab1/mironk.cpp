#include "bankomat.h"
#include <iostream>
using namespace std;

int main() {
	auto b = Bankomat();
	cin >> b;
	cout << b;
	cout << "input: " << b.putMoneyIn(10, 0, 20, 1, 1) << endl;
	cout << b;
	cout << "withdraw: " << b.withdrawMoney(100060) << endl<<b;
}
