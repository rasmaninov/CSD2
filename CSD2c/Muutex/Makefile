# Makefile for thread examples with C++ 11
#
CPP = g++ --std=c++11
CFLAGS = -Wall
LDFLAGS = -lpthread

MSGQOBJ = msgqueue.o

all: msgqueue

msgqueue: $(MSGQOBJ)
	$(CPP) -o $@ $(CFLAGS) $(MSGQOBJ) $(LDFLAGS)

.cpp.o:
	$(CPP) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f `find . -perm /111 -type f`
