#include "stuff.h"

//Global variable for printing commas
int printFlag = 1;

Node *del(Node *root, int num){

//if empty tree or reach null leaf
	if(root == NULL)
		return NULL;

	if(num < root->data){		//if num is less than root then delete from the left side
		root->left = del(root->left,num);
		return(root);
	}
	else if(num > root->data){	//if num is greater than root then delte from the right side
		root->right = del(root->right,num);
		return(root);

//We are deleting the root
	}else{

//if both the left and right are null then simply free root and make it null
		if(root->right == NULL && root->left == NULL){
			free(root);
			root=NULL;
		}

//if the right side of root is null then
		else if(root->right == NULL){
			Node *temp = root;		//store root in temp variable
			root = root->left;		//set previous root to point to the left side of current root
			free(temp);		//free the current root
		}

//if the left side of root is null
		else if(root->left == NULL){
			Node *temp = root;		//store root in a temp
			root = root->right;		//set previous root to point to the right side of current root
			free(temp);		//free current root
		}

	//if both left and right side are leafes
		else{
			Node *temp = largest(root->left);		//find the largest node on the left side of the tree
			root->data = temp->data;		//set current root data to the data of largest node
			root->left = del(root->left, temp->data);		//set the left side of the root tp the tree on the left  which doesn't contain the largest node
		}
	}
	return root;
}


Node *largest(Node *root){
  while(root->right != NULL)	//go until the most right node is null, the node previous is then the largest
    root = (root->right);
	return (root);	//return the largest node
}

//Recursive search of the tree
int search(Node *root, int num){
	int ret = 0;

	if(root == NULL)	//if reach null leaf then return 0
		return 0;

	if(root->data == num)		//if find a node that equals number then return 1
		return 1;

//if number is greater than current, search right tree
	if(num > root->data){
		ret = search(root->right,num); //keep track of return values
		if(ret == 1)		return 1;		//if return value was a 1 then keep return 1 while digging out of the recursive loop
		else 	return 0;
	}

//if number is less than the current data then search left tree
	if(num < root->data){
		ret = search(root->left, num);
		if(ret == 1)	return 1;		//keep track of the return values while digging out of the recursive loop
		else return 0;
	}
	return 0;
}

Node *insert(Node *root, int num){

//Once reach a leaf that is null then create a new node and store data value
	if(root == NULL){
		Node *temp;
		temp = malloc(sizeof(Node));
		temp->data = num;
		temp->right = NULL;
		temp->left = NULL;
		return (temp);  //return new tree
	}

//if number is greater than current data then insert into the right tree
	if(num > root->data)
		root->right = insert(root->right,num);
//else search the left tree
	else
		root->left = insert(root->left, num);
}


void printX(Node *root, struct qnode *queue){

//Print Node Left Right of tree
	printFlag = 1; //set flag for comma
	printf("NLR: ");
	nlr(root);
	printf("\n");

//Print Left Node Right of tree
	printFlag = 1;	//set flag for comma
	printf("LNR: ");
	lnr(root);
	printf("\n");

//Print Left Right Node
	printFlag = 1;	//set flag for commas
	printf("LRN: ");
	lrn(root);
	printf("\n");

//Print BFS tree
	printFlag = 1;	//set flag for commas
	addRoot(root,queue);
	printf("BFS: ");
	bfs(root,queue);
	printf("\n");

//Print Height of the tree
	printf("HEIGHT: %d\n",height(root));

//Print if tree is Balanced
	printf("BALANCE ");
	if(balance(root))
		printf("YES\n");
	else
		printf("NO\n");

}

void bfs(Node *root, struct qnode *queue){

//Execute if root isnt null
	if(root != NULL ){
		Node *t = remRoot(root,queue);		//set temp variable to the node that is being removed from the queue
		if(t != NULL){									 //if the temp variable is null
			if(printFlag == 1)						//execute flag set up to keep commas in order
				printFlag = 0;
			else
				printf(", ");

			printf("%d",t->data);				//print data of temp variable
			addRoot(t->left,queue);		 //insert left side to queue
			addRoot(t->right,queue);  //insert right side to queue
		}
		bfs(t,queue);		//call bfs with new root
	}
}

void addRoot(Node *root, struct qnode *queue){
	struct qnode *temp = queue;

//if root thats passed isn't null
	if(root != NULL){
		while(temp->next != NULL)		//traverse to end of queue
			temp = temp->next;
		temp->next = malloc(sizeof(struct qnode));	//allocate memory for new queue node
		temp->next->next = NULL;										//set the next data field of new node to NULL
		temp->next->data = root;										//set the data of new node to the root
	}
}

Node *remRoot(Node *root, struct qnode *queue){

//As long as sentinel is not pointing to Null
	if(queue->next != NULL){
		Node *t = queue->next->data;		//set temp t equal to first tree in queue
		struct qnode *temp = queue->next;		//set temp q equal to first node in queue
		queue->next = queue->next->next;	//set sentinel next to point to node after the first in the queue
		free(temp);		//free first node
		return(t);		//return root of first tree in queue
	}
	return NULL;  //if queue is empty then return Null
}
