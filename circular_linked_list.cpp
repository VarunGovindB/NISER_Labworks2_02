#include <iostream>
using namespace std;

struct varun          // node created
{
	int data;
	varun *next;
	varun()
	{
		data = 0;
		next = NULL;
	}
};

class kanna          // class declaration
{
private:
	varun *head, *tail;
public:
	kanna()          // constructor
	{
		head = NULL;
		tail = NULL;
	}
	
	void insert(int n)     // function to insert a node at the end of the list
	{
		varun *temp = new varun;
		temp->data = n;
		temp->next = head;
		if (head == NULL) 
		{
			head = temp;
			tail = temp;
			
		}
		else 
		{
			tail->next = temp;
			tail = temp;
		}
	}
	
	void insertAt(int pos, int value)  // function to insert a node anywhere in the list
	{
		varun *previous,*current;
		varun *temp = new varun;
		current = head;
		//pos=1 problem for head since previous will not be defined
		int a = countItems();
		if(pos<=a)
		{
		for (int i = 1; i < pos; i++) 
		{
			previous = current;
			current = current->next;
		}
		previous->next = temp;
		temp->data = value;
		temp->next = current;
	    }
	    else
	    cout<<endl<<"Position Exceeds number of nodes"<<endl;
	    
	}
	
	
	void display()    // function to display nodes
	{
		varun *temp = new varun;
		temp = head;
		cout << temp->data << "->";
		temp = temp->next;
		
		while (temp != head) 
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout<<"head";
		cout<<endl;
	}
	
	void deleteNode()  // function to delete node at the end
	{
		varun *previous = new varun; //Not needed
		varun *current = new varun;
		previous=NULL;
		current = head;
		while(current->next != head) 
		{
			previous = current;
			current = current->next;
		}
		tail = previous;
		previous->next = head;
		delete current;
	}
	
	void deleteAt(int pos) // function to delete node at a specified position
	{
		varun *previous = new varun;
		varun *current= new varun;
		current = head;
		for (int i = 1; i < pos; i++) 
		{
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		delete current;
	}
	
	int countItems()     //function to count items
	{
		varun *current;
		current = head->next; //Check for 0 and 1 element(s)
		int a=2;
		while(current->next!=head)
		{
			++a;
			current = current->next;	
		}
		return a;		
	}
};

int main()
{
	kanna a;
	a.insert(4);
	a.insert(6);
	a.insert(7);
	a.insert(12);
	a.insertAt(2,3);
	a.display();
	a.deleteNode();
	a.display();
	a.insert(3);
	a.display();
	a.deleteNode();
	a.display();
	a.deleteAt(2);
	a.display();
	cout<<a.countItems();
	a.insertAt(10,5);
	a.insert(8);
	a.display();
	return 0;
}
