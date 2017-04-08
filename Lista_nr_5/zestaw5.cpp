//Andrzej Wlodarczyk || Grupa lab. 6

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


using namespace std;

unsigned int checkSize(string* &tab){
	return atoi(tab[0].c_str());
}

unsigned int checkSize(fstream& plik){
	string str;
	getline(plik,str);
	return atoi(str.c_str());
}

string* load(fstream& plik){
	unsigned int size = checkSize(plik);
	string* tab = new string[size+1];
	
	tab[0] = to_string(size);
	for(unsigned int i=1; i<size+1; i++){
		getline(plik,tab[i]);
	}
	
	return tab;
}

void read(string* &tab){
	unsigned int size = checkSize(tab);
	cout << size << endl;
	for(unsigned int i=1; i<size+1; i++){
		cout << tab[i] << endl;
	}
}

string* add(string* &tab,string text){
	unsigned int size = checkSize(tab);
	string* nTab = new string[size+2];
	
	nTab[0] = to_string(size+1);
	for(unsigned int i=1; i<size+1; i++){
		nTab[i] = tab[i];
	}
	nTab[size+2] = text;
	
	return nTab;
}

int main(){
	char chose = 'e';
	fstream iPlik("iPlikZ5s.txt");
	string* tab, tab1;
	string text;
	
	do{
	cout << "Witam w bazie danych hasel z internetu." << endl;
	cout << "Wybierz jedna z ponizszych opcji:" << endl;
	cout << "i - wczytaj baze danych" << endl;
	cout << "o - wypisz zawartosc bazy danych" << endl;
    cout << "a - dodaj nowe haslo" << endl;
	cout << "d - usun haslo" << endl;
	cout << "s - zapisz zmiany" << endl;
	cout << "e - opusc program" << endl;	
	cin >> chose;

	switch(chose){
		case 'i':
			if(!iPlik){
				cerr << "Blad wczytania pliku!" << endl;
				return -1;
			}
			tab = load(iPlik);
			break;
	
		case 'o':
			read(tab);
			break;
		
		case 'a':
				cout << "Wpisz nowe haslo:" << endl;
				cin >> text;
				tab1 = add(tab,text);
			break;
		
		case 'e':
			break;
			
		default:
			chose = 'z';
			cout << "Opcja nieistnieje!" << endl;
			break;
	}
	} while(chose != 'e');

	return 0;
}
