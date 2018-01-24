#include <iostream>
using namespace std;

struct varun          // node created
{
	int data;
	varun *next;
	varun *prev;
	varun()
	{
		data = 0;
		next = NULL;
		prev = NULL;
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
		temp->next = NULL;
		temp->prev = NULL;
		if (head == NULL) 
		{
			head = temp;
			tail = temp;
		}
		else 
		{    
		    temp->prev = tail; 
			tail->next = temp;
			tail = temp;
		}
	}
	
void insertAt(int pos, int value)  // function to insert a node anywhere in the list
	{
		varun *previous,*current;
		varun *temp = new varun;
		current = head;
		int a = countItems();
		if(pos<=a)
		{
		for (int i = 1; i < pos; i++) 
		{
			previous = current;
			current = current->next;
		}
		temp->data = value;
		temp->prev = previous;
		previous->next = temp;
		temp->next = current;
		current ->prev = temp;
	    }
		
		else
		cout<<endl<<"Position Exceeds number of nodes"<<endl;
	}		
		
void display()    // function to display nodes
	{
		varun *temp;
		temp = head;
		while (temp != NULL) 
		{
			cout << temp->data << "<=>";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
	}

void deleteNode()  // function to delete node at the end
	{
		varun *previous, *current;
		previous=NULL;
		current = head;
		while(current->next != NULL) 
		{
			previous = current;
			current = current->next;
		}
		tail = previous;
		previous->next = NULL;
		current ->prev = NULL;
	}
	
	void deleteAt(int pos) // function to delete node at a specified position
	{
		varun *previous, *current;
		current = head;
		for (int i = 1; i < pos; i++) 
		{
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		(current->next)->prev = previous;
		
	}
	
	int countItems()     //function to count items
	{
		varun *current;
		current = head;
		int a=1;
		while(current->next!=NULL)
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
