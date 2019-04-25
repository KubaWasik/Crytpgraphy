#include <iostream>
using namespace std;

string encrypt(string);
string decrypt(string);

int main()
{
	string text, cipher;
	int input = 0;
	while (input != 3)
	{
		cout << "Szyfr Cezara";
		cout << "\n\n1.Szyfrowanie\n2.Deszyfrowanie\n3.Wyjscie\n\nWybor: ";
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "\nPodaj slowo do zaszyfrowania: ";
			cin >> text;
			cipher = encrypt(text);
			cout << "\nZaszyfrowany tekst: " << cipher << "\nNacisnij dowolny klawisz aby kontynuowac";
			cin.ignore();
			cin.get();
			system("cls");
			break;
		case 2:
			cout << "\nPodaj slowo do odszyfrowania: ";
			cin >> cipher;
			text = decrypt(cipher);
			cout << "\nOdszyfrowany tekst: " << text << "\nNacisnij dowolny klawisz aby kontynuowac";
			cin.ignore();
			cin.get();
			system("cls");
			break;
		case 3:
			cout << "\nWychodze, nacisnij dowolny klawisz aby zamknac program";
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

string encrypt(string text)
{
	if (text.length() == 0)
		return 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] >= 65 && text[i] <= 90)
			text[i] = (65 + (text[i] - 62) % 26);
		else if (text[i] >= 97 && text[i] <= 122)
			text[i] = (97 + (text[i] - 94) % 26);
	}
	return text;
}

string decrypt(string cipher)
{
	if (cipher.length() == 0)
		return 0;
	for (int i = 0; i < cipher.length(); i++)
	{
		if (cipher[i] >= 65 && cipher[i] <= 90)
			cipher[i] = (65 + (cipher[i] - 42) % 26);
		else if (cipher[i] >= 97 && cipher[i] <= 122)
			cipher[i] = (97 + (cipher[i] - 74) % 26);
	}
	return cipher;
}
