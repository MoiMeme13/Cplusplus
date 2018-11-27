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

/**
 * \fn: BorneFontaine::BorneFontaine
 * \brief: "Constructeur de borne fontaine"
 * \param[in] const unsigned int identifiant
 * \param[in] const float p_latitude
 * \param[in] const float p_longitude
 * \param[in] const std::string& p_direction
 * \param[in] const std::string& p_nomTopographique
 * \param[in] const std::string& p_ville
 * \param[in] const std::string& p_arrondissement
 * pre p_ville égale Quebec et arrondissement n'est pas vide
 * post m_ville contient la même chose que p_ville
 * post p_arrondissement contient la même chose que m_arrondissement
 * \return une BorneFontaine
 */
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

/**
 * \fn: BorneFontaine::verifieInvariant
 * \brief: "Verifie les invariants de la classe"
 * \return Rien
 */
void BorneFontaine::verifieInvariant() const {
	INVARIANT(m_ville == "Quebec" && m_arrondissement.empty());
}

/**
 * \fn: BorneFontaine::clone()
 * \brief: "Clone une borne fontaine"
 * \return Borne*
 */
Borne* BorneFontaine::clone() const {
	return new BorneFontaine(*this);
}

/**
 * \fn: BorneFontaine::reqBorneFormate
 * \brief: "Obtenir la borne fontaine au format string"
 * \return std::string
 */
std::string BorneFontaine::reqBorneFormate() const{
	std::ostringstream stream;

		stream << "Borne-fontaine" << std::endl;
		stream << "-----------------------------------" << std::endl;
		stream << Borne::reqBorneFormate() << std::endl;
		stream << "Nom de la ville : " << ObtenirVille() << std::endl;
		stream << "Nom de l'arrondissement : " << ObtenirArroundissement() << std::endl;

		return stream.str();
}

/**
 * \fn: BorneFontaine::ObtenirVille
 * \brief: "Obtenir la ville de la borne fontaine"
 * \return std::string
 */
const std::string& BorneFontaine::ObtenirVille() const {
	return m_ville;
}

/**
 * \fn: BorneFontaine::ObtenirArroundissement
 * \brief: "Obtenir l'arrondissement de la borne fontaine"
 * \return std::string
 */
const std::string& BorneFontaine::ObtenirArroundissement() const {
	return m_arrondissement;
}

} /* namespace BornesQuebec */
