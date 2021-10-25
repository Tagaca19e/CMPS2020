#include <iostream>

using namespace std;

class RingBuffer{
  private:
    int size, back, front;
    string * names;

  bool is_empty(){
    if(front == back){
      return true;
    }
    return false;
  }

  bool is_full(){
    if(((back + 1) % size) == front){
      return true;
    }
    return false;
  }

  public:
   RingBuffer(int size){
      
      this->size = size;
      front = 0;
      back = 0;
      names = new string[size];

      for(int i = 0; i < size; i++){
        names[i] = ""; 
      }
    }

    ~RingBuffer(){
      delete[] names; 
    }

    bool enqueue(string name){
      if(is_full()){
        return false;
      } else {
        names[back] = name;
     back = (back + 1) % size;
      }
      return true;
    }

    string dequeue(){
      if(is_empty()){
        return  "";
      } else{
        string data = names[front];
        front = (front + 1) % size;
        return data;
      }
    }

    friend void show(RingBuffer & rb){

      int counter = rb.front;

      while(counter != rb.back){
        cout << rb.names[counter] << endl;
        counter  = (counter+1) % rb.size;
      }
    }
};

int main()
{
  RingBuffer buffer(4);
  char action;
  string name = "";
  bool added;

  do
  {
    cout << "e - Enqueue" << endl;
    cout << "d - Dequeue" << endl;
    cout << "q - Quit" << endl;
    cout << "Action: ";
    cin >> action;

    if (action == 'e')
    {
      cout << "Name: ";
      cin >> name;
      if (buffer.enqueue(name))
      {
        cout << "Added " << name << endl;
      }
      else
      {
        cout << name << " was not added. Queue full" << endl;
      }
    } else if (action == 'd')
    {
      name = buffer.dequeue();
      if (name == "")
      {
        cout << "Queue is empty" << endl;
      }
      else
      {
        cout << "Dequeued " << name << endl;
      }
    }
    show(buffer);
    cout << "-------------" << endl;

  } while (action != 'q');
  return 0;
}