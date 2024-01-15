#include <iostream>
#include<fstream>
#include<vector>
using namespace std;

class apartament {
private:
	int nrCamere;
	float suprafata;
	const int idApartament;
	static int nrApartament;
	string* tipCamera;
public:
	//get-eri si set-eri
	static int getnrApartament() {
		return nrApartament;
	}
	int getnrCamere() {
		return nrCamere;
	}
	float getsuprafata() {
		return suprafata;
	}
	string* gettipCamera() const {
		return tipCamera;
	}
	void setsuprafata(const float& mp) {
		suprafata = mp;
	}
	void setCamere(const int nrCamere, string* tipCamera) {
		if (nrCamere > 0) {
			if (this->tipCamera != NULL) {
				delete[]this->tipCamera;
			}
			this->nrCamere = nrCamere;
			this->tipCamera = new string[nrCamere];
			for (int i = 0; i < nrCamere; i++) {
				this->tipCamera[i] = tipCamera[i];
			}
		}
	}

	//constructori

	apartament(int nrCamere, float suprafata, string* tipCamera) :
		idApartament(nrApartament) {
		nrApartament++;
		this->nrCamere = nrCamere;
		this->suprafata = suprafata;
		this->tipCamera = new string[nrCamere];
		for (int i = 0; i < nrCamere; i++) {
			this->tipCamera[i] = tipCamera[i];
		}

	}
	apartament() : idApartament(nrApartament) {
		nrApartament++;
		this->nrCamere = 0;
		this->suprafata = 58.2;
		this->tipCamera = NULL;

	}
	apartament(int nrCamere, string* tipCamera) :idApartament(nrApartament) {
		nrApartament++;
		this->suprafata = 90.3;
		this->nrCamere = nrCamere;
		this->tipCamera = new string[nrCamere];
		for (int i = 0; i < nrCamere; i++) {
			this->tipCamera[i] = tipCamera[i];
		}

	}

	//constructor de copiere

	apartament(const apartament& a) :idApartament(nrApartament) {
		nrApartament++;
		this->nrCamere = a.nrCamere;
		this->suprafata = a.suprafata;
		this->tipCamera = new string[a.nrCamere];
		for (int i = 0; i < a.nrCamere; i++) {
			this->tipCamera[i] = a.tipCamera[i];
		}
	}

	//operator =

	apartament operator=(const apartament& a) {
		if (this != &a) {
			this->nrCamere = a.nrCamere;
			this->suprafata = a.suprafata;
			if (this->tipCamera != NULL) {
				delete[]this->tipCamera;
			}
			this->tipCamera = new string[nrCamere];
			for (int i = 0; i < nrCamere; i++) {
				this->tipCamera[i] = tipCamera[i];
			}
		}
		return *this;
	}

	//operator ++

	apartament operator++(int) {
		this->suprafata++;
		return *this;
	}

	//operator >>

	friend istream& operator>>(istream& cit, apartament& a) {
		cout << "Suprafata: ";
		cit >> a.suprafata;
		cout << "Numar de camere: ";
		cit >> a.nrCamere;
		if (a.tipCamera != NULL) {
			delete[]a.tipCamera;
		}
		cout << " Tipurile de camere sunt: ";
		a.tipCamera = new string[a.nrCamere];
		for (int i = 0; i < a.nrCamere; i++) {
			cit >> a.tipCamera[i];
		}
		return cit;
	}

	//operator<<

	friend ostream& operator<<(ostream& out, const apartament& a) {
		out << a.suprafata << " ";
		out << a.nrCamere << " ";
		string tipCamera = " ";
		for (int i = 0; i < a.nrCamere; i++) {
			tipCamera += a.tipCamera[i];
			out << a.tipCamera[i] << " ";
		}
		return out;
	}

	//destructor

	~apartament() {
		if (this->tipCamera != NULL) {
			delete[]this->tipCamera;
		}
	}
	void afisareapartament() {
		cout << " Apartamentul cu suprafata de " << suprafata << " metri patrati, are " << nrCamere << " camere si are id-ul " << idApartament << ". Camerele sunt:" << endl;
		if (nrCamere > 0) {
			for (int i = 0; i < nrCamere; i++) {
				cout << tipCamera[i] << " ";

			}
			cout << endl;
		}
		else
			cout << "Apartamentul nu are camere" << endl;
	}

