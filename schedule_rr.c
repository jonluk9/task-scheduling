
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

void insertEnd(Task*);

struct node { 
   Task *task;
   struct node * next;
};

struct node * head; 
int size =0;
int time =0;
int response_updated =0;

// add a task to the list 
void add(char *name, int priority, int burst)
{
	struct task t;
    t.name=name;
    t.tid=priority;
    t.priority=priority;
    t.burst=burst;
    if(head->next==NULL)
    {
		struct node *newNode = malloc(sizeof(struct node));
		newNode->task = &t;
		newNode->next = NULL;
		head->next = newNode;
    }
    else
    {    
   	 	insertEnd(&t);
    }
	
	
	size++;
}

// invoke the scheduler
void schedule()
{
struct node * current=head;
int i=0;
int done=0;
int waitingtime[size];
int turntime[size];
int responsetime[size];
for(i=0;i<size;i++)
{
waitingtime[i]=0;
turntime[i]=0;
responsetime[i]=0;
}
	
i=0;

while(done==0){
current=head;
while(current->next!=NULL ){
if(response_updated==0)
{responsetime[i]=time;}
if(current.task->burst>0){
run(current.task, min(QUANTUM,current.task->burst) );
current.task->burst-=min(QUANTUM,current.task->burst) ;
time+=min(QUANTUM,current->task->burst);
current=current.next;}
else
{current=current.next;}
}
	
}response_updated=1;	

current=head;
done=1;
while(current->next!=NULL ){
if(current->task->burst>0)
{done=0;break;}
}
} 


void insertEnd(Task *newTask){
   struct node * newNode;
struct node * current=head;
   newNode = malloc(sizeof(struct node));
while(current->next!=NULL ){
current=current.next;}
   (*newNode).task = *newTask;
   (*newNode).next = NULL;

   current.next = *newNode;

}
void delete(Task *newTask){
struct node * current=head;

while(current->next!=NULL ){
if(current->next->task!=newTask)
{current=current.next;}
else
{current->next=current->next->next;}

}

}