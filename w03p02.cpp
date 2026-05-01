#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Osoba
{
private:
    string imie;
    string nazwisko;
    int rok_urodzenia;

public:
    void setImie(string imie) { this->imie = imie; }
    void setNazwisko(string nazwisko) { this->nazwisko = nazwisko; }
    void setWiek(int wiek)
    {
        time_t cl = time(NULL);
        tm *czas = localtime(&cl);
        rok_urodzenia = (czas->tm_year + 1900) - wiek;
    }
    string getImie() { return imie; }
    string getNazwisko() { return nazwisko; }
    int getWiek()
    {
        time_t cl = time(NULL);
        tm *czas = localtime(&cl);
        return (czas->tm_year + 1900) - rok_urodzenia;
    }
    Osoba(string imie = "NN", string nazwisko = "NN", int wiek = 0)
    {
        this->imie = imie;
        this->nazwisko = nazwisko;
        time_t cl = time(NULL);
        tm *czas = localtime(&cl);
        rok_urodzenia = (czas->tm_year + 1900) - wiek;
    }
};

int main()
{
    // Osoba ktos;
    // ktos.setImie("Jan");
    // ktos.setNazwisko("Kowalski");
    // ktos.setWiek(20);

    Osoba ktos("Jan", "Kowalski", 20);

    cout << ktos.getImie() << " " << ktos.getNazwisko() << "(" << ktos.getWiek() << ")";
    return 0;
}