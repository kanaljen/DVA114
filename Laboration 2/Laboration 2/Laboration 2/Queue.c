#include "Queue.h"
#include<assert.h>

Queue initializeQueue(void)
{
    Queue newQueue;
    newQueue.front = 0;
    newQueue.back = 0;
    return newQueue;
    
}

int queueIsEmpty(const Queue queue)
{
    if(queue.back == queue.front) return 1;
    return 0;
}

int queueIsFull(const Queue queue)
{
    if(queue.back == (queue.front-1)) return 1;
    if((queue.back == 0) && (queue.front == MAXLENGTH-1)) return 1;
	return 0;
}

void enqueue(Queue* queue, const Data data)
{
	// Precondition: kön är ej full
    assert(queueIsFull(*queue) != 1);
    
    (*queue).data[(*queue).back] = data;
    if((*queue).back == 19)(*queue).back = 0;
    else (*queue).back = (*queue).back + 1;
}

void dequeue(Queue* queue)
{
	// Precondition: kön är ej tom
    assert(!queueIsEmpty(*queue));
    
    if((*queue).front == 19)(*queue).front = 0;
    else (*queue).front = (*queue).front + 1;
}

Data peekQueue(const Queue queue)
{
	// Precondition: kön är ej tom
    assert(!queueIsEmpty(queue));
    
	return queue.data[queue.front];	// Ersätt med rätt returvärde
}
