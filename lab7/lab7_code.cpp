#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *parent;
	node *left;
	node *right;
	int color;
};
typedef node* NODE;


class RBTree {
public:
	NODE root;
	NODE TNULL;

    RBTree()
	{
		TNULL = new node;
		TNULL->color = 0;
		TNULL->left = nullptr;
		TNULL->right = nullptr;
		root = TNULL;
	}

	void fixInsert(NODE k)
	{
		NODE u;
		while (k->parent->color == 1)
        {
			if (k->parent == k->parent->parent->right)
			{
				u = k->parent->parent->left;
				if (u->color == 1)
				{
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
                else
                {
					if (k == k->parent->left)
					{
						k = k->parent;
						rightRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					leftRotate(k->parent->parent);
				}
			}
			else
            {
				u = k->parent->parent->right;
				if (u->color == 1)
                {
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else
                {
					if (k == k->parent->right)
                    {
						k = k->parent;
						leftRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					rightRotate(k->parent->parent);
				}
			}
			if (k == root)
            {
				break;
			}
		}
		root->color = 0;
	}

	void printTree(NODE root, string indent,bool last)
	{

	   	if (root != TNULL)
        {
		   cout<<indent;
		   if (last)
		   {
		      cout<<"R----";
		      indent += "     ";
		   }
           else
           {
		      cout<<"L----";
		      indent += "|    ";
		   }
           string sColor = root->color?"RED":"BLACK";
		   cout<<root->data<<"("<<sColor<<")"<<endl;
		   printTree(root->left, indent,false);
		   printTree(root->right, indent,true);
		}

	}

	void leftRotate(NODE x)
	{
		NODE y = x->right;
		x->right = y->left;
		if (y->left != TNULL)
        {
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr)
        {
			this->root = y;
		}
		else if (x == x->parent->left)
        {
			x->parent->left = y;
		}
		else
        {
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;

	}


	void rightRotate(NODE x)
	{
		NODE y = x->left;
		x->left = y->right;
		if (y->right != TNULL)
        {
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr)
        {
			this->root = y;
		}
		else if (x == x->parent->right)
        {
			x->parent->right = y;
		}
		else
        {
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}


	void insertion(int key) {
		NODE new_node = new node;
		new_node->parent = nullptr;
		new_node->data = key;
		new_node->left = TNULL;
		new_node->right = TNULL;
		new_node->color = 1;

		NODE y = nullptr;
		NODE x = this->root;

		while (x != TNULL)
        {
			y = x;
			if (new_node->data < x->data)
			{
				x = x->left;
			}
            else
            {
				x = x->right;
			}
		}
		new_node->parent = y;
		if (y == nullptr)
        {
			root = new_node;
		}
		else if (new_node->data < y->data)
        {
			y->left = new_node;
		}
		else
        {
			y->right = new_node;
		}
		if (new_node->parent == nullptr)
        {
			new_node->color = 0;
			return;
		}

        if (new_node->parent->parent == nullptr)
        {
			return;
		}

		fixInsert(new_node);
	}

};

int main()
{
	RBTree bst;
	int n;
	cout<<"Enter no of elements to be inserted"<<endl;
	cin>>n;
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<n;i++)
    {
        int e;
        cin>>e;
        bst.insertion(e);
    }
    cout<<"Elements in tree are"<<endl;
    if(bst.root)
        bst.printTree(bst.root,"",true);

	return 0;
}
