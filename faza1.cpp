#include <iostream>
using namespace std;

class apartament {
public:
	int nrCamere;
	float suprafata;
	const int idApartament;
	static int nrApartament;
	string* tipCamera;
	static int getnrApartament() {
		return nrApartament;
	}
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
		this->nrCamere = nrCamere;
		this->suprafata = 58.2;
		this->tipCamera = NULL;
		
	}
	apartament(int nrCamere,string*tipCamera) :idApartament(nrApartament) {
		nrApartament++;
		this->suprafata = 90.3;
		this->nrCamere = nrCamere;
		this->tipCamera = new string[nrCamere];
		for (int i = 0; i < nrCamere; i++) {
			this->tipCamera[i] = tipCamera[i];
		}

	}
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
};

int apartament::nrApartament = 0;

class dormitor {
public:
	int nrDulapuri;
	float latime;
	float lungime;
	string* culoare;
	const int idDormitor;
	static int nrDormitor;
	static int getnrDormtitor() {
		return nrDormitor;
	}

	dormitor(int nrDulapuri, string*culoare) : idDormitor(nrDormitor){
	
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
};

int dormitor::nrDormitor = 0;

class parcare {
public:
	int nrLocuri;
	float suprafata;
	string* tipParcare;
	const int idParcare;
	static int nrParcare;
	static int getnrParcare() {
		return nrParcare;
	}

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
};

int parcare::nrParcare = 0;

void main() {
	string* tipCamera = new string[3];
	tipCamera[0] = "Bucatarie";
	tipCamera[1] = "Baie";
	tipCamera[2] = "Dormitor";

	apartament apartament1;
	apartament1.afisareapartament();
	apartament apartament2(3, 78.9, tipCamera);
	apartament2.afisareapartament();
	apartament apartament3(2, tipCamera);
	apartament3.afisareapartament();
	cout << " Au fost inregistrate " << apartament::getnrApartament() << " apartamente " << endl;


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
	cout << " Au fost inregistrate " << dormitor::getnrDormtitor() << " dormitoare " << endl;

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
	cout << " Au fost inregistrate " << parcare::getnrParcare() << " parcari " << endl;
}

