#include <iostream>

using namespace std;

struct Window {
  string appname;
  Window * next;
  Window * prev;
};

class WindowManager {
  private:

    Window * current; //window that is currently used
    Window * dummy; // head in short

  Window * create() {
    Window * newnode;
    try {
      newnode = new Window;
    } catch (bad_alloc) {
      newnode = NULL;
    }
    return newnode;
  }

  void deallocate(){
    Window * temp = dummy->next;
    while (temp != dummy) {
      Window * deleted = temp;
      delete deleted;
      temp = temp->next;
    }
    delete dummy;

  }

  public:
    ~WindowManager(){
      deallocate();
    }
    bool start_app(string name) {

      Window * newNode = create();
      // check for newNode not being created
      if (newNode == NULL) {
        return false;
      }
      newNode -> appname = name;
      // insert node to left of dummy
      // check for the first node to be inserted
      if (dummy -> next == dummy) {
        dummy -> next = newNode;
        newNode -> prev = dummy;
      } else {
        newNode -> prev = dummy -> prev;
        dummy -> prev -> next = newNode;
      }
      newNode -> next = dummy;
      dummy -> prev = newNode;
      // set new node as current node
      current = newNode;
      return true;
    }

  WindowManager() {
    dummy = create();

    dummy -> appname = "";
    //setting this next and prev to dummy
    dummy -> prev = dummy;
    dummy -> next = dummy;
    // I do not have any head :D
    current = NULL;
  }
  
  Window * findapp(string name){
    Window * temp = dummy->next;
    if(dummy->next == dummy){
      return NULL;
    } 

      while(temp != dummy){
        if(name == temp->appname){
          return temp;
        } 
        temp = temp->next;
      }
      return NULL;
    
  }
  // not working rn
  bool close_app(string name){
    Window * found = findapp(name);
    if(found == NULL){
      return false;
    }

      current = found->next;
      found->prev->next = found->next;
      found->next->prev = found->prev;
      delete found;
      if(current == dummy){
        current = dummy->next;
      } 

      if(current == dummy){
        current = NULL;
      }
      return true;
  }

  void showapp(string name){
    cout << findapp(name) << endl;
  }

  string get_current(){
    if(current == NULL){
      return "";
    } else {
      return current->appname;
    }
  }

  string next(){

    if(current == NULL){
      return "";
    }
    if(current->next == dummy){
      current = dummy->next;
    } else{
      current = current->next;
    }
    return current->appname;
  } 

  string previous(){
    if(current == NULL){
      return "";
    } 

    if(current->prev == dummy){
      current = dummy->prev;
    } else{
      current = current->prev;
    }
    return current->appname;
  }

  //Tester for my traversal LOL
  friend void show(WindowManager & Q) {
    Window * temp = Q.dummy->next;
    while (temp != Q.dummy) {
      cout << temp->appname << endl;
      temp = temp->next;
    }
  }
};

int main()
{
  WindowManager winman;

  // simulate some apps running
  winman.start_app("Microsoft Word");
  winman.start_app("Firefox");
  winman.start_app("Halo");
  winman.start_app("Calculator");

  // at this point, Calculator is the last app launched
  // and should be the value of current in winman
  int action;
  do
  {
    cout << "1 - Launch new app" << endl;
    cout << "2 - Close current app" << endl;
    cout << "3 - Find app, then close it" << endl;
    cout << "4 - Go to next app" << endl;
    cout << "5 - Go to previous app" << endl;
    //Extra Function :D
    cout << "6 - Show Deque" << endl;

    cout << "0 - Shutdown" << endl;
    cin >> action;

    // fill in the rest of the necessary code to perform 
    // menu actions
  
    if(action == 1){
      string name;
      cout << "Enter your fav appname" << endl;
      cin >> name;
      winman.start_app(name);
  
    } else if (action == 2){
      winman.close_app(winman.get_current());
      cout << "current app: " << winman.get_current() << endl;

    } else if(action == 3){
  
      cout << "Enter app that you want to delete" << endl;
      string appname;
      cin.ignore();
      getline(cin, appname);
      winman.close_app(appname);
      cout <<  "current app: " << winman.get_current() << endl;

    } else if(action == 4){
      winman.next();
      cout <<  "current app: " << winman.get_current() << endl;
    } else if(action == 5){
       winman.previous();
       cout << winman.get_current() << endl;
    } else if(action == 6){
       show(winman);
    }
  }
  while (action != 0);
  
  cout << "Shutting down..." << endl;

  return 0;
}




// int main() {
//   WindowManager winman;

//   // simulate some apps running
//   winman.start_app("Microsoft Word");
//   winman.start_app("Firefox");
//   winman.start_app("Eidmone");
//   winman.start_app("tagaca");


//   show(winman);




//   winman.close_app("Microsoft Word");
//   show(winman);
//   //   winman.close_app("Eidmone");
//   // show(winman);
//   //   winman.close_app("tagaca");
//   //   cout <<"final" << endl;
//   // show(winman);



//   return 0;
// }