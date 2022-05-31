#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};
void PercolateUP(Node *temp){
	if(temp->left == NULL && temp->right == NULL){
		return;
	}
	
   	PercolateUP(temp->left);
	if(temp->left->data > temp->data){
		int x = temp->left->data;
		 temp->left->data = temp->data;
		 temp->data = x;	
	}
	
	PercolateUP(temp->right);
	if(temp->right->data > temp->data){
		int x = temp->right->data;
		 temp->right->data = temp->data;
		 temp->data = x;	
	}	

}
void PercolateDown(Node *temp){
	if(temp->left==NULL && temp->right==NULL){
		return;
	}
	if (temp->left->data<temp->data){
		int x=temp->left->data;
		temp->left->data=temp->data;
		temp->data=x;
	}
	if (temp->right->data<temp->data){
		int x=temp->right->data;
		temp->right->data=temp->right->data;
		temp->data=x;
	}

}

void traverse(Node *temp){
	cout<<temp->data<<" ";
	if(temp->left != NULL){
		traverse(temp->left);
	}
		
	if(temp->right != NULL){
			traverse(temp->right);
	}
	
}
int main(){
	Node *root, *node1,*node2,*node3,*node4,*node5,*node6;
	root = new Node;
	srand(time(0));
	
	root->data = rand()%200;
	node1 = new Node;
	node2 = new Node;
	
	node1->data = rand()%200;
	node2->data = rand()%200;
	root->left = node1;
	root->right = node2;
	
	node3 = new Node;
	node4 = new Node;
	node1->left = node3;
	node1->right = node4;
	
	node3->data = rand()%300;
	node4->data = rand()%300;
	
	node3->left = node3->right = NULL;
	node4->left = node4->right = NULL;
	
	node5 = new Node;
	node6 = new Node;
	node2->left = node5;
	node2->right = node6;
	
	node5->data = rand()%300;
	node6->data = rand()%300;
	
	node5->left = node5->right = NULL;
	node6->left = node6->right = NULL;
	
	traverse(root);
	cout<<endl;
	PercolateUP(root);
	
	traverse(root);
	
	
	return 0;
	
	
}
