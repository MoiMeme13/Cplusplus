/**
 *\file BorneUtilisation.cpp
 *\brief "Description"
 *\author "Maxime Lam"
 *\date 2018-11-26
 **/

#include <iostream>

#include "Borne.h"
#include "BorneStationnement.h"

using namespace BornesQuebec;
using namespace std;

int main() {
	BorneStationnement uneBorneStationnement(1234, 1.12, 1.14, "Nord", "Borne Fontaine","Stationnement", 1.2,12,12,"Nord");
	cout << uneBorneStationnement.reqBorneFormate();
	return 0;
}

