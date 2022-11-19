prog : liste_electorale.o main.o
	gcc liste_electorale.o main.o -o prog -g

main.o: main.c
	gcc -c main.c -g

liste_electorale: liste_electorale.c
	gcc -c liste_electorale.c -g


