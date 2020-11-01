#include "../include/operation.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct node* createnode(struct node* parent,const char* tag){
	struct node* _node=(struct node*)malloc(sizeof(struct node));
	_node->attribs=(struct attrib*)malloc(sizeof(struct attrib)*1);
	_node->childs=(struct node**)malloc(sizeof(struct node*)*0);
	_node->nchild=0;
	_node->parent=parent;
	_node->tag=(char*)tag;
	_node->attribs=(struct attrib*)malloc(sizeof(struct attrib)*1);
	_node->nattrib=1;
	_node->attribs->next=NULL;
	_node->attribs->key="#";
	_node->attribs->value="";
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
struct attrib* createattrib(const char* key,const char* value){
	struct attrib* _attrib=(struct attrib*)malloc(sizeof(struct attrib));
	_attrib->key=(char*)key;
	_attrib->value=(char*)value;
	_attrib->next=NULL;
	return _attrib;
}
void setattrib(struct node* _node,struct attrib* _attrib){
	struct attrib* temp=_node->attribs;
	while (temp->next!=NULL){
		if (strcmp(temp->key,_attrib->key)==0){
			temp->value=_attrib->value;
			return;
		}
		temp=temp->next;
	}
	temp->next=_attrib;
	_node->nattrib++;
}
void renattrib(struct node* _node,const char* key,const char* newkey){
	struct attrib* temp=_node->attribs;
	while (temp->next!=NULL){
		if (strcmp(temp->key,key)==0){
			temp->key=(char*)newkey;
			break;
		}
		temp=temp->next;
	}
}
const char* attribval(struct node* _node,const char* key){
	struct attrib* temp=_node->attribs;
	while (temp!=NULL){
		if (strcmp(temp->key,key)==0){
			return temp->value;
		}
		temp=temp->next;
	}
	return "";
}
void removeattrib(struct node* _node,const char* key){
	struct attrib* temp=_node->attribs;
	struct attrib* prev=NULL;
	while (temp!=NULL){
		if (strcmp(temp->key,key)==0){
			prev->next=temp->next;
			free(temp);
			break;
		}
		prev=temp;
		temp=temp->next;
	}
}
