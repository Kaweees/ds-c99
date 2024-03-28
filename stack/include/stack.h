#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdint.h>

/* Begin typedef declarations */

/* Represents an array-based stack. */
typedef struct Stack {
  uint32_t capacity;
  uint32_t size;
  void **items;
} Stack;

/* Begin function prototype declarations */

/* Creates a new stack with the given capacity. */
Stack *stackCreate(uint32_t capacity);

/* Destroys the given stack. */
void stackDestroy(Stack *stack);

/* Pushes a given item onto the given stack. */
bool stackPush(Stack *stack, void *item);

/* Pops an item from the given stack. */
void *stackPop(Stack *stack);

#endif /* STACK_H */