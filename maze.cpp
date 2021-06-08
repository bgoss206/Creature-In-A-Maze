/**
 *@brief implementation of maze.h that creates the maze from ASCII text and
 *gives a creature tools to navigate the maze
 *
 *@author Braxton Goss
 *
 *@date 5/7/2021
 */
#include "maze.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/**
 @pre maze is initalized and #include <iostream>
 @post maze will be sent to the ostream for printing/output
 @param Out ostream to capture all of the characters
 @param Maze maze to be printed (solved or unsolved)
*/
ostream &operator<<(ostream &Out, const Maze &Maze) {
  for (int Row = 0; Row < Maze.Height; ++Row) {
    for (int Col = 0; Col < Maze.Width; ++Col) {
      Out << Maze.Field[Row][Col];
    }
    Out << endl;
  }
  Out << endl;
  return Out;
}

// For Clion, need the following line in CMakeLists.txt so maze.txt is found
// at the same location as the cpp files
// # need to load data files from current directory as cpp files
// set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
Maze::Maze(const string &FileName) {
  ifstream InFile;
  InFile.open(FileName);
  if (!InFile) {
    cout << "Unable to open file";
    exit(1); // terminate with error
  }
  InFile >> Width >> Height;
  InFile >> ExitRow >> ExitColumn;
  string Str;
  getline(InFile, Str);
  for (int Row = 0; Row < Height; ++Row) {
    for (int Col = 0; Col < Width; ++Col) {
      InFile.get(Field[Row][Col]);
    }
    getline(InFile, Str);
  }
}

/**
 * @pre maze is initialized
 * @post exit row is returned, maze unchanged
 * @return int representing row # of exit (zero-indexed)
 */
int Maze::getExitRow() const { return ExitRow; }

/**
 * @pre maze is initialized
 * @post exit column is returned, maze unchanged
 * @return int representing column # of exit (zero-indexed)
 */
int Maze::getExitColumn() const { return ExitColumn; }

/**
 * @pre maze is initialized
 * @post width of maze is returned, maze unchanged
 * @return width of maze (given in maze.txt files)
 */
int Maze::getWidth() const { return Width; }

/**
 * @pre maze is initialized
 * @post height of maze is returned, maze unchanged
 * @return height of maze (given in maze.txt files)
 */
int Maze::getHeight() const { return Height; }

/**
 * @pre maze is initialized
 * @post bool showing if that element of the maze is clear, maze unchanged
 * @return bool showing whether the current element in the maze is an empty
 * space
 * @param Row : current creature row
 * @param Col : current creature column
 */
bool Maze::isClear(int Row, int Col) const { return Field[Row][Col] == ' '; }

/**
 *@pre maze is initlaized
 *@post maze unchanged, boundary bool returned
 *@return bool showing if the element is within the boundaries of the array:
 *(0->width) (0->height)
 * @param Row : current creature row
 * @param Col : current creature column
 */
bool Maze::isInBounds(int Row, int Col) const {
  return (Row >= 0 && Col >= 0 && Row < this->getHeight() &&
          Col < this->getWidth());
}

/**
 *@pre maze is initlaized and element is being explored
 *@post space at (row, col) in the maze is changed to *
 *@return VOID - no return value
 *@param Row : current creature row
 *@param Col : current creature column
 */
void Maze::markAsPath(int Row, int Col) { Field[Row][Col] = '*'; }

/**
 *@pre maze is initlaized and element is being backtracked
 *@post space at (row, col) in the maze is changed to +
 *@return VOID - no return value
 *@param Row : current creature row
 *@param Col : current creature column
 */
void Maze::markAsVisited(int Row, int Col) { Field[Row][Col] = '+'; }

/**
 *@pre maze is initlaized and element is in the boundaries of the maze
 *@post bool returned showing if the space is a part of the path, maze unchanged
 *@return bool returned showing if this element is path already
 *@param Row : current creature row
 *@param Col : current creature column
 */
bool Maze::isPartOfPath(int Row, int Col) const {
  return Field[Row][Col] == '*';
}

/**
 *@pre maze is initlaized and element is in the boundaries of the maze
 *@post bool returned showing if the space is a wall, represented by x, maze
 *unchanged
 *@return bool returned showing if this element is a wall in the maze in order
 *to backtrack
 *@param Row : current creature row
 *@param Col : current creature column
 */
bool Maze::isWall(int Row, int Col) const { return Field[Row][Col] == 'x'; }

/**
 *@pre maze is initlaized and element is in the boundaries of the maze
 *@post bool returned showing if the space has already been visited by a
 *backtrack, maze unchanged
 *@return bool returned showing if the creature has already explored this path
 *@param Row : current creature row
 *@param Col : current creature column
 */
bool Maze::hasBeenVisited(int Row, int Col) const {
  return Field[Row][Col] == '+';
}
