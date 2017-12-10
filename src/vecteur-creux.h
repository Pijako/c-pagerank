/*******************************************************************************
 *  Auteur   : tpichel
 *  Objectif : Spécification des vecteurs creux
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#ifndef VC_H
#define VC_H

typedef struct Couple Couple;

typedef int Indice;

typedef long double Valeur;

struct Couple{

	Indice indice;
	Valeur valeur;
	Couple *suivant;

};

typedef struct{

	int dimension;
	Couple *premier;

} Vecteurcreux;

void init(Vecteurcreux *v, int dimension);

void detruire(Vecteurcreux *v);

void ajouter(Vecteurcreux *v, Indice indice, Valeur valeur);

long double norme(Vecteurcreux v);

long double valeur(Vecteurcreux v, Indice indice);

long double scalaire(Vecteurcreux v, Vecteurcreux u);

Vecteurcreux somme(Vecteurcreux v1, Vecteurcreux v2);

void changer(Vecteurcreux *v, Indice indice, Valeur valeur);

void saisir(Vecteurcreux *v);

int lire(Vecteurcreux v);

#endif
