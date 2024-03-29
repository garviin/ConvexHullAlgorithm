/* * * * * * *
 * Implementation of the Inside Hull algorithm for Assignment 1
 *
 * created for COMP20007 Design of Algorithms 2019
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by <Insert Name Here>
 */

// You must not change any of the code already provided in this file, such as
// type definitions, constants or functions.
//
// You may, however, add additional functions and/or types which you may need
// while implementing your algorithms and data structures.

#ifndef CONVEX_HULL_H
#define CONVEX_HULL_H

#include "point.h"
#include "deque.h"

// Possible results from the inside_hull() algorithm
#define INSIDE_HULL_ERROR -1
#define COLLINEAR_POINTS -2

// The possible orientation() return values
#define LEFT 'l'
#define RIGHT 'r'
#define COLLINEAR 'c'

// Constants to initialize the deque hull
#define INITIAL_POINTS 3
#define POINT_ZERO 0
#define POINT_ONE 1
#define POINT_TWO 2

// Returns the orientation of Point p2 in relation to the line segment p0p1.
// If p2 is to the left of p0p1 then it returns LEFT ('l'), if p2 is to the
// right it returns RIGHT ('r').
// If p0, p1 and p2 are collinear then COLLINEAR ('c') is returned.
char orientation(Point p0, Point p1, Point p2);

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
int inside_hull(Point *polygon, int n, Point *hull);

// Helper functions

// Returns the orientation of the indexed point in respect to the top two points in the deque
char top_orientation(Deque *points, Point *polygon, int index);

// Returns the orientation of the indexed point in respect to the bottom two points in the deque
char bottom_orientation(Deque *points, Point *polygon, int index);

#endif
