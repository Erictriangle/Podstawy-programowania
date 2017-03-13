#include <iostream>
using namespace std;

int* tablica(unsigned int size){
	int* tab = new int[size];
	unsigned int supp = size-1;
	for(unsigned int i=0; i<size; i++){
		tab[i] = supp;
		supp = supp-1; 
	}
	return tab;
}

void wypisz(int* &tab, unsigned int size){
	for(unsigned int i=0; i<size; i++){
		cout << tab[i] << endl;
	}
}

int main(){
	unsigned int size;
	
	cout << "Podaj rozmiar tablicy: " << endl;
	cin >> size;
	int* tab = tablica(size);
	wypisz(tab,size);
	
	delete[] tab;
	return 0;
}
