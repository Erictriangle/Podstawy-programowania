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
	nTab[size+1] = text;
	
	delete[] tab;
	return nTab;
}

string* remove(string* tab){
	unsigned int size =checkSize(tab);
	string* nTab = new string[size];
	
	nTab[0] = to_string(size-1);
	for(unsigned int i=1; i<size; i++){
		nTab[i] = tab[i];
	}
	
	delete[] tab;
	return nTab;
}

void find(string* &tab,string text){
		unsigned int size = checkSize(tab);
		string spr = "Nie znaleziono!";
		
		for(unsigned int i=1; i<size+1; i++){
			if(!text.compare(tab[i])) spr = tab[i];
		}
		cout << spr << endl;
}

void save(fstream& plik,string* &tab){
	unsigned int size =checkSize(tab);
	
	plik << size << endl;
	for(unsigned int i=1; i<size+1; i++){
		plik << tab[i] << endl;
	}
}

int main(){
	char chose = 'e';
	fstream iPlik("iPlikZ5.txt");
	fstream oPlik("iPlikZ5.txt");
	string *tab;
	string text;
	
	do{
	cout << "Witam w bazie danych hasel z internetu." << endl;
	cout << "Wybierz jedna z ponizszych opcji:" << endl;
	cout << "i - wczytaj baze danych" << endl;
	cout << "o - wypisz zawartosc bazy danych" << endl;
    cout << "a - dodaj nowe haslo" << endl;
	cout << "d - usun ostatnie haslo" << endl;
	cout << "f - znajdz haslo" << endl;
	cout << "s - zapisz zmiany" << endl;
	cout << "e - opusc program" << endl;	
	cin >> chose;

	switch(chose){
		case 'i':
			if(!iPlik){
				cerr << "Bląd wczytania pliku!" << endl;
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
				tab = add(tab,text);
			break;
		
		case 'd':
				tab = remove(tab);
			break;
		
		case 'f':
			cout << "Wpisz szukane haslo:" << endl;
			cin >> text;
			find(tab,text);
			break;
		
		case 's':
			if(!oPlik){
				cerr << "Błąd wczytania pliku!" << endl;
			}
			save(oPlik,tab);
			break;
		
		case 'e':
			break;
			
		default:
			chose = 'z';
			cout << "Opcja nieistnieje!" << endl;
			break;
	}
	} while(chose != 'e');

	delete[] tab;
	return 0;
}
