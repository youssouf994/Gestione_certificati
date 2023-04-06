#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<iomanip>


#define dim 100


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
	int durata_contra;
};

void salvataggio_raw(certificato certi[], int dime)
{
	int i;

	ofstream save("archivio_dip.txt", ios::out | ios::trunc);
	for (i = 0; i < dime; i++)
	{
		if (certi[i].ore_set > 0)
		{
			save << setw(20) << certi[i].nome << "-" << setw(20) << certi[i].cognome << "-" << setw(20) << certi[i].mansione << "-" << setw(4) << certi[i].ore_set << "-" << setw(10) << certi[i].data_i.gg << "/" << certi[i].data_i.mm << "/" << certi[i].data_i.aa << "-" << setw(10) << certi[i].data_f.gg << "/" << certi[i].data_f.mm << "/" << certi[i].data_f.aa << ";" << endl;
		}
	}
	save.close();
}

void salvataggio(certificato certi[], int dime)
{
	int i;

	ofstream save("archivio_dip.txt", ios::out | ios::app);
	for (i = 0; i < dime; i++)
	{
		if (certi[i].ore_set > 0)
		{
			save << setw(20) << certi[i].nome <<"-"<< setw(20) << certi[i].cognome << "-" << setw(20) << certi[i].mansione << "-" << setw(4) << certi[i].ore_set << "-" << setw(10) << certi[i].data_i.gg << "/" << certi[i].data_i.mm << "/" << certi[i].data_i.aa << "-" << setw(10) << certi[i].data_f.gg << "/" << certi[i].data_f.mm << "/" << certi[i].data_f.aa << ";" << endl;
		}
	}
	save.close();
}

int quantifica()//dimensione dell'archivio (in voci)
{
	int i=0;
	string app;

	ifstream dime("archivio_dip.txt", ios::in);
	if (dime.is_open())
	{
		getline(dime, app);
	}

	while (getline(dime, app))
	{
		if (dime.is_open())
		{
			i++;
		}

	}
	dime.close();

	
	
	return i;

	
}

int quantifica_ram(certificato certi[], int dime)
{
	int num, i;

	num = 0;

	for (i = 0; i < dim; i++)
	{
		if (certi[i].ore_set != 0)
		{
			num++;
		}
	}

	return num;
}

void spacchetta(certificato certi[], int dime, char appoggio[], int d, int pos)//SPACCHETTAMENTO DAL FILE ALLA RAM
{
	int i , num;
	string componi="";

	i = 0;
	//pos = pos  1;

	while (i < d)
	{
		while (appoggio[i] != '-')
		{
			componi = componi + appoggio[i];
			i++;
		}
		certi[pos].nome = componi;
		i++;
		componi = "";

		while (appoggio[i] != '-')
		{
			componi = componi + appoggio[i];
			i++;
		}
		certi[pos].cognome = componi;
		i++;
		componi = "";

		while (appoggio[i] != '-')
		{
			componi = componi + appoggio[i];
			i++;
		}
		certi[pos].mansione = componi;
		i++;
		componi = "";

		while (appoggio[i] != '-')
		{
			componi = componi + appoggio[i];
			i++;
		}
		num = atoi(componi.c_str());
		certi[pos].ore_set = num;
		i++;
		componi = "";

//DATA INIZIO

		while (appoggio[i] != '/')
		{
			componi = componi + appoggio[i];
			i++;
		}
		num = atoi(componi.c_str());
		certi[pos].data_i.gg = num;
		i++;
		componi = "";

		while (appoggio[i] != '/')
		{
			componi = componi + appoggio[i];
			i++;
		}
		num = atoi(componi.c_str());
		certi[pos].data_i.mm = num;
		i++;
		componi = "";

		while (appoggio[i]!='-')
		{
			componi = componi + appoggio[i];
			i++;
		}
		num = atoi(componi.c_str());
		certi[pos].data_i.aa = num;
		i++;
		componi = "";

//DATA FINE

		while (appoggio[i] != '/')
		{
			componi = componi + appoggio[i];
			i++;
		}
		num = atoi(componi.c_str());
		certi[pos].data_f.gg = num;
		i++;
		componi = "";

		while (appoggio[i] != '/')
		{
			componi = componi + appoggio[i];
			i++;
		}
		num = atoi(componi.c_str());
		certi[pos].data_f.mm = num;
		i++;
		componi = "";

		while (appoggio[i] != ';')
		{
			componi = componi + appoggio[i];
			i++;
		}
		num = atoi(componi.c_str());
		certi[pos].data_f.aa = num;
		i++;
		componi = "";
	}
}

