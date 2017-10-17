#include <iostream>
using namespace std;

class binarySearchTree
{
private:
	class node
	{
	public:
		double data;
		node * left;
		node * right;

		node(double x)
		{
			data = x;
			left = NULL;
			right = NULL;
		}
	};

	node * root;

	//insert x into tree rooted at p
	void insert(double x, node * &p)
	{
		if (p == NULL)
		{
			p = new node(x);
		}
		else
		{
			if (x < p->data)
			{
				//put in left subtree
				insert(x, p->left);
			}
			else
			{
				//put in right subtree
				insert(x, p->right);
			}
		}
	}

	//print all items in tree rooted at p
	void display(node * p)
	{
		if (p == NULL)
		{
			//no items!!!!! no need to do ANY WORK!!!
			//SAVING SO MUCH TIME NOT TYPING CODE!!!!
		}
		else
		{
			display(p->left);
			cout << p->data << endl;
			display(p->right);
		}
	}

	int getHeight(node * p)
	{
		if (p == NULL)
			return -1;

		return 1+ max(getHeight(p->left), getHeight(p->right));
		
	}

	int max(int a, int b)
	{
		return (a > b) ? a : b;
	}
public:
	binarySearchTree()
	{
		root = NULL;
	}

	void insert(double x)
	{
		insert(x, root);
	}

	void display()
	{
		display(root);
	}

	int getHeight()
	{
		return getHeight(root);
	}
};