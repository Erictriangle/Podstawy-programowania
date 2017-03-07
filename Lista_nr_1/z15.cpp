#include <iostream>
using namespace std;

unsigned int max(int* &tab,unsigned int size){
	unsigned int position = 0;
	for(unsigned int i=1; i<size; i++){
		if(tab[i]>tab[i-1]){
			 position = i;
		 }
	}
	return position;
}

int* wypelnij(unsigned int size){
	int* tab = new int[size];
	for(unsigned int i=0; i<size; i++){
		if(i%2 == 0) tab[i]=i*i;
		else tab[i]=i-1;
	}
	return tab;
}

int main(){
	unsigned int n;
	
	cout << "Podaj n:" << endl;
	cin >> n;
	int* tab = wypelnij(n);
	cout << "Wartość maksymalna jest przypisana do indeksu nr." << max(tab,n) << endl; 
	delete[] tab;
	return 0;
}
