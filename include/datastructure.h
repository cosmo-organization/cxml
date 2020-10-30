#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H
struct attrib{
	struct attrib* from;
	char* key;
	char* value;
	struct attrib* to;
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
