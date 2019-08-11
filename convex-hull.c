/* * * * * * *
 * Implementation of the Inside Hull algorithm for Assignment 1
 *
 * created for COMP20007 Design of Algorithms 2019
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by <Insert Name Here>
 */

//                   WRITE YOUR IMPLEMENTATION HERE
//
// You should fill in the function definitions for orientation() and
// inside_hull() in this file.
//
// Don't be shy to add any extra functions or types you may need.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "convex-hull.h"
#include "deque.h"

// Returns the orientation of Point p2 in relation to the line segment p0p1.
// If p2 is to the left of p0p1 then it returns LEFT ('l'), if p2 is to the
// right it returns RIGHT ('r').
// If p0, p1 and p2 are collinear then COLLINEAR ('c') is returned.
char orientation(Point p0, Point p1, Point p2) {
  // Create vectors a and b
  Point a =new_point(p1.x-p0.x,p1.y-p0.y);
  Point b =new_point(p2.x-p0.x,p2.y-p0.y);

  // Find the cross product of a and b
  float cross = (a.x * b.y) - (a.y * b.x);

  // Value of cross product determines which side p2 is on
  if (cross == 0){
    return COLLINEAR;
  } else if(cross < 0){
    return RIGHT;
  } else{
    return LEFT;
  }
}

// Takes a polygon (i.e. an array of points) given in counter-clockwise order
// with n points.
//
// Stores the points of the convex hull into the hull array (the last point
// should NOT be the same as the first point), and returns the number of
// points which are in the convex hull.
//
// If three successive points in the polygon are collinear then the algorithm
// should terminate and COLLINEAR_POINTS should be returned.
//
// If an error occurs this function should return INSIDE_HULL_ERROR.
int inside_hull(Point *polygon, int n, Point *hull) {
  // Check if inputs are valid
  if (polygon == NULL || hull == NULL || n < INITIAL_POINTS){
    exit(INSIDE_HULL_ERROR);
  }

  // Make a new deque to store convex hull points
  Deque *points = new_deque();

  // Char variable to store orientation of initial points
  char orientation_init = orientation(polygon[POINT_ZERO], polygon[POINT_ONE], polygon[POINT_TWO]);
  
  int i = 0;
  if(orientation_init == LEFT){
    // Deque = {p2, p1, p0, p2}
    for(i = 0; i < INITIAL_POINTS; i++){
      deque_push(points, polygon[i]);
    }
    deque_insert(points,polygon[POINT_TWO]);
  } else{
    // Deque = {p2, p0, p1, p2}
    for(i = 0; i < INITIAL_POINTS; i++){
      deque_insert(points, polygon[i]);
    }
    deque_push(points, polygon[POINT_TWO]);
  }

  // Loop to find convex hull points and remove non convex hulls
  // i = 3
  while(i < n){
    // If 3 consecutive points are collinear, exit and return COLLINEAR_POINTS
    if(top_orientation(points, polygon, i) == COLLINEAR){
      free(points);
      exit(COLLINEAR_POINTS);
    }

    // Checking the validity of the existing points in the deque
    if ((top_orientation(points, polygon, i) == LEFT) && 
        (bottom_orientation(points, polygon, i) == LEFT)){
      i++;
      continue;
    }

    // Checking top two points to the ith point of the polygon
    while(top_orientation(points, polygon, i) == RIGHT){
      deque_pop(points);
    }

    // Checking bottom two points to the ith point of the polygon
    deque_push(points, polygon[i]);
    while(bottom_orientation(points, polygon, i) == RIGHT){
      deque_remove(points);
    }

    // Insert next convex point
    deque_insert(points, polygon[i]);

    // Move on to the next point
    i++;
  }

  // If equal, then remove end point to avoid duplicate
  if(points->bottom->point.x == points->top->point.x &&
  points->bottom->point.y == points->top->point.y){
    deque_pop(points);
  }

  // Index for hull array and counter for convex hull points
  int hull_count = 0;
  Node *current_node = points->bottom;

  // Loop assigns convex hull points in deque to hull array
  while(current_node != NULL){
    hull[hull_count] = current_node->point;
    current_node = current_node->next;
    hull_count++;
  }

  // Free memory
  free(points);

  // Return number of points in convex hull
  return hull_count;
}

// Returns the orientation of the indexed point in respect to the top two points in the deque
char top_orientation(Deque *points, Point *polygon, int index){
  return orientation(points->top->prev->point, points->top->point, polygon[index]);
}

// Returns the orientation of the indexed point in respect to the bottom two points in the deque
char bottom_orientation(Deque *points, Point *polygon, int index){
  return orientation(points->bottom->point, points->bottom->next->point, polygon[index]);
}
