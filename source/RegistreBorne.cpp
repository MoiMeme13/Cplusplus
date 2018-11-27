/**
 *\file RegistreBorne.cpp
 *\brief "Description"
 *\author "Maxime Lam"
 *\date 2018-11-21
 **/
#include <sstream>

#include "RegistreBorne.h"
#include "ContratException.h"

namespace BornesQuebec {

/**
 * \fn: RegistreBorne::RegistreBorne
 * \brief: "Constructeur de registre de borne"
 * \param[in] const std::string& p_nomRegistreBorne
 * \return un registre de borne
 */
RegistreBorne::RegistreBorne(const std::string& p_nomRegistreBorne) :
		m_nomRegistreBorne(p_nomRegistreBorne) {
	PRECONDITION(!p_nomRegistreBorne.empty())

	INVARIANTS();

	POSTCONDITION(p_nomRegistreBorne == m_nomRegistreBorne);
}

/**
 * \fn: RegistreBorne::verifieInvariant
 * \brief: "Verifie les invariant de la classe registre"
 * \return Void
 */
void RegistreBorne::verifieInvariant() const {
	INVARIANT(!m_nomRegistreBorne.empty());
}

/**
 * \fn: RegistreBorne::BorneEstDejaPresente
 * \brief: "Verifie si la borne existe déjà dans la liste des bornes"
 * \return bool
 */
bool RegistreBorne::BorneEstDejaPresente(const Borne& p_borne) const {
	bool estDejaPresente = false;
	for (unsigned int it = 0; it < m_vBorne.size(); ++it) {
		if (*m_vBorne.at(it) == p_borne)
			estDejaPresente = true;
	}

	return estDejaPresente;
}

/**
 * \fn: RegistreBorne::AjouteBorne
 * \brief: "Ajoute un borne dans la liste des bornes"
 * \return Void
 */
void RegistreBorne::AjouteBorne(const Borne& p_borne) {

	if (!BorneEstDejaPresente(p_borne)) {
		m_vBorne.push_back(p_borne.clone());
	}
}

/**
 * \fn: RegistreBorne::~RegistreBorne
 * \brief: "Détruit la liste des bornes et toutes les bornes"
 * \return Void
 */
RegistreBorne::~RegistreBorne() {
	for (unsigned int i = 0; i < m_vBorne.size(); i++)
		delete m_vBorne.at(i);
}

/**
 * \fn: RegistreBorne::reqBorneFormate
 * \brief: "Obtient les bornes dans un format string formaté"
 * \return string
 */
std::string RegistreBorne::reqBorneFormate() const {

	std::ostringstream stream;
	stream << "Registre des borne de la ville de " << m_nomRegistreBorne
					<< std::endl;

	for (unsigned int i = 0; i < m_vBorne.size(); i++) {
		stream << m_vBorne.at(i)->reqBorneFormate() << std::endl;
	}

	return stream.str();
}

} /* namespace BornesQuebec */
