test: main.o bear.o board.o card.o cat.o cow.o dog.o elephant.o frog.o giraffe.o goblin.o hedgehog.o pig.o rabbit.o
	g++ main.o bear.o board.o card.o cat.o cow.o dog.o elephant.o frog.o giraffe.o goblin.o hedgehog.o pig.o rabbit.o -o test

main.o: main.cpp animals.h board.h card.h
	g++ -c main.cpp -std=c++14

bear.o: bear.cpp animals.h
	g++ -c bear.cpp -std=c++14

board.o: board.cpp board.h
	g++ -c board.cpp -std=c++14

card.o: card.cpp card.h
	g++ -c card.cpp -std=c++14

cat.o: cat.cpp animals.h
	g++ -c cat.cpp -std=c++14

cow.o: cow.cpp animals.h
	g++ -c cow.cpp -std=c++14

dog.o: dog.cpp animals.h
	g++ -c dog.cpp -std=c++14

elephant.o: elephant.cpp animals.h
	g++ -c elephant.cpp -std=c++14

frog.o: frog.cpp animals.h
	g++ -c frog.cpp -std=c++14

giraffe.o: giraffe.cpp animals.h
	g++ -c giraffe.cpp -std=c++14

goblin.o: goblin.cpp animals.h
	g++ -c goblin.cpp -std=c++14

hedgehog.o: hedgehog.cpp animals.h
	g++ -c hedgehog.cpp -std=c++14

pig.o: pig.cpp animals.h
	g++ -c pig.cpp -std=c++14

rabbit.o: rabbit.cpp animals.h
	g++ -c rabbit.cpp -std=c++14

clean:
	rm *.o test