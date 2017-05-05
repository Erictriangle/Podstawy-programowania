//Andrzej Wlodarczyk

/*Program ma za zadanie stworzyc tabele
 * szyfrujaca, za pomoca ktorej 
 * zamieniamy tresc wejsciowego 
 * pliku tekstowego i zapisujemy go 
 * w innym pliku.
 * Dziala to wylacznie w jedna
 * strone z powodu niezastosowania
 * pelnego alfabetu w strukturze. */

#include <iostream> 
#include <fstream>
#include <string>

using namespace std;

/* Struktura zawierajaca schemat 
 * szyfrowania pliku tekstowego.
 * Wersja ta zamienia tylko kilka
 * liter, gdyz jest to prezentacja
 * pewnego zamyslu, a nie pelna
 * realizacja programu*/
struct szyfrowanie{
	char a;
	char e;
	char y;
	char i;
	char o;
	char u;
};


string* wczytaj(fstream& plik, string nazwa){
	plik.open(nazwa,ios::in);
	if (!plik){
		cerr << "Blad otwarcia pliku wejsciowego!" << endl;
		exit(-1);
	}	
	
	string napis;
	unsigned int wiersze = 0;

	while(!plik.eof()){
		getline(plik,napis);
		wiersze++;
	}

	plik.seekg(0);
	string* tekst = new string[wiersze];
	for(unsigned int i=0; i<wiersze; i++){
		getline(plik,tekst[i]);
	}
	
	cout << tekst[1] << tekst[2] << endl;
	return tekst;
	
}

/*void zapisz(fstream& plik, string nazwa, string* tekst, szyfrowanie szyfr){
	plik.open(nazwa,ios::out);
	if(!plik){
		cerr << "Blad otwarcia pliku wyjsciowego!" << endl;
		exit(-1);
	}

	unsigned int j = 0;
	while(nazwa[j][0] == '\0'){
		for(unsigned int i=0; i<tekst.length(); i++){
			if(nazwa[i] == 'a') nazwa[i] = szyfr.a;
			if(nazwa[i] == 'e') nazwa[i] = szyfr.e;
			if(nazwa[i] == 'y') nazwa[i] = szyfr.y;
			if(nazwa[i] == 'i') nazwa[i] = szyfr.i;
			if(nazwa[i] == 'o') nazwa[i] = szyfr.o;
			if(nazwa[i] == 'u') nazwa[i] = szyfr.u;

		}
		j++;
	}
	plik << tekst << endl;
}*/

int main(int argc, char**argv){
	if(argc != 3 ){
		cerr << "Niepoprawna liczba parametrow!" << endl;
		return -1;
	}

	fstream plikWejsciowy;
	fstream plikWyjsciowy;
	string nazwaWejsciowego = argv[1];
	string nazwaWyjsciowego = argv[2];
	szyfrowanie szyfr;

	cout << "a =";
	cin >> szyfr.a;
	cout << "e =";
	cin >> szyfr.e;
	cout << "y =";
	cin >> szyfr.y;
	cout << "i =";
	cin >> szyfr.i;
	cout << "o =";
	cin >> szyfr.o;
	cout << "u =";
	cin >> szyfr.u;
	
	string* tekst = wczytaj(plikWejsciowy,nazwaWejsciowego);
//	zapisz(plikWyjsciowy,argv[2],tekst,szyfr);


	delete[] tekst;
	return 0;

}
