#include <stdio.h>
#include <algorithm>

using namespace std;

template <typename T>
class Node{

 public:
  
   T value;
   Node* leftChild;
   Node* rightChild;

};


template <typename T>
class Tree{

  public:
   
    Node* root;

    Tree(T value, Node* left= NULL, Node* right= NULL){
	    root->value = value;
	    root->leftChild = left;
	    root->rightChild = right;

    }

    void preorder_traversal(Node* node){

	    if(node == NULL)
	      return;

	    cout << node->value << ' ';

	    preorder_traversal(node->leftChild);
	    preorder_traversal(node->rightChild);

    }


    void inorder_traversal(Node* node){

         if(node == NULL)
            return;

	 inorder_traversal(node->leftChild);
	 cout << node->value << ' ';
	 inorder_traversal(node->rightChild);

    }


    void postorder_traversal(Node* node){


	 if(node == NULL)
            return;

	 postorder_traversal(node->leftChild);
	 postorder_traversal(node->rightChild);         cout << node->value << ' ';

    }



};
