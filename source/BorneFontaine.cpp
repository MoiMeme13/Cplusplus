/**
 *\file BorneFontaine.cpp

 *\brief "Description"
 *\author "Maxime Lam"
 *\date 2018-11-11
 **/

#include <sstream>

#include "BorneFontaine.h"
#include "ContratException.h"

namespace BornesQuebec {

BorneFontaine::BorneFontaine(const unsigned int p_identifiant,
		const float p_latitude, const float p_longitude,
		const std::string& p_direction, const std::string& p_nomTopographique,
		const std::string& p_ville, const std::string& p_arrondissement) :
		Borne::Borne(p_identifiant, p_latitude, p_longitude, p_direction,
				p_nomTopographique),m_ville(p_ville),m_arrondissement(p_arrondissement)

{
	PRECONDITION(p_ville == "Quebec" && p_arrondissement.empty());

	POSTCONDITION(p_ville == m_ville);
	POSTCONDITION(p_arrondissement == m_arrondissement);

	INVARIANTS();
}

Borne* BorneFontaine::clone() const {
	return new BorneFontaine(*this);
}

std::string BorneFontaine::reqBorneFormate(const Borne& p_borne) const{
	std::ostringstream stream;

		stream << "Borne-fontaine" << std::endl;
		stream << "-----------------------------------" << std::endl;
		stream << Borne::reqBorneFormate(p_borne) << std::endl;
		stream << "Nom de la ville : " << ObtenirVille() << std::endl;
		stream << "Nom de l'arrondissement : " << ObtenirArroundissement() << std::endl;

		return stream.str();
}

void BorneFontaine::verifieInvariant() const {
	INVARIANT(m_ville == "Quebec" && m_arrondissement.empty());
}

const std::string& BorneFontaine::ObtenirVille() const {
	return m_ville;
}

const std::string& BorneFontaine::ObtenirArroundissement() const {
	return m_arrondissement;
}

} /* namespace BornesQuebec */
