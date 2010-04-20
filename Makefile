## These are the configurable variables. #############################

SHELL= /bin/bash
   CC= /usr/bin/g++
   AR= /usr/bin/ar
FLAGS= -Wall -I./ -L./
  BIN= templar
  LIB= templar

## Do not edit anything below this marker. ###########################

TLIBS= -ltesseract_full -lpthread -ltiff -ljpeg -lz -lmysqlpp

$(BIN): lib$(LIB).a templar.hpp main.cpp
	$(CC) $(FLAGS) -static main.cpp -l$(LIB) $(TLIBS) -o $(BIN)

lib$(LIB).a: templar.o ocrengine.o dbaccess.o
	$(AR) r lib$(LIB).a templar.o ocrengine.o dbaccess.o
	rm templar.o ocrengine.o dbaccess.o

templar.o: templar.hpp templar.cpp
	$(CC) $(FLAGS) -c templar.cpp

ocrengine.o: ocrengine.hpp ocrengine.cpp
	$(CC) $(FLAGS) -c ocrengine.cpp

dbaccess.o: dbaccess.hpp dbaccess.cpp
	$(CC) $(FLAGS) -c dbaccess.cpp

reset:
	rm -f {*.{o,a},$(BIN)}

## This is here because it looks pretty. #############################
