#include <iostream>
#include <cstdlib>
using namespace std;

double** utworz(unsigned int m,unsigned int n){
	double **tab = new double *[m];
	for(int i=0; i<n; i++){
		tab[i] = new double[n];
		for(int j=0; j<5; j++){
			tab[m][n]=0;
		}
	}
	return tab;
}


double** czytaj_losowo(double** &tabA; const unsigned int m, const unsigned int n, double** &tabB, const unsigned int p, const unsigned int q){
	for(unsigned int i=0; i<m; i++){
		for(unsigned int j=0; j<n; j++){
			tabA[m][n] = rand();
		}
	}
	for(unsigned int i=0; i<p; i++){
		for(unsigned int j=0; j<q; j++){
			tabB[p][q] = rand();
		}
	}
	return tabA;
}

void zapisz(double** &tab; const unsigned int m, unsigned int n){
	for(unsigned int i=0; i<m; i++){
		for(unsigned int j=0; j<n; j++){
			cout << tab[m][n] << " ";
		}
		cout << endl;
	}
}

void usun(double** &tabA, double** &tabB){
	for(unsigned int i=0; i<n, i++){
		delete[] tab[i];
	}
	delete[] tab;
	tab = 0;
}

int main(){
	srand(time(NULL));
	double **A = 0; B** =0;
	unsigned int n=2, m=3, p=3, q=2;
	
	A = utworz(m,n);
	B = utworz(p,q);
	if(czytaj_losowo(A, m, n, B, p, q)){
		zapisz(A, m, n);
		zapisz(B, p, q);
		
	}
	
	if(czytaj(A, m, n, B, p, q)){
		zapisz(A, m, n);
		zapisz(B, p, q);
		if(!suma(A, m, n, B, p, q, C)){
			cerr << "Macierze maja nieprawidlowe wymiary - suma niemozliwa" << endl;
		}
		else{
			cout << "suma macierz " << endl;
			zapisz(C, m, n);
		}
	}
	if(!roznica(A, m, n, B, p, q, C)){
		cerr < "Macierze maja nieprawidlowe wymiary" << endl;
	}
	else{
		cout << "roznica macierzy" << endl;
		zapisz(C, m, q);
	}
	
	if(!iloczyn(A, m, n, B, p, q, C)){
		cerr << "Macierze maja nieprawidlowe wymiary - iloczyn niemozliwy" << endl;
	}
	else{
		cout << "iloczyn macierzy " << endl;
		zapisz(C, m, q);
	}
	cout << "macierz przed transponowaniem" << endl;
	zapisz(B, p, q);
	cout << "macierz transponowana" << endl;
	transpose(B, p, q, C);
	usun(tabA,tabB);
	return 0;
}
