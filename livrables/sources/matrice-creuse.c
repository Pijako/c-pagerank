/*******************************************************************************suivant;
 *  Auteur   : tpichel
 *  Objectif : Implantation de matrices creuses
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "vecteur-creux.h"
#include "matrice-creuse.h"

void initm(Matricecreuse *m, int dimension){
	
	m->dimension = dimension;
	m->colonnes = malloc(dimension*sizeof(Vecteurcreux));
	
	for(int i=0;i<dimension;i++){
		init(&m->colonnes[i], dimension);
	}	
}

void saisir_matrice(Matricecreuse *m){
	
	for(int i=0;i<m->dimension;i++){
		saisir(&m->colonnes[i]);
	}
	
}

void lirem(Matricecreuse m){
	
	for(int i=m.dimension-1;i>=0;i--){
		lire(m.colonnes[i]);
	}

}

void tri(int **reseau, int taille) {

	int min;
	int valtmp[2];

	for(int i=0;i<taille;i++){
		min = i;
		for(int j=i;j<taille;j++){
			if(reseau[j][0] > reseau[min][0]){
				min = j;	
			}	
		}
		if(i != min){
			valtmp[0] = reseau[i][0];
			valtmp[1] = reseau[i][1];

			reseau[i][0] = reseau[min][0];
			reseau[i][1] = reseau[min][1];

			reseau[min][0] = valtmp[0];
			reseau[min][1] = valtmp[1];
		}	
	}
}

Vecteurcreux produit_matriciel_mutant(Matricecreuse m, Vecteurcreux pi, long double alpha, int *p){

	Vecteurcreux produit;
	long double N = m.dimension;

	init(&produit, N);
		
	for(int i=N-1;i>=0;i--){
		Vecteurcreux colonneG;
		init(&colonneG, N);
		
		for(int j=N-1;j>=0;j--){		
			if(p[j] != 0){
				ajouter(&colonneG, i, alpha*valeur(m.colonnes[i], j) + (1-alpha)/N );
			}
			else if(p[i] == 0){
				ajouter(&colonneG, i, 1/N + (1-alpha)/N );
			}
		}
		ajouter(&produit, i, scalaire(pi, colonneG));	
	}
	return produit;
}

void trier_pages(Vecteurcreux pi, int N){

	int *pages = malloc(N*sizeof(int));
	long double *poids = malloc(N*sizeof(long double));
	FILE *poidsfinaux = NULL;
	FILE *pagerank = NULL;
	poidsfinaux = fopen("poids.p","w");
	pagerank = fopen("pagerank.ord","w");	
	
	for(int i=0;i<N;i++){
		poids[i] = valeur(pi, i);
	}
	
	int min;
	float valtmp;
	
	for(int i=0;i<N;i++){
		min = i;
		for(int j=i;j<N;j++){
			if(poids[j] > poids[min]){
				min = j;	
			}	
		}
		if(i != min){
			valtmp = poids[i];
			poids[i] = poids[min];
			poids[min] = valtmp;
		}
		pages[i] = min;	
	}
	
	for(int i=0; i<N;i++){
		fprintf(pagerank, "%d\r", pages[i]);
	}
	fclose(pagerank);
	free(pages);
	
	for(int i=0; i<N;i++){
		fprintf(poidsfinaux, "%Lf\r", poids[i]);
	}
	fclose(poidsfinaux);
	free(poids);
}

int* initm_file(Matricecreuse *m, FILE *fichier){

	int **reseau;
	int couple[2];
	int dimension, page_source, page_cible;
	int nb_pages_sources = 0;
	int nb_pages_cibles = 0;
	long double poids, invpoids;
	int nb_liens = 0;
	int *p;
	
	fscanf(fichier, "%d", &dimension);
	p = malloc(dimension*sizeof(int));
	
	for(int i=0;i<6;i++){
		p[i] = 0;
	}
	initm(m, dimension);
	
	reseau = malloc(2*sizeof(*reseau));	
	reseau[0] = malloc(2*sizeof(**reseau));
	
	while(!feof(fichier)){			//On lit le fichier
		fscanf(fichier, "%d %d", &page_source, &page_cible);
		
		reseau[nb_liens][0] = page_source;
		reseau[nb_liens][1] = page_cible;

		p[page_source] = p[page_source]+1;			
		nb_liens++;
		
		reseau = realloc(reseau, (nb_liens+1)*sizeof(*reseau));
		reseau[nb_liens] = malloc(2*sizeof(**reseau));

	}
	p[dimension-1] = p[dimension-1] - 1;
	nb_liens--;
	tri(reseau, nb_liens);	
		
	for(int i=0;i<nb_liens;i++){	//On remplit la matrice
		long double invpoids = p[reseau[i][0]];
		ajouter(&m->colonnes[reseau[i][1]], reseau[i][0], 1/invpoids);
	}

	//On libère la mémoire utilisée par réseau

	for(int i=0;i<nb_liens;i++){
		free(reseau[i]);
	}
	free(reseau);
	fclose(fichier);

	return p;	
}

