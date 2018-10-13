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

/**
 * \class Borne
 * \brief Cette classe crée un objet Borne
 */
class Borne {
public:
	Borne(const std::string& p_numBorne, const std::string& p_coteRue,const float& p_lectureMetrique,const int& p_segmentRue, const std::string& p_direction,const std::string& p_nomTopographique) :
		m_numBorne(p_numBorne),m_coteRue(p_coteRue),m_lectureMetrique(p_lectureMetrique),m_segmentRue(p_segmentRue),m_direction(p_direction),  m_nomTopographique(p_nomTopographique){
	}

	const std::string& getCoteRue() const;
	const std::string& getDirection() const;
	float getLectureMetrique() const;
	const std::string& getNomTopographique() const;
	void setNomTopographique(const std::string& nomTopographique);
	const std::string& getNumBorne() const;
	int getSegmentRue() const;
	std::string reqBorneFormate() const;

private:
	const std::string m_numBorne;
	const std::string m_coteRue;
	const float m_lectureMetrique;
	const int m_segmentRue;
	const std::string m_direction;
	std::string m_nomTopographique;
};

#endif /* BORNE_H_ */
