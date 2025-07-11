hepsi: derle calistir

derle: 
	g++ -I ./include/ -o ./lib/board.o -c ./src/board.cpp
	g++ -I ./include/ -o ./lib/cell.o -c ./src/cell.cpp
	g++ -I ./include/ -o ./lib/game.o -c ./src/game.cpp
	g++ -I ./include/ -o ./bin/main ./lib/board.o ./lib/cell.o ./lib/game.o ./src/main.cpp
calistir:
	./bin/main