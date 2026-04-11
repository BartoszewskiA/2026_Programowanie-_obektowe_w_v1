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

//-------------------------------------------------------------
//           KLASA POCHODNA w 2 POKOLENIU
//-------------------------------------------------------------

class Piksel_3D : public Piksel
{
protected:
    int z;

public:
    Piksel_3D() : Piksel()
    {
        z = rand() % 201 - 100;
    }
    Piksel_3D(int x, int y, int z, string kolor) : Piksel(x, y, kolor), z(z) {}
    void setZ(int z) { this->z = z; }
    int getZ() { return z; }
    double odleglosc() // przykrywa metodę odleglosc z kaly PIksel
    {
        return sqrt(Piksel::odleglosc() * Piksel::odleglosc() + z * z);
    }
};

int main()
{
    srand(time(NULL));
    Piksel_3D p1(1, 5, 7, "red");
    Piksel_3D p2;
    // Piksel p2(10, 20, "red");
    // Piksel p1;
    //  p1.setX(10);
    //  p1.setY(20);
    //  p1.setKolor("green");
    cout << p1.getX() << " "
         << p1.getY() << " "
         << p1.getZ() << " "
         << p1.getKolor() << " "
         << p1.odleglosc();
    return 0;
}