	friend float SuprafataMedieCamera(const apartament& a1);
	friend string getSirCamere(const apartament& a2);
	//fisier bin
	void citireFisBin() {
		fstream g("ap.dat", ios::binary | ios::in);
		g.read((char*)&this->nrCamere, sizeof(int));
		g.read((char*)&this->suprafata, sizeof(float));
		g.close();
	}
	void aifsareFisBin() {
		fstream f("ap.dat", ios::binary | ios::out);
		f.write((char*)&this->nrCamere, sizeof(int));
		f.write((char*)&this->suprafata, sizeof(float));
		f.close();
	}
};

//functii globale

  float SuprafataMedieCamera(const apartament& a1) {
	  float smc = a1.suprafata / a1.nrCamere;
	  return smc;
}

  string getSirCamere(const apartament& a2) {
	  string auxA = " ";
	  for (int i = 0; i < a2.nrCamere; i++) {
		  auxA += a2.tipCamera[i] + ", ";
	  }
	  cout << "Apartamentul are " << a2.nrCamere << " camere si o suprafata de " << a2.suprafata << " mp. Are camere de tipurile: ";
	  return auxA;
  }
  

int apartament::nrApartament = 0;

class dormitor {
private:
	int nrDulapuri;
	float latime;
	float lungime;
	string* culoare;
	const int idDormitor;
	static int nrDormitor;
public:

	//get-eri si set-eri

	static int getnrDormtitor() {
		return nrDormitor;
	}
	int getnrDulapuri() {
		return nrDulapuri;
	}
	float getlatime() {
		return latime;
	}
	float getlungime() {
		return lungime;
	}
	string* getculoare() {
		return culoare;
	}

	void setlatime(const float& mp) {
		latime = mp;
	}
	void setlungime(const float& mp) {
		lungime = mp;
	}
	void setDulapuri(const int nrDulapuri, string* culoare) {
		if (nrDulapuri > 0) {
			if (this->culoare != NULL) {
				delete[]this->culoare;
			}
			this->nrDulapuri = nrDulapuri;
			this->culoare = new string[nrDulapuri];
			for (int i = 0; i < nrDulapuri; i++) {
				this->culoare[i] = culoare[i];
			}
		}
	}

	//constructori

	dormitor(int nrDulapuri, string* culoare) : idDormitor(nrDormitor) {

		nrDormitor++;
		this->nrDulapuri = nrDulapuri;
		this->latime = 4.2;
		this->lungime = 5.3;
		this->culoare = new string[nrDulapuri];
		for (int i = 0; i < nrDulapuri; i++) {
			this->culoare[i] = culoare[i];
		}
	}
	dormitor() : idDormitor(nrDormitor) {
		nrDormitor++;
		this->nrDulapuri = 0;
		this->latime = 3.2;
		this->lungime = 3.7;
		this->culoare = NULL;

	}

	dormitor(int nrDulapuri, float latime, float lungime, string* culoare) : idDormitor(nrDormitor) {
		nrDormitor++;
		this->nrDulapuri = nrDulapuri;
		this->latime = latime;
		this->lungime = lungime;
		this->culoare = new string[nrDulapuri];
		for (int i = 0; i < nrDulapuri; i++) {
			this->culoare[i] = culoare[i];
		}
	}

	//constructor de copiere

	dormitor(const dormitor& d) :idDormitor(nrDormitor) {
		nrDormitor++;
		this->nrDulapuri = d.nrDulapuri;
		this->latime = d.latime;
		this->lungime = d.lungime;
		this->culoare = new string[d.nrDulapuri];
		for (int i = 0; i < d.nrDulapuri; i++) {
			this->culoare[i] = d.culoare[i];
		}
	}

	//operator =

	dormitor operator=(const dormitor& d) {
		if (this != &d) {
			delete[]this->culoare;
			this->nrDulapuri = d.nrDulapuri;
			this->latime = d.latime;
			this->lungime = d.lungime;
			this->culoare = new string[d.nrDulapuri];
			for (int i = 0; i < d.nrDulapuri; i++) {
				this->culoare[i] = d.culoare[i];
			}
		}
		return *this;
	}

	//operator++

	dormitor operator++(int) {
		this->latime++;
		return *this;
	}

	//operator>>

