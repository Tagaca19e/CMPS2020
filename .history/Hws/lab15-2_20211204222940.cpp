#include <iostream>

using namespace std;

struct Node{
  int value;
  Node * left;
  Node * right;
};

class BST
{
  private:
    int count;
    Node * root;
    Node * create(int value);
    void add_node(Node *subtreeroot, int value); 
    void destroy_node(Node *node);
    
  public:
    BST() {
      root = NULL;
      count = 0;
    }
    ~BST() {
      destroy_node(root);
    }
    void add(int item);
    friend void show(BST & bst);
    //To get our count
    void get_count(){
      cout << count;
    }

};

Node* BST:: create(int value){
  Node *node = new Node;
  node->value = value;
  node->left = NULL;
  node->right = NULL;

  count++;
  return node;
}

void BST::add_node(Node *subtreeroot, int value){
  //initial
  if(subtreeroot == NULL){
    root = create(value);
   
  } else if (subtreeroot->value == value) {
     //Maybe we can store the counts of the duplicates but for now we reject it
      return;
  } else {
    //if we go to the left
    if(subtreeroot->value > value){
      if(subtreeroot->left != NULL){
        //recursion to find the right place
        add_node(subtreeroot->left, value);
      } else {
        subtreeroot->left = create(value);
      }
    } else {
    //if we go to the right
      if(subtreeroot->right != NULL){
        add_node(subtreeroot->right, value);
      } else {
        subtreeroot->right = create(value);
      }

    }
  }
  
}

void BST::add(int item){
  add_node(root, item);
}

void show_node(Node *subtreeroot){
  if(subtreeroot != NULL){
    show_node(subtreeroot->left);
    cout << subtreeroot->value << " ";
    show_node(subtreeroot->right);
  } 
}

void show(BST & bst){
  show_node(bst.root);
}

void BST::destroy_node(Node *node){
  //delete our nodes using postOrder traversal
  if(node != NULL){
    destroy_node(node->left);
    destroy_node(node->right);
  }
  delete node;
  count--;
}


int main() {
  int values[25] = { 23, 117, 45, 19, 7, 
13, 17, 40, 9, 11, 
93, 49, 35, 8, 3, 
10, 22, 77, 16, 6, 
51, 57, 55, 90, 31};


  BST bst;

  for(int i = 0; i < 25; i++){
    bst.add(values[i]);
  }
  cout << "==Tree Result==" << endl;
  show(bst);

  int ins;
  
  while(ins != -1){
  cout << endl;
  cout << "Enter Value:  " << endl;
  cin >> ins;

  bst.add(ins);

  cout << "==Tree Result==" << endl;
  show(bst);

  cout << "The number of nodes of the tree: " << endl;
  bst.get_count();
  }

  return 0;

} 