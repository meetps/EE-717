all: treetraversal

bst.o: bst.h bst.cpp
	g++ bst.cpp -c -o bst.o

treetraversal.o: treetraversal.cpp
	g++ treetraversal.cpp -c -o treetraversal.o

treetraversal: treetraversal.o bst.o
	g++ bst.o treetraversal.o -o treetraversal


clean:
	rm -f *~ *.o treetraversal
