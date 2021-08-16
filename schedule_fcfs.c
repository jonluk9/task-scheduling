
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"

void insertEnd(Task*);

struct node { 
   Task *task;
   struct node * next;
};

struct node * head; 
int size =0;
int time =0;


// add a task to the list 
void add(char *name, int priority, int burst)
{
	struct task t;
    t.name=name;
    t.tid=priority;
    t.priority=priority;
    t.burst=burst;
    if(head==NULL)
    {
		struct node *newNode = malloc(sizeof(struct node));
		newNode->task = &t;
		newNode->next = NULL;
		head = newNode;
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
int i=0;
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

while(head!=NULL ){
responsetime[i]=time;
waitingtime[i]=time;
run(head.task, head.task->burst);
time+=head.task->burst;
turntime[i]=head.task->burst+waitingtime[i];
i++;
head=head.next;
}
	
	
} 

void insertEnd(Task *newTask){
   struct node * newNode;
   newNode = malloc(sizeof(struct node));
while(head!=NULL ){
head=head.next;}
   (*newNode).task = *newTask;
   (*newNode).next = NULL;

   head.next = *newNode;

}