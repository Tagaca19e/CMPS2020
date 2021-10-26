#include <iostream>

using namespace std;

struct DataNode{
  string value;
  DataNode * next;
  DataNode * prev; 
};

class Deque{

protected:
  DataNode * head = NULL;
  DataNode * tail = NULL;

  DataNode * create()
{
  DataNode * newnode;
  try
  {
    newnode = new DataNode;
    newnode->prev = NULL;
    newnode->next = NULL;
  }
  catch (bad_alloc)
  {
    newnode = NULL;
  }
  return newnode;
}

  void deallocate(){
    DataNode * temp = head;

    while(temp != NULL){
      head = head->next;
      delete temp;

      temp = head;
    }
  }

  void add_to_head(string value){
    DataNode * newNode = create();
    newNode->value = value;
    if(head == NULL){
      head = newNode;
      tail = newNode;

    } else {
      //If the linked list is not empty
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }

  }

   string remove_from_tail() {
    // if the linke list is empty

    if (tail == NULL) {
      return "";
    } else if (head == tail) {
      string data = tail->value;
      delete tail;
      head = NULL;
      tail = NULL;
      return data;
    } else {
      string data = tail->value;
      tail = tail->prev;
      delete tail->next;
      tail->next = NULL;
      return data;
    }
  }


  void add_to_tail(string value){
    DataNode * newNode = create();

if(head == NULL){
      head = newNode;
      tail = newNode;
      newNode->value = value;
    } else {
      //If the linked list is not empty
      newNode->value = value;
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;

    }
  }


string remove_from_head(){
 if(head == NULL && tail == NULL){
   return "";
 } else if (head->next == NULL){
   string data = head->value;
   delete head;
   head = NULL;
   tail = NULL;
  return data;
   }else{
   string data = head->value;

    DataNode * temp = head;

    head = head->next;
    head->prev = NULL;

    delete temp;
    return data;

 }

}
  public:
    ~Deque(){
      deallocate();
      head = NULL;
      tail =NULL; 
    }

  friend void show(Deque & Q){
    DataNode * temp = Q.head;

    while(temp != NULL){
      cout << temp->value << endl;
      temp = temp->next;
    }
  }  

};


class Queue: public Deque{
public:
  void enqueue(string value){
    add_to_head(value);
  }

  string dequeue(){
    return remove_from_tail();
  }


};

class Stack: public Deque{
  public:
  void push(string value){
    add_to_tail(value);
  }
  void pop(){
    remove_from_tail();
  }
  void pop2(){
    remove_from_head();
  }

};


int main()
{
  Queue q;
//added additional funcs to use all the functions made
  q.enqueue("Heaven");
  q.enqueue("Hell");
  q.enqueue("Limbo");
  show(q);

  //THESE ARE TEST CASES
  // q.dequeue();
  // show(q);
  // additional driver code

 
  Stack s;

  s.push("Humpty");
  s.push("Dumpty");
  show(s);

  //THESE ARE TEST CASES
  // s.pop();
  // show(s);
  // s.pop2();
  // show(s);
  
  // additional driver code 
  return 0;
}