	friend istream& operator>>(istream& cit, dormitor& d) {
		cout << "Lungimea: ";
		cit >> d.lungime;
		cout << " Numar de dulapuri: ";
		cit >> d.nrDulapuri;
		if (d.culoare != NULL) {
			delete[]d.culoare;
		}
		cout << " Culorile dulapurilor sunt: ";
		d.culoare = new string[d.nrDulapuri];
		for (int i = 0; i < d.nrDulapuri; i++) {
			cit >> d.culoare[i];
		}
		return cit;
	}

	//operator<<

	friend ostream& operator<<(ostream& out, const dormitor& d) {
		out << d.lungime << " ";
		out << d.latime << " ";
		out << d.nrDulapuri << " ";
		string culoare = " ";
		for (int i = 0; i < d.nrDulapuri; i++) {
			culoare += d.culoare[i];
			out << d.culoare[i] << " ";
		}
		return out;
	}

	//destructor

	~dormitor() {
		if (this->culoare != NULL) {
			delete[]this->culoare;
		}
	}

	void afisaredormitor() {
		cout << " Dormitorul are o latime de " << latime << " metri si o lungime de " << lungime << ". Dormitorul are " << nrDulapuri << " dulapuri " << endl;
		if (nrDulapuri > 0) {
			for (int i = 0; i < nrDulapuri; i++) {
				cout << culoare[i] << " ";
			}
			cout << endl;
		}
		else cout << "Dormitorul nu are dulapuri" << endl;
	}
	friend float ArieDormitor(const dormitor& d1);
	friend string getSirDulapuri(const dormitor& d2);

	//fisier text

	friend ofstream& operator<<(ofstream& ofs, const dormitor& d){
		ofs << d.nrDulapuri << endl;
		ofs << d.latime << endl;
		ofs << d.lungime << endl;
		for (int i = 0; i < d.nrDulapuri; i++) {
			ofs << d.culoare[i] << " ";
		}
		ofs << endl;
		return ofs;
	}
	friend ifstream& operator>>(ifstream& ifs, dormitor& d) {
		ifs >> d.lungime;
		ifs >> d.nrDulapuri;
		if (d.culoare != NULL) {
			delete[]d.culoare;
		}
		d.culoare = new string[d.nrDulapuri];
		for (int i = 0; i < d.nrDulapuri; i++) {
			ifs >> d.culoare[i];
		}
		return ifs;
	}
};

//functii globale

float ArieDormitor(const dormitor& d1) {
	float ad = d1.latime * d1.lungime;
	return ad;
}

string getSirDulapuri(const dormitor& d2) {
	string auxD = " ";
	for (int i = 0; i < d2.nrDulapuri; i++) {
		auxD += d2.culoare[i] + ", ";
	}
	cout << "Dormitorul are " << d2.nrDulapuri << " dulapuri, o latime de " << d2.latime << " mp si o lungime de " << d2.lungime << "mp. Culorile dulapurilor sunt: ";
	return auxD;
}


int dormitor::nrDormitor = 0;

class parcare {
private:
	int nrLocuri;
	float suprafata;
	string* tipParcare;
	const int idParcare;
	static int nrParcare;
public:

	//get-eri si set-eri

	static int getnrParcare() {
		return nrParcare;
	}

	int getnrLocuri() {
		return nrLocuri;
	}

	float getsuprafata() {
		return suprafata;
	}

	string* gettipParcare() {
		return tipParcare;
	}

	void setsuprafata(const float& mp) {
		suprafata = mp;
	}

	void setParcari(const int nrParcare, string* tipParcare) {
		if (nrParcare > 0) {
			if (this->tipParcare != NULL) {
				delete[]this->tipParcare;
			}
			this->nrParcare = nrParcare;
			this->tipParcare = new string[nrParcare];
			for (int i = 0; i < nrParcare; i++) {
				this->tipParcare[i] = tipParcare[i];
			}
		}
	}

	//constructori

	parcare(int nrLocuri, string* tipParcare) : idParcare(nrParcare) {
		nrParcare++;
		this->nrLocuri = nrLocuri;
		this->suprafata = 80.5;
		this->tipParcare = new string[nrLocuri];
		for (int i = 0; i < nrLocuri; i++) {
			this->tipParcare[i] = tipParcare[i];
		}
	}

	parcare() : idParcare(nrParcare) {
		nrParcare++;
		this->nrLocuri = 0;
		this->suprafata = 118.3;
		this->tipParcare = NULL;
	}

