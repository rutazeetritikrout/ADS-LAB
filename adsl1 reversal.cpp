#include<bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node *next;
	//struct node *prev;
};


struct node *Insert(struct node* head, int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node*));
	temp->data = data;
	temp->next = NULL;
	//temp->prev = NULL;
	if(head == NULL)
	return temp;
	struct node *temper = head;
	
	while(temper->next!=NULL)
	{
		temper = temper->next;
	}
	temper->next = temp;
	return head;
}

void print(struct node* head)
{
	if(head == NULL)
	cout<<"null";
	while(head!=NULL)
	{
		cout<<head->data<<" - > ";
		head = head->next;
	}
	cout<<endl;
}


struct node* rev(struct node *head, struct node *temp, struct node *answer, int k, int counter, struct node *ansstart)
{
	if(head==NULL)
	{
		if(temp!=NULL)
		{
			if(answer==NULL)
			{
				answer = temp;
				ansstart = temp;
			}
			else
			{
				answer->next = temp;
				//cout<<temp->data<<"  last";
			}
		}
		return ansstart;
	}
	
	if(counter==k)
	{
		//cout<<endl;
		if(answer==NULL)
		{
			answer = temp;
			ansstart = temp;
			//cout<<ansstart->data<<" first"<<endl;
			
		}
		else
		{
			answer->next = temp;
			//cout<<answer->data<<" again"<<endl;
		}
		temp = NULL;
		while(answer->next!=NULL)
			answer= answer->next;
		counter = 0;		
	}
	else
	{
		counter++;
		if(temp == NULL)
		{
			temp = head;
			head  = head->next;
			temp->next = NULL;
			//cout<<temp->data<<" "<<counter<<endl;
		}
		else
		{
			struct node *point;
			point  = temp;
			temp = head;
			head = head->next;
			temp->next = point;
			//cout<<temp->data<<" "<<counter<<endl;
		}
	}
	//cout<<head->data;
	return rev(head,temp,answer,k,counter,ansstart);
}


struct node *rapper(struct node*head, int k)
{
	struct node *temp = NULL;
	struct node *answer = NULL;
	struct node *ansstart = NULL;
	ansstart = rev(head,temp,answer,k,0,ansstart);
	//print(ansstart);
	return ansstart;
}

int main()
{
		struct node* head=NULL;
		head = Insert(head,1) ;  //1-&gt;2-&gt;2-&gt;4-&gt;5-&gt;6-&gt;7-&gt;8
		head = Insert(head,2) ;  //1-&gt;2-&gt;2-&gt;4-&gt;5-&gt;6-&gt;7-&gt;8
		head = Insert(head,2) ;  //1-&gt;2-&gt;2-&gt;4-&gt;5-&gt;6-&gt;7-&gt;8
		head = Insert(head,4) ;  //1-&gt;2-&gt;2-&gt;4-&gt;5-&gt;6-&gt;7-&gt;8
		head = Insert(head,1) ;  //1-&gt;2-&gt;2-&gt;4-&gt;5-&gt;6-&gt;7-&gt;8
		head = Insert(head,5) ;  //1-&gt;2-&gt;2-&gt;4-&gt;5-&gt;6-&gt;7-&gt;8
		head = Insert(head,6) ;  //1-&gt;2-&gt;2-&gt;4-&gt;5-&gt;6-&gt;7-&gt;8
		head = Insert(head,7) ;
		head = Insert(head,8) ;  //1-&gt;2-&gt;2-&gt;4-&gt;5-&gt;6-&gt;7-&gt;8
		  print(head);
		int k = 4;
		head = rapper(head,k);
		print(head);
		
		
		
}
