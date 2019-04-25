#include <iostream>
#include <cctype>
using namespace std;

//funkcja szyfrująca
void encrypt(string);
//funkcja deszyfrująca
void decrypt(string);

int main()
{
    //text - początkowy tekst (niezaszyfrowany), cipher - zaszyfrowany tekst
    string text, cipher;
    //menu, pobieramy wartosc input i gdy będzie 3 zamykamy pętlę i program
    int input = 0;
    while (input != 3)
    {
        cout << "Szyfr polibiusza";
        cout << "\n\n1.Szyfrowanie\n2.Deszyfrowanie\n3.Wyjscie\n\nWybor: ";
        cin >> input;
        switch (input)
        {
        case 1:
            cout << "\nPodaj slowo do zaszyfrowania: ";
            cin.ignore();
            getline(cin, text);
            encrypt(text);
            cout << "\n\nNacisnij dowolny klawisz aby kontynuowac";
            cin.get();
            system("cls");
            break;
        case 2:
            cout << "\nPodaj slowo do odszyfrowania: ";
            cin.ignore();
            getline(cin, cipher);
            decrypt(cipher);
            cout << "\n\nNacisnij dowolny klawisz aby kontynuowac";
            cin.get();
            system("cls");
            break;
        case 3:
            cout << "\nNacisnij dowolny klawisz aby zamknac program";
            cin.ignore();
            cin.get();
            break;
        default:
            system("cls");
            cout << "Zla opcja...\n\n";
            break;
        }
    }
    return 0;
}

//funkcja szyfrująca nie zwracająca niczego bo za dużo błędów wyskakiwało gdy zwracałem tablice, tak jest prościej
void encrypt(string text)
{
    //tablica lokalna z wynikiem
    int cipher[text.length()];
    for (int i = 0; i < text.length(); i++)
    {
        //ignoruje spacje
        if (text[i] == ' ')
        {
            cipher[i] = 0;
            continue;
        }
        //wszystkie litery przekształcam na duże litery
        char letter = toupper(text[i]);
        //sprawdzanie czy napewno jest to litera z alfabetu
        if (isalpha(letter) == true)
        {
            int c1, c2;
            if (letter <= 'J')
            {
                if (letter == 'J')
                {
                    letter = 'I';
                }
                c1 = ((letter - 65) / 5) + 1;
                c2 = ((letter - 65) % 5) + 1;
                cipher[i] = c1 * 10 + c2;
            }
            else
            {
                c1 = ((letter - 66) / 5) + 1;
                c2 = ((letter - 66) % 5) + 1;
                cipher[i] = c1 * 10 + c2;
            }
        }
        else
        {
            cout << "\n\nPodano znak nie bedacy litera!";
        }
    }
    cout << "\n\nZaszyfrowany tekst: ";
    for (int i = 0; i < text.length(); i++)
    {
        if (cipher[i] != 0)
            cout << cipher[i] << " ";
    }
}

//funkcja deszyfrująca
void decrypt(string cipher)
{
    string text = "";
    int c1, c2;
    char tab[5][5] = {
        {'A', 'B', 'C', 'D', 'E'},
        {'F', 'G', 'H', 'I', 'K'},
        {'L', 'M', 'N', 'O', 'P'},
        {'Q', 'R', 'S', 'T', 'U'},
        {'V', 'W', 'X', 'Y', 'Z'}
    };
    for (int i = 0; i < cipher.length(); i += 3)
    {
        if (cipher[i] == ' ')
        {
            i -= 2;
            continue;
        }
        else if (isdigit(cipher[i]) && isdigit(cipher[i + 1])
                 && (cipher[i + 2] == '\0') ? 1 : (cipher[i + 2] == ' ') ? 1 : 0)
        {
            if (cipher[i] >= 48 && cipher[i] <= 53 && cipher[i + 1] > 48 && cipher[i + 1] <= 53)
            {
                c1 = cipher[i];
                c2 = cipher[i + 1];
                if (c1 == 50 && c2 == 52)
                {
                    text += "(I/J)";
                }
                else
                {
                    text += tab[c1 - 49][c2 - 49];
                }
            }
            else
            {
                cout << "\n\nPodano bledny szyfrogram!";
                return;
            }
        }
        else
        {
            cout << "\n\nPodano bledny szyfrogram!";
            return;
        }
    }
    cout << "\n\nOdkodowany wyraz to: " << text;
}
