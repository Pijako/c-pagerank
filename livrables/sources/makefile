pagerank :
					c99 -lm vecteur-creux.c matrice-creuse.c pagerank.c -o pagerank -Wall -pedantic
seatest-matrice-creuse :
					c99 -lm vecteur-creux.c matrice-creuse.c seatest.c seatest-matrice-creuse.c -o seatest-matrice-creuse -Wall -pedantic

clean:
					rm -rf *.o

#pagerank: pagerank.o matrice-creuse.o vecteur-creux.o
#			c99 -g -lm -o pagerank.o matrice-creuse.o vecteur-creux.o

#pagerank.o : pagerank.c matrice-creuse.o vecteur-creux.o matrice-creuse.h vecteur-creux.h
#			c99 -lm -o matrice-creuse.o vecteur-creux.o -c pagerank.c

#matrice-creuse.o: matrice-creuse.c vecteur-creux.o matrice-creuse.h vecteur-creux.h
#			c99 -lm -o matrice-creuse.o vecteur-creux.o -c matrice-creuse.c

#vecteur-creux.o: vecteur-creux.c vecteur-creux.h
#		c99 -lm -o vecteur-creux.o -c vecteur-creux.c

#seatest.o: seatest.c seatest.h
#		c99 -lm -o seatest.o -c seatest.c
