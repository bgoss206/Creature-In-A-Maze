/**
 *@brief header file for the maze.h. The maze class provides all the necessary
 *methods to initialize and modify the maze while solving using the creature
 *class
 *
 *@author Braxton Goss
 *
 *@date 5/7/2021
 */

#ifndef ASS3_MAZE_H
#define ASS3_MAZE_H

#include <ostream>

using namespace std;

enum CELL { CLEAR, WALL, PATH, VISITED };

class Maze {
  // used to print out the maze before and after solving using << operator
  friend ostream &operator<<(ostream &Out, const Maze &Maze);

private:
  const static int MAX_SIZE = 100;
  char Field[MAX_SIZE][MAX_SIZE];
  int Width, Height;
  int ExitRow, ExitColumn;

public:
  // maze constructor given the file name
  explicit Maze(const string &FileName);

  // mark (row, col) element of the maze as a path step
  void markAsPath(int Row, int Col);

  // mark (row, col) element of the maze as a visited portion
  void markAsVisited(int Row, int Col);

  // check to see if the creature has already visited this part of the maze
  bool hasBeenVisited(int Row, int Col) const;

  // check to see if the (row, col) element of the maze is a blank space
  bool isClear(int Row, int Col) const;

  // check to see if the (row, col) element of the maze is within the boundary
  // set by the file
  bool isInBounds(int Row, int Col) const;

  // check to see if the (row, col) element of the maze is already marked as
  // part of the path
  bool isPartOfPath(int Row, int Col) const;

  // check to see if the (row, col) element of the maze is a wall (marked by x's
  // in the file)
  bool isWall(int Row, int Col) const;

  // get width of the maze
  int getWidth() const;

  // get height of the maze
  int getHeight() const;

  // get the row of the goal/exit element
  int getExitRow() const;

  // get the column of the goal/exit element
  int getExitColumn() const;
};

#endif // ASS3_MAZE_H
