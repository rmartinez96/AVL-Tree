// Raul Martinez
// raul.martinez01@utrgv.edu 

#include <iostream>

using namespace std;

class AVLTree
{
private:
	class node
	{
	public:
		double data;
		int height;
		node * left;
		node * right;

		node(double x)
		{
			data = x;
			height = -1;
			left = NULL;
			right = NULL;
		}
	};

	node * root;

	// gets max value of two ints
	int max(int a, int b)
	{
		return (a > b) ? a : b;
	}


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

		p->height = 1 + max(getHeight(p->left), getHeight(p->right));

		int bal = balance(p);

		//left case
		if (bal > 1 && x < p->left->data)
			leftRotation(p);

		//left-right case
		if (bal > 1 && x > p->left->data)
		{
			leftRotation(p->left);
			rightRotation(p);
		}

		//right case
		if (bal < -1 && x > p->right->data)
			leftRotation(p);

		//right-left case
		if (bal < -1 && x < p->right->data)
		{
			rightRotation(p->right);
			leftRotation(p);
		}

	}


	//print all items in tree rooted at p
	void display(node * &p)
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

	void rightRotation(node * &p)
	{
		node * a = p->left;
		node * b = p->right;

		a->right = p;
		p->left = b;

		p->height = max(getHeight(p->left), getHeight(p->right)) + 1;
		a->height = max(getHeight(a->left), getHeight(a->right)) + 1;

		p = a;
	}

	// left rotation method
	void leftRotation(node * &p)
	{
		node * a = p->right;
		node * b = p->left;

		a->left = p;
		p->right = b;

		p->height = max(getHeight(p->left), getHeight(p->right)) + 1;
		a->height = max(getHeight(a->left), getHeight(p->right)) + 1;

		p = a;
	}

	//returns back difference in height
	int balance(node * p)
	{
		if (p == NULL)
			return 0;

		return getHeight(p->left) - getHeight(p->right);
	}

	//returns height
	int getHeight(node * p)
	{
		if (p == NULL)
			return -1;
		else
			return p->height;
	}


public:
	AVLTree()
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