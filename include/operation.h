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
void attribval(struct node* _node,struct attrib _attrib);//also in maintainance
void renattrib(struct node* _node,const char* key,const char* newkey);//some modification required
void removeattrib(struct node* _node,const char* key);//pending

#endif