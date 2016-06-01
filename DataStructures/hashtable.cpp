#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>

using namespace std;

/*struct node
{
	int rollNumber;
	char *name;
	node *next;
};*/

class cLinkList
{
   struct node
   {
	int rollNumber;
	char *name;
        node *next;
   };

  //struct node *head[26] ;
   public:
 	struct node *insert_Node(struct node *head, int srcRno, char *srcName);
	struct node *delete_Node(struct node *head, int srcRno);
	void search_Node(struct node*head, int srcRno, char *srcName);
};

cLinkList:: node *cLinkList::insert_Node(struct node *head, int srcRno, char *srcName)
{
  struct node *location = head;
  if(head==NULL)
  {
   head=(node *) malloc (sizeof(node));
   head->rollNumber=srcRno;
   head->name = new char[strlen(srcName)];
   strcpy(head->name, srcName);
   head->next=NULL;
  }
  else
  {
   struct node *previous = head;
   while(location->next != NULL)
   {
     if(location->rollNumber > srcRno)
     {
     	
  	struct node *nextNode=(node *)malloc (sizeof(node));
	previous->next=nextNode;
  	nextNode->rollNumber = srcRno ;
   	nextNode->name = new char[strlen(srcName)];
  	strcpy(nextNode->name,srcName);
 	nextNode->next = location;
	break;
     }
     previous = location;
     location=location->next;
   }
  struct node *nextNode=(node *)malloc (sizeof(node));
  location->next=nextNode;
  nextNode->rollNumber = srcRno ;
  nextNode->name = new char[strlen(srcName)];
  strcpy(nextNode->name, srcName);
  nextNode->next = NULL;
  }
return (head);
}

cLinkList:: node *cLinkList::delete_Node(struct node *head, int srcRno)
{
   node *location = head;
   node *previous = NULL;
   int flag = 0;
   if(head == NULL)
   {
	cout<<"\n there is no node to be deleted " ;
   }
   else if(head->rollNumber == srcRno)
   {
	struct node *newNode = head->next; 
	free(head);
	head = newNode;
   }
   else
   {
	while(location->next != NULL)
	{
	 if(location->rollNumber == srcRno)
        {
	  previous->next = location->next;
	  free(location);
	  flag = 1;
	  break;
	}
	previous = location;
	location = location->next;
        }

	if (flag == 1 )
	{
	  cout<<"\n the node was deleted";
	}
	
	else
	{
	  cout<<"\n the node with the matching roll number was not found";
	}
   }
   return (head);
}

void cLinkList::search_Node(struct node *head, int srcRno, char *srcName)
{
   struct node *location = head;
   
   while(location != NULL)
   {
	if(location->rollNumber == srcRno && strcmp(location->name,srcName)==0)
	{
	   cout<<"\n the roll number and name was found ";
	   cout<<"\n the roll number is"<<location->rollNumber<<" name found is"<<location->name;
	   break;
	}
	location = location->next;
   }

   if(location == NULL)
    {
	    cout<<"There is no matching entry with this name and roll number";
    }

	
}


class hashClass : public cLinkList 
{
	cLinkList objectArray;
	struct node *head[26] ;
//	memset((void*)head,0,sizeof(head)) ;
	int rollNumber;
	char name_entered[10];
	public: 
	hashClass();
	void input();
	void toInsert();
	void toDelete();
	void toSearch();
	void toPrint();
};

hashClass::hashClass()
{
	for(int i= 0 ; i<26; i++)
	{
	   head[i] = NULL;
	}
}
void hashClass::input()
{
   cout<<"\n enter the name";
   cin>>name_entered;
   cout<<"\nand roll number ";
   cin>>rollNumber;
   //gets(name);
}

void hashClass::toInsert()
{
   input();
   
   if(isalpha(name_entered[0]))
   {
	int value = 0;
	char c =  toupper(name_entered[0]);
	value = int(c);
	//cout<<"\n the value is"<<value;
	value = value-65;
	//cout<<"\n the value is"<<value;
//	cout<<"\n the value is"<<value;
//	cout<<"\n the value is"<<value;
//	cout<<"\n the value is"<<value;
//	cout<<"\n the value is"<<value;
	head[value] = objectArray.insert_Node(head[value],rollNumber,name_entered);
   }
  else
  {
	cout<<"\n wrong name entered";
  }
}

void hashClass::toDelete()
{
   input();
   if(isalpha(name_entered[0]))
   {
        int value = toupper(name_entered[0]);
        value = value-65;

        head[value] = objectArray.delete_Node(head[value],rollNumber);
   }
  else
  {
        cout<<"\n wrong name entered";
  }
}

void hashClass::toSearch()
{
  input();
  if(isalpha(name_entered[0]))
   {
        int value = toupper(name_entered[0]);
        value = value-65;

        objectArray.search_Node(head[value],rollNumber,name_entered);
   }
  else
  {
        cout<<"\n wrong name entered";
  }
}

void hashClass :: toPrint()
{
  char n;
  cout<<"\n enter the alphabet whose list you want to print";
  cin>>n;

  if(isalpha(n))
  {
	int value = toupper(n);
	value = value-65;
	struct node *location = head[value];
	if(location == NULL)
	{
		cout<<"\n there is no entry in the list";
	}	
	while(location != NULL)
	{
	   cout<<location->name<<"   " << location->rollNumber;
	   location = location->next;
	}
  }

  else
  {
    cout<<"\n wrong name entered";
  }
}


int main()
{
  hashClass h;

  char character;
  int number;
  do
  { 
     cout<<"\n enter your choice";
     cout<<"\n 1: add()";
     cout<<"\n 2: deletenode()";
     cout<<"\n 3: searchlist()";
     cout<<"\n 4: print()";
     cin>>number;

     switch(number)
     {

       case 1:h.toInsert();
      	      break;

       case 2:h.toDelete();
              break;
   
       case 3:h.toSearch();
              break;
        
       case 4:h.toPrint();
	      break;

       default:cout<<"\n you entered wrong choice";
               break;
      }

      cout<<"\n do you wish to continue enter your choice";
      cin>>character;

   }while(character=='y'||character=='Y');
return 0;
}
