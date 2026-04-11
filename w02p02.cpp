#include <iostream>

using namespace std;

class Test
{
public:
    Test() { cout << "Utworzono obiekt klasy Test\n"; }
    ~Test() { cout << "Usunieto obiekt klasy Test\n"; }
};

int main()
{
    //Test t1;
    Test tab[10];
    return 0;
}