/**
 *\file RegistreBorne.cpp
 *\brief "Description"
 *\author "Maxime Lam"
 *\date 2018-11-21
 **/
#include "RegistreBorne.h"
#include "ContratException.h"

namespace BornesQuebec {

RegistreBorne::RegistreBorne(const std::string& p_nomRegistreBorne) :
		m_nomRegistreBorne(p_nomRegistreBorne) {
	PRECONDITION(!p_nomRegistreBorne.empty())

	INVARIANTS();

	POSTCONDITION(p_nomRegistreBorne == m_nomRegistreBorne);
}

void RegistreBorne::verifieInvariant() const {
	INVARIANT(!m_nomRegistreBorne.empty());
}

bool RegistreBorne::BorneEstDejaPresente(const Borne& p_borne) const{
	bool estDejaPresente = false;
	for (unsigned int it = 0; it < m_vBorne.size(); ++it){
		if (*m_vBorne.at(it) == p_borne)
			estDejaPresente = true;
	}

	return estDejaPresente;
}

RegistreBorne::~RegistreBorne() {
	// TODO Auto-generated destructor stub
}

} /* namespace BornesQuebec */
