//SYCOA8 Mansi Ahir
//Assignment 5 - Queue using linked list 

#include <iostream>
using namespace std;
struct Node //structure Node is used to create the linked list for queue
{
   int data;
   struct Node *next;
};
struct Node* front = NULL; //tracks first element of queue
struct Node* rear = NULL; //tracks last element of the queue
struct Node* temp;//
void insert() //inserts new element into the queue
{
   int val;
   cout<<"\nEnter element you want to insert: ";
   cin>>val;
   if (rear == NULL) 
   {
      rear = (struct Node*)malloc(sizeof(struct Node));
      rear->next = NULL;
      rear->data = val;
      front = rear;
   } 
   else 
   {
      temp=(struct Node*)malloc(sizeof(struct Node));
      rear->next = temp;
      temp->data = val;
      temp->next = NULL;
      rear = temp;
   }
}
void del() //deletes element from the queue
{
   temp = front;
   if (front == NULL) //checking if the queue is empty
   {
      cout<<"\nQueue Underflow!";
      return;
   }
   else if (temp->next != NULL) 
   {
      temp = temp->next;
      cout<<"\nDeleted element: "<<front->data;
      free(front);
      front = temp;
   }
   else
   {
      cout<<"\nDeleted element: "<<front->data;
      free(front);
      front = NULL;
      rear = NULL;
   }
}
void display() //display elements of the queue
{
   temp = front;
   if (front == NULL && rear == NULL) //checking if the queue is empty
   {
      cout<<"\nQueue is empty!";
   }
   cout<<"\nQueue elements: ";
   while (temp != NULL) 
   {
      cout<<temp->data<<" ";
      temp = temp->next;
   }
}
int main()
{
  int ch;
  do //Menu Driven program to perform operations of queue
  {
  cout<<"\n\n1. Insert element to queue";
  cout<<"\n2. Delete element from queue";
  cout<<"\n3. Display all the elements of queue";
  cout<<"\n4. Exit";
  cout<<"\nEnter your choice: ";
  cin>>ch;
  switch(ch)
    {
      case 1:
        insert();
      break;
      case 2:
        del();
      break;
      case 3:
        display();
      break;
      case 4:
        cout<<"\nExited!";
      break;
      default: 
           cout<<"\nInvalid choice!";
      break;
      }
  }while(ch!=4);
  return 0;
}