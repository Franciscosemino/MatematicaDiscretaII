#include "TheOutsider.h"

void DestruirQueue(Queue q) {
    free(q->theQueue);
		free(q);
}

void Enqueue(Queue q, PVertice v) {
    // Increment tail index
    q->tail++;
    // Add the item to the Queue
    q->theQueue[q->tail] = v;
	}

PVertice Dequeue(Queue q) {
    PVertice v;
    q->head++;
    v = q->theQueue[q->head]; // Get character to return
    return v;           // Return popped character
}

u32 isEmpty(Queue q) {
    return (q->head == q->tail);
}
