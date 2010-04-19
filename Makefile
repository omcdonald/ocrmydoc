## These are the configurable variables. #############################
 
SHELL= /bin/bash
   CC= /usr/bin/g++
   AR= /usr/bin/ar
FLAGS= -Wall -I./ -L./
  BIN= templar
  LIB= templar
 
## Do not edit anything below this marker. ###########################

TLIBS= -ltesseract_full -lpthread -ltiff -ljpeg -lz

$(BIN): lib$(LIB).a templar.hpp main.cpp
	$(CC) $(FLAGS) -static main.cpp -l$(LIB) $(TLIBS) -o $(BIN)
	chmod u+x $(BIN)

lib$(LIB).a: templar.o sax.o
	$(AR) r lib$(LIB).a templar.o sax.o
	rm {templar,sax}.o

templar.o: templar.hpp templar.cpp
	$(CC) $(FLAGS) -c templar.cpp

sax.o: sax.hpp sax.cpp
	$(CC) $(FLAGS) -c sax.cpp

reset:
	rm -f {*.{o,a},$(BIN)}
 
## This is here because it looks pretty. #############################
