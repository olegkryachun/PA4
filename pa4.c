/*
Creator: Oleg Kryachun
Date: February 01 2019
Class: CSE 222
Assignment: PA4

Summary, this program creates a Binary Search Tree (BST) based on input from the user. The whole program is recursive which make for simple yet difficult writing.
The main program can insert, delete, and search. When inserting, the characteristic of a binary search order of complexity (log(n)) is preserved, the tree is always sorted after
numbers are inserted. Delete removes a root and if the root had chilren, it takes the largest node from the right and sets it as root. Search finds the node. At the end the program
frees all the memory and thats about all there is to a BST.

*/


#include "stuff.h"

int main(){

	mainLoop();
	return 0;
}
