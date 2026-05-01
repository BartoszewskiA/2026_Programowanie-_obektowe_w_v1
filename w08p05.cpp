#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class Wektor
{

private:
    double x, y;

public:
    Wektor(double x = 0, double y = 0) : x(x), y(y) {}
    // deklaracje przyjaźni
    Wektor operator+(const Wektor &w2)
    {
        Wektor w(this->x + w2.x, this->y + w2.y);
        return w;
    }

    Wektor operator-(Wektor w2)
    {
        Wektor wynik;
        wynik.x = this->x - w2.x;
        wynik.y = this->y - w2.y;
        return wynik;
    }

    Wektor operator*(double s)
    {
        Wektor wynik(this->x * s, this->y * s);
        return wynik;
    }
    friend Wektor operator*(double s, Wektor w); // musi być zdefiniowany na zewnątrz klasy

    void operator+=(Wektor w2)
    {
        this->x += w2.x;
        this->y += w2.y;
    }
    friend ostream &operator<<(ostream &str, Wektor w);  // musi być zdefiniowany na zewnątrz klasy
    friend istream &operator>>(istream &str, Wektor &w); // musi być zdefiniowany na zewnątrz klasy
    // operatory logiczne
    friend bool operator==(const Wektor &w1, const Wektor &w2);
};

//---operatory zaprzyjaźnione z klasą-------------

Wektor operator*(double s, Wektor w)
{
    Wektor wynik(w.x * s, w.y * s);
    return wynik;
}

ostream &operator<<(ostream &str, Wektor w)
{
    str << "[" << w.x << ";" << w.y << "]";
    return str;
}

istream &operator>>(istream &str, Wektor &w)
{
    str >> w.x >> w.y;
    return str;
}

bool operator==(const Wektor &w1, const Wektor &w2)
{
    if ((w1.x * w1.x + w1.y * w1.y) == (w2.x * w2.x + w2.y * w2.y))
        return true;
    else
        return false;
}
//--------------------------

int main()
{
    Wektor A(20, 50), B(30, -5);
    if (A == B)
        cout << "TAK";
    else
        cout << "NIE";
    return 0;
}