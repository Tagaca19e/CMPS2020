#include <iostream> 

using namespace std;

struct Location
{
  string name;
  string address;
};

struct VisitNode
{
  Location loc;
  VisitNode * next;
};



class Stack {

  private:
  VisitNode * head;

  VisitNode * create()
{
  VisitNode * newnode;
  try
  {
    newnode = new VisitNode;
  }
  catch (bad_alloc)
  {
    newnode = NULL;
  }
  return newnode;
}


void deallocate(){
  VisitNode * temp = head;

  while(temp != NULL){

    head = head->next;
    delete temp;

    temp = head;
  }

}

public:
  ~Stack(){
    deallocate();
    head=NULL;
  }

  bool push(string name, string address){
    VisitNode * newNode = create();

    if(newNode == NULL){
      return false;
    }

    newNode->loc.name = name;
    newNode->loc.address = address;
    newNode->next = NULL;

    if(head == NULL){
      head = newNode;
    } else {
      newNode->next = head;
      head = newNode;
    }
    return true;
  }

  string pop(){
    if(head == NULL){
      return "";
    } else {
      string data = head->loc.name;

      VisitNode * temp = head;

      head = head->next;

      delete temp;

      return data;
    }
  }


  friend void show(Stack & S){
    VisitNode * temp = S.head;

    while(temp != NULL ){
      cout << temp->loc.name << " ";
      temp = temp->next;
    }
  }
};


int main(){
  Stack browser;
  // simulate browser history
  browser.push("Google", "https://google.com");
  browser.push("Amazon", "https://amazon.com");
  browser.push("LinkedIn", "https://LinkedIn.com");
  browser.push("Reddit", "https://reddit.com");

  show(browser); // this should show the entire history


  string top = browser.pop();
  if (top != "") {
    cout << endl << "Clicked back from " << top << endl;
  }
  show(browser);

  // simulate clicking Back button
  top = browser.pop();
  if (top != "") {
    cout << endl << "Clicked back from " << top << endl;
  }
  show(browser);
  // simulate clicking Back button
  top = browser.pop();
  if (top != "") {
    cout << endl << "Clicked back from " << top << endl;
  }
  show(browser);

  return 0;


}
