/**
 *\file RegistreBorneTesteur.cpp
 *\brief "Description"
 *\author "Maxime Lam"
 *\date 2018-11-27
 */

#include <gtest/gtest.h>
#include "RegistreBorne.h"
#include "BorneFontaine.h"

using namespace BornesQuebec;

/**
 * \brief  Test du constructeur de la classe registre
 *        cas valide:
 *         Il retourne toutes les données passés en paramètre.
 *        cas invalide Aucun d'identifié
 */
TEST(RegistreBorne,ConstructeurDunRegistreDeBorne){
	BornesQuebec::RegistreBorne unRegistre("LeNomDuRegistre");
	ASSERT_EQ("LeNomDuRegistre",unRegistre.ObtenirNom());
}

/**
 * \brief  Test du d'ajout d'une borne dans le registre
 *        cas valide:
 *         	Il ajoute la borne dans le registre
 *        cas invalide
 *			Il n'a pas ajouté de borne dans le registre des bornes
 */
TEST(RegistreBorne,AjoutDuneBorneDansLeRegistre){
	BornesQuebec::RegistreBorne unRegistre("LeNomDuRegistre");
	BornesQuebec:: BorneFontaine uneBorneFontaine(1234,1.12,1.14,"Nord","Borne Fontaine","Quebec","beauport");

	unRegistre.AjouteBorne(uneBorneFontaine);

	ASSERT_EQ(1,unRegistre.m_vBorne.size());
}
