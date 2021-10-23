#include <iostream>
using namespace std;

struct MainNode
{
	string name;
	int pain;
	MainNode * next;
};

class Queue
{
	private:
		MainNode *head = NULL;

	MainNode* create()
	{
		MainNode * newnode;
		try
		{
			newnode = new MainNode;
		}

		catch (bad_alloc)
		{
			newnode = NULL;
		}

		return newnode;
	}

	void deallocate()
	{
		MainNode *temp = head;

		while (temp != NULL)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
	}

	public:
		~Queue()
		{
			deallocate();
			head = NULL;
		}

	bool enqueue(string name, int pain)
	{
		MainNode *newNode = create();

		if (newNode == NULL)
		{
			return false;
		}

		newNode->name = name;
		newNode->pain = pain;
		//Basically what I am doing here is to choose where the value will go, either up or down. If the pain value of the patient is the greatest within the list, it will become the head. This way any value that is lesser than the head can be easily positioned to its respective position. Also, we do this so that we can have one direction of traversal, that is why I can do this with only a singly linked list without extra pointers. 
		if (head == NULL)
		{
			head = newNode;
			head->next = NULL;
		}
		else
		{
			//This will either choose top or bottom placement
      //Make the biggest value the head.
			if (newNode->pain > head->pain)
			{
				
				newNode->next = head;
				head = newNode;

				//THIS IS WHERE YOU LEFT OF --- NOTE TO SELF
				//This will check if the value you are pushing is equal to the only value in the linked list.
        //This is a different similar to the if statement below but for the head. 
			}
			else if (newNode->pain == head->pain)
			{
				MainNode *temp = head;

				while (temp->pain == newNode->pain && temp->next != NULL)
				{
          if(temp->next->pain != newNode->pain){
            break;
          }
					temp = temp->next;
				}
        
				  if(temp->next == NULL){
            newNode->next = NULL;
            temp->next = newNode;
          } else {
            newNode->next = temp->next;
            temp->next = newNode;
          }

			} 
			else
			{
				//this will go to the bottom
				MainNode *temp = head;
				while (newNode->pain < temp->pain && temp->next != NULL)
				{
          if(temp->next->pain < newNode->pain){
            break;
          }
					temp = temp->next;
          
				}
      //This checks for the smallest value inserted
				if(temp->pain > newNode->pain && temp->next == NULL){
          newNode->next = NULL;
          temp->next = newNode;
        } else if (temp->pain == newNode->pain){
      //Check for duplication in the middle and in the end
          while (temp->pain == newNode->pain && temp->next != NULL)
				  {
            if(temp->next->pain != newNode->pain){
              break;
            }
					temp = temp->next;
				  }

          if(temp->next == NULL){
            newNode->next = NULL;
            temp->next = newNode;
          } else {
            newNode->next = temp->next;
            temp->next = newNode;
          }
        } else if(newNode->pain < temp->pain && temp->next != NULL){
          newNode->next = temp->next;
          temp->next = newNode;
        }
        
        
      
			}
		}

		return true;
	}

	//THIS HELP FUNCTION IS FOR DEBUGGING PURPOSES :D
	void help(string name, int pain)
	{
		MainNode *newNode = create();

		MainNode *temp = head;
		newNode->name = name;
		newNode->pain = pain;

		while (newNode->pain < temp->pain)
		{ 
      if(temp->next == NULL || temp->next->pain < newNode->pain){
        break;
      }
			temp = temp->next;
  
		}
  

  //  if (temp->pain == newNode->pain){
  //         while (temp->pain == newNode->pain && temp->next != NULL)
	// 			  {
  //           if(temp->next->pain != newNode->pain){
  //             break;
  //           }
	// 				temp = temp->next;
	// 			  }

  //       } 
    

		cout << temp->name << "this is our test" << endl;
	}

	string dequeue()
	{
		if (head == NULL)
		{
			return "";
		}
		else if (head->next == NULL)
		{
			string data = head->name;
			delete head;
			head = NULL;
			return data;
		}
		else
		{
			string data = head->name;

			MainNode *temp = head;

			head = head->next;

			delete temp;
			return data;
		}
	}

	friend void show(Queue & Q)
	{
		MainNode *temp = Q.head;
    cout << "------THIS IS THE LIST-----" << endl;
		while (temp != NULL)
		{
			cout << temp->name << " " << temp->pain << endl;
			temp = temp->next;
		}
	}
};

int main()
{
	Queue hello;
// -------Test Case 1-------
	hello.enqueue("Eidmone", 1);
	hello.enqueue("Caesar", 11);
	hello.enqueue("James", 3);
	hello.enqueue("Eidmone", 3);

	hello.help("James", 3);

	// hello.enqueue("Melloe", 4);
	// hello.enqueue("loly", 4);
	// hello.enqueue("Jepp", 6);
	// hello.enqueue("Jello", 4);
	// hello.enqueue("Jeff", 4);
	// hello.enqueue("Ethan", 3);
	// hello.enqueue("Jorge", 2);
	// hello.enqueue("Marcus", 3);
	// hello.enqueue("Neo", 6);
	// hello.enqueue("Justin", 7);
	// hello.enqueue("Natalie", 4);

// -------Test Case 2-------
	// hello.enqueue("Melloe", 5);
	// hello.enqueue("Joe", 5);
	// hello.enqueue("John", 5);
	// hello.enqueue("Nick", 2);
	// hello.enqueue("Eidmone", 1);
	// hello.enqueue("Eidmone", 5);
	// hello.enqueue("Eidmone", 5);
	// hello.enqueue("Eidmone", 5);
	// hello.enqueue("Jojo", 1);
	// hello.enqueue("Jojo", 4);






	//  hello.help("kirby", 6);




	//If ther is a duplicate in the end is done 

	show(hello);
	// hello.help("haroon", 0);

	// hello.enqueue("PaMela", 1);

	int action, age, start;

	cout << "You are working at the Manibos Hospital, you are a registered nurse and you want to make sure you want to keep the priority line. Your task is to enter the name of the patient and once they are done you want to remove them from the list (Press 1 to start)" << endl;

	cin >> start;
	if (start == 1)
	{
		do {
			cout << "Add Patient [1]" << endl;
			cout << "Mark Patient As Done [2]" << endl;
			cout << "Show The Patien List [3]" << endl;
			//Extra Function :D

			cout << "Exit [0]" << endl;
			cin >> action;

			// fill in the rest of the necessary code to perform
			// menu actions

			if (action == 1)
			{
				string name;
				cout << "What's the name of the patient?" << endl;
				cin >> name;
				cout << "What's the priority level of the patient?" << endl;
				cin >> age;
				hello.enqueue(name, age);
				show(hello);

			}
			else if (action == 2)
			{
				hello.dequeue();
			}
			else if (action == 3)
			{
				show(hello);
			}
		}

		while (action != 0);

		cout << "Shutting down..." << endl;

	}

	return 0;

}