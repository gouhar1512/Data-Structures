//Recursive Approach

#include<stdio.h>
#include<iostream>
#include<queue>
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
	preOrder(root);
	cout<<endl;
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
	if(ptr==NULL){
		return;
	}
 	cout<<ptr->data<<' ';
	preOrder(ptr->left);
	preOrder(ptr->right);
}

void inOrder(node *ptr){
	if(ptr==NULL){
		return;
	}
	inOrder(ptr->left);
 	cout<<ptr->data<<' ';
	inOrder(ptr->right);
}

void postOrder(node *ptr){
	if(ptr==NULL){
		return;
	}
	postOrder(ptr->left);
	postOrder(ptr->right);
 	cout<<ptr->data<<' ';

}

/*------Since we are inserting node LEVEL wise so it can't be recursive------*/
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
	if(leftNode){
		if(leftNode->data == data){
			return leftNode;
		}
	}
	node *rightNode = getNodeByValue(data, ptr->right);
	if(rightNode){
		if(rightNode->data == data){
			return rightNode;
		}
	}
	return NULL;
}


node* parent = root;
node* deepest = NULL;
int maxLevel=0;
bool found = false;
void deleteDeepestNode(node *par, node* dep, int currLevel){
	
	if(dep == NULL){
		return;
	}

	if(dep->left == NULL && dep->right == NULL){
		if(maxLevel<currLevel){
			parent = par;
			deepest = dep;
			maxLevel = currLevel;
		}
		return;
	}
	
	deleteDeepestNode(dep, dep->right, currLevel+1);
	deleteDeepestNode(dep, dep->left, currLevel+1);
}

void deleteNode(int data){

	parent = root;
	deepest = NULL;
	maxLevel = 0;
	found = false;

	node *temp = getNodeByValue(data, root);
	if(temp){
		deleteDeepestNode(root,root, 1);

		if(parent==deepest){
			delete(deepest);
			root = NULL;
		}else if(deepest){
			if(parent->right == deepest){
				parent->right = NULL;
			}else{
				parent->left = NULL;
			}
			temp->data = deepest->data;
			delete(deepest);
		}
	}
}

/*----------Tree Traversal-------*/
void dfs(){
	/*
		DFS
			i. Preorder
			ii. Inorder
			iii. Postorder
		All traverse depth wise
	*/
	cout<<"\nPre-order : ";preOrder(root);
	cout<<"\nIn-order : ";inOrder(root);
	cout<<"\nPost-order : ";postOrder(root);
}

void bfs(){

	/*
		Level order traversal
	*/
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node *curr = q.front();
		q.pop();
		cout<<curr->data<<' ';
		if(curr->left){
			q.push(curr->left);
		}
		if(curr->right){
			q.push(curr->right);
		}
	}
}


int main(){

	insertNode(1, root);
	insertNode(3, root);
	insertNode(5, root);
	insertNode(9, root);
	insertNode(6, root);
	insertNode(7, root);
	insertNode(4, root);

	printTree();
	// inOrder(root);
	// cout<<endl;
	// postOrder(root);
	// cout<<endl;
 	// deleteNode(1);
	// printTree();
	// deleteNode(3);
	// printTree();
	// deleteNode(9);
	// printTree();
	// deleteNode(7);
	// printTree();
	// deleteNode(4);
	// printTree();
	// deleteNode(1);
	// printTree();
	// deleteNode(5);
	// printTree();
	// deleteNode(6);
	// printTree();
	// dfs();
	// cout<<"\nBFS : ";bfs();cout<<endl;


	cout<<endl;

	return 0;
}