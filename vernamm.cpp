#include <iostream>
#include <string>
#include <bitset>

using namespace std;

string encrypt(string, string);
string decrypt(string, string);

int main()
{
    // pobranie tekstu jawnego i klucza
    string text, key, cipher = "";
    cout << "Podaj tekst do zaszyfrowania: ";
    getline(cin, text);
    cout << "\nPodaj klucz: ";
    getline(cin, key);
    // sprawdzenie czy są równe bądź czy klucz jest większy, jeżli nie to wyjście z programu
    if (text.length() >= key.length())
    {
        cerr << "\nBLAD! Nie rowne klucze!";
        exit(1);
    }
    // wypisanie tekstu jawengo i klucza w notacji binarnej używając rzutowania na typ bitset
    cout << "\nTekst:\t";
    for (size_t i = 0; i < text.size(); ++i)
    {
        cout << bitset<8>(text.c_str()[i]) << " ";
    }
    // wypisujemy klucz tylko do długości tekstu, więcej nie jest potrzebne
    cout << "\nKlucz:\t";
    for (size_t i = 0; i < text.size(); ++i)
    {
        cout << bitset<8>(key.c_str()[i]) << " ";
    }
    // wywołanie funkcji szyfrującej i wypisanie wyniku binarnie
    cout << "\nXOR:\t";
    cipher = encrypt(text, key);
    for (size_t i = 0; i < cipher.size(); ++i)
    {
        cout << bitset<8>(cipher.c_str()[i]) << " ";
    }
    // wypisanie przekształconego wyniku
    cout << "\n\nSzyfr: " << cipher;
    cout << "\n\nSzyfr:\t";
    for (size_t i = 0; i < cipher.size(); ++i)
    {
        cout << bitset<8>(cipher.c_str()[i]) << " ";
    }
    // odkodowanie
    cout << "\nKlucz:\t";
    for (size_t i = 0; i < cipher.size(); ++i)
    {
        cout << bitset<8>(key.c_str()[i]) << " ";
    }
    cout << "\nXOR:\t";
    string deszyfer = decrypt(cipher, key);
    for (size_t i = 0; i < deszyfer.size(); ++i)
    {
        cout << bitset<8>(deszyfer.c_str()[i]) << " ";
    }
    cout << "\n\ndeszyfr: " << deszyfer;
}

string encrypt(string text, string key)
{
    string cipher = "";
    for (size_t i = 0; i < text.size(); ++i)
    {
        // xorowanie bitowe każdego znaku
        unsigned long z = (bitset<8>(text.c_str()[i]) ^ bitset<8>(key.c_str()[i])).to_ulong();
        // zapisanie do wyniuku liczby o 65 większej, ponieważ nie da się wypisać na ekran wartości 0 z tablicy ASCII, 65 to 'A' w tablicy ASCII
        cipher += z + 65;
    }
    return cipher;
}

string decrypt(string cipher, string key)
{
    string text = "";
    for (size_t i = 0; i < cipher.size(); ++i)
    {
        // zakładając że dany cipher jest zwiększony o 65 to odejmujemy teraz tą wartość żeby móc xorować
        char z = cipher[i] - 65;
        // xor binarny
        z = (bitset<8>(z) ^ bitset<8>(key.c_str()[i])).to_ulong();
        text += z;
    }
    return text;
}
