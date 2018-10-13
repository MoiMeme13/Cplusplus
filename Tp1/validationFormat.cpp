/**
 * \file validationFormat.cpp
 *	\brief Fichier contenant les fonctions de validation de fichier de stationement
 *  \date 2018-10-11
 *  \author  Maime Lamontagne
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "validationFormat.h"

using namespace std;

namespace Util {

/**
 * \fn: validerPointCardinal
 * \brief: "Valide que le point cadinale entré est valide"
 * \param[in] const std::string&
 * \return bool
 */
bool validerPointCardinal(const std::string& p_cardinalite) {

	bool valide = p_cardinalite.empty();

	if (p_cardinalite.find("Nord") != string::npos)
		if (p_cardinalite.length() == 4)
			valide = true;

	if (p_cardinalite.find("Sud") != string::npos)
		if (p_cardinalite.length() == 3)
			valide = true;

	if (p_cardinalite.find("Est") != string::npos)
		if (p_cardinalite.length() == 3)
			valide = true;

	if (p_cardinalite.find("Ouest") != string::npos)
		if (p_cardinalite.length() == 5)
			valide = true;

	if (p_cardinalite.find("null") != string::npos)
		if (p_cardinalite.length() == 4)
			valide = true;

	return valide;
}

/**
 * \fn: validerLigneCVS
 * \brief: "Valide si la ligne csv envoyé est conforme"
 * \param[in] std::string&
 * \param[in] std::ostringstream&
 * \return bool
 */
bool validerLigneCVS(std::string& p_ligne, std::ostringstream& p_parametres) {
	int const nbrItemsValide = 9;
	int positionBarreCourante = 0;
	int positionBarreDernier = 0;
	static const string NomsColonnes[nbrItemsValide] = { "ID:", "COTE_RUE:",
			"LECT_MET:", "SEGMENT_RU:", "DIRECTION:", "NOM_TOPOG:", "NO_BORNE:",
			"LONGITUDE:", "LATITUDE:" };
	int nombreItems = 0;
	string ligneFichierOut = "";

	do {
		ligneFichierOut = "";
		ligneFichierOut.append(NomsColonnes[nombreItems++]);

		positionBarreCourante = p_ligne.find('|', positionBarreDernier);

		int length = positionBarreCourante - positionBarreDernier;
		string item = "";

		if (positionBarreDernier != string::npos)
			item = p_ligne.substr(positionBarreDernier, length);
		else
			item = p_ligne.substr(positionBarreDernier);

		positionBarreDernier = positionBarreCourante + 1;

		ligneFichierOut.append(item);
		p_parametres << ligneFichierOut << endl;

	} while (positionBarreCourante != string::npos);

	return nbrItemsValide == nombreItems;
}
/**
 * \fn: LireLigne
 * \brief: "Lie une ligne d'un fichier"
 * \param[in] ifstream&
 * \return string
 */
string LireLigne(ifstream& ifs) {

	char ligne[256];

	ifs.getline(ligne, 255);
	string contenuLigne = ligne;

	return contenuLigne;
}
/**
 * \fn: OuvertureFichierLecture
 * \brief: "Ouvre un chier pour le lire "
 * \param[in] string
 * \return ifstream
 */
ifstream OuvertureFichierLecture(string nomFichier) {
	ifstream ifs(nomFichier, ifstream::in);

	if (!ifs) {
		cerr << "Ouverture impossible" << endl;
	}
	return ifs;
}

/**
 * \fn: convertirChaineEnDouble
 * \brief: "Convertie un chaine de caratere en double"
 * \param[in] std::string&
 * \return double
 */
double convertirChaineEnDouble(std::string& p_chaine) {
	//on remplace la , en .
	for (unsigned int i = 0; i < p_chaine.length(); i++) {
		if (p_chaine[i] == ',') {
			p_chaine[i] = '.';
		}
	}
	istringstream is(p_chaine);
	double chaineConvertiEnDouble;
	is >> chaineConvertiEnDouble;
	return chaineConvertiEnDouble;
}

/**
 * \fn: validerGeom
 * \brief: "Valide une position Geom"
 * \param[in] const std::string&
 * \return bool
 */
bool validerGeom(const std::string& p_geom) {

	int positionParenthese = p_geom.find("(", 0);

	string positionWkt = p_geom.substr(positionParenthese + 1);

	int positionSpace = positionWkt.find(" ", 0);

	string longitude = positionWkt.substr(0, positionSpace);
	double longitudeDouble = convertirChaineEnDouble(longitude);

	int longeurLatitude = positionWkt.size() - positionSpace - 2;
	string latitude = positionWkt.substr(positionSpace + 1, longeurLatitude);
	double latitudeDouble = convertirChaineEnDouble(latitude);

	bool valide = p_geom.find("(", 0) != string::npos
			&& p_geom.find(")", 0) != string::npos
			&& p_geom.find("POINT", 0) != string::npos && longitudeDouble != 0
			&& latitudeDouble != 0;

	return valide;
}

/**
 * \fn: valideStationnemementGEOJSON
 * \brief: "Valide si le fichier GeoJson est valide"
 * \param[in] std::string&
 * \return bool
 */
