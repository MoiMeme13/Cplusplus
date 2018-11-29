/**
 *\file BorneStationnementTesteur.cpp
 *\brief "Description"
 *\author "Maxime Lam"
 *\date 2018-11-27
 */
#include <gtest/gtest.h>
#include "../BorneUtilisation/BorneStationnement.h"

 
TEST(BorneStationnement,ConstructeurAvecParametres){
	BornesQuebec::BorneStationnement uneBorne(123,1.12,1.14,"Nord","MoiMeme","Stationnement",1.12,144,111,"Droite");
	ASSERT_EQ(123,uneBorne.obtenirIdentifiant());
	ASSERT_EQ(1.12,uneBorne.obtenirLatitude());
	ASSERT_EQ(1.14,uneBorne.obtenirLongitude());
	ASSERT_EQ("Nord",uneBorne.obtenirDirection());
	ASSERT_EQ("MoiMeme",uneBorne.obtenirNomTopographique());
	ASSERT_EQ("Stationnement",uneBorne.ObtenirType());
	ASSERT_EQ(1.12,uneBorne.ObtenirLectureMetrique());
	ASSERT_EQ(144,uneBorne.ObtenirSegmentRue());
	ASSERT_EQ(111,uneBorne.ObtenirNumBorne());
	ASSERT_EQ("Droite",uneBorne.ObtenirCoteRue());
}

