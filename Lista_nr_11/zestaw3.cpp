#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>



struct SPunkt
{
	double x;
	double y;
};
	
struct SWielokat
{
	unsigned int ile;
	SPunkt* punkty;
	double* dlugosci;
	double obwod;
};

double* dlugosci_wielo(SWielokat& wielo);
double obwod(SWielokat& wielo);
double oblicz_dlugosc(double x1, double x2, double y1, double y2);
	
void ini_wielo(SWielokat& wielo, SPunkt* begin, SPunkt* end)	
{
	wielo.ile = end-begin;
	wielo.punkty = new SPunkt[wielo.ile];
	
	for(unsigned int i=0; i<wielo.ile; i++)
	{
		wielo.punkty[i] = begin[i];
	}
	
	wielo.dlugosci = dlugosci_wielo(wielo);
	wielo.obwod = obwod(wielo);
}

void ini_wielo_los(SWielokat& wielo, unsigned int rozmiar)
{
	double max = 100.0;
	double min = -100.0;
	
	wielo.ile = rozmiar;
	wielo.punkty = new SPunkt[rozmiar];
	
	for(unsigned int i=0 ; i<rozmiar; ++i)
	{
		wielo.punkty[i].x = (max - min)*( (double)rand()/(double)RAND_MAX);
		wielo.punkty[i].y = (max - min)*( (double)rand()/(double)RAND_MAX);
	}
}


void wypisz_wielo(SWielokat& wielo)
{
	using namespace std;
	
	cout << "Liczba wierzcholkow wielokata = " << wielo.ile << endl;
	cout << "Wspolrzedne wierzcholkow: \n \n";
	for(unsigned int i=0; i<wielo.ile; ++i)
	{
		cout << wielo.punkty[i].x << "	" << wielo.punkty[i].y << endl;
	}
	cout << endl;
	cout << "Dlugosci bokow: \n";
	for(unsigned int i=0; i<wielo.ile; ++i)
	{
		cout << wielo.dlugosci[i] << endl;
	} 
	cout << endl;
	cout << "Obwod wielokata = " << wielo.obwod << endl;
}


double* dlugosci_wielo(SWielokat& wielo)
{
	double* dlugosci = new double[wielo.ile];
	
	for(unsigned int i = 0; i<(wielo.ile-1); ++i)
	{
		dlugosci[i] = oblicz_dlugosc(wielo.punkty[i].x, wielo.punkty[i+1].x,
			wielo.punkty[i].y, wielo.punkty[i+1].y);
	}
	dlugosci[wielo.ile-1] = oblicz_dlugosc(wielo.punkty[wielo.ile-1].x, wielo.punkty[0].x,
			wielo.punkty[wielo.ile-1].y, wielo.punkty[0].y);
	return dlugosci;
}

double oblicz_dlugosc(double x1, double x2, double y1, double y2)
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

double obwod(SWielokat& wielo)
{
	double obwod = 0;
	for(unsigned int i=0; i<wielo.ile; ++i)
	{
		obwod = obwod + wielo.dlugosci[i];
	}
	return obwod;
}

czytaj_z_pliku(fstream& plik, char* nazwa)
{
	
}


//void del_wielo(SWielokat wielo){
//	delete[] wielo.punkty;
//	delete[] wielo.dlugosci;
//}

void test(char* iPlik, char* oPlik)
{
	SPunkt t[] = {
		{1.0, 2.0},
		{-1.0, 3.0},
		{0.0, -2.0},
		{3.0, 0.0}
		};
		
		SWielokat wielo, wielo_l;
		ifstream iPlik;
		
		
		ini_wielo(wielo, t, t+4);
		wypisz_wielo(wielo);
		
		ini_wielo_los(wielo_l,5);
		wypisz_wielo(wielo_l);

		//del_wielo(wielo);
		//del_wielo(wielo_l);
		czytaj_z_pliku(iPlik, wielo);
		zapisz_do_pliku(oPlik, wielo);

}



int main(int argc,char** argv)
{
	test(argv[1],argv[2]);
	
	return 0;
}
