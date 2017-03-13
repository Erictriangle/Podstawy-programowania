#include <iostream>
using namespace std;

int* wypelnij(unsigned int size){
	int* tab = new int[size];
	for(unsigned int i=0; i<size; i++){
		if(i%2 == 0) tab[i]=i*i;
		else tab[i]=i-1;
	}
	return tab;
}

int* sortowanie(int* &tab,unsigned int size){
	int supp, zmiana;

	do{
		zmiana = 0;
		for(unsigned int i=0; i<size-1; i++){
			if(tab[i]>tab[i+1]){
				zmiana = zmiana + 1;
				supp = tab[i];
				tab[i] = tab[i+1];
				tab[i+1] = supp;
			}
		}
	}
	while(zmiana == 0);
	return tab;
}

int main(){
	unsigned int size;
	
	cout << "Podaj n:" << endl;
	cin >> size;
	int* tab1=wypelnij(size);
	int* tab2=sortowanie(tab1,size);
	
	for(unsigned int i=0; i<size; i++){
		cout << tab2[i] << endl;
	}
	
	delete[] tab1;
	return 0;
}
