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

#define LEFT 'l'
#define RIGHT 'r'
#define COLLINEAR 'c'

// Returns the orientation of Point p2 in relation to the line segment p0p1.
// If p2 is to the left of p0p1 then it returns LEFT ('l'), if p2 is to the
// right it returns RIGHT ('r').
// If p0, p1 and p2 are collinear then COLLINEAR ('c') is returned.
char orientation(Point p0, Point p1, Point p2) {
  // initialize coefficients of line passing through point p0 and p1
  int a = (p1.y - p0.y);
  int b = (p0.x -  p1.x);
  int c = (p0.x*p1.y) - (p0.y*p1.x);

  // plugging p2 into the line equation
  int anto = (a*p2.x) + (b*p2.y) - c;

  // value of anto determines which side p2 is on
  if (anto == 0){
    return COLLINEAR;
  } else if(anto > 0){
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
  if (polygon == NULL || hull == NULL || n < 3){
    exit(INSIDE_HULL_ERROR);
  }

  Deque *points = new_deque();
  char orientation_anto = orientation(polygon[0], polygon[1], polygon[2]);
  
  int i = 0;
  if(orientation_anto == LEFT){
    for(i = 0; i < 3; i++){
      deque_push(points, polygon[i]);
    }
    deque_insert(points,polygon[2]);
  } else{
    for(i = 0; i < 3; i++){
      deque_insert(points, polygon[i]);
    }
    deque_push(points, polygon[2]);
  }

  while(i < n){

    if ((orientation(points->top->prev->point, points->top->point, polygon[i]) == LEFT) && 
    (orientation(points->bottom->point, points->bottom->next->point, polygon[i]) == LEFT)){
      i++;
      continue;
    }

    while(orientation(points->top->prev->point, points->top->point, polygon[i]) == RIGHT){
      deque_pop(points);
    }

    deque_push(points, polygon[i]);
    while(orientation(points->bottom->point, points->bottom->next->point, polygon[i]) == RIGHT){
      deque_remove(points);
    }

    deque_insert(points, polygon[i]);

    i++;
  }
  for (int i = 0; i < deque_size(points) - 1; i++){
    hull[i] = deque_remove(points);
  }
  return deque_size(points) - 1;
}
