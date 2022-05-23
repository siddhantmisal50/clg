/*
PS= Beginning with an empty binary search tree, construct binary search tree by
inserting the values in the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path from root
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped at every node
v. Search a value


Algorithm to insert a node in the binary tree:
1. Create a new BST node and assign values to it.
2. insert(node, key)
i) If root == NULL,
return the new node to the calling function.
ii) if root=>data < key
call the insert function with root=>right and assign the return value in root=>right.
root->right = insert(root=>right,key)
iii) if root=>data > key
call the insert function with root->left and assign the return value in root=>left.
root=>left = insert(root=>left,key)
3. Finally, return the original root pointer to the calling function.



Algorithm to find the minimum value in binary tree:
1. Define Node class which has three attributes namely: data, left and right. Here, left represents the left
child of the node and right represents the right child of the node.
2. When a node is created, data will pass to data attribute of node and both left and right will be set to
null.
3. Define another class which has an attribute root.
A) Root represent root node of the tree and initialize it to null.
*/


#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *l;
    Node *r;
    Node(int val)
    {
        data = val;
    }
} *head = NULL, *temp;
int checkTree(Node *temp, Node *ptr) // insert node in the BST.
{
    if (temp->data == ptr->data)
    {
        cout << "Repeated Entry";
        return 0;
    }
    else if (temp->data > ptr->data)
    {
        if (temp->l == NULL)
        {
            temp->l = ptr;
            return 1;
        }
        else
        {
            temp = temp->l;
            checkTree(temp, ptr);
        }
    }
    else if (temp->data < ptr->data)
    {
        if (temp->r == NULL)
        {
            temp->r = ptr;
            return 1;
        }
        else
        {
            temp = temp->r;
            checkTree(temp, ptr);
        }
    }
}
int insert(int val) // create node to be inserted.
{
    Node *ptr = new Node(val);
    ptr->l = NULL;
    ptr->r = NULL;
    if (head == NULL) // or root
    {
        head = ptr;
        return 1;
    }
    else
    {
        temp = head;
        checkTree(temp, ptr);
    }
    return 0;
}
void display(Node *root) // in order way.
{
    if (root != NULL)
    {
        display(root->l);
        cout << root->data << "\t";
        display(root->r);
    }
}
int minimum(Node *root) // returns minimum element.
{
    temp = root;
    while (temp->l != NULL)
    {
        temp = temp->l;
    }
    return temp->data;
}
int search(Node *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == key)
    {
        return 1;
    }
    else if (root != NULL)
    {
        if (root->data > key)
        {
            search(root->l, key);
        }
        else if (root->data < key)
        {
            search(root->r, key);
        }
    }
}
int main()
{
    int num, choice, key;
    while (1)
    {
        cout << "\nEnter choice : \n1. Insert Node\n2. Display Tree\n3. Search Node\n4. Minimum Node in Tree\n5. Exit.\n-->";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter num : ";
            cin >> num;
            insert(num);
            break;
        case 2:
            display(head);
            break;
        case 3:
            cout << "Enter element to search : ";
            cin >> key;
            if (search(head, key) == 1)
            {
                cout << "It is present!";
            }
            else
            {
                cout << "Not present!";
            }
            break;
        case 4:
            cout << minimum(head);
            break;
        default:
            exit(1);
        }
    }
}