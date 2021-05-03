CLASSDIR = /home/bedirhan/Desktop/sistemProgramlama_Proje/Odev
INCLUDE = -I$(CLASSDIR)/include
CFLAGS = $(INCLUDE)
LIBS = $(CLASSDIR)/lib/libfdr.a
CC = gcc

EX =\
	bin/odev\
	
all: $(EX) 
clean: 
	rm -f $(EX) *.o

bin/odev: src/odev.c
	$(CC) $(CFLAGS) -o bin/odev src/odev.c $(LIBS)



