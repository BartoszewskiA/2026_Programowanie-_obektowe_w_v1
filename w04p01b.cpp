#include <iostream>
#include <sstream>

using namespace std;

class Osoba
{
private:
    string imie;
    string nazwisko;
    int wiek;

public:
    Osoba(string IMIE, string NAZWISKO, int WIEK) : imie(IMIE), nazwisko(NAZWISKO), wiek(WIEK)
    {
        cout << "Zadzialal konstruktor (" << nazwisko << ")" << endl;
    }
    void setImie(string imie) { this->imie = imie; }
    void setNazwisko(string nazwisko) { this->nazwisko = nazwisko; }
    void setWiek(int wiek) { this->wiek = wiek; }
    string getImie() { return imie; }
    string getNazwisko() { return nazwisko; }
    int getWiek() { return wiek; }
    string toString()
    {
        stringstream bufor;
        bufor << imie << " " << nazwisko << " " << wiek;
        return bufor.str();
    }
    ~Osoba()
    {
        cout << "Zadziala destruktor (" << nazwisko << ")" << endl;
    }
};

void RODO(Osoba *x) //wskaznik
{
    string nazwisko = x->getNazwisko();
    for (int i = 1; i < nazwisko.length(); i++)
        nazwisko[i] = '*';
    x->setNazwisko(nazwisko);
}

void RODO(Osoba &x)  //referencja
{
    string nazwisko = x.getNazwisko();
    for (int i = 1; i < nazwisko.length(); i++)
        nazwisko[i] = '*';
    x.setNazwisko(nazwisko);
}

void RODO(Osoba x) //kopia obiektu
{
    string nazwisko = x.getNazwisko();
    for (int i = 1; i < nazwisko.length(); i++)
        nazwisko[i] = '*';
    x.setNazwisko(nazwisko);
}

int main()
{

    // Osoba *wsk_ktos = new Osoba("Adam", "Nowak", 30);
    Osoba ktos("Jan", "Kowalski", 40);
    Osoba *wsk_ktos = &ktos;
    cout << "Przed anonimizacja: " << ktos.toString() << endl;
    RODO(wsk_ktos);
    cout << "Po aninimizacji: " << ktos.toString() << endl;
    return 0;
}