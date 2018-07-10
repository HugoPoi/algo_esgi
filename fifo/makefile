IDIR =.
CC=gcc
CFLAGS=-Wall -Werror -I$(IDIR)

ODIR=obj
LDIR =.

LIBS=-lm

_DEPS = main.c
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o fifo.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

fifo: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~INCDIR
