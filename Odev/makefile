CLASSDIR = /home/dogukhan/Desktop/Odev
INCLUDE = -I$(CLASSDIR)/libfdr
LIBS = $(CLASSDIR)/libfdr/libfdr.a
CC = gcc
OBJS = $(CLASSDIR)/libfdr/dllist.o $(CLASSDIR)/libfdr/fields.o $(CLASSDIR)/libfdr/jval.o $(CLASSDIR)/libfdr/jrb.o
CFLAGS = -O

EX = libfdr.a	odev	clean
all: $(EX) 

clear:
	rm	-f	$(EX)

clean: 
	rm -f *.o
	rm -f core $(CLASSDIR)/libfdr/*.o $(CLASSDIR)/libfdr/libfdr.a

libfdr.a: $(OBJS)
	ar ru $(CLASSDIR)/libfdr/libfdr.a $(OBJS)
	ranlib $(CLASSDIR)/libfdr/libfdr.a 

odev: odev.o $(LIBS)
	$(CC) $(INCLUDE) -o odev odev.o $(LIBS)

odev.o:
	$(CC) $(INCLUDE) -g  -c  odev.c

dllist.o:
	$(CC) $(CFLAGS) -c $(CLASSDIR)/libfdr/dllist.c

fields.o:
	$(CC) $(CFLAGS) -c $(CLASSDIR)/libfdr/fields.c

jval.o:
	$(CC) $(CFLAGS) -c $(CLASSDIR)/libfdr/jval.c

jrb.o:
	$(CC) $(CFLAGS) -c $(CLASSDIR)/libfdr/jrb.c

