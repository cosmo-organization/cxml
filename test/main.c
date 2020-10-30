#include <stdio.h>
#include "../include/operation.h"
int main(int nargs, char** argvals) {
	struct node* root=createnode(NULL,"html");
	printf("%s\n",root->tag);
	struct node* head=createnode(root,"head");
	appendnode(head);
	deletenode(root);
	return 0;
}
