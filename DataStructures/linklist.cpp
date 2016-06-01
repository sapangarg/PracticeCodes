#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

struct node
{
    int number;
    node *next;
};

struct node *insert(node *head, int num)
{
    if(head == NULL)
    {
	head = (node *) malloc(sizeof(node));
	head->number = num;
	head->next = NULL;
    }

    else
    {
	node *location = head;
	while(location->next != NULL)
	{
	    location = location->next;
	}
	struct node *newNode = (node *) malloc (sizeof(node));
	newNode->number = num;
	newNode->next = NULL;
	location->next = newNode;
    }

    return head;
}

void print(node *head)
{
    node *location = head;
    if(location->next == NULL)
    {

    	cout<<"\n"<<location->number;
    }

    else
    {
    	while(location != NULL)
    	{
		cout<<"\n"<<location->number;
		location = location->next;
    	}
    }
}

void delete_node(node *head, int node_num)
{
	node *location = head;
	node *previous = head;
	if (node_num == 1)
	{
		head = head->next;
		free(location);
	}

	else
	{
		for(int i =1; i<node_num; i++)
		{	
			previous = location;
			location = location->next;
		}

		previous->next = location->next;
		free(location);
	}
}

void remove_duplicates(node *head)
{
	node *location = head;
	int count = 1 ;
	while(location!=NULL)
	{
		location = location->next;
		count++;
	}
	location = head->next;
	node *temp = head;
	node *previous = head;
	for(int i = 0 ; i<count-1;i++)
	{
		while(location!=NULL)
		{
			if(location->number == temp->number)
			{
				previous->next = location->next;	
				location = location->next;
			}
			else
			{
				previous = location; 
				location = location->next;
			}
		}
		if(temp->next != NULL)
		{
			temp = temp->next;
			location = temp->next;
		}
		else
		{break;}
	}
}


struct node *add_reverse_numbers(node *head, node *head1)
{
	struct node *location = head;
	int count_first = 0, count_second = 0;
	int sum=0, sum1=0, final_sum=0;
	while(location!= NULL)
	{
		sum = location->number*pow(10,count_first) + sum;
		count_first++;
		location = location->next;
	}

	location = head1;
	while(location!= NULL)
	{
		sum1 = sum1 + pow(10,count_second)*location->number;
		count_second++;
		location = location->next;
	}

	cout<< sum << "    " << sum1;

	final_sum = sum+sum1;
	struct node *head2 = NULL;
	while(final_sum)
	{
		sum = final_sum % 10; 
		head2 = insert(head2, sum);
		final_sum /= 10;
	}
	return head2;
}


struct node *reverse(struct node *head)
{

	struct node *location = head->next;
	struct node *next = NULL;
	struct node *previous = head;
	head->next = NULL;
	while(location != NULL)
	{
		struct node *temp = location->next;
		location->next = previous;
		previous = location;
		location = temp;

	}
	
	return previous;
}

struct node *oddeven(struct node *head) // function to rearrange the list in odd nodes and even nodes based on their position
{
	if(!head || !head->next)
	{
		return head;
	}

		struct node *head_for_odd = head; 
		struct node *head_for_even = head->next; 
		struct node *for_odd = head_for_odd; 
		struct node *for_even = head_for_even; 

	while(for_odd && for_odd->next && for_odd->next->next)	
	{
		for_odd = for_odd->next->next;
		for_even = for_even->next->next;
		for_odd = for_odd->next;
		for_even = for_even->next;
	
	}

	for_odd->next = head_for_even;

	return head_for_odd;
}
int main()
{
    node *head = NULL;
    node *head1 = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
//    head = insert(head, 6);
    print(head);
    cout<<"\n\n\n";
    head1 = insert(head1, 1);
    head1 = insert(head1, 2);
    head1 = insert(head1, 13);
    head1 = insert(head1, 10);
    head1 = insert(head1, 6);
    print(head1);
    //head = insert(head, 1);
    //head = insert(head, 2);
   // head = insert(head, 3);
   // head = insert(head, 3);
    //head = insert(head, 3);
    cout<<"\n\n\n";
    //print(head);
    //remove_duplicates(head);
    //cout<<"\n\n\n";
    //print(head);
    head = reverse(head);
    print(head);
    head1 = reverse(head1);
    print(head1);
   // node *head2 = add_reverse_numbers(head, head1);
    //cout<<head2->number;
    //print(head2);
    return 0;
}
