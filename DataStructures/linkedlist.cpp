
# include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
#include <string>
//using namespace std;

//struct Node
//{
	//int data;
	//struct Node * next;
//};

template <typename T>	
class Node
{
	private:
	T data;
	Node<T> * next;

public:
	Node (T tempData)
	{
		data = tempData;
		next = NULL;
	}

	Node<T> *  getNext();
	T  getData();
	void  setNext(Node<T> * n);
void  setData(T d);
};

template <typename T>
Node<T> * Node<T>::getNext()
{
	return next;
}

template <typename T>
T Node<T>::getData()
{
	return data;
}

template <typename T>
void Node<T>::setNext(Node<T> * n)
{
	next = n;
}

template <typename T>
void Node<T>::setData(T d)
{
	data = d;
}

 

template <typename T>
class LinkedList
{
private:

	 Node<T> * currentNode;
	 Node<T> * head;

public:
LinkedList()
{
	currentNode = NULL;
	head = NULL;
}

Node<T> * getHead();
Node<T> * getCurrentNode();
void addNode(T data);
void delete_Node_With_Data(T data);
void printLinkedList();
void addNode(T data, int position);
void reverseLinkedList();
void removeDuplicatesFromLinkedList();
 
};

template <typename T> 
Node<T> * LinkedList<T>:: getHead()
{
	return head;
}

template <typename T>
Node<T> * LinkedList<T> :: getCurrentNode()
{
	return currentNode;
}

template <typename T>
void LinkedList<T> :: addNode(T data)
{
	//std::cout<<"\n add called ";
	Node<T> * tempNode = new Node<T>(data);
	//tempNode->setData(data);
	//tempNode->setNext(NULL);

	if(head == NULL)
	{
		head = tempNode;
		currentNode = tempNode;
	}

	else
	{
		currentNode->setNext(tempNode);
		currentNode = tempNode;
	}

}

template <typename T>
void LinkedList<T> :: delete_Node_With_Data(T data)
{
	Node<T> * tempNode = head;
	Node<T> * previous ;

	while(tempNode != NULL && tempNode->getData() != data)
	{
		previous = tempNode;
		tempNode = tempNode->getNext();
	}

	if(tempNode == NULL)
	{
		throw "\n the data doesn't exist";
	}

	else if(tempNode->getData() == data)
	{
		previous->setNext(tempNode->getNext())  ;
		free(tempNode);
		std::cout<<"\n deletion successfull";
	}


} 
template <typename T>
void LinkedList<T> :: printLinkedList()
{
	Node<T> * tempNode = head;

	std::cout<<"\n";
	while(tempNode != NULL)
	{
		std::cout<<tempNode->getData()<< " ";
		tempNode = tempNode->getNext();
	}
	
}

template <typename T>
void LinkedList<T> ::  addNode(T data, int position)
{
	if(head == NULL)
		{
			//std::cout<<"\n No value in linked list";
			throw "\n No value in linked list";
			 
		}

	if(position <= 0 )
	{
		throw "\n Wrong value passed for deleting the node ";
	}

	if(position == 1)
	{
		Node<T> * newNode = new Node<T>(data);
		//newNode->setData(data);
		newNode->setNext(head)  ;
		head = newNode;
		 return;
	}

	Node<T> * tempNode = head;
	Node<T> * previous;

	int number_of_time_loop_run = 1; 

	while(number_of_time_loop_run < position)
	{
		if(tempNode->getNext() != NULL)
		{
			previous = tempNode;
			tempNode = tempNode->getNext();
			number_of_time_loop_run++;
		}

		else
		{
			throw "\n linked list does not have these many nodes";
			return;
		}
	}

	if(tempNode != NULL)
	{
		Node<T> * newNode = new Node<T>(data);
		//newNode->setData(data);
		//newNode->setNext(NULL)  ;
		previous->setNext(newNode) ;
		newNode->setNext(tempNode)  ;
	}

	 

}


template <typename T>
void LinkedList<T> ::  reverseLinkedList()
{
	if(getHead() == NULL)
		throw "\nlinked list is empty";

	Node<T> * tempNode = getHead();
	currentNode = tempNode;
	Node<T> * previousNode = NULL;
	Node<T> * nextNode = NULL;

	while(tempNode != NULL)
	{
		nextNode = tempNode->getNext();
		tempNode->setNext(previousNode);
		previousNode = tempNode;
		tempNode = nextNode;
		 
	}
 
	head = previousNode; 
 	 
}

template <typename T>
void LinkedList<T> ::  removeDuplicatesFromLinkedList()
{

	if(getHead() == NULL)
		throw "\n cannot remove anything as the linked list is empty";

	Node<T> * tempHead = getHead();
	Node<T> * previousNode = NULL;

	std::unordered_set<T> seenValues;

	while(tempHead != NULL)
	{
		if(seenValues.find(tempHead->getData()) != seenValues.end() )
		{
			Node<T> * tofreeNode = tempHead;
			previousNode->setNext(tempHead->getNext());
			free(tofreeNode);
			 
			if(previousNode->getNext() != NULL)
			{ 
				tempHead = previousNode->getNext();
			}
			else
			{
				tempHead = NULL;
			}
			
		}


		else
		{
			seenValues.insert(tempHead->getData()) ;
			previousNode = tempHead;
			tempHead = previousNode->getNext();
		}
	}

	currentNode = previousNode;
}

 


int main(int argc, char const *argv[])
{
	/* code */

	LinkedList<int> L1;
	std::cout<<"object created";
	L1.addNode(1);
 	L1.addNode(2);
 	L1.addNode(3);
 	L1.addNode(4);
 	L1.addNode(5);
 	L1.addNode(6);
	L1.printLinkedList();
 	try{
 		L1.delete_Node_With_Data(40);
 	}catch(const char * msg){
 		std::cerr<<msg<<std::endl;
 	}
 	
 	L1.printLinkedList();
 try
 {
 	L1.addNode(7,2);
 	L1.addNode(7,2);
 	L1.addNode(7,2);
	L1.addNode(7,2);
	L1.addNode(8,12);

}catch (const char* msg) {
     std::cerr << msg << std::endl;
   }
	
	L1.printLinkedList();
 
 	try{
 		L1.reverseLinkedList();
 	}catch(const char * msg){
 		std::cerr<<msg<<std::endl;
 	}
 	L1.printLinkedList();
 
 
 	try{
 		L1.removeDuplicatesFromLinkedList();
 
 	}catch(const char *msg){
 		std::cerr<<msg<<std::endl;
 	}
 
 	L1.printLinkedList();


 	LinkedList<std::string> L2;

 	L2.addNode("sapan");
 	L2.addNode("garg");
 	L2.addNode("this");
 	L2.addNode("is");
 	L2.addNode("to");
 	L2.addNode("test");
 	L2.printLinkedList();

 	L2.reverseLinkedList();
	L2.printLinkedList();

	L2.addNode("sapan");
 	L2.addNode("garg");
 	L2.addNode("sapan");
 	L2.addNode("garg");
 	L2.addNode("sapan");
 	L2.addNode("garg");
 	L2.addNode("sapan");
 	L2.addNode("garg");
 	L2.addNode("sapan");
 	L2.addNode("garg");
 	L2.printLinkedList();
 	L2.removeDuplicatesFromLinkedList();
	L2.printLinkedList();
L2.addNode("sapan1");
 	L2.addNode("garg2");
 	L2.printLinkedList();
	return 0;
}

