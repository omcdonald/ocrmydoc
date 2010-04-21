## These are the configurable variables. #############################

  SHELL= /bin/bash
     CC= /usr/bin/g++
     AR= /usr/bin/ar
 CFLAGS= -Wall -I. -I/usr/local/include/tesseract \
         -I/usr/include/mysql -I/usr/include/mysql++
LDFLAGS= -L.
    BIN= templar
    LIB= templar

## Do not edit anything below this marker. ###########################

LIBS= -l$(LIB) -ltesseract_full `mysql_config --cflags` -lmysqlpp \
      `mysql_config --libs_r` -ltiff -ljpeg -lz -lpthread

(BIN): lib$(LIB).a templar.hpp main.cpp
	$(CC) $(CFLAGS) -static main.cpp $(LDFLAGS) $(LIBS) -o $(BIN)

lib$(LIB).a: templar.o ocrengine.o dbaccess.o
	$(AR) r lib$(LIB).a templar.o ocrengine.o dbaccess.o
	rm templar.o ocrengine.o dbaccess.o

templar.o: templar.hpp templar.cpp
	$(CC) $(CFLAGS) -c templar.cpp

ocrengine.o: ocrengine.hpp ocrengine.cpp
	$(CC) $(CFLAGS) -c ocrengine.cpp

dbaccess.o: dbaccess.hpp dbaccess.cpp
	$(CC) $(CFLAGS) -c dbaccess.cpp

reset:
	rm -f {*.{o,a},$(BIN)}

## End makefile. #####################################################
