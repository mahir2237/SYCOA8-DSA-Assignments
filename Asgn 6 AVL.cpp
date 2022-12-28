//SYCOA8 Mansi Ahir
//Asgn 6 AVL Tree

#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *left,*right;
};

class AVL
{
  private:
    Node *root;
  public:
    AVL()
    { 
      root = NULL;
    }
    void create();
    void display();
    Node *insert(Node*,int);
    void inorder(Node*);
    void preorder(Node*);
    int height(Node*);
    int MAX(int,int);
    Node *LL(Node*);
    Node *RR(Node*);
    Node *LR(Node*);
    Node *RL(Node*);

};

Node *AVL::LL(Node *parent)
{
  Node *temp;
  temp=parent->left;
  parent->left=temp->right;
  temp->right=parent;
  return temp;
}

Node *AVL::RR(Node *parent)
{
  Node *temp;
  temp=parent->right;
  parent->right=temp->left;
  temp->left=parent;
  return temp;
}

Node *AVL::LR(Node *parent)
{
  parent->left=RR(parent->left);
  parent=LL(parent);
  return parent;
}

Node *AVL::RL(Node *parent)
{
  parent->right=RR(parent->right);
  parent=LL(parent);
  return parent;
}

int AVL::MAX(int a,int b)
{
  if(a>b)
    return a;
  else
    return b;
}

int AVL::height(Node *temp )
{
  if(temp==NULL)
    return -1;
  if(temp->left==NULL && temp->right==NULL)
    return 0;
  return(1+MAX(height(temp->left),height(temp->right)));
}

void AVL::inorder(Node *temp)
{
  if(temp!=NULL)
  {
    inorder(temp->left);
    cout<<" "<<temp->data;
    inorder(temp->right);
  }
}

Node *AVL::insert(Node *temp,int val)
{
  if(temp==NULL)
  {
    temp=new Node;
    temp->data=val;
    temp->left=temp->right=NULL;
  }
  else
  {
    if(val<temp->data)
    {
      temp->left=insert(temp->left,val);
      if((height(temp->left) - height(temp->right)==2))
      {
        if(val<temp->left->data)
          temp=LL(temp);
        else
          temp=LR(temp);
      }
    }
    else
    {
      temp->right=insert(temp->right,val);
      if((height(temp->left) - height(temp->right)==-2))
      {
        if(val>temp->right->data)
          temp=RR(temp);
        else
          temp=RL(temp);
      }
    }
  }
  return temp;
}

void AVL::display()
{
  cout<<"\nDictionary Data in Sorted way: ";
  inorder(root);
  cout<<"\nPreorder: ";
  preorder(root);
}

void AVL::create()
{
  int val;
  char ch;
  do
  {
    cout<<"\nEnter data: ";
    cin>>val;
    root=insert(root,val);
    cout<<"\nContinue: ";
    cin>>ch;
  }while(ch=='y' || ch=='Y');
}

void AVL::preorder(Node *temp)
{
  if(temp!=NULL)
  {
    cout<<"\t"<<temp->data;
    preorder(temp->left);
    preorder(temp->right);
  }
}

int main()
{
  AVL t;
  t.create();
  t.display();
  return 0;
}