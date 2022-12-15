//SYCOA8 Mansi Ahir
//Assignment 4 Stack

#include <iostream>
using namespace std;
struct Node //The structure Node is used to create the linked list
{
	int data;
	struct Node *next;
};
struct Node *top = NULL;
void push(int val) //The push function takes a value to be pushed into the stack
{
	struct Node *newnode = (struct Node*)malloc(sizeof(struct Node)); //A new node is created
	newnode->data = val;
	newnode->next = top;
	top = newnode;
}
void pop() //The pop function pops the value at the top of the stack
{
	if(top==NULL) //Condition to check if the stack is empty
		cout<<"\nStack Underflow!";
	else
		cout<<"\nPopped element is "<<top->data;
	  top = top->next;
}
void display() //The display function displays the elemnts of the stack
{
	struct Node *ptr;
	if(top==NULL)
		cout<<"\nStack empty!"; //Printing for empty stack
	else
	{
		ptr = top;
		cout<<"\nStack elements are: ";
		while(ptr!=NULL)
		{
			cout<<ptr->data<<"\t";
			ptr = ptr->next;
		}
	}
}
int main() //The main function provides a choice to the user for stack operations
{
   cout<<"\n          STACK USING LINKED LIST          ";
   int ch, value;
   do
   {
      cout<<"\n\n1. Push into stack";
      cout<<"\n2. Pop from stack";
      cout<<"\n3. Display the stack";
      cout<<"\n4. Exit";
      cout<<"\nEnter your choice: ";
      cin>>ch;
      switch(ch) //The functions are called according to user's input using the switch case
      {
	      case 1: 
            cout<<"\nEnter the value you want to push into the stack: ";
            cin>>value;
            push(value);
            break;
        case 2: 
            pop();
            break;
        case 3: 
            display();
            break;
        case 4: 
            cout<<"\nExited!";
            break;
        default: 
            cout<<"\nInvalid Choice!";
      }
   }while(ch!=4);
	return 0;
}
