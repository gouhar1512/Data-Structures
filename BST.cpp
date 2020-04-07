#include<bits/stdc++.h>
#define ll 		long long int
#define ld 		long double
#define pll 	pair<ll,ll>
#define vll 	vector<ll>
#define pb 		push_back

using namespace std;
struct node
{
	int data;
	struct node* left;
	struct node* right;
};


struct node* newNode(int element)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));

	temp->data = element;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}


struct node* insertNode(struct node* root, int element)
{
	if(root == NULL)
	{
		return newNode(element);
	}
	else
	{
		if(element<=root->data)
		{
			root->left = insertNode(root->left,element);
		}
		else
		{
			root->right = insertNode(root->right,element);
		}

		return root;
	}
}


void inOrder(struct node* root)
{
	if(root==NULL)
		return;

	inOrder(root->left);
	printf("%d ",root->data);
	inOrder(root->right);
}

void solve()
{
	int n;
	cin>>n;
	int arr[n];
	for(ll i=0 ; i<n ; i++)
	{
		cin>>arr[i];
	}

	struct node* root = (struct node*)malloc(sizeof(struct node));

	root->data = arr[0];
	root->left = NULL;
	root->right = NULL;


	for(ll i=1 ; i<n ; i++)
	{
		insertNode(root,arr[i]);
	}

	inOrder(root);

}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif

	solve();


	return 0;
}