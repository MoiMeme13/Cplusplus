/**
 *\file BorneStationnement.cpp
 *\brief "Description"
 *\author "Maxime Lam"
 *\date 2018-11-11
 **/
#include "BorneStationnement.h"
#include "Borne.h"

namespace BornesQuebec {

BorneStationnement::BorneStationnement(const unsigned int p_identifiant,
		const float p_latitude, const float p_longitude,
		const std::string& p_direction, const std::string& p_nomTopographique,
		const std::string& p_type, const float p_lectureMetrique,
		const unsigned int p_segmentRue, const unsigned short int p_numBorne,
		const std::string& p_coteRue) :
		Borne::Borne(p_identifiant, p_latitude, p_longitude, p_direction,
				p_nomTopographique),m_type(p_type),m_lectureMetrique(p_lectureMetrique),
				m_segmentRue(p_segmentRue),m_numBorne(p_numBorne),m_coteRue(p_coteRue){


}

BorneStationnement::~BorneStationnement() {
	// TODO Auto-generated destructor stub
}

} /* namespace BornesQuebec */
