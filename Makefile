#Makefile Génerique / Etienne PENAULT

OBJS	= main.o methode3old.o texts.o
OUT	= ProjetAS1
CC	 = g++
FLAGS	 = -O3 -c -std=c++17 -Wall

all: $(OBJS)
	$(CC) $(OBJS) -o $(OUT)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

methode3old.o: methode3old.cpp
	$(CC) $(FLAGS) methode3old.cpp

texts.o: texts.cpp
	$(CC) $(FLAGS) texts.cpp	
	
clean:
	rm $(OBJS) $(OUT)