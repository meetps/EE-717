#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stack>

using namespace std;
#include "bst.h"

BinSearchTree* BinSearchTree::buildTree(BinSearchTree *tree, char letter){
  BinSearchTree *recursion = tree;
  if (tree == NULL) 
  {
    tree = new BinSearchTree (letter); 
  } 
  else 
  { 
	/*DO NOT EDIT BEFORE THIS LINE*/
	/*Make appropriate changes here to build a BST*/
	if(letter < recursion->symbol)
		{
			if(recursion->lChild != NULL)
			{
				recursion = recursion->lChild;
				buildTree(recursion , letter);
			}
			else
			{	
				BinSearchTree *ltree;
				ltree = new BinSearchTree(letter);
				recursion->lChild = ltree;
			}
		}

	else if(letter > recursion->symbol)
		{
			if(recursion->rChild != NULL)
			{
				recursion = recursion->rChild;
				buildTree(recursion , letter);
			}
			else
			{	
				BinSearchTree *rtree;
				rtree = new BinSearchTree(letter);
				recursion->rChild = rtree;
			}	
		}		  	
	}
	tree = recursion;
}
void BinSearchTree::printTreePreOrder (BinSearchTree *temp, std::ofstream &fp1) 
{
/*Make appropriate changes here*/
    if (temp == NULL)
       {
       	return;
       }
 	
 	stack<BinSearchTree *> nodeStack;
    nodeStack.push(temp);
 
    while (nodeStack.empty() == false)
    {
        BinSearchTree *node = nodeStack.top();
       	fp1 << node->symbol<< " ";
        nodeStack.pop();
 		   if (node->rChild != NULL)
            	{
            		nodeStack.push(node->rChild);
            	}
        	if (node->lChild != NULL)
        		{
            		nodeStack.push(node->lChild);
        		}
    }	
}


void BinSearchTree::printTreeInOrder (BinSearchTree *temp, std::ofstream &fp1) 
{
/*Make appropriate changes here*/
 		if(temp==NULL) 
 			{
 				return;
 			}	
    	 printTreeInOrder(temp->lChild, fp1);
     	 fp1 << temp->symbol<<" ";
     	 printTreeInOrder(temp->rChild, fp1);

}
