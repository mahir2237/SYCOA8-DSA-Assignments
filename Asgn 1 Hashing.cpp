//DSA Asgn 1 
//SYCOA8 Mansi Ahir

#include <iostream>
using namespace std;
class hasht //class containing data members/functions required for hash table
{
	public:
	    struct employee //Creating a structure employee
		  {
		    long int id;
		    string name;
		    int key;
		  }database[10]; //A structure database of employees with default size=10
		
      int hfun(int);
      void insert();
      void del();
      void search();
      void display(); 
      hasht() //Default Constructor
      {
        for(int i=0;i<10;i++)
        {
          database[i].id= -1;
          database[i].key= -1;
          database[i].name="--";
        }
      }
};

int hasht::hfun(int key) //Function to generate a hash key for each employee
{
    return key%10; //10 is the default considered size of hash table
}

void hasht::insert() //Function to insert elements into the hash table according to their hash key generated
{
	int i,id,flag;
	string name;
	cout<<"\nEnter Employee's ID: ";
	cin>>id;
	cout<<"\nEnter Employee Name: ";
	cin>>name;

	int index=hasht::hfun(id); //Hash key generating function called
  int c=index;
  for(i=0;i<10;i++)
	{
    while(database[index].key!=-1 && flag==10)
	  {
	    index=(index+1)%10;
      flag++;
	  }
    database[index].id=id;
    database[index].name=name;
    database[index].key=c;
	}
}

void hasht::search() //Search function to search and display a specific id
{
   int Key,j;
   cout<<"\nEnter the employee id to be searched: ";
   cin>>Key;
   for(j=0;j<10;j++)
   {
      if(Key==database[j].id)
      {
         cout<<"\nEmployee id found at "<<j<<" index."<<endl;
      }
   }
}

void hasht::del() //Delete function to delete a specific id 
{
   int eid,i;
   cout<<"\nEnter id to be deleted: ";
   cin>>eid;
   for(i=0;i<10;i++)
   {
      if(eid==database[i].id)
      {
    	  database[i].id= -1;
    	  database[i].key= -1;
    	  database[i].name="--";
        cout<<"\nEntered employee id deleted"<<endl;
       }
   }
}

void hasht::display() //Function to display entire hash table
{
   cout<<"\nKey\t\tId\t\tName\n";
   int j; 
   for(int j=0;j<10;j++)
   {
      cout<<"\n"<<j<<"\t\t"<<database[j].id<<"\t\t"<<database[j].name<<endl;
   }
}

int main()
{
    cout<<"               EMPLOYEE DATABASE               ";
    hasht obj; //Creating an object of hash table class
    int ch;
    do
    {
       cout<<"\n************************************************";
       cout<<"\n1. Insert a new id\n2. Display the data\n3. Search an id\n4. Delete an id\n5. Exit";
       cout<<"\nEnter your choice: "; //Menu to display and choose operations for the hash table
       cin>>ch;
       switch(ch) //Cases to implement different operations of the hash table according to user's choice
       {
       case 1:
           obj.insert();
           break;
       case 2:
    	     obj.display();
    	     break;
       case 3:
    	     obj.search();
    	     break;
       case 4:
    	     obj.del();
    	     break;
       case 5:
           cout<<"\nExited!";
       default:
    	     break;
       }
    }while(ch!=5); //The hash table operations will be terminated when while condtion is false
    return 0;
}