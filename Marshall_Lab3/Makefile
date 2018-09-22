Lab2: main.o Executive.o HashTableQP.o HashTableDH.o
	g++ -std=c++11 -g -Wall main.o Executive.o HashTableQP.o HashTableDH.o -o Lab2

main.o: main.cpp Executive.h HashTableQP.h HashTableDH.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

HashTableQP.o: HashTableQP.h HashTableQP.cpp
	g++ -std=c++11 -g -Wall -c HashTableQP.cpp

HashTableDH.o: HashTableDH.h HashTableDH.cpp
	g++ -std=c++11 -g -Wall -c HashTableDH.cpp



clean:
	rm *.o Lab2
