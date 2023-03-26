#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>


#define dim 100
#define dim_data 10

using namespace std;

struct certificato
{
	struct da_i
	{
		int gg;
		int mm;
		int aa;
	}data_i;

	struct da_f
	{
		int gg;
		int mm;
		int aa;
	}data_f;

	string nome;
	string cognome;
	string mansione;
	int ore_set;
};

int quantifica()//dimensione dell'archivio (in voci)
{
	int i=0;
	string app;

	ifstream dime("archivio_dip.txt", ios::in);
		while(getline(dime, app))
		{
			i++;
		}
	dime.close();

	return i;
}

bool check_data(char date[], int d)//controllo data inserita correttamente
{
	bool ok=true;
	int i, x;
	
	i = 0;

	while (i != d)
	{
		while (i < 2)//controllo giorni
		{
			if ((date[i] < 48) || (date[i] > 57))
			{
				ok = false;
			}
			i++;
		}

		while (i < 3)//controllo slash
		{
			if (date[i] != '/')
			{
				ok = false;
			}
			i++;
		}

		while (i < 5)//controllo mesi
		{
			if ((date[i] < 48) || (date[i] > 57))
			{
				ok = false;
			}
			i++;
		}

		while (i < 6)//controllo slash
		{
			if (date[i] != '/')
			{
				ok = false;
			}
			i++;
		}

		while (i < 10)//controllo anno
		{
			if ((date[i] < 48) || (date[i] > 57))
			{
				ok = true;
			}
			i++;
		}
	}

	return ok;
}



void inserimento_ram(certificato certi[], int dime)
{
	int i, x, convertito;
	char app[4];
	char data[10];
	bool check = true;

	cout << "nome dipendente" << endl;
	cin >> certi[dime].nome;
	cout << "cognome dipendente" << endl;
	cin >> certi[dime].cognome;
	cout << "mansione dipendente" << endl;
	cin >> certi[dime].mansione;
	cout << "ore settimanali" << endl;
	cin >> certi[dime].ore_set;
	cout << "inizio rapporto gg/mm/aaaa" << endl;
	cin >> data;
	check = check_data(data, dim_data);
	if (check == false)
	{
		cout << "data errata" << endl;
	}
	else
	{
		i = 0;
		while (i < 5)
		{
			app[i] = ' ';
			i++;
		}

		x = 0;
		i = 0;

		while (data[i] != '/')
		{
			app[x] = data[i];
			i++;
			x++;
		}
		convertito = atoi(app);
		certi[dime].data_i.gg = convertito;
		i++;
		x = 0;

		while (data[i] != '/')
		{
			app[x] = data[i];
			i++;
			x++;
		}
		convertito = atoi(app);
		certi[dime].data_i.mm = convertito;
		i++;
		x = 0;

		while (data[i] != '/')
		{
			app[x] = data[i];
			i++;
			x++;
		}
		convertito = atoi(app);
		certi[dime].data_i.aa = convertito;
		x = 0;
		check = true;
	}


	cout << "fine rapporto gg/mm/aaaa" << endl;
	cin >> data;
	check = check_data(data, dim_data);
	if (check == false)
	{
		cout << "data errata" << endl;
	}
	else
	{
		i = 0;
		while (i < 5)
		{
			app[i] = ' ';
			i++;
		}

		x = 0;
		i = 0;

		while (data[i] != '/')
		{
			app[x] = data[i];
			i++;
			x++;
		}
		convertito = atoi(app);
		certi[dime].data_f.gg = convertito;
		i++;
		x = 0;

		while (data[i] != '/')
		{
			app[x] = data[i];
			i++;
			x++;
		}
		convertito = atoi(app);
		certi[dime].data_f.mm = convertito;
		i++;
		x = 0;

		while (data[i] != '/')
		{
			app[x] = data[i];
			i++;
			x++;
		}
		convertito = atoi(app);
		certi[dime].data_f.aa = convertito;
		x = 0;
	}


}

void salvataggio(certificato certi[], int dime, int posiz)
{
	ofstream save("archivio_dip.txt", ios::out, ios::app);
	save << certi[posiz].nome << "-" << certi[posiz].cognome << "-" << certi[posiz].mansione << "- ore sett. " << certi[posiz].ore_set << "- inizio rapp. " << certi[posiz].data_i.gg << "/" << certi[posiz].data_i.mm << "/" << certi[posiz].data_i.aa << "- fine rapp. " << certi[posiz].data_f.gg << "/" << certi[posiz].data_f.mm << "/" << certi[posiz].data_f.aa << endl;
	save.close();
}

int main()
{
	certificato certi[dim];
	int memoria;
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
				inserimento_ram(certi, dim);
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