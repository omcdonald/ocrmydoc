## These are the configurable variables. #############################

SHELL= /bin/bash
   CC= /usr/bin/g++
FLAGS= -Wall -I./ -L./
  BIN= templar
 
## Do not edit anything below this marker. ###########################

main: main.cpp libtemplar.a
	$(CC) $(FLAGS) -o $(BIN) -ltemplar main.cpp 
	chmod u+x $(BIN)
	rm *.o
libtemplar.a: templar.o
	ar rc libtemplar.a templar.o
templar.o: sax.hpp sax.cpp templar.hpp templar.cpp
	$(CC) $(FLAGS) -ltesseract_full -lpthread -ltiff -c templar.cpp
reset:
	rm -f {*.{o,a},$(BIN)}

## This is here because it looks pretty. #############################
