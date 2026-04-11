#include <iostream>

using namespace std;

class Punkt
{
public:
    int x;
    int y;
    void przedstaw_sie() //metoda inline
    {
        cout << "(" << x << " - " << y << ")";
    }
    void przedstaw_sie_v2();
};

void Punkt::przedstaw_sie_v2()
{
    cout << "(" << x << " - " << y << ")";
}

    int main()
{
    Punkt p1;
    p1.x = 10;
    p1.y = 20;
    //cout << "(" << p1.x << ";" << p1.y << ")";
    p1.przedstaw_sie();
    p1.przedstaw_sie_v2();
    cout<<endl;
    Punkt *wsk = new Punkt;
    wsk->x = 100;
    wsk->y = 200;
    //cout << "(" << wsk->x << ";" << wsk->y << ")";
    wsk->przedstaw_sie();
    delete wsk;
    return 0;
}