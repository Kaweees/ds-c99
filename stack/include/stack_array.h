#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdbool.h>
#include <stdint.h>

/* Begin typedef declarations */

/* Represents an array-based stack. */
typedef struct StackArray {
  uint32_t capacity;
  uint32_t size;
  void **items;
} StackArray;

/* Begin function prototype declarations */

/* Creates a new stack with the given capacity. */
StackArray *stackCreate(uint32_t capacity);

/* Destroys the given stack. */
void stackDestroy(StackArray *stack);

/* Pushes a given item onto the given stack. */
bool stackPush(StackArray *stack, void *item);

/* Pops an item from the given stack. */
void *stackPop(StackArray *stack);

#endif /* STACKARRAY_H */