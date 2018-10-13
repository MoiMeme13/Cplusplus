/**
 * \file Borne.cpp
 * \brief Fichier contenant toutes les fonctions d'une borne
 *  \date 2018-10-11
 *  \author  Maime Lamontagne
 */

#include <sstream>

#include "Borne.h"

/**
 * \fn: getCoteRue
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
 * \fn: getLectureMetrique
 * \brief: "Obtenir la lecture métrique"
 * \return float
 */
float Borne::getLectureMetrique() const {
	return m_lectureMetrique;
}

/**
 * \fn: Borne::getNomTopographique
 * \brief: "Obtenir le nom topographique"
 * \param[in]
 * \return const std::string&
 */
const std::string& Borne::getNomTopographique() const {
	return m_nomTopographique;
}

/**
 * \fn: setNomTopographique
 * \brief: "Assigner le nom topographique"
 * \param[in] const std::string&
 */
void Borne::setNomTopographique(const std::string& nomTopographique) {
	m_nomTopographique = nomTopographique;
}

/**
 * \fn: getNumBorne
 * \brief: "Obtenir le numéro de la borne"
 * \return const std::string&
 */
const std::string& Borne::getNumBorne() const {
	return m_numBorne;
}

/**
 * \fn: getSegmentRue
 * \brief: "Obtenir le segment de rue"
 * \return int
 */
int Borne::getSegmentRue() const {
	return m_segmentRue;
}
/**
 * \fn: reqBorneFormate
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

