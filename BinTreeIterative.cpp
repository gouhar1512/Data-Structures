//Iterative Approach

#include<stdio.h>
#include<iostream>
#include<queue>
#include<stack>
typedef struct node node;
using namespace std;

//Function Prototypes
void inOrder(node *);
void preOrder(node *);
void postOrder(node *);

struct node{
	int data;
	node *left, *right;
};

node *root = NULL;


void printTree(){
	preOrder(root);cout<<endl;
	inOrder(root);cout<<endl;
	postOrder(root);cout<<endl;
}

node *createNode(int data){
	node *link = (node*)malloc(sizeof(node));
	link->data = data;
	link->left = NULL;
	link->right = NULL;
	return link;
}

/*------TREE TRAVERSAL---------*/

void preOrder(node *ptr){
	// if(ptr==NULL){
	// 	return;
	// }
	// stack<node*> st;
	// st.push(ptr);
	// while(!st.empty()){
	// 	node* x = st.top();
	// 	st.pop();
	// 	cout<<x->data<<' ';

	// 	if(x->right){
	// 		st.push(x->right);
	// 	}

	// 	if(x->left){
	// 		st.push(x->left);
	// 	}
	// }
}

void inOrder(node *ptr){	// verified
	if(ptr==NULL){
		return;
	}
	stack<node*> st;
	while(true){
		while(ptr != NULL){
			st.push(ptr);
			ptr = ptr->left;
		}
		if(st.empty()){
			break;
		}
		
		ptr = st.top();
		st.pop();
		cout<<ptr->data<<' ';
		ptr = ptr->right;
	}

}

void postOrder(node *ptr){
	// if(ptr==NULL){
	// 	return;
	// }
	// stack<node*> st;
	// st.push(ptr);
	// while(!st.empty()){
	// 	node* x = st.top();
	// 	st.pop();
	// 	if(x->right){
	// 		st.push(x->right);
	// 	}
	// 	if(x->left){
	// 		st.push(x->left);
	// 	}
	// 	cout<<x->data<<' ';
	// }
}


void insertNode(int data, node *ptr){
	if(ptr == NULL){
		root = createNode(data);
		return;
	}
	queue<node*> q;
	q.push(ptr);
	while(!q.empty()){
		ptr = q.front();
		q.pop();

		if(ptr->left == NULL){
			ptr->left = createNode(data);
			break;
		}else{
			q.push(ptr->left);
		}

		if(ptr->right == NULL){
			ptr->right = createNode(data);
			break;
		}else{
			q.push(ptr->right);
		}
	}
}

node *getNodeByValue(int data, node *ptr){

	if(ptr==NULL){
		return NULL;
	}
	if(ptr->data == data){
		return ptr;
	}

	node *leftNode = getNodeByValue(data, ptr->left);
	if(leftNode != NULL){
		if(leftNode->data == data){
			return leftNode;
		}
	}
	node *rightNode = getNodeByValue(data, ptr->right);
	if(rightNode != NULL){
		if(rightNode->data == data){
			return rightNode;
		}
	}
	return NULL;
}

void deleteDeepestNode(node *temp){
	node *parent = root;
	node *deepest = root;
	queue<node *> q;
	q.push(root);
	while(!q.empty()){
		deepest = q.front();
		q.pop();
		if(deepest->left){
			parent = deepest;
			q.push(deepest->left);
		}
		if(deepest->right){
			parent = deepest;
			q.push(deepest->right);
		}
	}

	temp->data = deepest->data;


	if(parent==deepest){
		root = NULL;
	}else{
		if(parent->left==deepest){
			parent->left = NULL;
			delete(deepest);
		}else{
			parent->right = NULL;
			delete(deepest);
		}
	}
}

void deleteNode(int data){

	node *temp = getNodeByValue(data, root);
	if(temp!=NULL){
		deleteDeepestNode(temp);
	}
}




int main(){


	insertNode(1, root);
	insertNode(2, root);
	insertNode(3, root);
	insertNode(4, root);
	insertNode(5, root);
	insertNode(6, root);
	insertNode(7, root);

	inOrder(root);
	// inOrder(root);
	// cout<<endl;
	// postOrder(root);
	// cout<<endl;
	// deleteNode(9);
	// printTree();
	// deleteNode(5);
	// printTree();


	cout<<endl;

	return 0;
}