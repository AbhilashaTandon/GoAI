G++ = /usr/bin/g++
FLAGS = -O2 -g -Wall -c -Wpedantic -Wextra --std=c++17

runtest rt: all
	./StellaGo.exe -size 9 -iter 3

run r: all
	./StellaGo.exe 

all compileall compile ca:
	$(G++) $(FLAGS) -o AI.o AI.cpp
	$(G++) $(FLAGS) -o Game.o Game.cpp
	$(G++) $(FLAGS) -o main.o main.cpp
	$(G++) $(FLAGS) -o Board.o Board.cpp
	$(G++) -o "StellaGo.exe" AI.o Board.o Game.o main.o


