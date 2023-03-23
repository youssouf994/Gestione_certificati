#include<iostream>
#include<string>

using namespace std;

struct certificato
{
	struct da_i
	{
		int gg;
		int mm;
		int aa;
	};

	struct da_f
	{
		int gg;
		int mm;
		int aa;
	};

	string mansione;
	int ore_set;
};



int main()
{
	char scelta;

	do
	{
		cout << "i. Inserire certificato" << endl;
		cout << "v. Visualizza certificati" << endl;
		cout << "m. Modifica certificato" << endl;
		cout << "c. Cerca certificato" << endl;
		cout << "e. Elimina certificato" << endl;
		cout << "esc. Termina programma" << endl;
		cin >> scelta;

		switch (scelta)
		{
			case 'i':
			case 'I':
			break;

			case 'v':
			case 'V':
				break;

			case 'm':
			case 'M':
				break;

			case 'c':
			case 'C':
				break;

			case 'e':
			case 'E':
				break;

			case 27:
				break;

			default:
				cout << "scelta errata" << endl;
				break;
		}

	} while (scelta != 27);

	return 0;
}