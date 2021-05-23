#include <iostream>
#include "lab4.h"
using namespace std;
// функция вывода меню
void menu()
{
    string list[3] = { "Cylinder", "Cube", "Tetrahedron" };
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter " << i << " for test " << list[i] << endl;
    }
    cout << "Enter -1 for exit" << endl;
}

int main() {
    while (true)
    {
        int i;
        menu();
        cin >> i;
        switch (i)
        {
        case 0:
        {
            auto cl = Cilinder();
            cin >> cl;
            cl.getArea();
            cl.getPerimeter();
            cout << cl;
            break;
        }
        case 1:
        {
            auto cb = Cube();
            cin >> cb;
            cb.getArea();
            cb.getPerimeter();
            cout << cb;
            break;
        }
        case 2:
        {
            auto t = Tetrahedron();
            cin >> t;
            t.getArea();
            t.getPerimeter();
            cout << t;
            break;
        }
        case -1:
        {
            return 0;
        }
        }
    }
}