	parcare(int nrLocuri, float suprafata, string* tipParcare) : idParcare(nrParcare) {
		nrParcare++;
		this->nrLocuri = nrLocuri;
		this->suprafata = suprafata;
		this->tipParcare = new string[nrLocuri];
		for (int i = 0; i < nrLocuri; i++) {
			this->tipParcare[i] = tipParcare[i];
		}

	}

	//constructor de copiere

	parcare(const parcare& p) :idParcare(nrParcare) {
		nrParcare++;
		this->nrLocuri = p.nrLocuri;
		this->suprafata = p.suprafata;
		this->tipParcare = new string[p.nrLocuri];
		for (int i = 0; i < p.nrLocuri; i++) {
			this->tipParcare[i] = p.tipParcare[i];
		}
	}

	//operator =

	parcare operator=(const parcare& p) {
		if (this != &p) {
			delete[]this->tipParcare;
			this->nrLocuri = p.nrLocuri;
			this->suprafata = p.suprafata;
			if (this->tipParcare != NULL) {
				delete[]this->tipParcare;
			}
			this->tipParcare = new string[p.nrLocuri];
			for (int i = 0; i < p.nrLocuri; i++) {
				this->tipParcare[i] = p.tipParcare[i];
			}
		}
		return *this;
	}

	//operator ++

	parcare operator++(int) {
		this->suprafata++;
		return *this;
	}

	//operator >>

	friend istream& operator>>(istream& cit, parcare& p) {
		cout << "Suprafata: ";
		cit >> p.suprafata;
		cout << "Numar de locuri: ";
		cit >> p.nrLocuri;
		if (p.tipParcare != NULL) {
			delete[]p.tipParcare;
		}
		cout << "Tipurile de parcari sunt: ";
		p.tipParcare = new string[p.nrLocuri];
		for (int i = 0; i < p.nrLocuri; i++) {
			cit >> p.tipParcare[i];
		}
		return cit;
	}

	//operator <<

	friend ostream& operator<<(ostream& out, const parcare& p) {
		out << p.suprafata << " ";
		out << p.nrLocuri << " ";
		string tipParcare = " ";
		for (int i = 0; i < p.nrLocuri; i++) {
			tipParcare += p.tipParcare[i];
			out << p.tipParcare[i] << " ";
		}
		return out;
	}

	//destructor

	~parcare() {
		if (this->tipParcare != NULL) {
			delete[]this->tipParcare;
		}
	}

	void afisareparcare() {
		cout << " Parcarea cu o suprafata de " << suprafata << " metri patrati, are " << nrLocuri << " locuri de parcare. " << endl;
		if (nrParcare > 0) {
			for (int i = 0; i < nrLocuri; i++) {
				cout << tipParcare[i] << " ";
			}
			cout << endl;
		}
		else cout << "Parcarea nu are locuri de parcare" << endl;
	}
	friend float SuprafataLoc(const parcare& p1);
	friend string getSirLocuri(const parcare& p2);

	//fis bin

	void citireFisBin() {
		fstream g("d.dat", ios::binary | ios::in);
		g.read((char*)&this->nrLocuri, sizeof(int));
		g.read((char*)&this->suprafata, sizeof(float));
		g.close();
	}
	void aifsareFisBin() {
		fstream f("d.dat", ios::binary | ios::out);
		f.write((char*)&this->nrLocuri, sizeof(int));
		f.write((char*)&this->suprafata, sizeof(float));
		f.close();
	}
};

//functii globale

float SuprafataLoc(const parcare& p1) {
	float sl = p1.suprafata / p1.nrLocuri;
	return sl;
}
string getSirLocuri(const parcare& p2) {
	string auxP = " ";
	for (int i = 0; i < p2.nrLocuri; i++) {
		auxP += p2.tipParcare[i] + ", ";
	}
	cout << "Parcarea are " << p2.nrLocuri << " locuri si o suprafata de " << p2.suprafata << " mp. Are locuri de parcare de tipurile: ";
	return auxP;
}

int parcare::nrParcare = 0;

class Casa {
private:
	float inaltime;
	int nrUsi;
	dormitor dor1;
public:

	//constructori

	Casa() {
		this->inaltime = 6;
		this->nrUsi = 12;
		dormitor dor2();
	}
	Casa(float inaltime, int nrUsi) {
		this->inaltime = inaltime;
		this->nrUsi = nrUsi;
		dormitor dor3();
	}

	//get-eri si set-ero

	float getinaltime() {
		return inaltime;
	}
	int getnrUsi() {
		return nrUsi;
	}
	dormitor getdor1() {
		return this->dor1;
	}

