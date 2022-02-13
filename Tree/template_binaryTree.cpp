#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>


using namespace std;

class Node{

 public:
  
   int value;
   Node* left;
   int leftDist;
   Node* right;
   int rightDist;


   Node(int value, Node* left = NULL,int leftD, Node* right= NULL,int rightD){

      this->value = value;
      this->left = left;
      this->leftDist = leftD;
      this->right = right;
      this->rightDist = rightD;
   }

   void add_leftChild(Node* left){
	this->left = left;
   }

   Node* get_leftChild(){
        return this->left;
   }

   void add_rightChild(Node* right){
	this->right = right;
   }

   Node* get_rightChild(){
	return this->right;
   }

};



class Tree{

  public:
   
    Node* root;

    Tree(int value, Node* left= NULL, Node* right= NULL){
	    this->root = new Node(value,left,right);
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
	     
          }

	}


        return depth;
    }


    
    int get_diameter(){






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
