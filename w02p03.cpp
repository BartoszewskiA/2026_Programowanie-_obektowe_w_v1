#include <iostream>

using namespace std;

class Liczba
{
private:
    int x;

public:
    Liczba(int px) { x = px; } // konstruktor z parametrem
    void setX(int px) { x = px; }
    int getX() { return x; }
    ~Liczba() {}
};

int main()
{
    Liczba l1(10);
    Liczba(101); // obiekt ananimowy (bez nazwy)
    Liczba tab[] = {Liczba(10), Liczba(20), Liczba(30)};

    cout << tab[0].getX();
    return 0;
}