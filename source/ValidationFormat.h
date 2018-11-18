/**
 * \file validationFormat.h
 *
 *  \date 2018-10-11
 *  \author  Maime Lamontagne
 */
#include <sstream>

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

namespace Util {

	bool validerLigneCVS(std::string& p_ligne, std::ostringstream& p_parametres);
	std::string LireLigne(std::ifstream& ifs);
	std::ifstream OuvertureFichierLecture(std::string nomFichier);
	std::ofstream OuvrirFichierEcriture(std::string nomFichier);
	std::string ExtraireDonneesJson(std::string& ligneCourante);
	void EcrireLigneFichier(std::string& ligne, std::ofstream& p_parametres);
	bool valideStationnemementGEOJSON(std::string& p_enregistrement,
			std::ostringstream& p_attributs);
	bool validerPointCardinal(const std::string& p_cardinalite);
	double convertirChaineEnDouble(std::string& p_chaine);
	int convertirChaineEnInt(std::string& p_chaine);
	float convertirChaineEnfloat(std::string& p_chaine);
}
#endif /* VALIDATIONFORMAT_H_ */