	void setinaltime(const float& mp) {
		inaltime = mp;
	}

	//constructor de copiere

	Casa(const Casa& c) {
		this->inaltime = c.inaltime;
		this->nrUsi = c.nrUsi;
		this->dor1 = c.dor1;
	}

	//operator =

	Casa operator=(const Casa& c) {
		if (this != &c) {
			this->inaltime = c.inaltime;
			this->nrUsi = c.nrUsi;
			this->dor1 = c.dor1;
		}
		return *this;
	}

	//operator ++

	Casa operator++(int) {
		this->inaltime++;
		return *this;
	}

	//operator >>

	friend istream& operator>>(istream& cit, Casa& c) {
		cout << "Inaltime: ";
		cit >> c.inaltime;
		cout << "Numar de usi: ";
		cit >> c.nrUsi;
		cout << "Dormitoarele au: ";
		cit >> c.dor1;
		return cit;
	}

	//operator <<

	friend ostream& operator<<(ostream& out, Casa& c) {
		out << c.inaltime << " ";
		out << c.nrUsi << " ";
		out << c.dor1 << " ";
		return out;
	}

	//destructor

	~Casa() {

	}

	//fisiere text

	void afisareCasa() {
		cout << " Casa cu o inaltime de " << inaltime << " metri si are " << nrUsi << " usi. " << endl;
	}

