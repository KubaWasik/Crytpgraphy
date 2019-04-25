#include <iostream>
using namespace std;

//funkcja szyfrująca
string encrypt(string);
//funkcja deszyfrująca
string decrypt(string);

int main()
{
    //text - początkowy tekst (niezaszyfrowany), cipher - zaszyfrowany tekst
    string text, cipher;
    //menu, pobieramy wartosc input i gdy będzie 3 zamykamy pętlę i program
    int input = 0;
    while (input != 3)
    {
        cout << "Szyfr Bacona";
        cout << "\n\n1.Szyfrowanie\n2.Deszyfrowanie\n3.Wyjscie\n\nWybor: ";
        cin >> input;
        switch (input)
        {
        case 1:
            cout << "\nPodaj slowo do zaszyfrowania: ";
            cin.ignore();
            getline(cin, text);
            cipher = encrypt(text);
            cout << "\nZaszyfrowany tekst: " << cipher;
            cout << "\n\nNacisnij dowolny klawisz aby kontynuowac";
            cin.get();
            system("cls");
            break;
        case 2:
            cout << "\nPodaj slowo do odszyfrowania: ";
            cin.ignore();
            getline(cin, cipher);
            text = decrypt(cipher);
            cout << "\nOdszyfrowany tekst: " << text;
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

//funkcja szyfrująca
string encrypt(string text)
{
    int size = text.length();
    int cipher_size = 0;
    for (int i = 0; i < size; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            cipher_size += 5;
        }
        else
        {
            cipher_size++;
        }
    }
    string cipher;
    for (int i = 0; i < size; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            if (text[i] >= 'j')
            {
                text[i]--;
            }
            if (text[i] >= 'v')
            {
                text[i]--;
            }
            for (int bin = 16; bin > 0; bin /= 2)
            {
                cipher += ((bin & (text[i] - 'a')) ? 'b' : 'a');
            }
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            if (text[i] >= 'J')
            {
                text[i]--;
            }
            if (text[i] >= 'V')
            {
                text[i]--;
            }
            for (int bin = 16; bin > 0; bin /= 2)
            {
                cipher += ((bin & (text[i] - 'A')) ? 'B' : 'A');
            }
        }
        else
        {
            cipher += text[i];
        }
    }
    return cipher;
}

//funkcja deszyfrująca
string decrypt(string cipher)
{
    int cipher_size = cipher.length();
    int size;
    for (int i = 0; i < cipher_size; i++)
    {
        if ((cipher[i] == 'a' || cipher[i] == 'b') || (cipher[i] == 'A' || cipher[i] == 'B'))
        {
            i += 4;
        }
        size++;
    }
    string text;
    for (int i = 0; i < cipher_size; i++)
    {
        if (cipher[i] == 'A' || cipher[i] == 'B')
        {
            char letter = 'A';
            for (int bin = 16; bin > 0; bin /= 2)
            {
                if (cipher[i++] == 'B')
                {
                    letter += bin;
                }
            }
            if (letter >= 'J')
            {
                letter++;
            }
            if (letter >= 'V')
            {
                letter++;
            }
            text += letter;
            i--;
        }
        else if (cipher[i] == 'a' || cipher[i] == 'b')
        {
            char letter = 'a';
            for (int bin = 16; bin > 0; bin /= 2)
            {
                if (cipher[i++] == 'b')
                {
                    letter += bin;
                }
            }
            if (letter >= 'j')
            {
                letter++;
            }
            if (letter >= 'v')
            {
                letter++;
            }
            text += letter;
            i--;
        }
        else
        {
            text += cipher[i];
        }
    }
    return text;
}
