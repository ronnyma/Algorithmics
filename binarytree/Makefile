IDIR =include
CC=/usr/bin/clang
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =lib

LIBS=-lm

_DEPS = avl_tree.h binary_tree.h tree.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = avl_tree.o binary_tree.o tree.o entry.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	    $(CC) -c -o $@ $< $(CFLAGS)

entry: $(OBJ)
	    $(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	    rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

