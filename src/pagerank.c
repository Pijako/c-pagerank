/*******************************************************************************
 *  Auteur   : gscotto tpichel
 *  Objectif : Implantation des vecteurs creux
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#include "vecteur-creux.h"
#include "matrice-creuse.h"

int main (int argc , char **argv) 
{
	int i=1;
	long double alpha;
	int it;
	char *nom;
	
	FILE* fichier = NULL;
	
	int *p;
	Matricecreuse m;
	Vecteurcreux pi0, pi;
	
	if ( (strlen(argv[i]))%2 != 0 ) {
		assert((strlen(argv[i]))%2 == 0);
	}
	
	if(argc == 2){
		
		alpha = 0.85;
		it = 150;
		fichier = fopen (argv[1], "r");
		
		if(fichier == NULL){
			printf("Fichier non valide ou inexistant\n");
			assert(fichier != NULL);
		}
	}
	
	else{
		fichier = fopen(argv[argc], "r");
		
		if(fichier == NULL){
			printf("Fichier non valide ou inexistant\n");
			assert(fichier != NULL);
		}
		
		if (argv[i][0]=='-') {
			if (strlen(argv[i])!=2) {
				printf("on attends un I ou un A après un - \n");
			}
			
			switch (argv[i][1]){
				
				case 'I':
					sscanf(argv[i+1],"%d",&it);
					printf("Nombre d'Itérations = %d\n" , it);
					break;
					
				case 'A':
					printf("Vous devez rentrer le nb d'itérations avant la valeur alpha \n");
					break;
					
				default:
					printf("Vous devez rentrer un entier après un tiret");
					break;
			}
		}
		
		if (argv[i+2][0]=='-') {
			if (strlen(argv[i+2])!=2) {
				printf("on attends un I ou un A après un - \n");
			}
			switch (argv[i+2][1]){
				case 'A':
					alpha = atof(argv[i+3]);
					//sscanf(argv[i+2],"%f",&alpha);
					printf("alpha = %Lf\n\n", alpha );
					break;
				case 'I':
					printf("vous devez rentrer le nb d'itérations avant la valeur alpha \n");
					break;
				default:
					printf("vous devez rentrer un entier après un tiret \n");
					break;
			}
		}
	}		
	
	p = initm_file(&m, fichier);
	long double N = m.dimension;
	printf("Matrice H :\n");
	lirem(m);
	init(&pi0, N);
	init(&pi, N);

	for(int i=N-1;i>=0;i--){
		ajouter(&pi0, i, 1/N);
	}
	
	printf("\nVecteur Pi0:\n");
	lire(pi0);
	printf("\n-->Lancement des itérations\n");	

	pi = produit_matriciel_mutant(m, pi0, alpha, p);
	for(int i=1;i<=it;i++){
		pi = produit_matriciel_mutant(m, pi, alpha, p);
	}
	printf("Vecteur Pi approché\n");
	lire(pi);
	trier_pages(pi, N);
	printf("\n-->Fichiers sauvegardés\n");

	return 0;
}


