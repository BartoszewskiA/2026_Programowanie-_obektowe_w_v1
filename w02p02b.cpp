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
    // Test t1;
    Test *tab[10];
    for (int i = 0; i < 10; i++)
        tab[i] = new Test;
    for (int i = 0; i < 10; i++)
        delete tab[i];
    return 0;
}