bool valideStationnemementGEOJSON(std::string& p_enregistrement,
		std::ostringstream& p_attributs) {

	int positionBracket = 0, bracketDernier = 0, premierGuilement = 0,
			compteur = 0;
	string donneeExtraite = "", ligneDonnee = "";

	//Validation de la présence de tous les crochets (« brackets »).
	for (int i = 0; i < 3; i++) {
		bracketDernier = positionBracket;
		positionBracket = p_enregistrement.find("{", bracketDernier + 1);

		if (positionBracket == string::npos)
			return false;
	}

	int position = 0;
	int compteurGuillemet = -1;
	do {
		position = p_enregistrement.find("\"", ++position);
		compteurGuillemet++;
	} while (position != string::npos);

	//Validation qu'il y a un nombre pair de guillemets
	if (compteurGuillemet % 2 != 0)
		return false;

	int positionDepartLecture = positionBracket;

	for (int i = 0; i < 3; i++) {
		bracketDernier = positionBracket;
		positionBracket = p_enregistrement.find("}", ++bracketDernier);

		if (positionBracket == string::npos)
			return false;
	}

	//Lecture du fichier GeoJson
	do {
		premierGuilement = p_enregistrement.find("\"", ++positionDepartLecture);
		int deuxiemeGuilement = 0;

		if (premierGuilement != string::npos) {
			deuxiemeGuilement = p_enregistrement.find("\"", ++premierGuilement);
			int longeur = deuxiemeGuilement - premierGuilement;

			donneeExtraite = p_enregistrement.substr(premierGuilement, longeur);

			//Ajout de la donnée à la ligne pour avoir un format adéquat.
			if (compteur++ % 2 == 0)
				ligneDonnee.append(donneeExtraite);
			else {
				ligneDonnee.append(" : ");
				ligneDonnee.append(donneeExtraite);
				ligneDonnee.append("\n");
			}

			//Validation du Point WKT.
			if (donneeExtraite.find("POINT", 0) != -1) {
				bool geomValide = validerGeom(donneeExtraite);

				if (geomValide) {
					cout << "Position Geom valide" << endl << endl;
				} else {
					cout << "Position Geom non valide" << endl << endl;
				}
			}
		}

		//Localisation des données nulles.
		int positionNull = p_enregistrement.find("null",
				++positionDepartLecture);

		if (positionNull == deuxiemeGuilement + 4) {
			ligneDonnee.append(" : ");
			ligneDonnee.append("null");
			ligneDonnee.append("\n");
			compteur++;
		}

		//Localisation des données à ne pas prendre en compte (NO_CIVIQ et ID_VOIE_PUB").
		if (ligneDonnee.find("NO_CIVIQ", 0) != string::npos
				|| ligneDonnee.find("ID_VOIE_PUB", 0) != string::npos) {
			for (int i = 0; i < 2; i++) {
				premierGuilement = p_enregistrement.find("\"",
						++positionDepartLecture);
				deuxiemeGuilement = p_enregistrement.find("\"",
						++premierGuilement);
				positionDepartLecture = deuxiemeGuilement;
			}
			ligneDonnee = "";

		} else if (compteur % 2 == 0) {
			//Ajout d'une ligne dans le stream.
			p_attributs << ligneDonnee;
			ligneDonnee = "";
		}

		positionDepartLecture = deuxiemeGuilement;
	} while (premierGuilement != string::npos);

	return true;
}

/**
 * \fn: validationAvanceGeoJSON
 * \brief: "Validation avancée du fichier GeoJson"
 * \param[in] std::string&
 * \return bool
 */
bool validationAvanceGeoJSON(std::string& p_enregistrement) {
	/*J'ai essayé de faire une validation plus avancée du GeoJSON (plus complexe que je croyais).
	 int position = positionDepartLecture;
	 int positionDeuxPoints = 0;
	 int positionNull = 0;
	 int positionDoubleDebut = 0;
	 int positionDoubleFin = 0;
	 int compteurGuillemet = -1;
	 double chiffre = 0;
	 int positionPointGeom = -1;

	 do {
	 position = p_enregistrement.find("\"", ++position);
	 compteurGuillemet++;
	 position = p_enregistrement.find("\"", ++position);
	 compteurGuillemet++;

	 positionDeuxPoints = position = p_enregistrement.find("\"", position);

	 positionNull = p_enregistrement.find("null", position);

	 if (positionNull == string::npos) {
	 positionPointGeom = p_enregistrement.find("POINT", position);
	 }

	 if (positionPointGeom == string::npos && positionNull == string::npos) {
	 chiffre = -1;
	 positionDoubleDebut = p_enregistrement.find(" ", position);
	 positionDoubleFin = p_enregistrement.find(" ",
	 ++positionDoubleDebut);
	 int longeurDouble = positionDoubleFin - positionDoubleDebut;
	 string stringChiffre = p_enregistrement.substr(positionDoubleDebut,
	 longeurDouble);
	 chiffre = convertirChaineEnDouble(stringChiffre);

	 }

	 if (chiffre == 0 && positionPointGeom == string::npos && positionNull == string::npos) {
	 position = p_enregistrement.find("\"", ++position);
	 compteurGuillemet++;

	 if (position != string::npos) {
	 position = p_enregistrement.find("\"", ++position);
	 compteurGuillemet++;
	 }

	 }
	 positionPointGeom = -1;
	 positionNull = -1;
	 chiffre =0;

	 } while (position != string::npos);

	 //Validation qu'il y a un nombre paire de guillemet
	 if (compteurGuillemet % 2 != 0)
	 return false;
	 */
	return true;
}

}
