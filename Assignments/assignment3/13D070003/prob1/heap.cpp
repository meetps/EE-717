#include <iostream>
using namespace std;
#include "heap.h"

Heap::Heap(int size){
//create a heap of size+1 positions. 0th position is unused.
	priority = new int[size+1];
}

Heap::~Heap()
{
	delete []priority;
	priority = NULL;
}

void Heap::createHeap() {
//upon creation, no elements are in the heap
   last = 0;
}

int Heap::empty() {
  if (last == 0)
    return(1);
  else
    return(0);
}


int Heap::deleteMin() 
{
  int item;
  
  if (last < 1)
  	return(-10000);
  item = priority[1];

  priority[1] = priority[last];
  last = last - 1;
  
  Heapify(1);
  return(item);
}

/*DO NOT EDIT BEFORE THIS LINE*/
void Heap::Heapify(int pos)
{
/*Fill in the functionality to perform Heapify() operation on the array priority[] at position pos*/
}
void Heap::insertHeap(int x) 
{
/*Fill in the functionality for inserting elements into a heap. The heap is stroed in an array called 
priority*/

}

/*DO NOT EDIT AFTER THIS LINE*/

/*If you need to, call this function to see if the heap is being built properly and operated properly*/
void Heap::printHeap()
{
	int i=1;
	while(i<=last){
		cout << priority[i++] << " ";
	}
	cout<<endl;
}

