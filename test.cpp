#include <iostream> 
#include <string>

using namespace std;

enum Spr{
	jakis 
};

struct SCos{
	Spr typ;
};


int main(){
	SCos bla;
	bla.typ = jakis;
	cout << bla.typ << endl;
	
	return 0;
}
