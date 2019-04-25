#include <iostream>
#include <algorithm>

using namespace std;

void sort_key(string, int[]);
void sort_table(string[], int[], int);
string encrypt(string, string);
string decrypt(string, string);

int main()
{
    string key, text, cipher;
    cout << "Podaj klucz: ";
    cin >> key;
    cout << "\nPodaj tekst do zaszyfrowania: ";
    cin.ignore();
    getline(cin, text);
    cipher = encrypt(text, key);
    cout << "\nSzyfrogram: " << cipher;
    text = decrypt(cipher, key);
    cout << "\nOdszyfrowany tekst: " << text << endl;
    cout << "Wcisnij dowolny klawisz aby zakonczyc...";
    cin.get();
    return 0;
}

void sort_key(string key, int tab[])
{
    string tmp;
    int key_size = key.length();
    for (int i = 0; i < key_size; i++)
    {
        tab[i] = i + 1;
    }
    cout << "\nPodany klucz: " << key;
    tmp = key;
    int changes = 0;
    for (int i = 0; i < key_size; i++)
    {
        for (int j = 1; j < key_size - i; j++)
        {
            if (tmp[j - 1] > tmp[j])
            {
                swap(tmp[j - 1], tmp[j]);
                swap(tab[j - 1], tab[j]);
                changes = 1;
            }
        }
        if (changes == 0)
        {
            break;
        }
    }
}

void sort_table(string table[], int tab[], int key_size)
{
    int changes = 0;
    int tmp[key_size];
    for (int i = 0; i < key_size; i++)
    {
        tmp[i] = tab[i];
    }
    for (int i = 0; i < key_size; i++)
    {
        for (int j = 1; j < key_size - i; j++)
        {
            if (tmp[j - 1] > tmp[j])
            {
                swap(tmp[j - 1], tmp[j]);
                swap(table[j - 1], table[j]);
                changes = 1;
            }
        }
        if (changes == 0)
        {
            break;
        }
    }
}

string encrypt(string text, string key)
{
    int key_size = key.length();
    int text_size = text.length();
    int f[key_size] = {0};
    sort_key(key, f);
    cout << "\n\nf[]:\n";
    for (int i = 0; i < key_size; i++)
    {
        cout << f[i] << " ";
    }
    cout << endl << endl;
    int rows = 0;
    text_size % key_size == 0 ? rows = text_size / key_size : rows = text_size / key_size + 1;
    string cipher_table[rows];
    cout << "Tablica szyfru:\nKlucz:" << "\t" << key << endl << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < key_size; j++)
        {
            if ((i * key_size) + j < text_size)
            {
                cipher_table[i] += text[(i * key_size) + j];
            }
            else
            {
                cipher_table[i] += '_';
            }
        }
        cout << "[" << i << "]\t" << cipher_table[i] << endl;
    }
    string transposition_table[key_size];
    cout << "\nOdwrocona tablica szyfru:\n\n";
    for (int i = 0; i < key_size; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            transposition_table[i] += cipher_table[j][i];
        }
        cout << "[" << i << "]\t" << transposition_table[i] << endl;
    }
    string cipher;
    for (int i = 0; i < key_size; i++)
    {
        cipher += transposition_table[f[i] - 1];
    }
    return cipher;
}

string decrypt(string cipher, string key)
{
    string text;
    int key_size = key.length();
    int text_size = cipher.length();
    int f[key_size] = {0};
    sort_key(key, f);
    int rows = 0;
    text_size % key_size == 0 ? rows = text_size / key_size : rows = text_size / key_size + 1;
    string cipher_table[key_size], tmp_table[key_size];
    cout << endl << endl;
    for (int i = 0; i < key_size; i++)
    {
        tmp_table[i] = cipher.substr((i * rows), rows);
        cout << "[" << i << "]\t" << tmp_table[i] << endl;
    }
    cout << endl;
    sort_table(tmp_table, f, key_size);

    for (int i = 0; i < rows; i++)
    {
        cout << "[" << i << "]\t";
        for (int j = 0; j < key_size; j++)
        {
            if (tmp_table[j][i] == '_') {
                continue;
            }
            cout << tmp_table[j][i] << " ";
            text += tmp_table[j][i];
        }
        cout << endl;
    }
    
    return text;
}
