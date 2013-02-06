CC=g++
CFLAGS=-Wall -O2 -fPIC -pedantic -ansi -Wextra -pipe  -std=c++11
LFLAGS=-shared -ltag
INC=-I/usr/include/lua5.2 -I/usr/local/include/taglib

all: ../lib/taglib.so

../lib/taglib.so: taglib.o
		$(CC) taglib.o $(LFLAGS) -o ../lib/taglib.so

taglib.o: taglib.cpp
		$(CC) $(CFLAGS) $(INC) -c taglib.cpp -o taglib.o

clean:
		rm -rf *.o ../lib/*.so
