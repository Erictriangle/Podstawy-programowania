#include <iostream>
using namespace std;

int* wypelnij(unsigned int size){
	int* tab = new int[size];
	for(unsigned int i=0; i<size; i++){
		tab[i] = i;
	}
	return tab;
}

int* kasuj_element(int* &tab, unsigned int size, unsigned int element){
	int* tab1 = new int[size-1];
	
	for(unsigned int i=0; i<element-1; i++){
		tab1[i] = tab[i];
	}
	for(unsigned int i=element; i<size; i++){
		tab1[i-1] = tab[i];
	}
	return tab1;
}

int main(){
	unsigned int size;
	unsigned int element;
	
	cout << "Podaj n: " << endl;
	cin >> size;
	int* tab = wypelnij(size);
	
	cout << "Wybierz element do usuniecia: " << endl;
	cin >> element;
	int* tab1 = kasuj_element(tab,size,element);
	cout << endl;
	for(unsigned int i=0; i<size-1; i++){
		cout << tab1[i] << endl;
	}
	
	delete[] tab;
	return 0;
} 
