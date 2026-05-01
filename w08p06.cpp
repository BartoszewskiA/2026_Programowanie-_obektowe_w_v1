#include <iostream>
#include <ctime>

using namespace std;

class ArrayInt
{
private:
    int n;
    int *tab;

public:
    ArrayInt(int ile) : n(ile)
    {
        tab = new int[n];
    }     
    ~ArrayInt()
    {
        delete[] tab;
    }

    int &operator[](unsigned int index)
    {
        return tab[index];
    }
    int length()
    {
        return n;
    }
};

void losuj(ArrayInt &t)
{
    for (int i = 0; i < t.length(); i++)
        t[i] = rand() % 101;
}
void wypisz(ArrayInt &t)
{
    for (int i = 0; i < t.length(); i++)
        cout << t[i] << " ";
}

int main()
{
    srand(time(NULL));
    cout << "ile elementow: ";
    int dlugosc = 0;
    cin >> dlugosc;
    ArrayInt tablica(dlugosc);
    losuj(tablica);
    wypisz(tablica);
    return 0;
}
