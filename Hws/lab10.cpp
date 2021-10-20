#include <iostream>
using namespace std;

struct MainNode{
  string name;
  int pain;
  MainNode * next;
};

class Queue{
  private:
    MainNode * head = NULL;

    MainNode * create(){
      MainNode * newnode;
      try{
        newnode = new MainNode;
      }
      catch (bad_alloc){
        newnode = NULL;
      }
      return newnode;
    }

    void deallocate(){
      MainNode * temp = head;

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

    bool enqueue(string name,int pain){
      MainNode * newNode = create();


      if(newNode == NULL){
        return false;
      }
      newNode->name = name;
      newNode->pain = pain;

      if(head == NULL){
        head = newNode;
        newNode->next = NULL;
      } else{
        MainNode * temp = head;


        while(newNode->pain < temp->pain || temp->next->pain == newNode->pain){

          if(temp->next == NULL){
            break;
          }
          temp = temp->next;
        }



        //temmp ->next = newNode->next;
        if(temp->pain < newNode->pain){

          newNode->next = head;
          head = newNode;
        } else {
        newNode->next = temp->next;;
        temp->next = newNode;
        }



      }
      return true;
    }


string dequeue(){
 if(head == NULL){
   return "";
 } else if (head->next == NULL){
   string data = head->name;
   delete head;
   head = NULL;
  return data;
   }else{
   string data = head->name;

    MainNode * temp = head;

    head = head->next;

    delete temp;
    return data;
 }
}

    friend void show(Queue & Q){
      MainNode * temp = Q.head;


      while(temp != NULL){
        cout << temp->name << " " << temp->pain << endl;
        temp = temp->next;
      }
    }
};


int main() {
  Queue hello;

  hello.enqueue("Erick", 9);
hello.enqueue("Johnson", 8);

  hello.enqueue("Mark", 9);

  hello.enqueue("Eidmone", 5);

  hello.enqueue("Jack", 10);
hello.enqueue("Liz", 9);




int action,age, start;

  cout << "You are working at the Manibos Hospital, you are a registered nurse and you want to make sure you want to keep the priority line. Your task is to enter the name of the patient and once they are done you want to remove them from the list (Press 1 to start)" << endl;

  cin >> start;
  if(start == 1){
  do
  {
    cout << "Choose from the options-" << endl;
    cout << "1 - Add Patient" << endl;
    cout << "2 - Mark Patient As Done" << endl;
    cout << "3 - Show The Patien List" << endl;
    //Extra Function :D

    cout << "0 - Close List" << endl;
    cin >> action;

    // fill in the rest of the necessary code to perform
    // menu actions

    if(action == 1){
      string name;
      cout << "What's the name of the patient?" << endl;
      cin >> name;
      cout << "What's the priority level of the patient?" << endl;
      cin >> age;
      hello.enqueue(name, age);
      show(hello);

    } else if(action == 2){
      hello.dequeue();
    } else if(action == 3){
      show(hello
      );
    }
  }
  while (action != 0);

  cout << "Closed..." << endl;

  }
  return 0;

}