//Andrzej Wlodarczyk

/*
 * Struktura pliku tekstowego
 * 
 * 1.Liczba studentow w bazie danych
 * 2.Liczba niezaliczonych kursow
 * 3.Imie nazwisko
 * 4.Pierwszy niezaliczony kurs
 * 5.Drugi niezaliczony kurs itd.
 * 6.Liczba niezaliczonych kursow
 * 7.Imie nazwisko
 * 8.itd....
 * 
 */ 


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>

using namespace std;




string** wczytaj(fstream& plik,char* nazwa){
	plik.open(nazwa,ios::in);
	if(!plik){
		cerr << "Nie otwrto pliku!" << endl;
		exit(-1);
	}
	
	unsigned int rozmiar1;
	unsigned int rozmiar2;
	string wiersz;
	
	getline(plik,wiersz);
	rozmiar1 = atoi(wiersz.c_str());
	string** tab = new string*[rozmiar1+1];
	
	for(unsigned int i=0; i<rozmiar1+1; i++){
		if(i == 0){
			tab[i] = new string[1];
			tab[i][0] = wiersz;
		} else{
			getline(plik,wiersz);
			rozmiar2 = atoi(wiersz.c_str());
			tab[i] = new string[rozmiar2+2];
			tab[i][1] = wiersz;
			
			
			for(unsigned int j=0; j<rozmiar2+2; j++){
				if(j != 1){
					 getline(plik,wiersz);
					 tab[i][j] = wiersz;
				 }
			}
			
		}
		
	}
	plik.close();
	
	return tab;
}

void wypisz(fstream& plik, string** tab){
	unsigned int rozmiar1 = atoi(tab[0][0].c_str());
	unsigned int rozmiar2;


	for(unsigned int i=1; i<rozmiar1+1; i++){
		rozmiar2 = atoi(tab[i][1].c_str());
		
		
		for(unsigned int j=0; j<rozmiar2+2; j++){
			cout << tab[i][j] << " ";
		} 
		cout << endl;
	}
}


int main(int argc, char** argv){
	if(argc != 2){
		cerr << "Niepoprawne parametry wejsciowe!" << endl;
		return -1;
	}
	
	fstream plik;
	string** tab = wczytaj(plik,argv[1]);

	wypisz(plik,tab);
	
	delete[] tab;
	return 0;
}
