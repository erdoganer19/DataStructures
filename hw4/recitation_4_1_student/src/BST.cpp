#include <iostream>
#include <stack>
#include <list>
#include <queue>
#include "BST.h"

using namespace std;

BST::BST()
{
    this->root=nullptr;


}

BST::~BST()
{
 
 postorder_destruct(root);

}


Node* BST::get_root()
{
    return this->root;
}




    
void BST::add(int data)
{
    if(this->root == NULL){
        this->root=new Node(data);
    }
    else {
        this->root->add(data);
    }

}

void Node::add(int data){

        if(this->data>data)
            if(this->left != NULL)
                this->left->add(data);
            else this->left = new Node(data);
        else if(this->data<data)
            if(this->right != NULL)
                this->right->add(data);
            else this->right = new Node(data);
        else return;
}


void BST::corrupted_add(vector<int> data)
{
    queue<Node*> q;
    Node* temp;
    int turn = 0;    // Suggests the left turn
    while (!data.empty()){
        int num = data.back();
        data.pop_back();

        if (num == INT32_MIN){
            q.pop();
            continue;
        }

        Node* n = new Node(num);

        if (root == nullptr){
            root = n;
            q.push(root);
            q.push(root);
        }
        else{
            temp = q.front();
            q.pop();
            if(turn == 0){
                temp->set_left(n);
                turn = 1;
            }
            else if(turn == 1){
                temp->set_right(n);
                turn = 0;
            }
            q.push(n);
            q.push(n);
        }
    }
}



bool BST::contains(int data)
{
    
    Node* curr = root;
    bool n = true;
    while(n){
        if(curr->get_data() == data){
            break;
        }
        else if(curr->get_data()<data){
            if(curr->get_right() == nullptr){
                n = false;
                break;
            }
            else{
                curr = curr->get_right();
            }
        }
        else if(curr->get_data()>data){
            if(curr->get_left() == nullptr){
                n = false;
                break;
            }
            else{
                curr = curr->get_left();
            }
        }
    }
    return n;         

}








void BST::postorder_traverse(Node* n)
{


   if (n == NULL)
        return;
    
    // left 
    postorder_traverse(n->get_left());
 
    //right 
    postorder_traverse(n->get_right());
 
    cout << n->get_data() << " ";

}



void BST::postorder_destruct(Node* n)
{

   if(n){
        postorder_destruct(n->get_left());
        postorder_destruct(n->get_right());
        delete n;
        }


}


void BST::printPostOrder()
{
    this->postorder_traverse(this->root);
    cout << endl;
}

int BST::maxSumBST(Node* node){

    int sum = 0;
    if (root == NULL)	
		return 0;
	
	sum = INT32_MIN;

	findLargest(root, sum);

    return sum;
}


int BST::findLargest(Node* root, int& ans)
{

	if (root == NULL)	
		return 0;
	
	int currSum = root->get_data() + findLargest(root->get_left(), ans)+ findLargest(root->get_right(), ans);


	ans = max(ans, currSum);

	return currSum;
}

