#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<iomanip>


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

void salvataggio(certificato certi[], int dime)
{
	int i;

	i = 0;
	ofstream save("archivio_dip.txt", ios::out, ios::trunc | ios::app );
	for (i = 0; i < dime; i++)
	{
		save << certi[i].nome << "-" << certi[i].cognome << "-" << certi[i].mansione << "-" << certi[i].ore_set << "-" << certi[i].data_i.gg << "/" << certi[i].data_i.mm << "/" << certi[i].data_i.aa << "- fine rapp. " << certi[i].data_f.gg << "/" << certi[i].data_f.mm << "/" << certi[i].data_f.aa << endl;
	}
	save.close();
}

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

void spacchetta(certificato certi[], int dime, char appoggio[], int d)//SPACCHETTAMENTO IN RAM
{
	int i , num;
	string componi="";

	i = 0;

	while (i <= d)
	{
		while (appoggio[i] != '-')
		{
			componi = componi + appoggio[i];
			i++;
		}
		certi[i].nome = componi;
		i++;
		componi = "";

		while (appoggio[i] != '-')
		{
			componi = componi + appoggio[i];
			i++;
		}
		certi[i].cognome = componi;
		i++;
		componi = "";

		while (appoggio[i] != '-')
		{
			componi = componi + appoggio[i];
			i++;
		}
		certi[i].mansione = componi;
		i++;
		componi = "";

		while (appoggio[i] != '-')
		{
			componi = componi + appoggio[i];
			i++;
		}
		num = atoi(componi.c_str());
		certi[i].ore_set = num;
		i++;
		componi = "";

//DATA INIZIO

		while (appoggio[i] != '/')
		{
			componi = componi + appoggio[i];
			i++;
		}
		num = atoi(componi.c_str());
		certi[i].data_i.gg = num;
		i++;
		componi = "";

		while (appoggio[i] != '/')
		{
			componi = componi + appoggio[i];
			i++;
		}
		num = atoi(componi.c_str());
		certi[i].data_i.mm = num;
		i++;
		componi = "";

		while (appoggio[i] != '/')
		{
			componi = componi + appoggio[i];
			i++;
		}
		num = atoi(componi.c_str());
		certi[i].data_i.aa = num;
		i++;
		componi = "";

//DATA FINE

		while (appoggio[i] != '/')
		{
			componi = componi + appoggio[i];
			i++;
		}
		num = atoi(componi.c_str());
		certi[i].data_f.gg = num;
		i++;
		componi = "";

		while (appoggio[i] != '/')
		{
			componi = componi + appoggio[i];
			i++;
		}
		num = atoi(componi.c_str());
		certi[i].data_f.mm = num;
		i++;
		componi = "";

		while (appoggio[i] != '/')
		{
			componi = componi + appoggio[i];
			i++;
		}
		num = atoi(componi.c_str());
		certi[i].data_f.aa = num;
		i++;
		componi = "";
	}
}

void fill_ram()
{
	certificato certi[dim];
	int i = 0, x, y, lunghezza;
	string app, app2;
	char spacc[70];


	for (i = 0; i < 70; i++)
	{
		spacc[i] = ' ';
	}

	i = 0;
	x = 0;
	y = 0;

	ifstream fill("archivio_dip.txt", ios::in);
	while (!EOF)
	{
		while (getline(fill, app))
		{
			lunghezza = app.length();
			app2 = app.c_str();

			while (x < lunghezza)
			{
				spacc[x] = app2[y];
				x++;
				y++;
			}

			spacchetta(certi, dim, spacc, lunghezza);
		}
		
		i++;
	}
}

bool check_data(char date[], int d)//controllo data inserita correttamente
{
	bool ok=true;
	int i;
	
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

void inserimento_ram(certificato certi[], int dime, int d)
{
	int i, x, convertito;
	char app[6];
	char data[11] = { '\0' };
	bool check = true;

	cout << "nome dipendente" << endl;
	cin >> certi[d+1].nome;
	cout << "cognome dipendente" << endl;
	cin >> certi[d + 1].cognome;
	cout << "mansione dipendente" << endl;
	cin >> certi[d + 1].mansione;
	cout << "ore settimanali" << endl;
	cin >> certi[d + 1].ore_set;
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
		certi[d + 1].data_i.gg = convertito;
		i++;
		x = 0;

		while (data[i] != '/')
		{
			app[x] = data[i];
			i++;
			x++;
		}
		convertito = atoi(app);
		certi[d + 1].data_i.mm = convertito;
		i++;
		x = 0;

		while (i<10)
		{
			app[x] = data[i];
			i++;
			x++;
		}
		convertito = atoi(app);
		certi[d + 1].data_i.aa = convertito;
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
			app[i] = '\0';
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
		certi[d + 1].data_f.gg = convertito;
		i++;
		x = 0;

		while (data[i] != '/')
		{
			app[x] = data[i];
			i++;
			x++;
		}
		convertito = atoi(app);
		certi[d + 1].data_f.mm = convertito;
		i++;
		x = 0;

		while (i<10)
		{
			app[x] = data[i];
			i++;
			x++;
		}
		convertito = atoi(app);
		certi[d + 1].data_f.aa = convertito;
	}
}



void visualizza(certificato certi[], int dime)
{
	int i;

	cout << setw(20) << "NOME" << setw(20) << "COGNOME" << setw(20) << "MANSIONE" << setw(4) << "ORE SETTIMANALI" << setw(10) << "INIZIO RAPPORTO LAV." << setw(10) << "FINE RAPPORTO LAV." << endl;

	for(i=0;i<dime;i++)
	{		
		cout << setw(20) << certi[i].nome << setw(20) << certi[i].cognome << setw(20) << certi[i].mansione << setw(4) << certi[i].ore_set << setw(10) << certi[i].data_i.gg<<"/"<< certi[i].data_i.mm <<"/"<< certi[i].data_i.aa << setw(10) << certi[i].data_f.gg << "/" << certi[i].data_f.mm << "/" << certi[i].data_f.aa << endl;
	}
}

int main()
{
	certificato certi[dim];
	int memoria;
	char scelta;

	certi[0] = {
	{ 27, 3, 2023 }, 
	{ 99, 99, 9999 },
	"gestione",
	"certificati",
	"Elephant Software",
	40 // ore_set: 40 ore
	};

	do
	{
		memoria = quantifica();
		if(memoria>0)
		{
			fill_ram();
			salvataggio(certi, dim);
		}

		else
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
					inserimento_ram(certi, dim, memoria);
				break;

				case 'v':
				case 'V':
					if (memoria == 0)
					{
						cout << "non sono presenti certificati da mostrare" << endl;
						break;
					}
					else
					{
						visualizza(certi, dim);
					}
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
		}

	} while (scelta != 27);

	return 0;
}