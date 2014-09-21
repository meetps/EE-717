#include <iostream>
using namespace std;
#include <math.h>
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
  // if((priority[pos] >= priority[pos*2] && pos*2 < last )  || (priority[pos] >= priority[(pos*2)+1] && ((pos*2)+1 < last ) ))
  // {
      // if(priority[pos] >= priority[pos*2])
// 
         int temp, left, right, recursiveHeapify;

    left = 2*pos; // get the left child
    right = 2*pos+1; // get the right child

    if((left <= last) && (priority[left] < priority[pos]))
        recursiveHeapify = left;
    else recursiveHeapify = pos;
    if((right <= last) && (priority[right] < priority[recursiveHeapify]))
        recursiveHeapify = right;
    if(recursiveHeapify != pos) // one of the two child nodes has proved 
                     // larger than priority[i], so interchange values
    {
        //swap parent with left child
        temp = priority[pos];
        priority[pos] = priority[recursiveHeapify];
        priority[recursiveHeapify] = temp;

        Heapify(recursiveHeapify);
  }
}

int getParent(int position)
{
    int level = log2(position);
    int diff  = position - pow(2,level);
    int parent = pow(2,level-1) + diff/2;
    return parent;
}

void Heap::insertHeap(int x) 
{
/*Fill in the functionality for inserting elements into a heap. The heap is stroed in an array called 
priority*/
int child = last+1; 
int level = log2(last+1);
int temp = 0;
priority[last+1] = x;

    for(int j =1; j <= level; j++)
    {   
        if(priority[getParent(child)] >  x)
        {
          temp = priority[child]; 
          priority[child] = priority[getParent(child)];
          priority[getParent(child)] = temp;
          child = getParent(child);     
        }
        else
        {
          priority[child] = x;
          break;
        }
    }


last = last +1;    
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

