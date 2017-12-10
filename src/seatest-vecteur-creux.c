#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "seatest.h"
#include "vecteur-creux.h"


/* -------------------------------------------------------------*
 *    Definition des SP de test                                 *
 * -------------------------------------------------------------*/

/*
 * Sous-programme de test du SP init
 */
void test_init()
{
	Vecteurcreux vc;
	int dim;

	printf("-->Fonction Init()");
	printf("Dimension ? ");
	scanf("%d", &dim);
	init(&vc, dim);
	
	assert(lire(vc) == 0);
}

/*
 * Sous-programme de test du SP ajouter
 */

void test_ajouter()
{
	Vecteurcreux vc;
	int dim;
	int nb_valeurs;
	int indice;
	float val;

	printf("->Fonction Ajouter()\n");
	printf("Dimension ? ");
	scanf("%d", &dim);
	init(&vc, dim);
	printf("Combien de valeurs souhaitez-vous ajouter ? ");
	scanf("%d", &nb_valeurs);

	for(int i=0;i<nb_valeurs;i++){
		printf("Indice : ");
		scanf("%d", &indice);
		printf("Valeur :");
		scanf("%f", &val);	
		ajouter(&vc, indice, val);
	}
	lire(vc);
}
void test_valeur()
{
	Vecteurcreux vc;
	int indice;
	
	printf("-->Fonction Valeur()\n");

	init(&vc, 6);
	for(int i=3;i>=1;i--){
		ajouter(&vc, 2*i, 1);
	}
	
	printf("->Entrez un 1 <= indice <= 3\n");
	scanf("%d", &indice);
	assert(indice >= 1 && indice <= 3);	
	printf("%Lf\n", valeur(vc, indice));
	//assert(indice == valeur(vc, indice));

}

void test_changerDebut(){

	Vecteurcreux vc;
	init(&vc, 7);
	printf("-->test_changerDebut()\n");

	for(int i=3;i>=1;i--){
		ajouter(&vc, 2*i, 1);
	}
	printf("Avant: \n");
	lire(vc);
	printf("Changement:\n");
	changer(&vc, 2, 200);
	printf("Après: \n");
	lire(vc);
}

void test_changerMilieu(){

	Vecteurcreux vc;
	init(&vc, 7);
	printf("-->test_changerMilieu()\n");

	for(int i=3;i>=1;i--){
		ajouter(&vc, 2*i, 1);
	}
	printf("Avant: \n");
	lire(vc);
	printf("Changement:\n");
	changer(&vc, 4, 200);
	printf("Après: \n");
	lire(vc);
}

void test_changerFin(){

	Vecteurcreux vc;
	init(&vc, 7);
	printf("-->test_changerFin()\n");

	for(int i=3;i>=1;i--){
		ajouter(&vc, 2*i, 1);
	}
	printf("Avant: \n");
	lire(vc);
	printf("Changement:\n");
	changer(&vc, 6, 200);
	printf("Après: \n");
	lire(vc);
}

void test_ajouterDebut(){

	Vecteurcreux vc;
	init(&vc, 7);
	printf("-->test_ajouterDebut()\n");

	for(int i=3;i>=1;i--){
		ajouter(&vc, 2*i, 1);
	}
	printf("Avant: \n");
	lire(vc);
	printf("Changement:\n");
	changer(&vc, 1, 200);
	printf("Après: \n");
	lire(vc);
}


void test_ajouterMilieu(){

	Vecteurcreux vc;
	init(&vc, 7);
	printf("-->test_ajouterMilieu()\n");

	for(int i=3;i>=1;i--){
		ajouter(&vc, 2*i, 1);
	}
	printf("Avant: \n");
	lire(vc);
	printf("Changement:\n");
	changer(&vc, 3, 200);
	printf("Après: \n");
	lire(vc);
}

void test_ajouterFin(){

	Vecteurcreux vc;
	init(&vc, 7);
	printf("-->test_ajouterFin()\n");

	for(int i=3;i>=1;i--){
		ajouter(&vc, 2*i, 1);
	}
	printf("Avant: \n");
	lire(vc);
	printf("Changement:\n");
	changer(&vc, 7, 200);
	printf("Après: \n");
	lire(vc);
}

void test_saisir(){
	
	Vecteurcreux vc;
	
	printf("-->Fonction test_saisir()\n");
	printf("Saississez un vecteur :\n");
	saisir(&vc);
	printf("Vous avez saisi le vecteur :\n");
	lire(vc);
	
}

void test_norme(){
	
	Vecteurcreux vc;
	
	printf("Entrez un vecteur :\n");
	saisir(&vc);
	lire(vc);
	printf("La norme de ce vecteur est %Lf\n", norme(vc));

}

void test_somme(){
	
	Vecteurcreux v1;
	Vecteurcreux v2;
	
	printf("Entrez le premier vecteur :\n");
	saisir(&v1);
	lire(v1);
	printf("Entrez le deuxième vecteur :\n");
	saisir(&v2);
	lire(v2);
	printf("La somme de ces 2 vecteurs est :\n");
	lire(somme(v1, v2));

}

void test2_Somme() 
{ 
     
    //vecteur u 
     
   	Vecteurcreux m, w, c;
	init(&m, 2);
	init(&w, 2);
	init(&c, 3);
	 
   	ajouter(&m,4,4);
	ajouter(&m, 1, 1); 
	
	lire(m); 
     
   	ajouter(&w,3,3); 
   	ajouter(&w,1,1); 
	
	lire(w);
	
	c = somme(m,w);
     
	lire(c);
}

/* -------------------------------------------------------------*
 * Creation d'un jeu de tests dans le framework Seatest         *
 * Ici vous pouvez lancer un ensemble de tests a partir des     *
 * SP de test d√©finis ci-avant                                  *
 * -------------------------------------------------------------*/
void jeuTestGeneral(void)
{/*
	test_fixture_start();      
	run_test(test_init);
	run_test(test_ajouter);
	run_test(test_valeur);
	run_test(test_changer);
	test_fixture_end();*/
}

void jeuTestChanger(void)
{
	test_fixture_start();      
	
	run_test(test_changerDebut);
	run_test(test_changerMilieu);
	run_test(test_changerFin);
	run_test(test_ajouterDebut);
	run_test(test_ajouterMilieu);
	run_test(test_ajouterFin);
	
	test_fixture_end();
}

 // ... on peut definir plusieurs jeux de test si besoin ..


/* -------------------------------------------------------------*
 * Lancement de tous les jeus de test                           *
 * -------------------------------------------------------------*/
void all_tests( void )
{
	run_test(jeuTestChanger);
}

/* -------------------------------------------------------------*
 * Main qui lance tous les tests                                *
 * -------------------------------------------------------------*/
int main()
{
	run_tests(test_valeur);	
	return 0;
}
