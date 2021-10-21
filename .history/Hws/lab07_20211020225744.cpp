#include <iostream>
using namespace std;

struct JobNode
{
  string name;
  JobNode * next;
};


class Queue {
  private:
    JobNode * head = NULL;

  JobNode * create()
{
  JobNode * newnode;
  try
  {
    newnode = new JobNode;
  }
  catch (bad_alloc)
  {
    newnode = NULL;
  }
  return newnode;
}

void deallocate(){
  JobNode * temp = head;

  while(temp != NULL){
    head = head->next;
    delete temp;
    temp = head;
  }
}

  public:
    ~Queue(){
      deallocate();
      head = NULL;
    }

  bool enqueue(string name){
    JobNode * newNode = create();

    if(newNode == NULL){
      return false;
    }
    newNode->name = name;
    newNode->next = NULL;

    if(head == NULL){
      head = newNode;
    } else {
      newNode->next = head;
      head = newNode;
    }
    return true; 
  } 

  string dequeue(){
      string data;
    if(head == NULL){
       return "";
  
    } else if(head->next == NULL){
        string data = head->name;
        delete head;
        head = NULL; 
    return data;
    } else {
      

      JobNode * temp = head;

      while(temp != NULL){
        if(temp->next->next == NULL){
           data = temp->next->name;
            delete temp->next;
            temp->next = NULL;
        // cout << temp->next->name << "this is name" <<  endl; 

        break;
        }
        temp = temp->next;
      }
    }
         return data;
  }

  friend void show(Queue & Q){
    JobNode * temp = Q.head;

    while (temp != NULL){
      cout << temp->name << " ";
      temp = temp->next;
    }
  }
};

int main()
{
  Queue spooler;

  // simulate a printer spooler
  spooler.enqueue("Comm100 Paper.docx");
  spooler.enqueue("Fwd: Direct Deposit");
  spooler.enqueue("document(1).doc");
  spooler.enqueue("lab9.cpp");

  cout << "Pending jobs: " << endl;
  show(spooler);   // this shows all jobs

  // simulate the printer completing the jobs
  string oldest;
  do
  {
    oldest = spooler.dequeue();
    if (oldest != "")
    {
      cout << "Printing..." << endl;
      cout << oldest << " printed" << endl;

      cout << endl << "Pending jobs:" << endl; 
      show(spooler);     
    }
  } while (oldest != "");

  cout << "No jobs" << endl;

  return 0;
}
