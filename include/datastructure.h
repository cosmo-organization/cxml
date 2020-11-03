#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H
struct attrib{
	struct attrib* next;
	char* key;
	char* value;
};
struct node{
	struct node* parent;
	struct node* child;
	unsigned int nchild;
	struct node* next;
	struct attrib* attribs;
	unsigned int nattrib;
	char* tag;
};
#endif
