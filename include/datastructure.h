#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H
struct attrib{
	struct attrib* next;
	char* key;
	char* value;
};
struct node{
	struct node* parent;
	struct node** childs;
	unsigned int nchild;
	struct attrib* attribs;
	unsigned int nattrib;
	char* tag;
};
#endif