	friend ofstream& operator<<(ofstream& ofs, const Casa& c) {
		ofs << c.nrUsi << endl;
		ofs << c.inaltime<< endl;
		ofs << c.dor1 << endl;
		ofs << endl;
		return ofs;
	}
	friend ifstream& operator>>(ifstream& ifs, Casa& c) {
		ifs >> c.nrUsi;
		ifs >> c.inaltime;
		ifs >> c.dor1;
		return ifs;
	}

	};

	void main() {
		string tipCamera[] = { "bucatarie", "baie", "dormitor" };
		/*tipCamera[0] = "Bucatarie";
		tipCamera[1] = "Baie";
		tipCamera[2] = "Dormitor";*/

		apartament apartament1;
		apartament1.afisareapartament();
		apartament apartament2(3, 78.9, tipCamera);
		apartament2.afisareapartament();
		apartament apartament3(2, tipCamera);
		apartament3.afisareapartament();
		cout << apartament2.getsuprafata() << endl;
		cout << apartament1.getnrCamere() << endl;
		apartament2.setsuprafata(50.3);
		cout << apartament2.getsuprafata() << endl;
		apartament2.setCamere(2, tipCamera);
		apartament apartament4 = apartament3;
		apartament apartament5;
		apartament5 = apartament3;
		apartament3++;
		apartament3.afisareapartament();
		apartament a6;
		cin >> a6;
		cout << a6 << endl;
		cout << " Suprafata medie a unei camere este de: " << SuprafataMedieCamera(apartament2) << " mp. " << endl;
		cout << getSirCamere(apartament2) << endl;
		//VARIABILA PENTRU GETTER CIFRE MULTE
		int var = apartament2.getnrCamere();
		cout << apartament2.getnrCamere() << endl;
		int i = 0;
		while (i < var) {
			cout << *(apartament2.gettipCamera() + i) << " ";
			i++;
		}
		cout << " Au fost inregistrate " << apartament::getnrApartament() << " apartamente " << endl;
		//fis bin
		apartament apartament8;
		apartament8.aifsareFisBin();
		apartament8.citireFisBin();

		string* culoare = new string[4];
		culoare[0] = "alb";
		culoare[1] = "negru";
		culoare[2] = "rosu";
		culoare[3] = "albastru";

		dormitor dormitor1;
		dormitor1.afisaredormitor();
		dormitor dormitor2(3, culoare);
		dormitor2.afisaredormitor();
		dormitor dormitor3(2, 3.5, 4.2, culoare);
		dormitor3.afisaredormitor();
		cout << dormitor2.getlatime() << endl;
		cout << dormitor2.getlungime() << endl;
		cout << dormitor2.getculoare() << endl;
		cout << dormitor2.getnrDormtitor() << endl;
		cout << dormitor2.getnrDulapuri() << endl;
		dormitor2.setlatime(4.8);
		cout << dormitor2.getlatime() << endl;
		dormitor2.setlungime(5.6);
		cout << dormitor2.getlungime() << endl;
		dormitor2.setDulapuri(3, culoare);
		cout << dormitor2.getnrDulapuri() << " " << dormitor2.getculoare() << endl;
		dormitor dormitor4 = dormitor3;
		dormitor dormitor5;
		dormitor5 = dormitor3;
		dormitor3++;
		dormitor3.afisaredormitor();
		dormitor d6;
		cin >> d6;
		cout << d6;
		cout << " Aria unui dormitor este egala cu " << ArieDormitor(dormitor2) << " mp." << endl;
		cout << getSirDulapuri(dormitor2) << endl;
		cout << " Au fost inregistrate " << dormitor::getnrDormtitor() << " dormitoare " << endl;

		//fisier text
		dormitor dormitor7;
		dormitor dormitor8(4, culoare);
		ofstream afi("dormitor.txt", ios::out);
		afi << dormitor8;
		afi.close();

		string* tipParcare = new string[5];
		tipParcare[0] = " de handicap ";
		tipParcare[1] = " de masinsa ";
		tipParcare[2] = " de camion ";
		tipParcare[3] = " de autobuz ";
		tipParcare[4] = " de rulota ";

		parcare parcare1;
		parcare1.afisareparcare();
		parcare parcare2(2, tipParcare);
		parcare2.afisareparcare();
		parcare parcare3(3, 75.3, tipParcare);
		parcare3.afisareparcare();
		parcare parcare4 = parcare3; //constructor de copiere
		parcare parcare5;
		parcare5 = parcare3; //operator =
		parcare3++; //operator++
		parcare3.afisareparcare();
		parcare p6;
		cin >> p6; //operator >>
		cout << p6; //operator <<

		cout << parcare2.getnrLocuri() << endl;
		cout << parcare2.getnrParcare() << endl;
		cout << parcare2.getsuprafata() << endl;
		cout << parcare2.gettipParcare() << endl;
		parcare2.setsuprafata(93.5);
		cout << parcare2.getsuprafata() << endl;
		parcare2.setParcari(4, tipParcare);
		cout << parcare2.getnrLocuri() << " " << parcare2.gettipParcare() << endl;
		cout << "Un loc de parcare are " << SuprafataLoc(parcare2) << " mp" << endl;
		cout << getSirLocuri(parcare2) << endl;
		cout << " Au fost inregistrate " << parcare::getnrParcare() << " parcari " << endl;
		//fis bin
		parcare parcare7;
		parcare7.aifsareFisBin();
		parcare7.citireFisBin();

		
		Casa Casa1;
		Casa1.afisareCasa();
		Casa Casa2(5.7, 9);
		Casa2.afisareCasa();
		Casa Casa3 = Casa2;
		Casa Casa4;
		Casa4 = Casa2;
		Casa2++;
		Casa2.afisareCasa();
		Casa c1;
		cin >> c1;
		cout << c1;
		cout << Casa2.getinaltime() << endl;
		cout << Casa2.getnrUsi() << endl;
		cout << Casa2.getdor1() << endl;
		Casa2.setinaltime(5.3);
		cout << Casa2.getinaltime() << endl;
		//fos txt
		/*Casa Casa5;
		Casa Casa6();
		ofstream afis("Casa.txt", ios::out);
		afis << Casa6;
		afis.close();*/


		apartament apvec[3];
		dormitor dorvec[3];
		parcare parvec[3];

		for (int i = 0; i <= 2; i++) {
			cin >> apvec[i];
		}

		for (int i = 0; i <= 2; i++) {
			cin >> dorvec[i];
		}

		for (int i = 0; i <= 2; i++) {
			cin >> parvec[i];
		}

		for (int i = 0; i <= 2; i++) {
			cout << apvec[i] << "\n";
		}

		cout << "\n";

		for (int i = 0; i <= 2; i++) {
			cout << dorvec[i] << "\n";
		}

		cout << "\n";

		for (int i = 0; i <= 2; i++) {
			cout << parvec[i] << "\n";
		}

		cout << "\n";

		apartament apmat[2][2];

		for (int i = 0; i <= 1; i++) {
			for (int j = 0; j <= 1; j++) {
				cin >> apmat[i][j];
			}
		}

		for (int i = 0; i <= 1; i++) {
			for (int j = 0; j <= 1; j++) {
				if (j != 1)
					cout << apmat[i][j] << " || ";
				else
					cout << apmat[i][j];
			}
			cout << "\n";
		}
		
	}