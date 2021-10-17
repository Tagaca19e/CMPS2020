#include <iostream>

using namespace std;

struct Location{
    string name;
    string address;
};

class Stack{
    private:
        Location nodes[100];
        int count;

    public:
        bool push(string name, string address){
            //push if empty
            if(count == 0){
                nodes[0].name = name;
                nodes[0].address = address;
                count++;
            } else {
                //shift right
                for(int i = count; i >= 0; i--){
                    nodes[i+1].name = nodes[i].name;
                    nodes[i+1].address = nodes[i].address;
                }
                //replace idx 0 with our push value
                nodes[0].name = name;
                nodes[0].address = address;
                count++;
            }
            if(count > 100){ 
                return true;
            }
            return false; // push > 100 = segfault
        }
        
        string pop(){
            // empty checker
            if(count == 0){
                return "";
            } else {
                //store name in temp
                string temp = nodes[0].name;
                //shifting elements
                for(int i = 0; i < 100; i++){
                    nodes[i] = nodes[i+1];
                }
                //update count
                count--;
            //return temp data    
            return temp;
            }
        }


        friend void show(Stack &brows){
            //traversing
            for(int i = 0; i < brows.count; i++){
                cout << brows.nodes[i].name << endl;
            }
        }



};

int main()
{
  Stack browser;

  // simulate a browser history
  browser.push("Google", "https://google.com");
  browser.push("Amazon", "https://amazon.com");
  browser.push("LinkedIn", "https://LinkedIn.com");
  browser.push("Reddit", "https://reddit.com");  

  show(browser);   // this should show the entire history

  // simulate clicking Back button
  string top = browser.pop();
  if (top != "")
    cout << endl << "Clicked back from " << top << endl;
  show(browser);

  // simulate clicking Back button  
  top = browser.pop();
  if (top != "")
    cout << endl << "Clicked back from " << top << endl;
  show(browser);

  // simulate clicking Back button
  top = browser.pop();
  if (top != "")
    cout << endl << "Clicked back from " << top << endl;
  show(browser);

  return 0;
}