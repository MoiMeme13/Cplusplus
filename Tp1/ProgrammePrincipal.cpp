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

using namespace std;
using namespace Util;

int main() {
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
