## TODO : adapter

CPP=g++
EXE = analog

DEBUG= no
ifeq ($(DEBUG),yes)
	CPPFLAGS = -DMAP -ansi -pedantic -Wall -std=c++11 -g
else 
	CPPFLAGS = -ansi -pedantic -Wall -std=c++11 -g
endif

VALGRINDFLAGS = --leak-check=full
ECHO= @echo
RM = rm 
EFFACE = clear
SRC= Analog.cpp Graph.cpp LogRead.cpp
OBJ= $(SRC:.cpp=.o)

#éditions des liens
$(EXE) : $(OBJ)
ifeq ($(DEBUG),yes)
	$(ECHO) "edition des liens en mode debug"
else 
	$(ECHO) "edition des liens"
endif
	$(CPP) -o $@ $^

#compilation
%.o : %.cpp %.h
	$(ECHO) "compilation de $<"
	$(CPP) -c $< $(CPPFLAGS)

.PHONY : clean memcheck run map

#suppression de tous les fichiers compilés
clean :
	$(EFFACE)
	$(ECHO) "suppression des fichiers compilés"
	$(RM) $(OBJ)
	$(RM) $(EXE)

#compile les fichiers modifiés et execute le programme en suivant l'état de la mémoire
memcheck :
	make
	valgrind $(VALGRINDFLAGS) ./$(EXE) 

#execute le programme
run :
	make
	./$(EXE)

#compilation en mode debug
map : 
	make DEBUG=yes