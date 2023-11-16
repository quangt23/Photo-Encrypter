CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
DEPS = test.o LinearFSR.o
OBJECTS = Encrypt.o LinearFSR.o main.o

all: Encrypt Encrypt.a test
Encrypt.a: LinearFSR.o Encrypt.o
	ar rcs Encrypt.a LinearFSR.o Encrypt.o
LinearFSR.o: LinearFSR.cpp
	$(CC) $(CFLAGS) -c LinearFSR.cpp -o LinearFSR.o
test: $(DEPS)
	$(CC) $(CFLAGS) -o test $(DEPS) $(LIB) 
test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp
Encrypt: $(OBJECTS)
	$(CC) $(CFLAGS) -o Encrypt $(OBJECTS) $(LIB)
Encrypt.o: Encrypt.cpp Encrypt.hpp
	$(CC) $(CFLAGS) -c Encrypt.cpp -o Encrypt.o $(LIB)
main.o: main.cpp Encrypt.hpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o $(LIB)
clean:
	rm Encrypt test *.o Encrypt.a