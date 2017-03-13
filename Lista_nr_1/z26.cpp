#include <iostream>
using namespace std;

int* wypelnij(unsigned int size){
	int* tab = new int[size];
	for(unsigned int i=0; i<size; i++){
		tab[i] = i;
	}
	return tab;
}

void skopiuj_do(int* &tab, unsigned int size, int* &docelowa){
	for(unsigned int i=0; i<size; i++){
		docelowa[i] = tab[i];
	}
	for(unsigned int i=0; i<size-1; i++){
		cout << tab[i] << "    " << docelowa[i] << endl;
	}
}

int main(){
	unsigned int size;
	
	cout << "Podaj n: " << endl;
	cin >> size;
	int* tab1 = wypelnij(size);
	int* tab2 = new int[size];
	skopiuj_do(tab1,size,tab2);
		
	delete[] tab1;
	delete[] tab2;
	return 0;
} 

