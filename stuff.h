#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

typedef struct node{
  int data;
  Node *left;
  Node *right;
}Node;

struct qnode{
	Node *data;
	struct qnode *next;
};

void mainLoop();
Node * insert(Node *, int);
Node *del(Node *, int);
void printInfo();
int search(Node *, int);
void printX(Node *,struct qnode *);
void freeRoot(Node *);
void freeQueue(struct qnode *queue);
void printError();
void lnr(Node *);
void lrn(Node *);
void nlr(Node *);
int height(Node *);
int max(int,int);
int balance(Node *);
void addRoot(Node *, struct qnode *);
Node *remRoot(Node *, struct qnode *);
void bfs(Node *, struct qnode *);
Node *largest(Node *);
