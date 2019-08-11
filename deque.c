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
#include <assert.h>

#include "deque.h"
#include "point.h"

// Create a new empty Deque and return a pointer to it
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
Deque *new_deque() {
  // Creates memory for the deque
  Deque *new_deque = malloc(sizeof(Deque));

  // Checks if deque is valid
  assert(new_deque);

  // Intialize top/bottom pointers and size of deque
  new_deque->top = NULL;
  new_deque->bottom = NULL;
  new_deque->size = 0;

  // Returns pointer to the new deque
  return new_deque;
}

// Free the memory associated with a Deque
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
void free_deque(Deque *deque) {
  // Checks if input is valid
  assert(deque != NULL);

  // Traverses deque from the bottom and frees each node
  Node *current_node = deque->bottom;
  Node *next_node;
  while(current_node){
    next_node = current_node->next;
    free_node(current_node);
    current_node = next_node;
  }

  // Frees the deque itself
  free(deque);
}

// Add a Point to the top of a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: ...
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
void deque_push(Deque *deque, Point data) {
  // Checks if input is valid
  assert(deque != NULL);

  // Create new node to push in the top deque
  Node *node = new_node();
  
  // Assign node data to the input data
  node->point = data;

  // Update node pointers
  node->next = NULL;
  node->prev = deque->top;

  // Update old top node
  if(deque->size > 0){
    deque->top->next = node;
  }

  // Update the deque top and bottom nodes
  deque->top = node;
  if(deque->size == 0){
    deque->bottom = node;
  }

  // Update list size
  deque->size++;
}

// Add a Point to the bottom of a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: ...
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
void deque_insert(Deque *deque, Point data) {
  // Check if input is valid
  assert(deque != NULL);

  // Create new node to insert in the bottom of deque
  Node *node = new_node();
  
  // Assign node data to the input data
  node->point = data;

  // Update node pointers
  node->next = deque->bottom;
  node->prev = NULL;

  // Update old bottom node
  if(deque->size > 0){
    deque->bottom->prev = node;
  }
  
  // Update deque top and bottom
  deque->bottom = node;
  if(deque->size == 0){
    deque->top = node;
  }

  // Update list size
  deque->size++;
}

// Remove and return the top Point from a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: ...
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
Point deque_pop(Deque *deque) { 
  // Check if input is valid
  assert(deque != NULL);
  assert(deque->size > 0);

  // Stores top node pointer and its data for later use
  Node *top_node = deque->top;
  Point data = top_node->point;
  
  // Check if deque will be empty after removing the node
  if (deque->size > 1){
    // Update new top node of the deque
    deque->top = top_node->prev;
    deque->top->next = NULL;
  } else{
     // If it will be, no points remain
    deque->top = NULL;
    deque->bottom = NULL;
  }

  // Update the size of the deque
  deque->size--;

  // Free the memory
  free(top_node);

  // Return value of the popped node
  return data;
}

// Remove and return the bottom Point from a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: ...
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
Point deque_remove(Deque *deque) {
  // Check if input is valid
  assert(deque != NULL);
  assert(deque->size > 0);

  // Stores bottom node pointer and its data for later use
  Node *bottom_node = deque->bottom;
  Point data = bottom_node->point;
  
  // Check if deque will be empty after removing the node
  if (deque->size > 1){
    // Update new bottom node of the deque
    deque->bottom = bottom_node->next;
    deque->bottom->prev = NULL;
  } else {
    // If it will be, no points remain
    deque->bottom = NULL;
    deque->top = NULL;
  }
  
  // Update the size of the deque
  deque->size--;

  // Free memory
  free(bottom_node);

  // Return the value of the removed node
  return data;
}

// Return the number of Points in a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: ...
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
int deque_size(Deque *deque) {
  // Check if input is valid
  assert(deque != NULL);

  // Return the number of nodes in the deque
  return deque->size;
}

// TODO: Add any other functions you might need for your Deque module

// HELPER FUNCTIONS

// Frees up memory associated with the node
void free_node(Node *node) {
	free(node);
}

// Creates a new node
Node *new_node() {
	Node *new_node = malloc(sizeof(Node));
	assert(new_node);
	
	return new_node;
}
