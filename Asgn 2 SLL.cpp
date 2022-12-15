#include <iostream>
using namespace std;
struct Node //structure Node contains the data and a pointer to the next linked list node
{
  int data;
  Node *next;
};
class singlell 
{
private:
  Node *header = NULL;
  Node *del(Node *header, int d);

public:
  void InsertAtBeginning();
  void InsertAtPos();
  void InsertAtEnd();
  Node *DeleteNode();
  void DisplayList();
};
void singlell::InsertAtBeginning() //inserts data at the beginning of the linked list
{
  struct Node *newnode;
  newnode = new struct Node;
  cout << "\nEnter the data part of the new node: ";
  cin >> newnode->data;
  newnode->next = header;
  header = newnode;
  cout << "\nNew node added at the beginning!";
}
void singlell::InsertAtPos() //inserts data at a specific position in the linked list 
{
  int insert_pos;
  Node *p, *newnode, *store;
  newnode = new Node;
  p = new Node;
  store = new Node;
  p = header;
  cout << "\nEnter the position at which you want to enter the new node: ";
  cin >> insert_pos;
  cout << "\nEnter the data part of new node: ";
  cin >> newnode->data;
  for (int i = 0; i < insert_pos - 1; i++)
    {
    if (newnode->next != NULL) 
    {
      p = p->next;
      p++;
    }
  }
  store = p->next;
  p->next = newnode;
  newnode->next = store;
  cout << "\nNew node added at the position!";
}
void singlell::InsertAtEnd() //inserts data at the end of the linked list
{
  struct Node *p;
  struct Node *newnode;
  newnode = new struct Node;
  p = new struct Node;
  p = header;
  cout << "\nEnter the data part of the new node: ";
  cin >> newnode->data;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = newnode;
  newnode->next = NULL;
  cout << "\nInsertAtLast Done!";
}
Node *singlell::DeleteNode() //deletes a node from the linked list
{
  int d;
  cout << "Enter the data of node to be deleted: ";
  cin >> d;
  struct Node *p, *q;
  q = header;
  p = header->next;
  if (q->data == d) {
    header = p;
    delete (q);
  } else {
    while (p->data != d) {
      p = p->next;
      q = q->next;
    }
    if (p->next == NULL) {
      q->next = NULL;
      delete (p);
    } else {
      q->next = p->next;
      delete (p);
    }
  }
  return header;
  cout << "Node deleted";
}
void singlell::DisplayList() //displays the complete linked lists
{
  Node *temp;
  temp = header;
  while (temp != NULL) {
    cout << temp->data << "\t";
    temp = temp->next;
  }
}
int main() 
{
  singlell o;
  int ch;
  do {
    cout << "\n\n1. Insert a node at beginning.";
    cout << "\n2. Insert a node at a specific position.";
    cout << "\n3. Insert a node at end.";
    cout << "\n4. Delete a node.";
    cout << "\n5. Display";
    cout << "\n6. Exit";
    cout << "\nEnter your choice: ";
    cin >> ch;
    switch (ch) {
    case 1:
      o.InsertAtBeginning();
      break;
    case 2:
      o.InsertAtPos();
      break;
    case 3:
      o.InsertAtEnd();
      break;
    case 4:
      o.DeleteNode();
      break;
    case 5:
      o.DisplayList();
      break;
    case 6:
      cout << "\nExited!";
      break;
    default:
      break;
    }
  } while (ch != 6);
  return 0;
}