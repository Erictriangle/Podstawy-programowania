#include <iostream>
#include <fstream>
using namespace std;

double** utworz(const unsigned int sizeY, const unsigned int sizeX){
	double** tablica = new double*[sizeY];
	for(unsigned int i=0; i<sizeY; i++){
		tablica[i] = new double[sizeX];
		for(unsigned int j=0; j<sizeX; i++){
			tablica[i][j] = 0;
		}
	}
	return tablica;
}

int main(){
	unsigned int sizeY, sizeX;
	
	cout << "Podaj wymiary macierzy:" << endl;
	cin >> sizeY;
	cin >> sizeX;
	
	double** tablica = utworz(sizeY,sizeX);
	for(unsigned int i=0; i<sizeY; i++){
		for(unsigned int j=0; j<sizeX; i++){
			cout << tablica[i][j];
		}
		cout << endl;
	}
	
	delete[] tablica;
	return 0;
}
