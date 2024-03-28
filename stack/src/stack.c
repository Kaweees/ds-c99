#include "stack.h"

#include <stdbool.h>
#include <unistd.h>

/**
 * @brief Creates a new stack with the given capacity
 * @param capacity the capacity of the stack
 * @return a pointer to the stack
 */
Stack *stackCreate(uint32_t capacity) {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  if (stack == NULL) {
    return NULL;
  }

  stack->capacity = capacity;
  stack->size = 0;
  stack->items = (void **)malloc(sizeof(void *) * capacity);
  if (stack->items == NULL) {
    free(stack);
    return NULL;
  }
  return stack;
}

/**
 * @brief Destroys the given stack
 * @param stack the stack to destroy
 */
void stackDestroy(Stack *stack) {
  free(stack->items);
  free(stack);
}

/**
 * @brief Pushes a given item onto the given stack.
 * @param stack the stack to push onto
 * @param item the item to push
 * @return true if the item was pushed, false otherwise
 */
bool stackPush(Stack *stack, void *item) {
  if (stack->size == stack->capacity) {
    return false;
  } else {
    stack->items[stack->size++] = item;
    return true;
  }
}

/**
 * @brief Pops an item from the given stack.
 * @param stack the stack to pop from
 * @return the item that was popped, or NULL if the stack is empty
 */
void *stackPop(Stack *stack) {
  if (stack->size == 0) {
    return NULL;
  } else {
    return stack->items[--stack->size];
  }
}