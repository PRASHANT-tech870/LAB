#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *left;
	struct node *right;

};

typedef struct node *NODE;


NODE create_node(int item){
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	temp->data=item;
	temp->left=NULL;
	temp->right =NULL;
	return temp;
	

}

NODE insert_bst(NODE root, int item){

	NODE temp;
	temp=create_node(item);
	if(root==NULL)
		return temp;
	else{
		if(item< root->data)
			root->left =insert_bst(root->left, item);
		else
			root->right =insert_bst(root->right, item);
	
	
	}
	return root;



}


void preorder(NODE root){
	if(root!=NULL){
		printf("%d", root->data);
		preorder(root->left);
		preorder(root->right);
	
	}



}

void inorder(NODE root){
	if(root!=NULL){
	
		inorder(root->left);
		printf("%d", root->data);
		inorder(root->right);
	}



}

void postorder(NODE root){
	if(root!=NULL){
	
		postorder(root->left);
		postorder(root->right);
		printf("%d", root->data);
	}


}

NODE inordersuccessor(NODE root){

	NODE cur =root;
	while(cur->left !=NULL)
		cur= cur->left;
	return cur;
}
NODE delete_node(NODE root, int key){
	NODE temp;
	if(root==NULL)
		return NULL;
	if(key<root->data)
		root->left =delete_node(root->left, key);
	else if(key> root->data)
		root->right =delete_node(root->right, key);
	else{
		if(root->left == NULL){
		temp =root->right;
		free(root);
		return temp;
		}
		if(root->right ==NULL){
			temp= root->left;
			free(root);
			return temp;
		}
		temp =inordersuccessor(root->right);
		root->data= temp->data;
		root->right =delete_node(root->right, temp->data);	
	
	
	}
	return root;


}

int main(){

NODE root =NULL;
int ch, item, key;
for(;;){
printf("1.insert, 2.preorder, 3.inorder,4.postorder, 5.delete, 6.exit");
printf("choice\n");
scanf("%d", &ch);

switch(ch){

	case 1: printf("ele to be inserted");
		scanf("%d", &item);
		root= insert_bst(root,item);
		break;
	case 2: printf("preorder is \n");
		preorder(root);
		break;
	case 3: printf("inorder is \n");
		inorder(root);
		break;
	case 4: printf("postorder is \n");
		postorder(root);
		break;
	case 5: printf("node to be delted\n");
		scanf("%d", &key);
		root =delete_node(root, key);
		break;
	default :exit(0);

}


}
return 0;
}


