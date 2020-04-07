/*
	1. All possible Binary Trees with given inorder traversal
	2. Finding inorder predecessor and successor
	3. Print node at a given level
*/
#include<stdio.h>
#include<iostream>
#include<queue>

//Utility macros
#define Node node
#define pb push_back
#define nl cout<<"\n"
#define print(x) cout<<x->data<<' ';

typedef struct node node;
using namespace std;


#include "binTree_layout.cpp"


// All possible Binary Trees with given inorder traversal
/*vector<node*> getTrees(int a[], int start, int end){

	vector<node*> trees;

	if(start>end){
		trees.pb(NULL);
		return trees;
	}

	for(int i=start ; i<=end ; i++){
		vector<node*> ltrees = getTrees(a, start, i-1);
		vector<node*> rtrees = getTrees(a, i+1, end);

		for(int j=0 ; j<ltrees.size() ; j++){
			for(int k=0 ; k<rtrees.size() ; k++){
				node *newNode = createNode(a[i]);
				newNode->left = ltrees[j];
				newNode->right = rtrees[k];
				trees.pb(newNode);
			}
		}
	}
	return trees;
}*/


//Replacing nodes with its inorder predecessor
int inPred = 0;
void inorderPred(node *ptr){
	if(ptr==NULL){
		return;
	}
	inorderPred(ptr->left);

	int temp = ptr->data;
	ptr->data = inPred;
	inPred = temp;
	
	inorderPred(ptr->right);
}


//Replacing nodes with its inorder successor
int inSucc = 0;
void inorderSucc(node *ptr){
	if(ptr==NULL){
		return;
	}
	inorderSucc(ptr->right);

	int temp = ptr->data;
	ptr->data = inSucc;
	inSucc = temp;
	
	inorderSucc(ptr->left);
}

//Print node at a given level

void printNodeAtLevel(node *ptr, int level){	//left to right
	if(ptr==NULL){
		return;
	}
	printNodeAtLevel(ptr->left, level-1);
	if(level == 1){
		print(ptr);
	}
	printNodeAtLevel(ptr->right, level-1);
}

void printNodeAtLevelRev(node *ptr, int level){	//right to left
	if(ptr==NULL){
		return;
	}
	printNodeAtLevelRev(ptr->right, level-1);
	if(level == 1){
		print(ptr);
	}
	printNodeAtLevelRev(ptr->left, level-1);
}


void printEachLevelInNewLine(node *ptr){
	//Method 1 : using printNodeAtLevel()
	//Method 2 : below

	queue<node*> q;
	q.push(ptr);
	while(!q.empty()){
		int sz = q.size();
		while(sz--){
			node *x = q.front();
			q.pop();
			cout<<x->data<<' ';
			if(x->left){
				q.push(x->left);
			}
			if(x->right){
				q.push(x->right);
			}
		}
		cout<<endl;
	}

}

int main(){

	int n = 10;
	for(int i=1 ; i<=n ; i++){
		insertNode(i, root);
	}
	inOrder(root);nl;

	// for(int i=1 ; i<=4 ; i++){
	// 	printNodeAtLevelRev(root, i);nl;
	// }
		
	printEachLevelInNewLine(root);

	return 0;
}