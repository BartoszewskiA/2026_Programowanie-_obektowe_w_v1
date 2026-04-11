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
    Liczba l1(101);
    //l1.setX(10);
    cout << "Przechowywana liczba to: " << l1.getX();
    return 0;
}