#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

string miesiac[] = {"Styczen", "Luty", "Marzec", "Kwiecien", "Maj", "Czerwiec", "Lipiec", "Sierpien", "Wrzesien", "Pazdziernik", "Listopad", "Grudzien"};

int main()
{
    cout << time(NULL) << endl;
    time_t czas_lin = time(NULL);
    tm *czas = localtime(&czas_lin);
    cout << czas->tm_mday << " " << miesiac[czas->tm_mon] << " " << czas->tm_year + 1900 << endl;
    cout << czas->tm_hour << ":" << czas->tm_min << ":" << czas->tm_sec << endl;

    return 0;
}