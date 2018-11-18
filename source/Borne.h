/**
 * \file Borne.h
 *
 *  \date 2018-10-11
 *  \author  Maime Lamontagne
 */
#include <string>
#include <fstream>

#ifndef BORNE_H_
#define BORNE_H_

namespace BornesQuebec {
/**
 * \class Borne
 * \brief Cette classe crée un objet Borne
 */
class Borne {
public:
	Borne(const unsigned int p_identifiant, const float p_latitude,
			const float p_longitude, const std::string& p_direction,
			const std::string& p_nomTopographique);

	const unsigned int obtenirIdentifiant() const;
	const float obtenirLatitude() const;
	const float obtenirLongitude() const;
	const std::string& obtenirDirection() const;
	const std::string& obtenirNomTopographique() const;

	void changerNomTopographique(const std::string& nomTopographique);
	virtual std::string reqBorneFormate(const Borne& borne) const=0;
	const bool operator==(const Borne& p_borne) const;
	virtual ~Borne();
	virtual Borne* clone() const=0;

private:
	unsigned int m_identifiant;
	float m_latitude;
	float m_longitude;
	std::string m_direction;
	std::string m_nomTopographique;

	void verifieInvariant() const;
};

}/*Namespace BornesQuebec*/
#endif /* BORNE_H_ */
