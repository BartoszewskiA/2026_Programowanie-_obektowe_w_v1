#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

class Punkt // klasa bazowa
{
protected:
    int x;
    int y;

public:
    Punkt()
    {
        x = rand() % 201 - 100;
        y = rand() % 201 - 100;
    }
    Punkt(int x, int y) : x(x), y(y) {}
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    int getX() { return x; }
    int getY() { return y; }
};

//-------------------------------------------------------------
//           KLASA POCHODNA
//-------------------------------------------------------------

class Piksel : public Punkt // klasa pochodna
{
protected:
    string kolor;

public:
    Piksel() : Punkt()
    {
        string kolory[] = {"Red", "Green", "Blue"};
        kolor = kolory[rand() % 3];
    }
    Piksel(int x, int y, string kolor) : Punkt(x, y), kolor(kolor) {}
    double odleglosc()
    {
        return sqrt(x * x + y * y);
    }
    void setKolor(string kolor) { this->kolor = kolor; }
    string getKolor() { return kolor; }
};

int main()
{
    srand(time(NULL));
    Piksel p2(10, 20, "red");
    Piksel p1;
    // p1.setX(10);
    // p1.setY(20);
    // p1.setKolor("green");
    cout << p1.getX() << " "
         << p1.getY() << " "
         << p1.getKolor() << " "
         << p1.odleglosc();
    return 0;
}