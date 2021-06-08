/**
 *@brief header file for creature.cpp. used to create a creature that solves a
 *maze
 *
 *@author Braxton Goss
 *
 *@date 5/7/2021
 */

#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>

class Creature {
public:
  // used to format and print the creature's current location
  friend ostream &operator<<(ostream &Out, const Creature &Creature);

private:
  int Row;
  int Col;

public:
  // create the creature
  Creature(int Row, int Col);

  // solve the maze and return the path, no path will return "no path found"
  string solve(Maze &Maze);
  // helper method for solve() that carries out the recursion and pathfinding
  bool solveMazeHelper(Maze &Maze, string &Path);
  // test to see if the creature is at the end of the maze
  bool atExit(const Maze &Maze) const;
};

#endif // ASS3_CREATURE_H
