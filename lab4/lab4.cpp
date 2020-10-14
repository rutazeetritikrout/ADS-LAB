#include<bits/stdc++.h>

using namespace std;

class node
{
	public:
	int data;
	node *left;
	node *right;
	node(int val)																	
	{
		data = val;
		left = NULL;
		right  = NULL;
	}
};


int height(node *head)																		
{
	if(head==NULL)
		return 0;
	int leftHeight = 1, rightHeight = 1;
	leftHeight += height(head->left);
	rightHeight += height(head->right);
	if(leftHeight>rightHeight)
		return (leftHeight);
	return (rightHeight);
}

node *leftRotate(node *head)																
{
	node *child = head->right;
	node *grandChild = head->right->left;
	child->left = head;
	head->right = grandChild;
	return child;
}

node *rightRotate(node *head)																
{
	node *child = head->left;
	node *grandChild = head->left->right;
	child->right = head;
	head->left = grandChild;
	return child;
}


node *balance(node *head)													   				
{
	int bal = height(head->left) - height(head->right);
	
	if(bal>1)
	{
		
		if(height(head->left->right) <= height(head->left->left)) 							
		{
            //left left case
			return rightRotate(head);
		}
		else if(height(head->left->right) > height(head->left->left)) 						
		{
            //left right case
			head->left = leftRotate(head->left);
			return rightRotate(head);
		}
	}
	else if(bal<-1)
	{
		
		if(height(head->right->left) <= height(head->right->right)) 						
		{
            //right right case
			return leftRotate(head);
		}
		else if(height(head->right->left) > height(head->right->right))  					
		{
            // right left case
			head->right = rightRotate(head->right);
			return leftRotate(head);
		}
	}
	return head;
}

node *inorderSuccessor(node *head)															
{																							
	node *temp = head;
	while(head->left!=NULL)
		head = head->left;
	return head;
}

node *insert(node *head, int val)
{
	if(head==NULL)																			
		return new node(val);
		
	if(val < head->data)
		head->left = insert(head->left,val);
	else if(val > head->data)
		head->right = insert(head->right,val);
	else																					
		return head;
	return balance(head);																	
}

node *deleteNode(node *head, int val)
{
	if(head==NULL)																			
		return head;
	if(val < head->data)
		head->left = deleteNode(head->left,val);
	else if(val > head->data)
		head->right = deleteNode(head->right,val);
	else																					
	{
		if(head->left == NULL && head->right == NULL)									
		{
			delete head;
			return NULL;
		}
		else if(head->left==NULL)														
		{
			node *temp = head;
			head = head->right;
			delete temp;
		}
		else if(head->right==NULL)														
		{
			node *temp = head;
			head= head->left;
			delete temp;
		}
		else																				
		{
			node *temp = inorderSuccessor(head->right);									 
			head->data = temp->data;														
			head->right = deleteNode(head->right,temp->data);								
		}
	}
	if(head==NULL)
	return NULL;
	
	return balance(head);
	
}


void preOrderTraversal(node *head)  														
{  
	node *temp = head;
    if(temp == NULL)   
    	return;
    cout << temp->data << " ";  
    preOrderTraversal(temp->left);  
    preOrderTraversal(temp->right);  
}  

int main()
{
	node *head = NULL;
	
		for(;;)
		{
			int choice;
			cout<<"[1]Insert \n[2]Delete \n[3]Exit \nEnter choice: ";
			cin>>choice;
			switch(choice)
			{
				case 1: cout<<"Enter the number to be inserted: ";
						cin>>choice;
						head = insert(head,choice);
						cout<<"the tree is :\t";
						preOrderTraversal(head);
						cout<<"\n\n";
						break;
				case 2: cout<<"Enter the number to be deleted: ";
						cin>>choice;
						head = deleteNode(head,choice);
						preOrderTraversal(head);
						cout<<"\n\n";
						break;
				default: return 0;
			}
		}
	return 0;  
}
