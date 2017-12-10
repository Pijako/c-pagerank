/*******************************************************************************suivant;
 *  Auteur   : tpichel
 *  Objectif : Implantation de matrices creuses
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef struct {
	
	int dimension;
	Vecteurcreux *colonnes;
	
} Matricecreuse;

void initm(Matricecreuse *m, int dimension);

void lirem(Matricecreuse m);

int* initm_file(Matricecreuse *m, FILE *fichier);

void tri(int** reseau, int taille);

Vecteurcreux produit_matriciel_mutant(Matricecreuse m, Vecteurcreux v, long double alpha, int *p);

void trier_pages(Vecteurcreux pi, int N);


