/**
 *\file BorneFontaine.h

 *\brief "Description"
 *\author "Maxime Lam"
 *\date 2018-11-11
 **/
#include <string>

#ifndef BORNEFONTAINE_H_
#define BORNEFONTAINE_H_

#include "Borne.h"

namespace BornesQuebec {

/**
 * \class BorneFontaine
 * \brief Cette classe crée un objet BorneFontaine
 */
class BorneFontaine: public virtual Borne {

public:
	BorneFontaine(const unsigned int p_identifiant, const float p_latitude,
			const float p_longitude, const std::string& p_direction,
			const std::string& p_nomTopographique,const std::string& p_ville,
			const std::string& p_arroundissement);

	const std::string& ObtenirVille() const;
	const std::string& ObtenirArroundissement() const;
	virtual std::string reqBorneFormate() const;
	virtual Borne* clone() const;

private:
	std::string m_ville;
	std::string m_arrondissement;

	void verifieInvariant() const;

};

} /* namespace BornesQuebec */

#endif /* BORNEFONTAINE_H_ */
