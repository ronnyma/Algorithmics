CC=/usr/bin/clang
CFLAGS = -I.

entry: entry.c entry.h binary_tree.o avl_tree.o tree.o
	$(CC) $(CFLAGS) entry.c tree.c binary_tree.c avl_tree.c -o entry

binary_tree.o: binary_tree.c binary_tree.h
	$(CC) -c binary_tree.c

avl_tree.o: avl_tree.c
	$(CC) -c avl_tree.c

tree.o: tree.c
	$(CC) -c tree.c
clean:
	rm -v entry
