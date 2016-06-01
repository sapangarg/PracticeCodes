#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
        int data;
	struct node* left;
	struct node* right;
};

int min_node = 1000;
int max_node = 0;
int path[10];
struct node *root = NULL;
struct node *root1 = NULL;
int lookup(struct node* start,int data);
struct node* insert(struct node* start,int data);
int traversal(struct node* node);
int maxdepth(struct node*node);
int haspathsum(struct node* node, int sum);
int printpath(struct node* node);
void mirror(struct node* node);
void doubleTree(struct node* node);
int same(struct node*a, struct node*b);
void minimum(struct node* node);
void maximum(struct node* node);
int BST(struct node* node);

int main()
{
	
	
	int choice = 0,number = 0,b=0,sum=0, result;
	char ch;
//	node *root= NULL;
	do
	{

	cout<<"\n enter your choice:";
	cout<<"\n 1.insert()";
	cout<<"\n 2.insert 2()";
	cout<<"\n 3.traverse()";
	cout<<"\n 4.maxdepth()";
	cout<<"\n 5.haspathsum()";
	cout<<"\n 6.printpath()";
	cout<<"\n 7.mirror()";
	cout<<"\n 8.doubleTree()";
	cout<<"\n 9.same()";
	cout<<"\n 10.isBST()";
	cout<<"\n 11.exit(0)";
	cin>>choice;
	
	switch(choice)
	{
	
	case 1: 
		cout<<"\n enter the data to be inserted";
		cin>>number;
		root = insert(root,number);
		break;

	case 2: cout<<"\n enter the data to be inserted";//replaced
		cin>>number;
		root1 = insert(root1,number);
		break;

	case 3: b=traversal(root);
		cout<<"\n the number of nodes in the tree is "<<b;
		cout<<"\n the smallest data in the tree is "<<min_node;
		break;

	case 4: b = maxdepth(root);
		cout<<"\n the max depth is"<<b;
		break;

	case 5: cout<<"\n enter the sum to be found";
		cin>>sum;
		b=haspathsum(root,sum);	
		if(b)
		{
		cout<<"the tree has the path equal to the sum";
		}
		else
		{
		 cout<<"\n the tree does not have the path equal to the sum";
		}
		break;

	case 6: printpath(root);
		break;


	case 7: mirror(root);
		break;


	case 8: doubleTree(root);
		break;

	case 9: b= same(root,root1);
		if(b)
		{
		  cout<<"\n the tree are same";
		}
		
		else
		{
		  cout<<"\n the tree are not same";
		}
		break;
	
	case 10: result = BST(root);
		 if(result)
		 {
		  cout<<"\n yes it is a Binary Tree";
		 }
	
		 else
		 {
		  cout<<"\n NO it is not a binary tree";
		 }
	
		 break;
	case 11: exit(0);
		 break;

	case 12: cout<<"\n enter the number to be looked for";
		 cin>>number;
		 result = lookup(root,number);
		 if(result == 1)
		 {
		 	cout<<"\n the number was found";
		 }

		 else
		 {
		 	cout<<"\n the number was not found";
		 }
		 break;
	
	default : cout<<"\n you entered wriong choice";
		  break;

	}
	cout<<"\n do you wish to continue";
	cin>>ch;
	}while(ch=='y' || ch=='Y');

return 0;
}



struct node* insert(node* start,int data)
{
	if(start == NULL)
	{
		struct node *temp = new(struct node);
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		return(temp);
	}

	else
	{
		if(data < start->data)
		{
			start->left = insert(start->left, data);
		}
		else
		{
			start->right = insert(start->right, data);
		}
	}
return start;
}


int lookup(struct node* start,int data)
{
	if(start == NULL)
	{
		return 0;
	}

	if(start->data == data)
	{
		return 1;
	}

	else if(start->data > data)
	{
		lookup(start->left,data);
	}

	else if(start->data < data)
	{
		lookup(start->right,data);
	}

	else
	{
		return 0;
	}
}


int traversal(struct node* node)
{
	static int count = 0;
	if(node == NULL)
	{
		return count;
	}

	else
	{
		count++;
		traversal(node->left);
		return(traversal(node->right));
	}
}


int maxdepth(struct node* node)
{
	int left = 0;
	int right = 0;

	if(node == NULL)
	{
		return 0;
	}
	
	left =  maxdepth(node->left);
	right = maxdepth(node->right);
	if(right > left)
	{
		return (right+1);
	}

	else
	{
		return (left+1);
	}
}


int haspathsum(struct node* node, int sum)
{
	if(node == NULL)
	{
		return (sum == 0);
	}

	return(haspathsum(node->left,(sum-node->data)) || haspathsum(node->right,(sum-node->data)));
}


int printpath(struct node* node)
{
	static int temp = 0;
	if(node == NULL)
	{
		return 0;
	}

	if(node->left == NULL && node->right == NULL)
	{
		for(int i = 0; i<temp ; i++)
		{
			cout<< " " << path[i];
		}

		cout<<" " << node->data<<"\n";
		return 1;
	}

	path[temp] = node->data;
	temp++;
	printpath(node->left);
	printpath(node->right);
	temp--;
}

void mirror(struct node* node)
{
	if(node == NULL)
	{
		return ;
	}
	
	struct node *temp = node->left;
	node->left = node->right;
	node->right = temp;

	mirror(node->right);
	mirror(node->left);

	
}

void doubleTree(struct node* node)
{
	if(node == NULL)
	{
		return ;
	}

	struct node *temp = node->left;
	struct node *newnode = new (struct node);
	newnode->data = node->data;
	newnode->left = temp;
	newnode->right = NULL;
	node->left = newnode;
	doubleTree(newnode->left);
	doubleTree(node->right);

}

int same (struct node *a, struct node *b)
{
	static int flag = 0;
	if((a==NULL && b != NULL) || (a!= NULL && b == NULL))
	{
		flag++;
		return false;
	}

	if(a == NULL || b == NULL)
	{
		return true;
	}

	if(a->data == b->data)
	{
		same(a->left, b->left);
		same(a->right, b->right);
	}

	else
	{
		flag++;
	}

	if(flag == 0)
	{
		return true;
	}

	else
	{
		return false;
	}


}


void minimum(struct node* node)
{
	if(node == NULL)
	{
		return;
	}	

	if(node->data < min_data)
	{
		min_data = node->data;
	}

	minimum(node->left);
	minimum(node->right);
}

void maximum(struct node* node)
{
	if(node == NULL)
	{
		return;
	}	

	if(node->data > min_data)
	{
		min_data = node->data;
	}

	maximum(node->left);
	maximum(node->right);
}

int BST(struct node* node)
{
	

}	

