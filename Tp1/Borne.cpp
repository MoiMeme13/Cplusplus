/**
 * \file Borne.cpp
 * \brief Fichier contenant toutes les fonctions d'une borne
 *  \date 2018-10-11
 *  \author  Maime Lamontagne
 */

#include <sstream>

#include "Borne.h"

/**
 * \fn: Borne::getCoteRue
 * \brief: "Obtenir le code de la rue"
 * \return string
 */
const std::string& Borne::getCoteRue() const {
	return m_coteRue;
}

/**
 * \fn: Borne::getDirection
 * \brief: "Obtenir la direction"
 * \return const std::string&
 */
const std::string& Borne::getDirection() const {
	return m_direction;
}

/**
 * \fn: Borne::getLectureMetrique
 * \brief: "Obtenir la lecture métrique"
 * \return float
 */
float Borne::getLectureMetrique() const {
	return m_lectureMetrique;
}

/**
 * \fn: Borne::getNomTopographique
 * \brief: "Obtenir le nom topographique"
 * \return const std::string&
 */
const std::string& Borne::getNomTopographique() const {
	return m_nomTopographique;
}

/**
 * \fn: Borne::setNomTopographique
 * \brief: "Assigner le nom topographique"
 * \param[in] const std::string&
 */
void Borne::setNomTopographique(const std::string& nomTopographique) {
	m_nomTopographique = nomTopographique;
}

/**
 * \fn: Borne::getNumBorne
 * \brief: "Obtenir le numéro de la borne"
 * \return const std::string&
 */
const std::string& Borne::getNumBorne() const {
	return m_numBorne;
}

/**
 * \fn: Borne::getSegmentRue
 * \brief: "Obtenir le segment de rue"
 * \return int
 */
int Borne::getSegmentRue() const {
	return m_segmentRue;
}
/**
 * \fn: Borne::reqBorneFormate
 * \brief: "Obtenir sous le format de chaine de caractè les informations de la bornes."
 * \return std::string
 */
std::string Borne::reqBorneFormate() const {

	std::ostringstream stream;

	stream << "Numero de la borne : " << m_numBorne << std::endl;
	stream << "Cote de la rue : " << m_coteRue << std::endl;
	stream << "Distance mesuree : " << m_lectureMetrique << std::endl;
	stream << "Segment de rue : " << m_segmentRue << std::endl;
	stream << "Direction : " << m_direction << std::endl;
	stream << "Nom topographique : " << m_nomTopographique << std::endl;

	return stream.str();
}

/**
 * \fn: Borne::operator==
 * \brief: "Regarde si deux bornes sont égales"
 * \param[in] const Borne& p_borne
 * \return bool
 */
bool Borne::operator==(const Borne& p_borne) const {

	return m_coteRue == p_borne.m_coteRue && m_direction == p_borne.m_direction
			&& m_lectureMetrique == p_borne.m_lectureMetrique
			&& m_nomTopographique == p_borne.m_nomTopographique
			&& m_numBorne == p_borne.m_numBorne
			&& m_segmentRue == p_borne.m_segmentRue;
}

/**
 * \fn: Borne::operator<<
 * \brief: "Remplacer l'opérateur de base "<<" pour une borne"
 * \param[in] ostream& p_os, const Borne& p_borne
 * \return ostream&
 */
std::ostream& operator<<(std::ostream& p_os,const Borne& p_borne){

	p_os << "Numero de la borne : " << p_borne.m_numBorne << std::endl;
	p_os << "Cote de la rue : " << p_borne.m_coteRue << std::endl;
	p_os << "Distance mesuree : " << p_borne.m_lectureMetrique << std::endl;
	p_os << "Segment de rue : " << p_borne.m_segmentRue << std::endl;
	p_os << "Direction : " << p_borne.m_direction << std::endl;
	p_os << "Nom topographique : " << p_borne.m_nomTopographique << std::endl;

	return p_os;
}


