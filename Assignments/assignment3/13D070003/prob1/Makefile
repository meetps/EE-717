all: heapsort

heap.o: heap.h heap.cpp
	g++ heap.cpp -c -o heap.o

heapsort.o: heapsort.cpp
	g++ heapsort.cpp -c -o heapsort.o

heapsort: heap.o heapsort.o
	g++ heap.o heapsort.o -o heapsort


clean:
	rm -f *~ *.o heapsort
