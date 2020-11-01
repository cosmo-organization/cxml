#include <stdio.h>
#include "../include/operation.h"
int main(int nargs, char** argvals) {
	struct node* root=createnode(NULL,"html");
	struct node* head=createnode(root,"head");
	struct node* body=createnode(root,"body");
	appendnode(head);
	appendnode(body);
	setattrib(body,createattrib("bgcolor","blue"));
	setattrib(body,createattrib("bg","test"));
	setattrib(body,createattrib("tx","100001"));
	removeattrib(body,"bg");
	removeattrib(body,"bgcolor");
//	removeattrib(body,"tx");
	printf("%s\n",attribval(body,"tx"));
	printf("%s\n",attribval(body,"bg"));
	printf("%s\n",attribval(body,"bgcolor"));
	deletenode(root);
	return 0;
}
