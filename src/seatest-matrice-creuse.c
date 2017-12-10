#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "seatest.h"
#include "vecteur-creux.h"
#include "matrice-creuse.h"


/* -------------------------------------------------------------*
 *    Definition des SP de test                                 *
 * -------------------------------------------------------------*/

/*
 * Sous-programme de test du SP init
 */

void test_initm(){
	
	Matricecreuse m;
	int dim;
	
	printf("Dimension de la matrice\n");
	scanf("%d", &dim);
	initm(&m, dim);
	lirem(m);
	
}

void test_initm_file(){
	
	Matricecreuse m;
	FILE *fichier = NULL;
	fichier = fopen("reseau.txt", "r");
	
	initm_file(&m, fichier);
	printf("Matrice H :\n");
	lirem(m);
	
}

void testpm(){
	
	int *p;
	Matricecreuse m;
	FILE *fichier = NULL;
	fichier = fopen("reseau.txt", "r");
	
	p = initm_file(&m, fichier);
	long double N = m.dimension;
	lirem(m);

	Vecteurcreux pi0, pi;
	init(&pi0, N);
	init(&pi, N);

	for(int i=N-1;i>=0;i--){
		ajouter(&pi0, i, 1/N);
	}

	for(int i=0;i<N;i++){
		printf("%d\n", p[i]);
	}

	printf("Vecteur pi0:\n");
	lire(pi0);
	printf("Lancement des itérations\n");	

	pi = produit_matriciel_mutant(m, pi0, 0.85, p);
	for(int i=1;i<=10;i++){
		pi = produit_matriciel_mutant(m, pi, 0.85, p);
		lire(pi);
	}
	printf("Pagerank\n");
	trier_pages(pi, N);
	
}

void testpr(){

	int *p;
	Matricecreuse m;
	FILE *fichier = NULL;
	fichier = fopen("reseau.txt", "r");
	
	p = initm_file(&m, fichier);
	lirem(m);

	Vecteurcreux pi0, pi;
	init(&pi0, m.dimension);
	init(&pi, m.dimension);

	long double N = m.dimension;

	for(int i=N;i>=1;i--){
		ajouter(&pi0, i, 1/N);
	}
	printf("Vecteur pi0 :\n");
	lire(pi0);
	printf("Itérations :\n");

	pi = produit_matriciel_mutant(m, pi0, 0.85, p);

	for(int i=1;i<=10;i++){
		pi = produit_matriciel_mutant(m, pi, 0.85, p);
		lire(pi);
	}	
	lire(pi);

}

void jeuTest1(void)
{
	test_fixture_start();      
	
	//run_test(test_changerDebut);
	
	test_fixture_end();
}

/* -------------------------------------------------------------*
 * Lancement de tous les jeus de test                           *
 * -------------------------------------------------------------*/
void all_tests(void)
{
	test_fixture_start();
	
	run_test(test_initm);
	run_test(test_initm_file);
	run_test(testpm);
	run_test(testpr);
	
	test_fixture_end();
}

/* -------------------------------------------------------------*
 * Main qui lance tous les tests                                *
 * -------------------------------------------------------------*/
int main()
{
	run_tests(all_tests);	
	return 0;
}

