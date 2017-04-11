#include<iostream>
#include<fstream>

using namespace std;

void wczytaj_obraz(unsigned** &mac, 
		   unsigned &wier,
		   unsigned &kol, unsigned &ssz,
		   istream& in = cin
		  )
{
  string mn;
  in >> mn;
  if (mn!="P2" && mn!="P5")
  {
    cerr << "BLAD FORMATU" << endl;
    return;
  }
  in >> kol >> wier;
  in >> ssz;
  mac = new unsigned*[wier];
  for(unsigned i=0; i<wier; ++i)
  {
    mac[i] = new unsigned[kol];
    for(unsigned j=0; j<kol; ++j)
    {
      in >> mac[i][j];
    }
  }
}

void zapisz_obraz(unsigned** mac, 
		   unsigned wier,
		   unsigned kol, unsigned ssz,
		   ostream& out = cout
		  )
{
  out << "P2" << endl;
  out << kol << ' ' << wier << endl;
  out << ssz << endl;
  for(unsigned i=0; i<wier; ++i)
  {
    for(unsigned j=0; j<kol; ++j)
    {
      out << mac[i][j] << ' ';
    }
    out << endl;
  }
}

void negatyw(unsigned** mac, 
		   unsigned wier,
		   unsigned kol, unsigned ssz
		  )
{
  for(unsigned i=0; i<wier; ++i)
  {
    for(unsigned j=0; j<kol; ++j)
    {
      mac[i][j] = ssz - mac[i][j];
    }
  }
}

void zanurzenie(unsigned** &mac, unsigned &wier,unsigned &kol, unsigned &ssz){
	unsigned int px=0;
	unsigned int px2=0;
	for(unsigned int i=0; i<wier; i++){
		for(unsigned int j=0, j<kol; j++){
			if(tab[i][j]!=255) px++;
			
		}
	}
	
}

int main() 
{
	ifstream obr("gora_lodowa.pgm");
	unsigned** mac = 0;
	unsigned wier, kol, ssz;
	wczytaj_obraz(mac,wier,kol,ssz,obr);
	ofstream obr2("obrazek_wyj.pgm");
	zanurzenie(mac,wier,kol,ssz)
	zapisz_obraz(mac,wier,kol,ssz,obr2);
	
}
