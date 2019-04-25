#include <iostream>

using namespace std;

string encrypt(string, int);
string decrypt(string, int);

int main()
{
    //text - początkowy text (niezaszyfrowany), cipher - zaszyfrowany text
    string text, cipher;
    int key;
    //menu, pobieramy wartosc input i gdy będzie 3 zamykamy pętlę i program
    int input = 0;
    while (input != 3)
    {
        cout << "Szyfr przestawieniowy plotkowy";
        cout << "\n\n1.Szyfrowanie\n2.Deszyfrowanie\n3.Wyjscie\n\nWybor: ";
        cin >> input;
        switch (input)
        {
        case 1:
            cout << "\nPodaj wysokosc plotu: ";
            cin >> key;
            cout << "\nPodaj slowo do zaszyfrowania: ";
            cin.ignore();
            getline(cin, text);
            cipher = encrypt(text, key);
            cout << "\nZaszyfrowany text: " << cipher;
            cout << "\n\nNacisnij dowolny klawisz aby kontynuowac";
            cin.get();
            system("cls");
            break;
        case 2:
            cout << "\nPodaj key (height plotka): ";
            cin >> key;
            cout << "\nPodaj slowo do odszyfrowania: ";
            cin.ignore();
            getline(cin, cipher);
            text = decrypt(cipher, key);
            cout << "\nOdszyfrowany text: " << text;
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

string encrypt(string text, int height)
{
    /* Szyfrowanie, rozdzielamy text na mniejsze stringi, dokładnie na tyle ile jaka jest wysokość (key)
	   i potem je czytamy i łączymy tworząc cipher */
    string cipher = "";
    string fence[height] = {""};
    int position = 0;
    int direction = 1;
    for (int i = 0; i < text.length(); i++)
    {
        fence[position] += text[i];
        // żeby nie przekraczać wysokości (klucza) sprawdzamy direction i position
        if (((position == height - 1) && (direction == 1)) || ((position == 0) && (direction == -1)))
        {
            direction = -direction;
        }
        position += direction;
    }
    int row = 0;
    while (row < height)
    {
        for (int i = 0; i < fence[row].length(); i++)
        {
            cipher += fence[row][i];
        }
        row++;
    }
    return cipher;
}

string decrypt(string cipher, int height)
{
    /* Deszyfrowanie, tworzymy tablicę (płotek) gdzie fence to znak spejalny "`",
	   myślę że nikt nie będzie go chciał wrzucać do szyfru wiec go wybrałem,
	   a text szyfru to 1, potem 1 zamieniamy na znaki z szyfru i odczytujemy po kolei */
    string text = "";
    int size = cipher.length();
    string fence[height] = {""};
    int position = 0;
    int direction = 1;
    // stworzenie płotka
    for (int i = 0; i < size; i++)
    {
        fence[position] += "1";
        for (int j = 0; j < height; j++)
        {
            if (j == position)
            {
                continue;
            }
            fence[j] += '`';
        }
        if (((position == height - 1) && (direction == 1)) || ((position == 0) && (direction == -1)))
        {
            direction = -direction;
        }
        position += direction;
    }
    // zamiana 1 na znaki szyfru
    int tmp = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (fence[i][j] == '1')
            {
                fence[i][j] = cipher[tmp++];
            }
            else
            {
                continue;
            }
        }
    }
    // odczytanie odszyfrowanego tekstu
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (fence[j][i] == '`')
            {
                continue;
            }
            else
            {
                text += fence[j][i];
            }
        }
    }
    return text;
}
