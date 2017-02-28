#include <iostream>
using namespace std;



double polowki(int* &tab, unsigned int rozmiar){
	tab = new int[rozmiar];
	double zera = 0;
	double jedynki = 0;
	for(unsigned int i=0; i<rozmiar; i++){
		if(i<(rozmiar/2)){
			 tab[i]=0;
			 zera=zera+1;
		 }
		else{
			 tab[i]=1;
			 jedynki=jedynki+1;
		 }
	}
	return (zera/jedynki);
}

int main(){
	int r;
	int* b = 0;
	cout << "Podaj rozmiar tablicy:" << endl;
	cin >> r;
	cout << "Stosunek zer do jedynek:" << polowki(b, r) << endl;
	return 0;
}

