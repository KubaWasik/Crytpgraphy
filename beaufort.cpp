#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string beaufort(string, string);

int main()
{
    string text, key;
    cout << "Podaj tekst do zaszyfrowania: ";
    getline(cin, text);
    cout << "\nPodaj klucz: ";
    cin >> key;
    transform(begin(text), end(text), begin(text), ::tolower);
    transform(begin(key), end(key), begin(key), ::tolower);
    string cipher = beaufort(text, key);
    cout << "\nSzyfr: " << cipher;
    cout << endl << endl << "Odszyfrowane: " << beaufort(cipher, key);
    return 0;
}

string beaufort(string text, string key)
{
    string cipher = "";
    for (int i = 0; i < text.length(); i++)
    {
        int shift = (key[i % key.length()] - 'a');
        if (text[i] == ' ')
        {
            cipher += text[i];
        }
        else
        {
            int symbol = (text[i] - 'a');
            cipher += ((char)('a' + (-symbol + 26 + shift) % 26));
        }
    }
    return cipher;
}
