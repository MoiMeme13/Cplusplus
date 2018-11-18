/**
 *\file BorneStationnement.h
 *\brief "Description"
 *\author "Maxime Lam"
 *\date 2018-11-11
 **/
 #ifndef BORNESTATIONNEMENT_H_
 #define BORNESTATIONNEMENT_H_

 #include "Borne.h"


 namespace BornesQuebec {

 class BorneStationnement : public virtual Borne {

 public:
 BorneStationnement(const unsigned int p_identifiant,
			const float p_latitude, const float p_longitude,
			const std::string& p_direction, const std::string& p_nomTopographique,
			const std::string& p_type, const float p_lectureMetrique,
			const unsigned int p_segmentRue, const unsigned short int p_numBorne,
			const std::string& p_coteRue);

 const std::string& ObtenirType() const ;
 const float ObtenirLectureMetrique() const ;
 const unsigned int ObtenirSegmentRue() const ;
 const unsigned short ObtenirNumBorne() const ;
 const std::string& ObtenirCoteRue() const ;
 virtual std::string reqBorneFormate(const Borne& borne) const;
 virtual Borne* clone() const;
 virtual ~BorneStationnement();

 private:
 std::string m_type;
 float m_lectureMetrique;
 unsigned int m_segmentRue;
 unsigned short int m_numBorne;
 std::string m_coteRue;

 };

 } /* namespace BornesQuebec */

#endif /* BORNESTATIONNEMENT_H_ */
