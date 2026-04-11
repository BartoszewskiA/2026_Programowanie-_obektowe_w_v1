#include <iostream>
#include <ctime>

using namespace std;

class Liczba
{
private:
    int x;

public:
    Liczba(int px) { x = px; } // konstruktor z parametrem
    void setX(int px) { x = px; }
    int getX() { return x; }
    ~Liczba() {}
};

int main()
{
    srand(time(NULL));
    Liczba *tab[100];
    for (int i = 0; i < 100; i++)
        tab[i] = new Liczba(rand() % 100);
    for (int i = 0; i < 100; i++)
        cout << tab[i]->getX() << " ";
    for (int i = 0; i < 100; i++)
        delete tab[i];
    return 0;
}