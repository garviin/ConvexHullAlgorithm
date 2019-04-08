/* * * * * * *
 * Deque module (i.e., double ended queue) for Assignment 1
 *
 * created for COMP20007 Design of Algorithms 2019
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by <Insert Name Here>
 */

//                   WRITE YOUR IMPLEMENTATION HERE
//
// You should fill in the function definitions for
//  - new_deque()
//  - free_deque()
//  - deque_push()
//  - deque_insert()
//  - deque_pop()
//  - deque_remove()
//  - deque_size()
//
// Don't be shy to add any extra functions or types you may need.

#include <stdio.h>
#include <stdlib.h>

#include "deque.h"
#include "point.h"



struct node{
  Node *prev;
  Node *next;
  Point *point;
};

// TODO: Fill in this struct definition, or change the typedef in deque.h
struct deque {
  Node *top;
  Node *bottom;
  int size;
};

// Create a new empty Deque and return a pointer to it
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
Deque *new_deque() {
  Deque *new_deque = malloc(sizeof(Deque));
  assert(new_deque);

  new_deque->top = NULL;
  new_deque->bottom = NULL;
  new_deque->size = 0;

  return new_deque;
}

Node *new_node() {
	Node *new_node = malloc(sizeof(Node));
	assert(new_node);
	
	return new_node;
}

// Free the memory associated with a Deque
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
void free_deque(Deque *deque) {
  assert(deque != NULL);

  Node *current_node = deque->top;
  Node *next_node;
  while(current_node){
    next_node = current_node->next;
    free_node(current_node);
  }

  free(deque);
}

void free_node(Node *node) {
	free(node);
}

// Add a Point to the top of a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: ...
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
void deque_push(Deque *deque, Point data) {
  // TODO: Implement deque_push()
  fprintf(stderr, "Error: deque_push() not implemented\n");
  exit(EXIT_FAILURE);
}

// Add a Point to the bottom of a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: ...
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
void deque_insert(Deque *deque, Point data) {
  // TODO: Implement deque_insert()
  fprintf(stderr, "Error: deque_insert() not implemented\n");
  exit(EXIT_FAILURE);
}

// Remove and return the top Point from a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: ...
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
Point deque_pop(Deque *deque) {
  // TODO: Implement deque_pop()
  fprintf(stderr, "Error: deque_pop() not implemented\n");
  exit(EXIT_FAILURE);
}

// Remove and return the bottom Point from a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: ...
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
Point deque_remove(Deque *deque) {
  // TODO: Implement deque_remove()
  fprintf(stderr, "Error: deque_remove() not implemented\n");
  exit(EXIT_FAILURE);
}

// Return the number of Points in a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: ...
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
int deque_size(Deque *deque) {
  // TODO: Implement deque_size()
  fprintf(stderr, "Error: deque_size() not implemented\n");
  exit(EXIT_FAILURE);
}

// TODO: Add any other functions you might need for your Deque module
