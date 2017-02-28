#include <iostream>
using namespace std;

int* kasuj_element(int* &tab, unsigned int rozmiar, unsigned int element){
	tab = new int[rozmiar];
}

int main(){
	unsigned int r = 6;
	unsigned int e;
	int* b = 0;
	cout << "Wybierz element do usuniecia: " << endl;
	cin >> e;
	kasuj_element(b, r, e);
	
	
} 
