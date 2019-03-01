#include "stuff.h"

extern int printFlag;

//print info for the porgram
void printInfo(){

  printf("Valid commands are:\n");
  printf("d #  delete # from the tree\n");
  printf("s #  search for #\n");
  printf("X    show contents and analysis of tree\n");
  printf("#    (any number) inserts that number into the tree\n");
  printf("?    gives this help message\n");
  printf("Q    free memory and quit\n");

}

//print message if input is invalid
void printError(){
  printf("Enter ? for help ");
}

//recursive print Left Node Right of the tree
void lnr(Node *root){
  if(root != NULL){
    lnr(root->left);

		if(printFlag == 1)
			printFlag = 0;
		else
			printf(", ");
  printf("%d",root->data);

    lnr(root->right);
  }
}

//recursibe print Node Left Right of the tree
void nlr(Node *root){
  if(root!=NULL){

    if(printFlag == 1)
      printFlag = 0;
    else
      printf(", ");

    printf("%d",root->data);

     nlr(root->left);
    nlr(root->right);
  }
}

//recursive print Left Right Node of the tree
void lrn(Node *root){
  if(root != NULL){
    lrn(root->left);
    lrn(root->right);

    if(printFlag == 1)
      printFlag = 0;
    else
      printf(", ");

    printf("%d", root->data);

  }
}

//recursive height calculator
int height(Node *root){

  if(root == NULL)
    return (-1);

  return(1+max(height(root->left),height(root->right)));
}


//return max of two numbers used in calculating the height
int max(int a, int b){

  if(a > b)
    return a;
  return b;

}

//recursivly freeing memory
void freeRoot(Node *root){
  if(root != NULL){
    freeRoot(root->left);
    freeRoot(root->right);
    free(root);
  }
}

void freeQueue(struct qnode *queue){

	while(queue != NULL){
		struct qnode *temp = queue;
		queue = queue->next;
		free(temp);
	}
	free(queue);
}


int balance(Node *root){

//as long is root isn't null and the height is 1 or less and both sides of the tree are balanced then Balanced is true
	if((root == NULL) ||((abs(height(root->left)-height(root->right)) <= 1) && balance(root->right) && balance(root->left)))
		return 1;
	else
	return 0;		//not balanced
}
