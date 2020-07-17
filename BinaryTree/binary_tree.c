#include <stdio.h> 
#include <stdlib.h> 
#include "./check_bst.h"
// struct BstNode{
// 	int data;
// 	struct BstNode* left;
// 	struct BstNode* right;
// };

struct BstNode* get_new_node(int data){
	struct BstNode* new_node=(struct BstNode*)malloc(sizeof(struct BstNode));
	new_node->data=data;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}

struct BstNode* insert(struct BstNode* root, int data){
	if(root==NULL){
		root=get_new_node(data);
	}
	else if(data<=root->data){
		root->left=insert(root->left,data);
	}
	else{
		root->right=insert(root->right,data);
	}
	return root;
}

int search(struct BstNode* root,int data){
	if(root==NULL){
		return 0;
	}
	if(root->data == data){
		return 1;
	}
	else if(data<=root->data){
		return search(root->left,data);
	}
	else{
		return search(root->right,data);
	}
}

//find and return the node 
struct BstNode* find(struct BstNode* root,int data){
	if(root==NULL){
		return NULL;
	}
	if(root->data == data){
		return root;
	}
	else if(data<=root->data){
		return find(root->left,data);
	}
	else{
		return find(root->right,data);
	}
}

//find the min element of the tree 
struct BstNode* find_min(struct BstNode* root){
	if(root==NULL){
		printf("Error:Empty tree\n");;
		return NULL;
	}
	if(root->left ==NULL){
		return root;
	}
	else{
		return find_min(root->left);
	}
}
//find the max element of the tree 
int find_max(struct BstNode* root){
	if(root==NULL){
		printf("Empty tree error\n");
		return -1;
	}
	if(root->right==NULL){
		return root->data;
	}
	else{
		return find_max(root->right);
	}
}

int max(int a,int b){
	int ret;
	ret=(a>b)?a:b;
	return ret;

}
//find the height of the tree 
int find_height(struct BstNode* root){
	if (root==NULL)
		return -1; 
	return max(find_height(root->left),find_height(root->right))+1;
	//calculate heights of left and right subtrees recursively 
}

void preorder(struct BstNode* root){
	if(root==NULL) return;
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(struct BstNode* root){
	if(root==NULL) return;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}
void postorder(struct BstNode* root){
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->data);
}
struct BstNode* delete(struct BstNode* root,int data){
	if(root==NULL)return root;
	else if(data<root->data){
		root->left=delete(root->left,data);
	}
	else if(data > root->data){
		root->right=delete(root->right,data);
	}
	else{
	        // data is found
		//case 1: the node has no child 
		if(root->left ==NULL && root->right==NULL){
			free(root);
			root=NULL;
		}
		//case 2: the node has one child 
		else if(root->left==NULL){
			struct BstNode* temp=root;
			root=root->right;
			free(temp);
		}
		else if(root->right==NULL){
			struct BstNode* temp=root;
			root=root->left;
			free(temp);
		}
		//case 3: has 2 children 
		else{
			struct BstNode* temp=find_min(root->right); // the idea is to find the minimum of the right subtree and put its data in the current node 
			//alternative idea: find the max of the left subtree and do the same thing 
			root->data=temp->data;
			root->right=delete(root->right,temp->data);
		}
	}
	return root;
		

}


struct BstNode* inorder_successor(struct BstNode* root,int data){
	struct BstNode* current;
	current=find(root,data);
	//case 1: current node has right subtree
	if(current->right!=NULL){
		return find_min(current->right);
	}
	else{
	//case 2: doesn't have the right subtree 
	//idea is to find the nearest ancestor to which the current node is in the left subtree 
	struct BstNode* ancestor=root; //kind of like iterator 
	struct BstNode* successor=NULL;
	while(ancestor != NULL){
		if(current->data < ancestor->data){
			successor=ancestor;
			ancestor=ancestor->left;
		}
		else{
			ancestor=ancestor->right;
		}
	}
	return successor;
}

} 
int main(){
	struct BstNode* root_ptr,*successor;
	int data;
	root_ptr=NULL;
	root_ptr=insert(root_ptr,8);
	root_ptr=insert(root_ptr,10);
	root_ptr=insert(root_ptr,7);
	root_ptr=insert(root_ptr,11);
	root_ptr=insert(root_ptr,9);

	printf("Enter a number to search:\n");
	scanf("%d",&data);
	search(root_ptr,data)?printf("Found"):printf("Not found\n");
	printf("Minimum element:%d\n",find_min(root_ptr)->data);
	printf("Maximum element:%d\n",find_max(root_ptr));
	
	printf("Height of the tree is:%d\n",find_height(root_ptr));
	is_binary_search_tree(root_ptr)?printf("It is a BST\n"):printf("Not a BST\n");
	
	printf("Preorder:\n");
	preorder(root_ptr);
	
	printf("\nPostorder:\n");
	postorder(root_ptr);
	
	printf("\nInorder:\n");
	inorder(root_ptr);
	
//	root_ptr=delete(root_ptr,7);
	printf("After deletion, inorder:");
	inorder(root_ptr);

	printf("Inorder successor:");
	successor=inorder_successor(root_ptr,8);
	printf("\t%d\n",successor->data);
	return 0;
}
