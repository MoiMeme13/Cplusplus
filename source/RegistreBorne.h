/**
 *\file RegistreBorne.h
 *\brief "Description"
 *\author "Maxime Lam"
 *\date 2018-11-21
 **/
 #ifndef REGISTREBORNE_H_
 #define REGISTREBORNE_H_


#include <vector>
#include "Borne.h"

 namespace BornesQuebec {

 class RegistreBorne {
 public:
 RegistreBorne(const std::string& p_nomRegistreBorne);
 std::string ObtenirNom() const;
 virtual ~RegistreBorne();
 void AjouteBorne(const Borne& p_borne);
 virtual std::string reqBorneFormate() const;

 private:
 RegistreBorne(const Borne& p_borne);
 const Borne& operator=(const Borne& p_borne);
 bool BorneEstDejaPresente(const Borne& p_borne) const;
 void verifieInvariant() const;
 std::string m_nomRegistreBorne;
 std::vector<Borne*> m_vBorne;
 };

 } /* namespace BornesQuebec */

#endif /* REGISTREBORNE_H_ */
