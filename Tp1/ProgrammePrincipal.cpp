/**
 * \file ProgrammePrincipal.cpp
 *	\brief Fichier contenant le programme principal (main)
 *  \date 2018-10-11
 *  \author  Maime Lamontagne
 */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "validationFormat.h"
#include "Borne.h"

using namespace std;
using namespace Util;

int main() {
	cout << "Saisir les données d'une borne." << endl;

	string numeroBorne = "";
	do {
		cout << "Donner moi le numéro de la borne." << endl;
		cin >> numeroBorne;

	} while (numeroBorne.empty());

	string coteRue = "";
	do {
		cout << "Donner moi le côté de la rue de la borne." << endl;
		cin >> coteRue;

	} while (coteRue.empty());

	float lectureMetrique = 0;
	string itemEntree = "";
	do {
		cout << "Donner moi la leture métrique de la borne." << endl;
		cin >> itemEntree;
		lectureMetrique = convertirChaineEnfloat(itemEntree);

	} while (itemEntree.empty() || lectureMetrique == 0);

	string nomTopographique = "";
	do {
		cout << "Donner moi le nom topographique de la borne." << endl;
		cin >> nomTopographique;

	} while (nomTopographique.empty());

	string direction = "";
	do {
		cout << "Donner moi la direction de la borne" << endl;
		cin >> direction;
	} while (direction.empty());

	int segmentRue = 0;
	do {
		cout << "Donner moi le segment de la rue de la borne." << endl;
		cin >> itemEntree;
		segmentRue = convertirChaineEnInt(itemEntree);

	} while (nomTopographique.empty() || segmentRue == 0);

	Borne borne(numeroBorne, coteRue, lectureMetrique, segmentRue, direction,
			nomTopographique);

	cout << borne.reqBorneFormate() << endl;
	/*
	 //Déclaration des noms de fichiers à lire.
	 string const nomFichierLectureCsv = "BORNE_PAIE.CSV";
	 string const nomFichierLectureJson = "PARCOMETRE.GEOJSON";

	 ifstream fichierLecture = OuvertureFichierLecture(nomFichierLectureCsv);

	 //Sauter la ligne d'entête
	 char ligneEntete[256];
	 fichierLecture.getline(ligneEntete, 255);

	 string ligne = LireLigne(fichierLecture);

	 ostringstream stream;
	 bool valide = validerLigneCVS(ligne, stream);

	 if (valide)
	 cout << "Csv valide" << endl << endl;
	 else
	 cout << "Csv non valide" << endl << endl;

	 cout << stream.str();

	 // Lecture fichier Json
	 fichierLecture = OuvertureFichierLecture(nomFichierLectureJson);
	 fichierLecture.seekg(0, fichierLecture.end);
	 int length = fichierLecture.tellg();
	 fichierLecture.seekg(0, fichierLecture.beg);

	 //Lecture des données
	 char * buffer = new char[length];
	 fichierLecture.read(buffer, length);
	 string enregistrement = "";
	 enregistrement.append(buffer);

	 //Création du memory stream
	 ostringstream ofs;

	 valide = valideStationnemementGEOJSON(enregistrement, ofs);
	 //Afficher à la console le résultat

	 if (valide)
	 cout << "Geojson valide" << endl << endl;
	 else
	 cout << "Geojson non valide" << endl << endl;

	 cout << ofs.str();
	 */

	return 0;
}
