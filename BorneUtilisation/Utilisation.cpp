#include <iostream>

#include "BorneStationnement.h"
#include "BorneFontaine.h"
#include "RegistreBorne.h"
#include "ValidationFormat.h"

using namespace BornesQuebec;
using namespace std;

int main() {

	string nomRegistre = "Registre de la ville de quebec";
	int identifiants = -1;
	float latitude = 0.0;
	float longitude = 0.0;
	string direction = "";
	float lectureMetrique = 0.0;
	int segmentRue = -1;
	short int numBorne = -1;
	string coteRue = "";
	string type = "";
	string nomTopographique = "";
	RegistreBorne leRegistre(nomRegistre);


	char buffer[256];
	cout
			<< "Pouvez-vous me donner les informations pour la borne de stationement."
			<< std::endl;

	do {
		cout << "Identifiant:" << std::endl;
		cin.getline(buffer, 256);
		string reponse = buffer;
		identifiants = Util::convertirChaineEnInt(reponse);
	} while (identifiants < 0);

	bool valide = false;
	do {
		cout << "Direction:" << std::endl;
		cin.getline(buffer, 256);
		direction = buffer;
		valide = Util::validerPointCardinal(direction) && !direction.empty();

	} while (!valide);

	do {
		cout << "Nom topographique:" << std::endl;
		cin.getline(buffer, 256);
		nomTopographique = buffer;
		valide = !nomTopographique.empty();
	} while (!valide);

	do {
		cout << "Longitude:" << std::endl;
		cin.getline(buffer, 256);
		string reponse = buffer;
		longitude = Util::convertirChaineEnfloat(reponse);
	} while (longitude < 0);

	do {
		cout << "Latitude:" << std::endl;
		cin.getline(buffer, 256);
		string reponse = buffer;
		latitude = Util::convertirChaineEnfloat(reponse);
	} while (latitude < 0);

	do {
		cout << "Lecture métrique:" << std::endl;
		cin.getline(buffer, 256);
		string reponse = buffer;
		lectureMetrique = Util::convertirChaineEnfloat(reponse);
	} while (lectureMetrique < 0);

	do {
		cout << "Type de borne:" << std::endl;
		cin.getline(buffer, 256);
		type = buffer;
	} while (type != "stationnement" && type != "paiement");

	do {
		cout << "Segment de la rue:" << std::endl;
		cin.getline(buffer, 256);
		string reponse = buffer;
		segmentRue = Util::convertirChaineEnInt(reponse);
	} while (segmentRue < 0);

	do {
		cout << "Numéro de la borne:" << std::endl;
		cin.getline(buffer, 256);
		string reponse = buffer;
		numBorne = Util::convertirChaineEnInt(reponse);
	} while (numBorne > 9999 || numBorne < 0);

	do {
		cout << "Côté de la rue:" << std::endl;
		cin.getline(buffer, 256);
		string reponse = buffer;
		coteRue = reponse;
		;
	} while (!Util::validerPointCardinal(coteRue) && !direction.empty());

	BorneStationnement uneBorneStationnement(identifiants, latitude, longitude,
			direction, nomTopographique, type, lectureMetrique, segmentRue,
			numBorne, coteRue);

	leRegistre.AjouteBorne(*uneBorneStationnement.clone());

	cout << "Donner moi les données de la borne fontaine." << std::endl;
	cout << "------------------------------------------" << std::endl;

	string ville = "";
	string arrondissement = "";

	do {
		cout << "Identifiant:" << std::endl;
		cin.getline(buffer, 256);
		string reponse = buffer;
		identifiants = Util::convertirChaineEnInt(reponse);
	} while (identifiants < 0);

	valide = false;
	do {
		cout << "Direction:" << std::endl;
		cin.getline(buffer, 256);
		direction = buffer;
		valide = Util::validerPointCardinal(direction) && !direction.empty();

	} while (!valide);

	do {
		cout << "Nom topographique:" << std::endl;
		cin.getline(buffer, 256);
		nomTopographique = buffer;
		valide = !nomTopographique.empty();
	} while (!valide);

	do {
		cout << "Longitude:" << std::endl;
		cin.getline(buffer, 256);
		string reponse = buffer;
		longitude = Util::convertirChaineEnfloat(reponse);
	} while (longitude < 0);

	do {
		cout << "Latitude:" << std::endl;
		cin.getline(buffer, 256);
		string reponse = buffer;
		latitude = Util::convertirChaineEnfloat(reponse);
	} while (latitude < 0);

	cout << "Ville:" << std::endl;
	cin.getline(buffer, 256);
	string reponse = buffer;
	ville = buffer;

	do {
		cout << "Arrondissement:" << std::endl;
		cin.getline(buffer, 256);
		string reponse = buffer;
		arrondissement = ville;
	} while (ville == "Quebec" && arrondissement.empty());

	BorneFontaine uneBorneFontaine(identifiants,latitude,longitude,direction,nomTopographique,ville,arrondissement);

	leRegistre.AjouteBorne(*uneBorneFontaine.clone());

	cout << leRegistre.reqBorneFormate();
	return 0;

}

