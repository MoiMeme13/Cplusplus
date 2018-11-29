/**
 * \file Borne.cpp
 * \brief Fichier contenant toutes les fonctions d'une borne
 *  \date 2018-10-11
 *  \author  Maime Lamontagne
 */

#include "Borne.h"

#include <sstream>
#include <string>
#include "ContratException.h"
#include "ValidationFormat.h"

namespace BornesQuebec {

/**
 * \fn: Borne::Borne
 * \brief: "Constructeur de borne fontaine"
 * \param[in] const unsigned int identifiant
 * \param[in] const float p_latitude
 * \param[in] const float p_longitude
 * \param[in] const std::string& p_direction
 * \param[in] const std::string& p_nomTopographique
 * \return une Borne
 */
Borne::Borne(const unsigned int p_identifiant, const float p_latitude,
		const float p_longitude, const std::string& p_direction,
		const std::string& p_nomTopographique) :
		m_identifiant(p_identifiant), m_latitude(p_latitude), m_longitude(
				p_longitude), m_direction(p_direction), m_nomTopographique(
				p_nomTopographique) {
	PRECONDITION(p_identifiant >= 0);
	PRECONDITION(Util::validerPointCardinal(p_direction));
	PRECONDITION(!p_nomTopographique.empty());

	POSTCONDITION(p_identifiant == m_identifiant);
	POSTCONDITION(p_latitude == m_latitude);
	POSTCONDITION(p_longitude == m_longitude);
	POSTCONDITION(p_direction == m_direction);
	POSTCONDITION(p_nomTopographique == m_nomTopographique);

	INVARIANTS();
}

/**
 * \fn: Borne::verifieInvariant
 * \brief: "Verifier les invariants de la borne"
 * \return Void
 */
void Borne::verifieInvariant() const {
	INVARIANT(!m_nomTopographique.empty());
	INVARIANT(m_identifiant >= 0);
	INVARIANT(Util::validerPointCardinal(m_direction))
}

/**
 * \fn: Borne::obtenirDirection
 * \brief: "Obtenir la direction"
 * \return const std::string&
 */
const std::string& Borne::obtenirDirection() const {
	return m_direction;
}

/**
 * \fn: Borne::obtenirIdentifiant
 * \brief: "Obtenir l'identifiant de la borne"
 * \return float
 */
const unsigned int Borne::obtenirIdentifiant() const {
	return m_identifiant;
}

/**
 * \fn: Borne::obtenirNomTopographique
 * \brief: "Obtenir le nom topographique"
 * \return const std::string&
 */
const std::string& Borne::obtenirNomTopographique() const {
	return m_nomTopographique;
}

/**
 * \fn: Borne::changerNomTopographique
 * \brief: "Assigner le nom topographique"
 * \param[in] const std::string&
 */
void Borne::changerNomTopographique(const std::string& p_nomTopographique) {
	PRECONDITION(!p_nomTopographique.empty());
	m_nomTopographique = p_nomTopographique;
	POSTCONDITION(p_nomTopographique == m_nomTopographique);
	INVARIANTS();
}

/**
 * \fn: Borne::obtenirLatitude
 * \brief: "Obtenir la latitude
 * \return Réel
 */
const float Borne::obtenirLatitude() const {
	return m_latitude;
}

/**
 * \fn: Borne::obtenirLongitude
 * \brief: "Obtenir la longitude de la borne"
 * \return Réel
 */
const float Borne::obtenirLongitude() const {
	return m_longitude;
}
/**
 * \fn: Borne::reqBorneFormate
 * \brief: "Obtenir sous le format de chaine de caractè les informations d'une bornes."
 * \return std::string
 */
std::string Borne::reqBorneFormate() const {

	std::ostringstream stream;

	stream << "Identifiant de la borne : " << m_identifiant << std::endl;
	stream << "Direction : " << m_direction << std::endl;
	stream << "Nom topographique : " << m_nomTopographique << std::endl;
	stream << "Longitude : " << m_longitude << std::endl;
	stream << "Latitude : " << m_latitude << std::endl;

	return stream.str();
}

/**
 * \fn: Borne::operator==
 * \brief: "Regarde si deux bornes sont égales"
 * \param[in] const Borne& p_borne
 * \return bool
 */
const bool Borne::operator==(const Borne& p_borne) const {

	return m_identifiant == p_borne.m_identifiant
			&& m_latitude == p_borne.m_latitude
			&& m_longitude == p_borne.m_longitude
			&& m_nomTopographique == p_borne.m_nomTopographique
			&& m_direction == p_borne.m_direction;
}


}/*Namespace BornesQuebec*/
