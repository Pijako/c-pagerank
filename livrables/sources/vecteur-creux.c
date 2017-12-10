/*******************************************************************************
 *  Auteur   : tpichel
 *  Objectif : Implantation des vecteurs creux
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "vecteur-creux.h"

void init(Vecteurcreux *v, int dimension){

	v->dimension = dimension;
	v->premier = NULL;

}

void detruire(Vecteurcreux *v){

	free(v);

}

void ajouter(Vecteurcreux *v, Indice indice, Valeur valeur){
	//assert(indice < v->premier->indice);
	assert(indice >= 0);
	assert (v != NULL);
  
	if(v->premier == NULL){
		Couple *v1 = malloc(sizeof(Couple));
		v1->indice = indice;
		v1->valeur = valeur;
		v1->suivant = NULL;
		v->premier = v1;
	}

	else{
		Couple *v2 = malloc(sizeof(Couple));
		v2->indice = indice;
		v2->valeur = valeur;
		v2->suivant = v->premier;
		v->premier = v2;
	}  
}
/*
void ajouter(Vecteurcreux *v, Indice indice, Valeur valeur){
	assert(indice >= 0);
	assert(indice <= v->dimension);
	assert (v != NULL);
	
	if(v->premier == NULL){
		Couple *nouveau1 = malloc(sizeof(Couple));
		nouveau1->indice = indice;
		nouveau1->valeur = valeur;

		nouveau1->suivant = NULL;
		v->premier = nouveau1;
	}

	else{
		assert(indice < v->premier->indice);
		Couple *nouveau2 = malloc(sizeof(Couple));
		nouveau2->indice = indice;
		nouveau2->valeur = valeur;

		nouveau2->suivant = v->premier;
		v->premier = nouveau2;
	}	
}
*/
long double norme(Vecteurcreux v){

	Couple *tmp;
	tmp = v.premier;
	long double norme = 0;
	int fin = 0;

	while(fin == 0){
		norme = norme + (tmp->valeur)*(tmp->valeur);
		if(tmp->suivant != NULL){
			tmp = tmp->suivant;
		}
		else{
			fin = 1;
		}
	}
	
	printf("\n");
	norme = sqrt(norme);

	return norme;
}

long double valeur(Vecteurcreux v, Indice indice){

	Couple *tmp = v.premier;
	long double result = 0;
	int fin = 0;

	while(fin != 1){
		if(tmp->indice == indice){
			result = tmp->valeur;
			fin = 1;
		}
		else if( (tmp->indice != indice) && (tmp->suivant != NULL) ){
			tmp = tmp->suivant;
		}
		else if(tmp->suivant == NULL){
			fin = 1;
			result = 0;
		}
	}

	return result;
}

long double scalaire(Vecteurcreux v, Vecteurcreux u)
{
	assert (v.dimension=u.dimension); 

	long double resultat = 0;
	Couple *tmp1 = v.premier;
	Couple *tmp2 = u.premier;

	while( (tmp1!=NULL) && (tmp2!=NULL) ){

		if (tmp1->indice<tmp2->indice) {
			tmp1=tmp1->suivant;
		}

		else if( tmp1->indice>tmp2->indice) {
			tmp2=tmp2->suivant;
		}

		else{
			resultat=resultat+(tmp1->valeur)*(tmp2->valeur);
			tmp1=tmp1->suivant;
			tmp2=tmp2->suivant;
		}
	}

	return resultat;
}

double scalaire_iteratif(Vecteurcreux v1, Vecteurcreux v2){
	assert(v1.dimension == v2.dimension);

	Couple *tmp1 = v1.premier;
	Couple *tmp2 = v2.premier;
	double ps = 0;

	while(tmp1 != NULL){
		ps = ps + (tmp1->valeur)*(tmp2->valeur);
		tmp1 = tmp1->suivant;
		tmp2 = tmp2->suivant;
	}
	return ps;
}

/* double scalaire_recursif(Vecteurcreux v1, Vecteurcreux v2){
	assert(v1.dimension == v2.dimension);

	Vecteurcreux tmp1 = v1;
	Vecteurcreux tmp1 = v1;
	double ps = 0;	
	
	tmp1 = v1.premier->suivant;
	tmp2 = v2.premier->suivant;
	tmp1.dimension--;
	tmp2.dimension--;

	return ps + scalaire_recursif(tmp1, tmp2);

} */