void fill_ram(certificato certi[], int dime)
{
	int i, x, y, lunghezza, posizione, index=0;
	string app, app2;
	char spacc[70];
	

	ifstream fill("archivio_dip.txt", ios::in);
	if (fill.is_open())
	{
		getline(fill, app);

		
	
		while (getline(fill, app))
		{
			for (i = 0; i < 70; i++)
			{
				spacc[i] = ' ';
			}

			x = 0;
			y = 0;

			app2 = app;
			app2 = app.c_str();

			while (app2[y] != ';')
			{
				if (app2[y]!=' ')//( ( (app2[y]>47) && (app2[y]<58) ) || ( (app2[y]>64) && (app2[y]<123) ) )
				{
					spacc[x] = app2[y];
					x++;
					y++;
				}

				else
				{
					y++;
				}

				if (app2[y] == ';')
				{
					spacc[x] = app2[y];
				}
			}

				

			lunghezza = x;
			index = quantifica_ram(certi, dim) + 1;
			
				spacchetta(certi, dim, spacc, lunghezza, index);
				index++;
		}
	}
	fill.close();		
	
}

bool check_data(char date[], int d)//controllo data inserita correttamente
{
	int mesi[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	bool ok=false;
	int i, x, g=0, m=0, a=0;
	char app[4] = {'\0'};
	
	i = 0;
	x = 0;

	while (i != d)
	{
		while (i < 2)//controllo giorni
		{
			if (!((date[i] < 48) || (date[i] > 57)))
			{
				app[x] = date[i];
				ok = true;
			}
			i++;
			x++;
		}
		g = atoi(app);
		x = 0;

		while (i < 3)//controllo slash
		{
			if (date[i] != '/')
			{
				ok = true;
			}
			i++;
		}

		while (i < 5)//controllo mesi
		{
			if (!((date[i] < 48) || (date[i] > 57)))
			{
				app[x] = date[i];
				ok = true;
			}
			i++;
			x++;
		}
		
		m = atoi(app);
		x = 0;

		while (i < 6)//controllo slash
		{
			if (date[i] != '/')
			{
				ok = true;
			}
			i++;
		}

 		while (i < 10)//controllo anno
		{
			if (!((date[i] < 48) || (date[i] > 57)))
			{
				app[x] = date[i];
				ok = true;
			}
			i++;
			x++;
		}
		a = atoi(app);
		x = 0;
	}

	

	if ((m > 12)||(m<1))
	{
		ok = false;
	}

	 m = m - 1;

	 if (m == -1)
	 {
		 m = m + 1;
	 }


	if ((g > mesi[m]) || (g < 1))
	{
		ok = false;
	}

	 if ((a > 2023)||(a<1900))
	 {
		ok = false;
	 }

	return ok;
}

void inserimento_ram(certificato certi[], int dime, int d)
{	
	int i, x, convertito;
	char app[6];
	char data[11] = { '\0' };
	bool check = true;
	int dim_data;
	int inde;

	cout << "nome dipendente" << endl;
	cin >> certi[d].nome;
	cout << "cognome dipendente" << endl;
	cin >> certi[d].cognome;
	cout << "mansione dipendente" << endl;
	cin >> certi[d].mansione;
	cout << "ore settimanali" << endl;
	cin >> certi[d].ore_set;

	cout << "inizio rapporto gg/mm/aaaa" << endl;
	int j = 0;
	do
	{

		cin >> data;
		dim_data = strlen(data);
			check = check_data(data, dim_data);

		switch (check)
		{
			case false:
				cout << "reinserire - data errata" << endl;
				break;

			case true:
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
				certi[d].data_i.gg = convertito;
				i++;
				x = 0;

				while (data[i] != '/')
				{
					app[x] = data[i];
					i++;
					x++;
				}
				convertito = atoi(app);
				certi[d].data_i.mm = convertito;
				i++;
				x = 0;

				while (i < 10)
				{
					app[x] = data[i];
					i++;
					x++;
				}
				convertito = atoi(app);
				certi[d].data_i.aa = convertito;
				x = 0;
				j = 1;
				check = true;
				break;
		}

	} while (j != 1);
	
	
	cout << "fine rapporto gg/mm/aaaa-99 per indeterminato" << endl;

	j = 0;
	do
	{
		cin >> data;
		inde = atoi(data);

		if (inde == 99)
		{
			certi[d].data_f.aa = inde;
			j = 1;
		}
		
		else
		{
			dim_data = strlen(data);
			check = check_data(data, dim_data);

			switch (check)
			{
				case false:
					cout << "reinserire - data errata" << endl;
					break;

				case true:
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
					certi[d].data_f.gg = convertito;
					i++;
					x = 0;

					while (data[i] != '/')
					{
						app[x] = data[i];
						i++;
						x++;
					}
					convertito = atoi(app);
					certi[d].data_f.mm = convertito;
					i++;
					x = 0;

					while (i < 10)
					{
						app[x] = data[i];
						i++;
						x++;
					}
					convertito = atoi(app);
					certi[d].data_f.aa = convertito;
					x = 0;
					j = 1;
					check = true;
					break;
			}
		}

	} while (j != 1);

}

void genera_archivio(certificato certi[], int dime)
{
	int i;

	for (i = 0; i < dime; i++)
	{
		certi[i].nome=" ";
		certi[i].cognome = " ";
		certi[i].mansione = " ";
		certi[i].ore_set = 0;
		certi[i].data_i.gg = 0;
		certi[i].data_i.mm = 0;
		certi[i].data_i.aa = 0;
		certi[i].data_f.gg = 0;
		certi[i].data_f.mm = 0;
		certi[i].data_f.aa = 0;
	}

	fill_ram(certi, dim);
}

void tit()
{
	ofstream titolo("archivio_dip.txt", ios::out);
	titolo << setw(20) << "NOME" << setw(20) << "COGNOME" << setw(20) << "MANSIONE" << setw(4) << "ORE SETTIMANALI" << setw(10) << "INIZIO RAPPORTO LAV." << setw(10) << "FINE RAPPORTO LAV." << endl;
	titolo.close();
}

void visualizza(certificato certi[], int dime, int d)
{
	int i;

	cout << setw(20) << "NOME " << setw(20) << " COGNOME " << setw(20) << " MANSIONE " << setw(4) << " ORE SETTIMANALI " << setw(10) << " INIZIO RAPPORTO LAV. " << setw(10) << " FINE RAPPORTO LAV. " << endl;

	for(i=0;i<d;i++)
	{		
		if (certi[i].ore_set > 0)
		{
			cout << setw(20) << certi[i].nome << setw(20) << certi[i].cognome << setw(20) << certi[i].mansione << setw(4) << certi[i].ore_set << setw(10) << certi[i].data_i.gg << "/" << certi[i].data_i.mm << "/" << certi[i].data_i.aa << setw(10) << certi[i].data_f.gg << "/" << certi[i].data_f.mm << "/" << certi[i].data_f.aa << endl;
		}
	}
}

void visualizza_unico(certificato certi[], int dime, int i)
{
	cout << setw(20) << "NOME " << setw(20) << " COGNOME " << setw(20) << " MANSIONE " << setw(4) << " ORE SETTIMANALI " << setw(10) << " INIZIO RAPPORTO LAV. " << setw(10) << " FINE RAPPORTO LAV. " << endl;

	cout << setw(20) << certi[i].nome << setw(20) << certi[i].cognome << setw(20) << certi[i].mansione << setw(4) << certi[i].ore_set << setw(10) << certi[i].data_i.gg << "/" << certi[i].data_i.mm << "/" << certi[i].data_i.aa << setw(10) << certi[i].data_f.gg << "/" << certi[i].data_f.mm << "/" << certi[i].data_f.aa << endl;
	
}

int ricerca(certificato certi[], int dime)
{
	int i, trovato;
	string cerca;

	cout << "nome da cercare" << endl;
	cin >> cerca;

	i=0;

	while (i < dime)
	{
		if (certi[i].nome == cerca)
		{
			trovato = i;
			cout << "il contatto trovato è" << endl;
			visualizza_unico(certi, dim, trovato);
		}
		i++;
	}

	return trovato;
}

void modifica(certificato certi[], int dime, int quale)
{
	int i, sce, sce2;
	string nuovo;
	char data[10];

	cout << "modifica" << endl;
	cout<<"1.modifica nome"<<endl;
	cout<<"2.modifica cognome"<<endl;
	cout<<"3.modifica mansione"<<endl;
	cout<<"4.modifica ore settimanali"<<endl;
	cout<<"5.modifica data inizio aa/mm/aaaa "<<endl;
	cout<<"6.modifica data fine aa/mm/aaaa"<<endl;
	cin >> sce;

	switch (sce)
	{
		case 1:
			cout << "modifica nome" << endl;
			cout << "attuale: " << setw(20) << certi[quale].nome << setw(20) << "nuovo: " << setw(20);
			cin >> nuovo;

			cout << "confermare? 0 no 1 si" << endl;
			cin >> sce2;
			switch (sce2)
			{
				case 0:
					break;

				case 1:
					certi[quale].nome = nuovo;
					break;
			
				default:
					cout << "scelta errata" << endl;
					break;
			}
			break;

		default:
			cout << "scelta errata" << endl;
			break;
	}


}

int main()
{
	certificato certi[dim];
	int memoria;
	char scelta='\0';
	int pointer_;

	memoria = quantifica();
	//memoria = memoria + 1;

	if (memoria == 0)
	{
		tit();
	}

	
	
	do
	{
		genera_archivio(certi, dim);
		fill_ram(certi, dim);
		
		
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
				salvataggio(certi, dim);
				memoria = quantifica();
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
					memoria = quantifica();
					visualizza(certi, dim, memoria);
					break;
				}
				break;

			case 'm':
			case 'M':
				pointer_ = ricerca(certi, dim);
				modifica(certi, dim, pointer_);
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
