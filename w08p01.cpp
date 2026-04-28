#include <iostream>
#include <sstream>

using namespace std;

class Wektor
{
public:
    double x, y;
    Wektor(double x = 0, double y = 0) : x(x), y(y) {}
    string wypisz()
    {
        stringstream s;
        s << "[" << x << ";" << y << "]";
        return s.str();
    }
};

//---operatory -------------
Wektor operator-(Wektor w1, Wektor w2)
{
    Wektor wynik;
    wynik.x = w1.x - w2.x;
    wynik.y = w1.y - w2.y;
    return wynik;
}

Wektor operator+(const Wektor &w1, const Wektor &w2) // nie następuje kopiowanie  przy przekazywaniu parametrów
{
    Wektor wynik(w1.x + w2.x, w1.y + w2.y);
    return wynik;
}

Wektor operator*(Wektor w, double s)
{
    Wektor wynik(w.x * s, w.y * s);
    return wynik;
}

Wektor operator*(double s, Wektor w)
{
    Wektor wynik(w.x * s, w.y * s);
    return wynik;
}

void operator+=(Wektor &w1, Wektor w2)
{
    // w1.x = w1.x + w2.x;
    // w1.y = w1.y + w2.y;
    w1.x += w2.x;
    w1.y += w2.y;
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
//--------------------------

int main()
{
    Wektor A(20, 50), B(30, -5);

    // Wektor wynik(A.x + B.x, A.y+B.y);

    // Wektor wynik = A - B;
    // Wektor wynik = 3 * A;

    Wektor wynik;
    // wynik = wynik + A;

    wynik += A;
    // cout << wynik.wypisz();
    cin >> wynik;
    cout << wynik;
    return 0;
}