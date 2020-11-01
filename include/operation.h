#ifndef OPERATION_H
#define OPERATION_H
#include "datastructure.h"
struct node* createnode(struct node* parent,const char* tag);
void deletefirst(struct node* parent);
void deletelast(struct node* parent);
void deletenode(struct node* parent);
void appendnode(struct node* child);
struct node* childat(struct node* parent,int index);
struct node* firstchild(struct node* parent);
struct node* lastchild(struct node* parent);
void setattrib(struct node* _node,struct attrib* _attrib);
void renattrib(struct node* _node,const char* key,const char* newkey);
void removeattrib(struct node* _node,const char* key);
struct attrib* createattrib(const char* key,const char* value);
const char* attribval(struct node* _node,const char* key);

#endif
