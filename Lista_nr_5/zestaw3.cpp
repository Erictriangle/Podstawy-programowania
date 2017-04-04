//Andrzej Włodarczyk - Zestaw III

#include <iostream>
#include <fstream>
using namespace std;

//zadanie 1

void zapisz_wektor(ofstream& plik,double* &wek,const unsigned int rozmiar){
	for(unsigned int i=0; i<rozmiar+1; i++){
		plik << wek[i] << endl;
	}
}


//zadanie 2
double* wczytaj_wektor(ifstream& plik,const unsigned int rozmiar){
	double* wek = new double[rozmiar];
	wek[0] = rozmiar;
	for(unsigned int i=1; i<rozmiar+1; i++){
		plik >> wek[i];
	}
	return wek;
}
	
//zadanie 3
double* dodaj_wektor(double* &wek1, double* &wek2, const unsigned int roz1, const unsigned int roz2, unsigned int& roz3){
	if(roz1==roz2){
		double* wektor = new double[roz1];
		for(unsigned int i=1; i<roz1; i++){
			wektor[i] = wek1[i] + wek2[i];
		}
		if(roz1>roz2) roz3 = roz1;
		else roz3 = roz2;
		return wektor;
	} 
	else{
		cout << "Złe wymiary!" << endl;
		roz3 = 0;
		return 0;
	}
}

//zadanie 4
void zapisz_inzyniersko(ofstream& plik,double* &wek,const unsigned int rozmiar){
	for(unsigned int i=0; i<rozmiar+1; i++){
		plik << wek[i] << scientific << endl; 
	}
}

int main(){
	ifstream iPlik("iPlik.txt");
	ofstream oPlik("oPlik.txt");
	unsigned int roz1;
	
	iPlik >> roz1;
	double* wek = wczytaj_wektor(iPlik,roz1);
	zapisz_inzyniersko(oPlik,wek,roz1);
	
	
	delete[] wek;
	return 0;
}
