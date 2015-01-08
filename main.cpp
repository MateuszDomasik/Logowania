#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char znaki[35];
string kod;

void losowanie()
{
    int litera=97, cyfra=48, wylosowana_liczba, wylosowana_litera, litera_liczba;

    for(int i=0; i<36; i++)
    {
        if(i<26) znaki[i]=litera+i;
        else znaki[i]=cyfra++;
    }

    srand(time(NULL));

    for(int i=0; i<6; i++)
    {
        litera_liczba=rand()%2;

        if(litera_liczba==1)
        {
            wylosowana_liczba=rand()%10+48;
            kod[i]=wylosowana_liczba;
            cout << kod[i];
        }
        else
        {
            wylosowana_litera=rand()%26+97;
            kod[i]=wylosowana_litera;
            cout << kod[i];
        }
    }
}

void wprowadzanie_danych()
{
    string kod_wpisany, login, haslo;
    int poprawnosc=0, a=0, b=0;
    cout << "Wpisz login: ";
    cin >> login;
    cout << "Wpisz haslo: ";
    cin >> haslo;
    cout << "Przepisz podany kod: ";
    losowanie();
    cout << " Tutaj -> ";
    cin >> kod_wpisany;

    for(int i=0; i<6; i++)
    {
        if(kod[i]!=kod_wpisany[i])
        {
            cout << "Zle przepisany kod! ";
            break;
        }
        if(i==6) cout << "Poprawnie przepisany kod! ";
    }
}
int main()
{
    wprowadzanie_danych();
    return 0;
}
