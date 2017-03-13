#include <iostream>
using namespace std;

<<<<<<< HEAD
int* tablica(int size){
	int* tab = new int[size];
	for(int i=0; i<size; i++){
		if(i%2 == 0) tab[i] = i*2;
		else tab[i] = i-1;
=======
int* wypelnij(unsigned int size){
	int* tab = new int[size];
	for(unsigned int i=0; i<size; i++){
		if(i%2 == 0) tab[i]=i*i;
		else tab[i]=i-1;
>>>>>>> 652ca14672c88223942800958a2b126f74845b81
	}
	return tab;
}

<<<<<<< HEAD
int main(){
	int n;
	cin >> n;
	int* tab = tablica(n);
	for(int i=0; i<n; i++){
		cout << tab[i] << endl;
	}
	delete[] tab;
	return 0;

}
=======
void wypisz(int* &tab, unsigned int size){
	for(unsigned int i=0; i<size; i++){
		cout << tab[i] << " ";
	}
	cout << endl;
}

int main(){
	unsigned int n;
	
	cout << "Podaj n:" << endl;
	cin >> n;
	int* tab=wypelnij(n);
	wypisz(tab,n);
	delete[] tab;	
	return 0;
}

>>>>>>> 652ca14672c88223942800958a2b126f74845b81
