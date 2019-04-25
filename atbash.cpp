#include <iostream>
#include <cctype>
using namespace std;

//funkcja szyfrująca i deszyfrująca
string encrypt_decrypt(string);

int main()
{
	//text - początkowy tekst (niezaszyfrowany), cipher - zaszyfrowany tekst
	string text, cipher;
	//menu, pobieramy wartosc choice i gdy będzie 3 zamykamy pętlę i program
	char choice = 48;
	while (choice != 51)
	{
		cout << "Szyfr atbash";
		cout << "\n\n1.Szyfrowanie\n2.Deszyfrowanie\n3.Wyjscie\n\nWybor: ";
		cin >> choice;
		if (!isdigit(choice))
		{
			choice = 48;
		}
		switch (choice)
		{
		case 49:
			cout << "\nPodaj slowo do zaszyfrowania: ";
			cin.ignore();
			getline(cin, text);
			cipher = encrypt_decrypt(text);
			//szyfruje funkcja i je�li zwr�ci ona string zawieraj�cy "-1" oznacza to b��d na wej�ciu
			if (cipher == "-1")
			{
				cout << "\nTekst zawiera niedozwolone znaki!";
			}
			else
			{
				cout << "\nZaszyfrowany tekst: " << cipher;
			}
			cout << "\n\nNacisnij dowolny klawisz aby kontynuowac";
			cin.get();
			system("cls");
			break;
		case 50:
			cout << "\nPodaj slowo do odszyfrowania: ";
			cin.ignore();
			getline(cin, cipher);
			text = encrypt_decrypt(cipher);
			//deszyfruje funkcja i jeśli zwróci ona string zawierający "-1" oznacza to błąd na wejściu
			if (text == "-1")
			{
				cout << "\nTekst zawiera niedozwolone znaki!";
			}
			else
			{
				cout << "\nOdszyfrowany tekst: " << text;
			}
			cout << "\n\nNacisnij dowolny klawisz aby kontynuowac";
			cin.get();
			system("cls");
			break;
		case 51:
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

string encrypt_decrypt(string input)
{
	string cipher;
	//w pętli zamieniam znaki zgodnie z wzorem:
	//(znak = liczba_liter_w_alfabecie - (pozycja_w_alfabecie - pozycja_najmniejszego_elelementu) + pozycja_najmniejszego_elelementu
	//pomijam spacje i liczby w zamianie i przepisuje je do wyjścia, a w przypadku znaku nie będącego literą, spacją lub liczbą
	//zwracam błąd w postaci stringa zawierającego "-1"
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] >= 65 && input[i] <= 90)
		{
			cipher += 25 - (input[i] - 65) + 65;
		}
		else if (input[i] >= 97 && input[i] <= 122)
		{
			cipher += 25 - (input[i] - 97) + 97;
		}
		else if (isdigit(input[i]) || input[i] == 32)
		{
			cipher += input[i];
		}
		else
		{
			cipher = "-1";
			return cipher;
		}
	}
	return cipher;
}
