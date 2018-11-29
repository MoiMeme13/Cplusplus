#include <gtest/gtest.h>

#include "../BorneUtilisation/BorneFontaine.h"/**
 *\file BorneTesteur.cpp
 *\brief "Description"
 *\author "Maxime Lam"
 *\date 2018-11-25
 */
#include "../BorneUtilisation/BorneFontaine.h"

using namespace BornesQuebec;

/**
 * \brief Test du Constructeur BorneFontaine(const unsigned int identifiant, const float p_latitude,const float p_longitude,const std::string& p_direction,
 * const std::string& p_nomTopographique,const std::string& p_ville,const std::string& p_arrondissement);
 *        cas valide ConstructeurAvecParametre: Borne fontaine avec des arguments
 *        cas invalide Aucun d'identifié
 */
//CAS valide
 TEST(Borne,ConstructeurAvecParametres){
	 BorneFontaine uneBorneFontaine(1234,1.12,1.14,"Nord","Borne Fontaine","Quebec","beauport");
	 ASSERT_EQ(1234,uneBorneFontaine.obtenirIdentifiant());
	 ASSERT_EQ(1.2,uneBorneFontaine.obtenirLatitude());
	 ASSERT_EQ(1.4,uneBorneFontaine.obtenirLongitude());
	 ASSERT_EQ("Nord",uneBorneFontaine.obtenirDirection());
	 ASSERT_EQ("Quebec",uneBorneFontaine.ObtenirVille());
	 ASSERT_EQ("beauport",uneBorneFontaine.ObtenirArroundissement());
 }