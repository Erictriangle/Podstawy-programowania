//Andrzej Wlodarczyk

/*Format pliku wejsciowego
	* 1.Liczba wektorow
	* 2.liczba skladowych wektora
	* 3.skladowe wektora
	* 
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct SWektor{
	unsigned int rozmiar;
	double* tab;
};

unsigned int pobierz_rozmiar(fstream& plik,char* nazwa){
	plik.open(nazwa,ios::in);
	if(!plik){
		cerr << "Nie otwarto pliku!" << endl;
		exit(-1);
	}
	
	
	string supp;
	getline(plik,supp);
	unsigned int rozmiar = atoi(supp.c_str());
	
	plik.close();
	return rozmiar;
}

SWektor* wczytaj(fstream& plik,char* nazwa,const unsigned int rozmiar){
	plik.open(nazwa,ios::in);
	if(!plik){
		cerr << "Nie otwarto pliku!" << endl;
		exit(-1);
	}
	unsigned int wymiary;
	string supp;
	getline(plik,supp);
	
	SWektor* wektor = new SWektor[rozmiar];
	for(unsigned int i=0; i<rozmiar; i++){
		getline(plik,supp);
		wymiary = atoi(supp.c_str());
		
		double* tab = new double[wymiary];
		tab[0].rozmiar = wymiary;
		
		for(unsigned int j=1; j<wymiary; j++){
			getline(plik,supp);
			tab[j] = atof(supp.c_str());
		}
		wektor[i].tab = tab;
	}
	
	
	plik.close();
	return wektor;
}

void wczytaj(SWektor* wektor,const unsigned int rozmiar){
	for(unsigned int i=0; i<rozmiar; i++){
		for(unsigned int j=1; j<wektor[i].rozmiar; j++){
			cout << wektor[i] -> 
		}
	}
}



int main(int argc, char** argv){
	if(argc != 2){
		cerr << "Niepoprawna liczba parametrow!" << endl;
		return -1;
	}
	fstream plik;
	unsigned int rozmiar = pobierz_rozmiar(plik,argv[1]);
	SWektor* wektor = wczytaj(plik,argv[1],rozmiar);
	
	return 0;
}
