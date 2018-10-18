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

	} while (itemEntree.empty() || lectureMetrique == 0 || (itemEntree.find(",") == string::npos && itemEntree.find(".") == string::npos));

	string nomTopographique = "";
	do {
		cout << "Donner moi le nom topographique de la borne." << endl;
		cin >> nomTopographique;

	} while (nomTopographique.empty());

	string direction = "";
	do {
		cout << "Donner moi la direction de la borne" << endl;
		cin >> direction;
	} while (direction.empty() || !Util::validerPointCardinal(direction));

	int segmentRue = 0;
	do {
		cout << "Donner moi le segment de la rue de la borne." << endl;
		cin >> itemEntree;
		segmentRue = convertirChaineEnInt(itemEntree);

	} while (nomTopographique.empty() || segmentRue == 0);

	Borne borne(numeroBorne, coteRue, lectureMetrique, segmentRue, direction,
			nomTopographique);

	cout << borne.reqBorneFormate() << endl;

	cout << borne << endl;

	return 0;
}
