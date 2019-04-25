#include <iostream>

using namespace std;

string rot13(string);

int main()
{
    string text;
    cout << "Szyfr ROT13\nPodaj tekst do zaszyfrowania: ";
    getline(cin, text);
    cout << "\nZaszyfrowany tekst: " << rot13(text) << "\n\nOdszyfrowany: " << rot13(rot13(text));
    return 0;
}

string rot13(string input)
{
    string output = "";
    for (auto i : input)
    {
        if (i >= 65 && i <= 90)
        {
            output += (char)(((i - 65) + 13) % 26 + 65);
        }
        else if (i >= 97 && i <= 122)
        {
            output += (char)(((i - 97) + 13) % 26 + 97);
        }
        else
        {
            output += i;
        }
    }
    return output;
}
