#include "stuff.h"


void mainLoop(){

  Node *root = NULL;	//initialize root as empty

//Initialize the queue
	struct qnode *queue = malloc(sizeof(struct qnode));
		queue->next = NULL;
		queue->data = NULL;

  char buff[120];
  int num;

  printf("Welcome, Enter ? for help :");

  while(NULL != fgets(buff,120,stdin)){  //take input from stdin as long as there is stuff to take


    if(sscanf(buff,"%d",&num) == 1){  		 //User input a number

      if(search(root,num))							 //check if number already exists, if so print an Error message
        printf("ERROR: Number already existss\n");
      else
        root = insert(root,num);				 //if the number doesn't exist then add the number into the tree

    }else{    //User input something thats not a #

    switch(buff[0]){
      case 'd': //delete number from tree

        if(1 == sscanf(buff,"d %d",&num)){	//check if user input 'd #'
          if(search(root,num) == 0){				//if so the search the tree for the # if number doesnt exist then print an error
            printf("ERROR: Number not in tree\n");
            break;
          }
          root = del(root,num);					//set root equal to new root with the deleted number
        }else  printError();						//if d wasn't followed with a # then print error message
        break;

      case 's':   //search tree
        if(1 == sscanf(buff,"s %d",&num)){	//if user input s followed by # 
          if(search(root,num))							//search the tree for the #
            printf("Found %d\n",num);				//notify if found
          else
            printf("%d is not in tree\n",num);	//notify if not found
        }else  printError();	//if s wasn't followed by # then print error message
        break;

      case 'X':  //Examine tree
        printX(root,queue);
        break;

      case '?':   //Print command info
        printInfo();
        break;

      case 'Q':   //Free memory and quit program
				printf("Terminating Memory\n");
        freeRoot(root);
				freeQueue(queue);
        return;

      default: printError();	//if non of the cases matched then print error message by default
        break;

    }
    }
    printf(": ");
  }
}

