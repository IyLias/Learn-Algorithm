#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>


using namespace std;

class Node{

 public:
  
   int value;
   Node* leftChild;
   Node* rightChild;


   Node(int value, Node* left = NULL, Node* right= NULL){

      this->value = value;
      this->leftChild = left;
      this->rightChild = right;

   }

   void add_leftChild(Node* left){
	this->leftChild = left;
   }

   Node* get_leftChild(){
        return this->leftChild;
   }

   void add_rightChild(Node* right){
	this->rightChild = right;
   }

   Node* get_rightChild(){
	return this->rightChild;
   }

};



class Tree{

  public:
   
    Node* root;

    Tree(int value, Node* left= NULL, Node* right= NULL){
	    root->value = value;
	    root->leftChild = left;
	    root->rightChild = right;

    }

    // return depth of tree
    int get_tree_depth(){

        if(this->root == NULL)
	  return 0;

	queue<Node*> node_queue;
	node_queue.push(this->root);

	int depth = -1;

	while(!(node_queue.empty())){

          depth+=1;
	  int temp_size = node_queue.size();
	  for(int i=0;i<temp_size;i++){
	      //Node* cur_root = node_queue.pop();
	     // if(cur_root->leftChild != NULL)
	//	  node_queue.push(cur_root->leftChild);
//
//	      if(cur_root->rightChild != NULL)
//		  node_queue.push(cur_root->rightChild);
          }

	}


        return depth;
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



int main(){

 Tree* sampleTree = new Tree(10,new Node(15,NULL,NULL),NULL);
 // printf("%d\n",sampleTree->get_tree_depth());
sampleTree->postorder_traversal(sampleTree->root);

 return 0;
}
