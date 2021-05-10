#include <vector>
#include <stdexcept>
#include <string>
#include "Triad.h"

int main()
{
    vector<Triad*> vector;
    try {
        vector.push_back(new Triad(1, 2, 3));
        vector.push_back(new Time(10, 59, 59));
        //vector.push_back(new Time(-1,2,3)); раскомментировать для формирования исключения
        //vector.push_back(new Time(23,0,60));
    }

    catch (exception& e) {
        cout << e.what() << endl;
        return -1;
    }

    for (auto& i : vector) {
        cout << i->toString() << " |Incremented: ";

        try {
            i->Increment();
        }

        catch (exception& e) {
            std::cout << e.what() << endl;
        }

        cout << i->toString() << endl
            << "First: " << i->getElement(0) << endl
            << "Second: " << i->getElement(1) << endl
            << "Third: " << i->getElement(2) << endl;

        cout<< "Manually setting first value to 3: ";
        i->setElement(0, 3);
        cout << i->toString() << endl;

        cout << "Manually setting second value to 4: ";
        i->setElement(1, 4);
        cout << i->toString() << endl;

        cout << "Manually setting third value to 8: ";
        i->setElement(2, 8);
        cout << i->toString() << endl;

        if (Time* t = dynamic_cast<Time*>(i)) {
            cout << "Incremented by 1 minute and 2 seconds: " << endl;
            try {
                dynamic_cast<Time*>(i)->addNMinutes(1);
                dynamic_cast<Time*>(i)->addNSeconds(2);
                cout << i->toString();
            }

            catch (exception& e) {
                cout << e.what() << endl;
                return -1;
            }
        }
        cout << endl;
    }
    return 0;
}