CLASSDIR = /home/dogukhan/Desktop/Odev
INCLUDE = -I$(CLASSDIR)/include
LIBS = $(CLASSDIR)/lib/libfdr.a
CC = gcc

EX = odev
all: $(EX) 
clean: 
	rm -f $(EX) *.o

odev: odev.o $(LIBS)
	$(CC) $(INCLUDE) -o odev odev.o $(LIBS)


.SUFFIXES: .c .o

.c.o: 
	$(CC) $(INCLUDE) -g  -c  $*.c

