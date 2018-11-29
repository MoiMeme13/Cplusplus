/**
 *\file BorneTesteur.cpp
 *\brief "Description"
 *\author "Maxime Lam"
 *\date 2018-11-27
 */
#include <gtest/gtest.h>
#include "../BorneUtilisation/Borne.h"
using namespace BornesQuebec;

/**
 * \class BorneTesteur
 * \brief Cette classe test les fonctions de la classe Borne qui est abstraite
 */
class BorneTest: public virtual Borne
{
public:
	BorneTest(const unsigned int p_identifiant, const float p_latitude,
				const float p_longitude, const std::string& p_direction,
				const std::string& p_nomTopographique): Borne(m_identifiant,m_latitude,m_longitude,m_direction,m_nomTopographique){

	}
	virtual std::string reqBorneFormate() const;
	virtual Borne* clone() const;

private:
	unsigned int m_identifiant;
	float m_latitude;
	float m_longitude;
	std::string m_direction;
	std::string m_nomTopographique;
};






