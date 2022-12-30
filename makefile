#MAKEFILE NICOLAS CHATAIGNON

OS=linux
ifeq ($(OS), win)
	SUPP=del
else
	SUPP=rm
endif

# creer un rep 'sauvegarde' s'il n'existe pas déjà:
$(shell test ! -e sauvegarde && mkdir sauvegarde)



# VARIABLES
CC=gcc
CCX=g++

EXEC=prog

ARCHIVE=sortie.zip

#CFLAGS= -Wall # WARNINGS ALL



# Identifier tous les fichiers .c
SRC=$(wildcard *.c)

# Créer une liste des fichiers .o liée à la liste des fichiers .c
OBJ=$(SRC:.c=.o)

# LABELS : 

all:$(EXEC)

$(EXEC): $(OBJ)
	# $@ : cible , ici le $(EXEC) qui vaut prog
	# $^ : liste des dépendances , ici tous les .o
	$(CC) -o $@ $^ $(CFLAGS) 


# %.o : tous les .o ; %.c : tousl es .c
%.o:%.c
	# $@ : cible ; $< : première dépendance
	$(CC) -o $@ -c $< $(CFLAGS)



# main.o:main.c
# 	$(CC) -o main.o -c main.c $(CFLAGS)

# fonctions.o:fonctions.c
# 	$(CC) -o fonctions.o -c fonctions.c $(CFLAGS)



clean:
	rm -rf *.o

mrproper:clean
	$(SUPP) -rf $(EXEC) $(ARCHIVE)
	$(SUPP) -rf sauvegarde 

zip:
	zip -r $(ARCHIVE) *.h *.c 
