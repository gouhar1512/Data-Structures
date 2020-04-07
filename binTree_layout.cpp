//Function Prototypes
void inOrder(node *);
void preOrder(node *);
void postOrder(node *);

struct node{
	int data;
	node *left, *right;
};

node *root = NULL;

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
