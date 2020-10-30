#include "../include/operation.h"
#include <stdlib.h>
#include <string.h>
struct node* createnode(struct node* parent,const char* tag){
	struct node* _node=(struct node*)malloc(sizeof(struct node));
	_node->attribs=(struct attrib*)malloc(sizeof(struct attrib)*1);
	_node->childs=(struct node**)malloc(sizeof(struct node*)*0);
	_node->nattrib=1;
	_node->nchild=0;
	_node->parent=parent;
	_node->tag=(char*)tag;
	struct attrib _t;
	_t.key="#";
	_t.value="";
	_node->attribs[0]=_t;
	return _node;
}

void deletenode(struct node* parent){
	int i=0;
	for (i;i<parent->nchild;i++){
		deletenode(parent->childs[i]);
	}
	free(parent->attribs);
	free(parent);
}
void deletefirst(struct node* parent){
	deletenode(parent->childs[0]);
}
void deletelast(struct node* parent){
	deletenode(parent->childs[parent->nchild-1]);
}
void appendnode(struct node* child){
	child->parent->nchild++;
	child->parent->childs=(struct node**)realloc(child->parent->childs,sizeof(struct node*)*child->parent->nchild);
	child->parent->childs[child->parent->nchild-1]=child;
}
struct node* childat(struct node* parent,int index){
	return parent->childs[index];
}
struct node* firstchild(struct node* parent){
	return parent->childs[0];
}
struct node* lastchild(struct node* parent){
	return parent->childs[parent->nchild-1];
}
void attribval(struct node* _node,struct attrib _attrib){
	int i=0;
	int signal=1;
	for (i;i<_node->nattrib;i++){
		if (strcmp(_node->attribs[i].key,_attrib.key)==0){
			signal=0;
			break;
		}
	}
	if (signal==0){
		_node->attribs[i].value=_attrib.value;
	}else{
	    _node->nattrib++;
	    _node->attribs=(struct attrib*)realloc(_node->attribs,sizeof(struct attrib)*_node->nattrib);
    	_node->attribs[_node->nattrib-1]=_attrib;
   }
}
void renattrib(struct node* _node,const char* key,const char* newkey){
	int i=0;
	for (i;i<_node->nattrib;i++){
		if (strcmp(_node->attribs[i].key,key)==0){
			_node->attribs[i].key=(char*)key;
			break;
		}
	}
}

