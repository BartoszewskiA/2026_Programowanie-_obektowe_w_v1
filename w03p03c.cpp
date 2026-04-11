#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;

class Osoba
{
private:
    const string imie;
    const string nazwisko;
    int rok_urodzenia;

public:
    string getImie() { return imie; }
    string getNazwisko() { return nazwisko; }
    int getWiek()
    {
        time_t cl = time(NULL);
        tm *czas = localtime(&cl);
        return (czas->tm_year + 1900) - rok_urodzenia;
    }
    Osoba(string imie = "NN", string nazwisko = "NN", int wiek = 0) : imie(imie), nazwisko(nazwisko)
    {
        time_t cl = time(NULL);
        tm *czas = localtime(&cl);
        rok_urodzenia = (czas->tm_year + 1900) - wiek;
    }
    string toString()
    {
        stringstream bufor;
        bufor << "Imie: " << imie << endl
              << "Nazwisko: " << nazwisko << endl
              << "Wiek: " << getWiek() << endl;
        return bufor.str();
    }
};

int main()
{
    // Osoba ktos;
    // ktos.setImie("Jan");
    // ktos.setNazwisko("Kowalski");
    // ktos.setWiek(20);

    Osoba ktos("Jan", "Kowalski", 20);
    // cout << ktos.getImie() << " " << ktos.getNazwisko() << "(" << ktos.getWiek() << ")";
    cout << ktos.toString();
    return 0;
}