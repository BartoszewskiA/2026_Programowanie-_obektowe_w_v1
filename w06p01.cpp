#include <iostream>
#include <cmath>

using namespace std;

class Punkt // klasa bazowa
{
protected:
    int x;
    int y;

public:
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    int getX() { return x; }
    int getY() { return y; }
};

class Piksel : public Punkt // klasa pochodna
{
public:
    double x;
    double odleglosc()
    {
        // int a = getX();
        // int b = getY();
        // return sqrt(a*a + b*b);
        return sqrt(x * x + y * y);
    }
    void metoda_testowa()
    {
        x;        // x z klasy pochodnej
        Punkt::x; // x z klasy bazowej (przesłonięty)
    }
};

int main()
{
    Piksel p1;
    p1.setX(10);
    p1.setY(20);
    cout << p1.getX() << " " << p1.getY() << " " << p1.odleglosc();
    return 0;
}