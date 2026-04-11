#include <iostream>
#include <ctime>
#include <sstream>
#include <cmath>

using namespace std;

const int ZYCIE = 100;
const int PUNKTY = 30;

class Cios
{
public:
    int atak_fizyczny;
    int atak_magiczny;
    bool podstepny_atak;
    Cios() : atak_fizyczny(0), atak_magiczny(0), podstepny_atak(false) {}
};

class Postac
{
private:
    string imie;
    int zycie;
    int sila_fizyczny;
    int sila_magiczna;
    int obrona_fizyczna;
    int obrona_magiczna;
    double procentGauss(int skupienie);
    double procentGauss(int minimum, int skupienie);

public:
    Postac(string imie) : imie(imie)
    {
        zycie = ZYCIE;
        int atak = round(PUNKTY * procentGauss(3, 2));
        int obrona = PUNKTY - atak;
        sila_fizyczny = round(atak * procentGauss(1, 2));
        sila_magiczna = atak - sila_fizyczny;
        obrona_fizyczna = round(obrona * procentGauss(1, 2));
        obrona_magiczna = obrona - obrona_fizyczna;
    }
    Postac(string imie, int af, int am, int of, int om) : imie(imie), sila_fizyczny(af), sila_magiczna(am), obrona_fizyczna(of), obrona_magiczna(om) {}
    bool czy_zyje()
    {
        if (zycie > 0)
            return true;
        else
            return false;
    }
    string przedstaw_sie();
    Cios zadaj_cios();
    bool przyjmij_cios(Cios c);
};
//--------------koniec ciała klasy ----------

//---------------metody klasy -----------------
double Postac::procentGauss(int skupienie) // <0,1)
{
    double wynik = 0.0;
    for (int i = 0; i < skupienie; i++)
        wynik += rand() % 100;
    wynik /= skupienie;
    return wynik / 100.0;
}
double Postac::procentGauss(int minimum, int skupienie) // <minimum/100 , 1)
{
    double wynik = 0.0;
    for (int i = 0; i < skupienie; i++)
        wynik += rand() % (100 - minimum);
    wynik = wynik / skupienie + minimum;
    return wynik / 100.0;
}

string Postac::przedstaw_sie()
{
    stringstream temp;
    temp << imie << " ("
         << zycie << ")["
         << sila_fizyczny << " "
         << sila_magiczna << " "
         << obrona_fizyczna << " "
         << obrona_magiczna << "]";
    return temp.str();
}

Cios Postac::zadaj_cios()
{
    Cios c;
    c.atak_fizyczny = round(sila_fizyczny * procentGauss(1, 2));
    c.atak_magiczny = round(sila_magiczna * procentGauss(1, 2));
    if (rand() % 5 == 0)
        c.podstepny_atak = true;
    else
        c.podstepny_atak = false;
    return c;
}

bool Postac::przyjmij_cios(Cios c)
{
    int obrazenia_fizyczne = 0;
    int obrazenia_magiczne = 0;
    if (c.podstepny_atak)
    {
        obrazenia_fizyczne = c.atak_fizyczny;
        obrazenia_magiczne = c.atak_magiczny;
    }
    else
    {
        obrazenia_fizyczne = c.atak_fizyczny - round(obrona_fizyczna * procentGauss(2));
        obrazenia_magiczne = c.atak_magiczny - round(obrona_magiczna * procentGauss(2));
    }
    if (obrazenia_fizyczne < 0)
        obrazenia_fizyczne = 0;
    if (obrazenia_magiczne < 0)
        obrazenia_magiczne = 0;
    zycie = zycie - obrazenia_fizyczne - obrazenia_magiczne;
    return czy_zyje();
}
//----------- koniec metod klasy -----------------

int ring(Postac &p1, Postac &p2)
{
    int ile_ciosow = 0;
    Cios c;
    do
    {

        c = p1.zadaj_cios();
        p2.przyjmij_cios(c);
        ile_ciosow++;
        if (!p2.czy_zyje())
            break;
        c = p2.zadaj_cios();
        p1.przyjmij_cios(c);
        ile_ciosow++;
    } while (p1.czy_zyje() && p2.czy_zyje() && ile_ciosow < 200);
    return ile_ciosow;
}

int main()
{
    srand(time(NULL));
    Postac zawodnik1("Conan the Barbarian");
    Postac zawodnik2("Hary Potter");
    cout << "Przed walka: " << zawodnik1.przedstaw_sie() << " VS " << zawodnik2.przedstaw_sie() << endl;
    cout << "przeciwnicy wymienili " << ring(zawodnik1, zawodnik2) << " ciosow" << endl;
    cout << "Po walce: " << zawodnik1.przedstaw_sie() << " VS " << zawodnik2.przedstaw_sie() << endl;
    return 0;
}