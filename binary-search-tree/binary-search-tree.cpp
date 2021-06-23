#include<cstdlib>
#include <iostream>

struct node
{
	int data;
	node* left;
	node* right;

};

node* root;
//set current to be equal to root node
node* current = root;

//add nodes
void addNodes(int data);

//delete nodes
void deleteNodes(int data);

//function to add node
int main()
{
    //intial array
	int arr[] = { 50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80 };
	int arrSize = std::size(arr);

	for (int i = 0; i < arrSize; i++)
	{
		addNodes(arr[i]);
	}

	deleteNodes(78);
	
}

void addNodes(int data)
{
	node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;



	//check if root node is empty
	if (root == NULL)
	{
		root = temp;
		std::cout << data << " is the root" << std::endl;
	}
	else
	{

		//check if current node's value is > or <
		if (data < current->data)
		{
			if (current->left != NULL)
			{
				current = current->left;
				if (data < current->data)
				{
					addNodes(data);

				}
				else
				{
					if (data > current->data)
					{
						//check if current->right is null
						if (current->right != NULL)
						{
							current = current->right;
							addNodes(data);
						}
						else
						{
							current->right = temp;
							std::cout << data << " added right of node: " << current->data << std::endl;
						}
						
					}
					else
					{
						std::cout << "This value is already inserted" << std::endl;
					}
				}
			}
			else
			{
				current->left = temp;
				std::cout << data << " added to the left of node: " << current->data << std::endl;
			}
			
			
		}
		else
		{
			//check if right node is null
			if (current->right != NULL)
			{
				current = current->right;
				addNodes(data);
			}
			else
			{
				current->right = temp;
				std::cout << data << " added to the right of node: " << current->data << std::endl;
			}

		}


	}
	
	current = root;
}

void deleteNodes(int data) {
	node* temp;
	node* prev = current;

	//check if root node is data to delete
	if (root->data == data)
	{
		//find least value in right side and make it root
		current = root->right;
		//go left of each node
		while (current->left != NULL)
		{
			current = current->left;
		}

		root->data = current->data;
		std::cout << "\nNew root data is: " << root->data << std::endl;
		delete current;
	}
	else
	{

		if (data < current->data)
		{
			if (current->left != NULL)
			{

				current = current->left;
				deleteNodes(data);
			}
			else
			{
				std::cout << "This value is not available in the tree\n";
			}

		}
		else if(data > current->data)
		{
			if (current->right != NULL)
			{
		
				current = current->right;
				deleteNodes(data);
			}
			else
			{
				std::cout << "This value is not available in the tree\n";
			}
			
		}
		else
		{
			//condition where current data is equal to data to delete
			
			//check if node has right side
			if (current->right != NULL)
			{
				//traverse rest of its children to find least value from its right side
				temp = current->right;
				while (temp->left != NULL)
				{
					temp = temp->left;
				}
				std::cout << "Deleting node: " << current->data << " and replacing with: " << temp->data << std::endl;
				//replace current value with temp
				current->data = temp->data;
				
				
			}
			else
			{
				if (current->left != NULL)
				{
					//has single child so child replaces node in tree
					temp = current->left;
					if (prev->left->data == current->data) {
						prev->left = temp;
						std::cout << "Deleting node: " << current->data << " and replacing with: " << temp->data << std::endl;
					}
					else
					{
						prev->right = temp;
						std::cout << "Deleting node: " << current->data << " and replacing with: " << temp->data << std::endl;
					}
				}
				else
				{
					std::cout << "Deleting node: " << current->data << " with no replacement " << std::endl;
				}

				
				
			}

		}
	}
	
	current = root;
}


