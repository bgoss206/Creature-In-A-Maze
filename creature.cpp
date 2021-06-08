/**
 *@brief implementation the creature to move around the maze
 *
 *@author Braxton Goss
 *
 *@date 5/6/2021
 */
#include "creature.h"
#include <iostream>

using namespace std;
/**
 *@pre creature is initalized
 *@post ostream of creature's current location is returned
 *@return formatted creature location is returned in (row, column) format
 *@param Out: ostream to be added to and returned
 *@param Creature : creature to be formatted in (row, column) format
 */
ostream &operator<<(ostream &Out, const Creature &Creature) {
  Out << "(" << Creature.Row << ", " << Creature.Col << ")";
  return Out;
}
/** constuctor
 *@pre creature given a position (row, column) at initialization
 *@post creature created
 *@return no return -- creature is initalized
 *@param Row : creature row position
 *@param Col : creature column position
 */
Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {
  this->Row = Row;
  this->Col = Col;
}

/**
 * @pre maze is initalized
 * @post maze and creature are unchanged
 * @return boolean showing if the creature is at the exit
 * @param Maze: maze is not changed
 */
bool Creature::atExit(const Maze &Maze) const {
  return (Row == Maze.getExitRow() && Col == Maze.getExitColumn());
}

/**
 *@pre maze and creature are both initialized
 *@post maze gets modified to show paths and any backtracks taken
 *@return string cotaining all of the directions taken by the creature to the
 *end
 *@param Maze - Maze for the creature to navigate and solve
 */
string Creature::solve(Maze &Maze) {
  string Path;
  if (solveMazeHelper(Maze,
                      Path)) { // if a path to the exit was found, return it
    return Path;
  } else {
    return "Path Not Found"; // otherwise, let the client program know that the
                             // creature could not find a path
  }
}

/**
 *@pre called from the solve() method with an empty path to help with finding
 *the path recursively. Maze and Path must already be initialized
 *@post maze is navigated, if a path is found, that value is updated to reflect
 *directions, and the boolean returned shows if a path was found or not
 *@return boolean reflectig if a path was found or not
 *@param Maze: Maze for creature to navigate
 *@param Path: Path taken by the creature so far, can include directions that
 *won't be included in final path while taking alternate paths & backtracking
 *afterwards
 */
bool Creature::solveMazeHelper(Maze &Maze, string &Path) {

  // base case: reached exit, return true to the solve function
  if (atExit(Maze)) {
    Maze.markAsPath(Row, Col);
    return true;
  }
  // if hit a wall, is already part of the solution path, or has been visited:
  // remove the previous direction from Path string, return false
  if (Maze.isWall(Row, Col) || Maze.isPartOfPath(Row, Col) ||
      Maze.hasBeenVisited(Row, Col) || !Maze.isInBounds(Row, Col)) {
    Path.pop_back();
    return false;
  }

  // check if current search is clear and in bounds
  if (Maze.isClear(Row, Col) && Maze.isInBounds(Row, Col)) {

    // mark row and column as part of assumed solution path
    Maze.markAsPath(Row, Col);

    /* move left(west) */
    Path.push_back('W');
    Col -= 1;
    if (solveMazeHelper(Maze, Path)) {
      return true;
    } else {
      Col += 1;
    }

    /* move right(east) */
    Path.push_back('E');
    Col += 1;
    if (solveMazeHelper(Maze, Path)) {
      return true;
    } else {
      Col -= 1;
    }

    /* move up(north) */
    Path.push_back('N');
    Row -= 1;
    if (solveMazeHelper(Maze, Path)) {
      return true;
    } else {
      Row += 1;
    }

    /* move down(south) */
    Path.push_back('S');
    Row += 1;
    if (solveMazeHelper(Maze, Path)) {
      return true;
    } else {
      Row -= 1;
    }

    /* If none of the above movements work, backtrack, marking visited and
     * removing added directions from string (which acts like a stack) */
    Maze.markAsVisited(Row, Col);
    Path.pop_back();
    return false;
  }
  // if there's no solution to the maze, return false to the solve function
  return false;
}
