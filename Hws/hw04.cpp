#include <iostream>
using namespace std;

struct Window
{
  string appname;
  Window *next;
  Window *prev;
};

class WindowManager{
  private:
    Window * head;
    Window * current; //window that is currently used
    Window * dummy; // head in short

    Window * create()
{
  Window * newnode;
  try
  {
    newnode = new Window;
  }
  catch (bad_alloc)
  {
    newnode = NULL;
  }
  return newnode;
}



  public:
   
    bool start_app(string name){
        Window * newNode = create();

        if(newNode == NULL){
            return false;
        }
        newNode->appname = name;

        newNode->next = dummy;
        newNode->prev = dummy->prev;
        dummy->prev->next = newNode;
        dummy->prev = newNode;

        current = newNode;
        return true;
    }

    WindowManager(){
        dummy = create();

        dummy->appname = "";
        dummy->prev = NULL;
        dummy->next = NULL;
        // I do not have any head
        current = NULL;
    }


  
    


};


int main() {
    WindowManager winman;

  // simulate some apps running
  winman.start_app("Microsoft Word");
  winman.start_app("Firefox");
  return 0;
}