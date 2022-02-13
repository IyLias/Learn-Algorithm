#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>


using namespace std;

class Node{

 public:
  
   int value;
   vector<Node*> childs;
   vector<int> distance;

   Node(int value, Node* child = NULL,int dist){

      this->value = value;
      if(child != NULL)
      	(this->childs).push_back(child);
      (this->distance).push_back(dist);
 
   }

   void add_child(Node* child){
	(this->childs).push_back(child);
   }

   Node* get_child(int target){
        return this->childs[target];
   }

   int get_distance(int target){
	return this->distance[target];
   }

};



class Tree{

  public:
   
    Node* root;

    Tree(int value, Node* child= NULL,int dist){
	    this->root = new Node(value,child,dist);
    }


    void tree_add_child(int p,int c,int d){

	Node* targetNode = getChild(this->root,p);

	targetNode->add_child(new Node(c,NULL,0),d);
    }

    Node* get_child(Node* node, int value){




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

	    for(int child=0;child<(this->root)->childs.size();child++)
	    	preorder_traversal(node->childs[child]);
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

 int n;
 scanf("%d",&n);

 Tree* myTree = new Tree(1,NULL,0);
 for(int i=0;i<n;i++){
    int p,c,d;
    scanf("%d %d %d",&p,&c,&d);

    myTree->tree_add_child(p,c,d);
 }

 printf("%d\n",myTree->get_diameter());

 return 0;
}
