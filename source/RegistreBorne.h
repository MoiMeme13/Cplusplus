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

 private:
 bool BorneEstDejaPresente(const Borne& p_borne) const;
 void verifieInvariant() const;
 std::string m_nomRegistreBorne;
 std::vector<Borne*> m_vBorne;
 };

 } /* namespace BornesQuebec */

#endif /* REGISTREBORNE_H_ */
