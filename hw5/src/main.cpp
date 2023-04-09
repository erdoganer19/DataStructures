#include <iostream>
#include <vector>
#include "BinSTree.h"

using namespace std;

void print_menu();
bool perform_operation(char);
void convert(Node*);
void print_preorder_heap(Node*);
void print_less_than(int n, Node*);
void BST_to_MinHeap(Node*, vector<int> , int*);
void inorder_traversal(Node*, vector<int>&);

BinSTree* bst = new BinSTree();

int main()
{

    bool end = false;
    char choice;


    while (!end)
    {
        print_menu();
        cin >> choice;
        end = perform_operation(choice);
    }

    return EXIT_SUCCESS;
}

void print_menu()
{
    cout << "Choose an operation" << endl;
    cout << "A: Add node to Binary Search Tree" << endl;
    cout << "C: Convert Binary Search Tree to Min Heap"<< endl;
    cout << "L: List Heap node less than the entered value"<< endl;
    cout << "P: Print Min Heap"<< endl;
    cout << "E: Exit" << endl;
    cout << "Enter a choice {A,C,L,P,E}:";
}

bool perform_operation(char choice)
{
    bool terminate = false;
    int e,l;

    switch (choice)
    {
        case 'A':
        case 'a':
            cout << "Enter node data:";
            cin >> e;
            bst->add(e);
            break;
        case 'C':
        case 'c':
            bst->root = bst->buildTree();
            convert(bst->root);
            break;
        case 'L':
        case 'l':
            cout << "Enter value:";
            cin >> l;
            print_less_than(l, bst->root);
            cout << endl;
            break;
        case 'P':
        case 'p':
            print_preorder_heap(bst->root);
            cout << endl;
            break;
        case 'E':
        case 'e':
            terminate = true;
            break;
        default:
            cout << "Error: You have entered an invalid choice" << endl;
            cin >> choice;
            terminate = perform_operation(choice);
            break;
    }
    return terminate;
}

void convert(Node* root)
{
    vector<int> arr;
    int i = -1;
    inorder_traversal(root, arr);
    BST_to_MinHeap(root, arr, &i);
}
void print_preorder_heap(Node* root)
{
    if(root)
    {
        cout << root->get_data() << " ";
        print_preorder_heap(root->get_left());
        print_preorder_heap(root->get_right());
    }
}
void print_less_than(int n, Node* root)
{
    //This function takes two parameters. First parameter is n which is the value of user wants to print
    //all nodes less than n. Second parameter is the root.

    if (root->get_data() >= n)
    {
        return;
    }
   
   
    cout<<root->get_data()<< " " ;

    if (root->get_left() != NULL)
        print_less_than(n,root->get_left());
    if (root->get_right() != NULL)
        print_less_than(n,root->get_right());

    //– Using preorder traversing and recursive, you should write the nodes value of the Min Heap(converted
    //from Complete Binary Search Tree) which is less than x.

}

void BST_to_MinHeap(Node* root, vector<int> arr, int* i)
{   

    if (root == NULL)
        return;
 
    // first copy data at index 'i' of 'arr' to
    // the node
    root->set_data(arr[++*i]);
 
    BST_to_MinHeap(root->get_left(), arr, i);
 
    BST_to_MinHeap(root->get_right(), arr, i);

    //This function takes three parameters. First parameter is the root of the Complete Binary Search
    //Tree. Second parameter is a vector which holds the values of the nodes of the Binary Search
    //Tree in ascending order(these values are created in inorder traversal function). Third parameter
    //is used for index of the vector.

    //Using preorder traversing, you change the value of the Complete Binary Search Tree Nodes with
    //vector values one by one recursively. How the function works is shown in the figures below.
}


void inorder_traversal(Node* root, vector<int>& arr)
{
    //This function takes two parameters. Root of the Binary Search Tree and a vector. Firstly vector
    //is empty. Using inorder traversal, you should add the value of the nodes of Binary Search Tree
    //to vector recursively. Thus, the nodes added to the vector will be in ascending order.
    if(root!=NULL){
        inorder_traversal(root->get_left(),arr);
        arr.push_back(root->get_data());
        inorder_traversal(root->get_right(),arr);
    }
}