Vecteurcreux somme(Vecteurcreux v1, Vecteurcreux v2){
	assert(v1.dimension == v2.dimension);

	Couple *tmp1 = v1.premier;
	Couple *tmp2 = v2.premier;

	Couple *somme = malloc(v1.dimension*sizeof(Couple));
	
	int i = 0;
	int fin = 0;
	Vecteurcreux result;

	while(fin == 0){
		
		if( (tmp1->indice == tmp2->indice) && (tmp1->indice == i+1) ){
			
			somme[i].indice = tmp1->indice;
			somme[i].valeur = tmp1->valeur + tmp2->valeur;
			printf("i = %d , v1 et v2 non nuls, on somme l'indice %d %Lf\n", i, somme[i].indice, somme[i].valeur);
			
			if(tmp1->suivant != NULL){
				tmp1 = tmp1->suivant;
				tmp2 = tmp2->suivant;
			}
			else{
				printf("On fini 1\n");
				fin = 1;
			}
			i++;
			
		}
		else if( (tmp1->indice < tmp2->indice) && (tmp1->indice == i+1) ){
			
			somme[i].indice = tmp1->indice;
			somme[i].valeur = tmp1->valeur;
			
			printf("i = %d, v2 est nul et la somme vaut %Lf\n", i, somme[i].valeur);
			
			if(tmp1->suivant != NULL){
				tmp1 = tmp1->suivant;
			}
			else{
				printf("On fini 2\n");
				fin = 1;
			}
			i++;
		}
		else if( (tmp1->indice > tmp2->indice) && (tmp2->indice == i+1) ){
			
			somme[i].indice = tmp2->indice;
			somme[i].valeur = tmp2->valeur;
			printf("i = %d, v1 est nul et la somme vaut %Lf\n", i, somme[i].valeur);
			
			if(tmp2->suivant != NULL){
				tmp2 = tmp2->suivant;
			}
			else{
				printf("On fini 3\n");
				fin = 1;
			}
			i++;
		}
		else if( (tmp1->indice > i+1) && (tmp2->indice > i+1) ){
			printf("i = %d, les deux sont nuls\n", i);
			i++;
		}
		
	}
	init(&result, v1.dimension);

 	for(int j=i-1;j>=0;j--){
		if(somme[j].indice > 0){
 			ajouter(&result, somme[j].indice, somme[j].valeur);
			printf("v1 et v2 non nuls, on rentre l'indice %d %Lf\n", somme[j].indice, somme[j].valeur);
		}
		else{
			printf("Trou pour i = %d\n", j);
		}
 	}
	
	return result;
	free(somme);
}

void changer(Vecteurcreux *v, Indice indice, Valeur valeur){
	assert(indice <= v->dimension);
	Couple *tmp = v->premier;
	
	//Si le couple n'existe pas et se trouve avant le début
	if(indice < tmp->indice){
		printf("Cas 1\n");
		Couple *nouveau = malloc(sizeof(Couple));
		nouveau->indice = indice;
		nouveau->valeur = valeur;
		nouveau->suivant = v->premier;
		v->premier = nouveau;
	}
	//Sinon, on parcourt la liste chaînée jusqu'à l'indice recherché ou juste un cran avant
	else{	
		while((tmp->suivant != NULL) && (tmp->suivant->indice <= indice)){
			printf("Indice %d\n", tmp->indice);
			tmp = tmp->suivant;
		}
		//Si le couple est déjà existant, on change sa valeur
		if(tmp->indice == indice){
			printf("Cas 2\n");
			tmp->valeur = valeur;
		}
	
		//Si le couple n'existe pas et se trouve avant la fin de la dernière valeur, on rajoute un nouvel élément
		if( (tmp->suivant != NULL) && (tmp->indice > indice) ){
			printf("Cas 3\n");
			Couple *nouveau = malloc(sizeof(Couple));
			nouveau->indice = indice;
			nouveau->valeur = valeur;
			nouveau->suivant = tmp->suivant;
			tmp->suivant = nouveau;
		}
	
		//Si le couple n'existe pas et se trouve après la dernière valeur, on le rajoute aussi
		if( (tmp->suivant == NULL) && (tmp->indice < indice) ){
			printf("Cas 4\n");
			Couple *nouveau = malloc(sizeof(Couple));
			nouveau->indice = indice;
			nouveau->valeur = valeur;
			tmp->suivant = nouveau;
			nouveau->suivant = NULL;
		}
	}
}

void saisir(Vecteurcreux *v){

	int dim = 0;
	int i = 0;
	int fin = 0;
	Indice indice;

	Couple *couples = malloc(sizeof(Couple));

	while(fin == 0){
		
		scanf("%d", &indice);
		
		if(indice < 0){
			break;  
		}
		else if(indice > 0){
			couples[i].indice = indice;
			scanf("%Lf", &couples[i].valeur);
			i++;
			couples = realloc(couples, sizeof(Couple));
		}
	}
	i--;
	dim = couples[0].indice;
	init(v, dim);
	printf("Dimension : %d\n", dim);
	for(int j=0;j<=i;j++){
		if(couples[j].indice > 0){
			printf("On rentre %d %Lf\n", couples[j].indice, couples[j].valeur);
			ajouter(v, couples[j].indice, couples[j].valeur);
		}
		else{
			printf("Trou pour i = %d\n", j);
		}
		
	}
	printf("Saisie terminée\n");
	free(couples);

}

int lire(Vecteurcreux v){

	Couple *tmp = v.premier;
	int result = 0;

	if(v.premier == NULL){
		printf("Le vecteur est vide !\n");
		result = 0;
	}
	else{
		while(tmp != NULL){
			printf("[%d , %Lf] --> ", tmp->indice, tmp->valeur);
			tmp = tmp->suivant;
			result++;
		}
		printf("NULL\n");
	}
	return result;
}
