#include <iostream>

using namespace std;

class Testowa
{
public:
    int x;
    Testowa(int x) : x(x) { cout << "Zadzialal konstruktor z parametrem\n"; }
    Testowa() : x(101) { cout << "Zadzialal konstruktor domyslny\n"; }
    Testowa(Testowa &szablon)
    {
        x = szablon.x;
        cout << "zadzialal konstruktor kopiujacy\n";
    }
};

void f(Testowa o)
{
    cout << "Zadzialala funkcja f\n";
    cout << "x=" << o.x << endl;
}
int main()
{
    Testowa o1(1002);
    f(o1);
    return 0;
}
