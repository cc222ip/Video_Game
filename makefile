CC=g++
std=-std=c++11
CFLAG=-Wall -pedantic
DEBUG=-g
EXE=TheGame

ifeq ($(OPTIM),oui)
	MODEOPTIM=-O
else
	MODEOPTIM=
endif

all : $(EXE)

$(EXE) : Main.o Fight.o Ability.o Character.o Map.o Config.o Inventory.o Game.o
	$(CC) $(std) -o $(EXE) Main.o Fight.o Ability.o Character.o Map.o Config.o Inventory.o Game.o $(CFLAG) $(DEBUG) $(MODEOPTIM)

Main.o : Main.cpp Config.h Game.h Character.h  Inventory.h Fight.h Map.h
	$(CC) $(std) -c Main.cpp $(CFLAG) $(DEBUG) $(MODEOPTIM)

Fight.o : Fight.cpp Fight.h
	$(CC) $(std) -c Fight.cpp $(CFLAG) $(DEBUG) $(MODEOPTIM)

Ability.o : Ability.cpp Ability.h
	$(CC) $(std) -c Ability.cpp $(CFLAG) $(DEBUG) $(MODEOPTIM)

Character.o : Character.cpp Ability.h Inventory.h
	$(CC) $(std) -c Character.cpp $(CFLAG) $(DEBUG) $(MODEOPTIM)

Map.o : Map.cpp Map.h
	$(CC) $(std) -c Map.cpp $(CFLAG) $(DEBUG) $(MODEOPTIM)

Config.o : Config.cpp Config.h
	$(CC) $(std) -c Config.cpp $(CFLAG) $(DEBUG) $(MODEOPTIM)

Inventory.o : Inventory.cpp Inventory.h
	$(CC) $(std) -c Inventory.cpp $(CFLAG) $(DEBUG) $(MODEOPTIM)

Game.o : Game.cpp Game.h
	$(CC) $(std) -c Game.cpp $(CFLAG) $(DEBUG) $(MODEOPTIM)

clean :
	rm -rf *.o

mrproper: clean
	rm -rf $(EXE)
