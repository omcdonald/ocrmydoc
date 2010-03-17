# These are the configurable variables. #############################

SHELL= /bin/sh
   CC= /usr/bin/g++
FLAGS= -Wall -I. -L.
  BIN= templar

## Do not edit anything below this marker. ###########################

main: main.cpp libtemplar.a
	$(CC) $(FLAGS) -o $(BIN) main.cpp -ltemplar
	chmod u+x $(BIN)
	rm *.o
libtemplar.a: libtemplar.o
	ar -cvq libtemplar.a libtemplar.o
libtemplar.o: sax.o templar.o
	$(CC) $(FLAGS) -o libtemplar.o -c sax.o templar.o \
					-ltesseract_full -lpthread -ltiff
templar.o: sax.hpp templar.hpp templar.cpp
	$(CC) $(FLAGS) -c templar.cpp 
sax.o: sax.hpp sax.cpp
	$(CC) $(FLAGS) -c sax.cpp

## This is here because it looks pretty. #############################
