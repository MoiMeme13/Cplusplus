/**
 *\file BorneStationnement.cpp
 *\brief "Description"
 *\author "Maxime Lam"
 *\date 2018-11-11
 **/
#include "BorneStationnement.h"
#include "Borne.h"
#include "ContratException.h"
#include "ValidationFormat.h"

namespace BornesQuebec {

BorneStationnement::BorneStationnement(const unsigned int p_identifiant,
		const float p_latitude, const float p_longitude,
		const std::string& p_direction, const std::string& p_nomTopographique,
		const std::string& p_type, const float p_lectureMetrique,
		const unsigned int p_segmentRue, const unsigned short int p_numBorne,
		const std::string& p_coteRue) :
		Borne::Borne(p_identifiant, p_latitude, p_longitude, p_direction,
				p_nomTopographique),m_type(p_type),m_lectureMetrique(p_lectureMetrique),
				m_segmentRue(p_segmentRue),m_numBorne(p_numBorne),m_coteRue(p_coteRue)
{
	PRECONDITION(p_type == "stationnement" || p_type == "paiement");
	PRECONDITION(p_lectureMetrique > 0);
	PRECONDITION(p_segmentRue > 0);
	PRECONDITION(p_numBorne >= 0 && p_numBorne <= 9999);
	PRECONDITION(Util::validerPointCardinal(p_coteRue));

	POSTCONDITION(p_type == m_type);
	POSTCONDITION(p_lectureMetrique == m_lectureMetrique);
	POSTCONDITION(p_segmentRue == m_segmentRue);
	POSTCONDITION(p_numBorne == m_numBorne);
	POSTCONDITION(p_coteRue == m_coteRue);

	INVARIANTS();
	}

void BorneStationnement::verifieInvariant() const {
	INVARIANT(m_type =="stationnement" || m_type == "paiement");
	INVARIANT(m_lectureMetrique > 0);
	INVARIANT(m_segmentRue > 0);
	INVARIANT(m_numBorne >= 0 && m_numBorne <= 9999);
	INVARIANT(Util::validerPointCardinal(m_coteRue));
}

std::string BorneStationnement::reqBorneFormate() const {

	std::ostringstream stream;

	stream << "Borne de " << m_type <<std::endl;
	stream << "-----------------------------------" << std::endl;
	stream << Borne::reqBorneFormate() << std::endl;
	stream << "Distance mesuree : " << m_lectureMetrique << std::endl;
	stream << "Segment de rue : " << m_segmentRue << std::endl;
	stream << "Numero de la borne : " << m_numBorne << std::endl;
	stream << "Cote de la rue : " << m_coteRue << std::endl;

	return stream.str();
}

const std::string& BorneStationnement::ObtenirType() const{
	return m_type;
}

const float BorneStationnement::ObtenirLectureMetrique() const {
	return m_lectureMetrique;
}
 const unsigned int BorneStationnement::ObtenirSegmentRue() const {
	 return m_segmentRue;
 }
 const unsigned short BorneStationnement::ObtenirNumBorne() const {
	 return m_numBorne;
 }
 const std::string& BorneStationnement::ObtenirCoteRue() const {
	 return m_coteRue;
 }

 Borne* BorneStationnement::clone() const {
 	return new BorneStationnement(*this);
 }

} /* namespace BornesQuebec */
