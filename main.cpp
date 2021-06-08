/**
 *@brief Driver and test function to solve mazes from ASCII text-based mazes
 *
 *@author Braxton Goss
 *
 *@date 5/6/2021
 */
#include <cassert>
#include <iostream>

#include "creature.h"
#include "maze.h"

// test function to open and run all 6 test mazes
void test() {
  /*
   * TESTING MAZE #1 FROM ASSIGNMENT EXAMPLE
   */
  Maze M1("maze.txt");
  Creature C1(4, 4);
  cout << "Empty maze1:" << endl << M1;
  cout << "Starting at " << C1 << "and going to (" << M1.getExitRow() << ", "
       << M1.getExitColumn() << ") in maze.txt" << endl;
  string SolvedPath1 = C1.solve(M1);
  cout << "Path from navigation: " << SolvedPath1 << endl;
  cout << "Path from Canvas assignment: EEENNNEEEEEESEESSSEEENNNNN" << endl;
  assert(SolvedPath1 == "EEENNNEEEEEESEESSSEEENNNNN");
  cout << M1 << endl;

  /*
   * TESTING MAZE #2 (MODIFIED FROM MAZE #1)
   */
  Maze M2("maze2.txt");
  Creature C2(4, 4);
  cout << "Empty maze2:" << endl << M2;
  cout << "Starting at " << C2 << "and going to (" << M2.getExitRow() << ", "
       << M2.getExitColumn() << ") in maze2.txt" << endl;
  string SolvedPath2 = C2.solve(M2);
  cout << "Path:" << SolvedPath2 << endl;
  assert(SolvedPath2 == "EEENNNEEEEEESEESSSEEEE");
  cout << M2 << endl;

  /*
   * TESTING MAZE #3 (HEAVILY MODIFIED FROM MAZE #1)
   */
  Maze M3("maze3.txt");
  Creature C3(4, 11);
  cout << "Empty maze3:" << endl << M3;
  cout << "Starting at " << C3 << "and going to (" << M3.getExitRow() << ", "
       << M3.getExitColumn() << ") in maze3.txt" << endl;
  string SolvedPath3 = C3.solve(M3);
  cout << "Path:" << SolvedPath3 << endl;
  assert(SolvedPath3 == "WWWWWWWWWWNNNEEEESEEEEENEEESEESSSEEES");
  cout << M3 << endl;

  /*
   * TESTING MAZE #4 (COMEPLETELY CUSTOM)
   */
  Maze M4("maze4.txt");
  Creature C4(1, 1);
  cout << "Empty maze4:" << endl << M4;
  cout << "Starting at " << C4 << "and going to (" << M4.getExitRow() << ", "
       << M4.getExitColumn() << ") in maze4.txt" << endl;
  string SolvedPath4 = C4.solve(M4);
  cout << "Path:" << SolvedPath4 << endl;
  assert(SolvedPath4 ==
         "SSSSSSSSEEEEEEEEEEEEEEEEEEEENNNNWWNNNNWWWWWWWWWWWWWWWN");
  cout << M4 << endl; // print solved maze

  /*
   * TESTING MAZE #5 (TESTING SNAKE-TYPE MOVEMENT)
   */
  Maze M5("maze5.txt");
  Creature C5(1, 1);
  cout << "Empty maze5:" << endl << M5;
  cout << "Starting at " << C5 << "and going to (" << M5.getExitRow() << ", "
       << M5.getExitColumn() << ") in maze5.txt" << endl;
  string SolvedPath5 = C5.solve(M5);
  cout << "Path:" << SolvedPath5 << endl;
  assert(SolvedPath5 == "SSSEENNNEESSSEENNNEESSSEENNNEESSSEENNNEESSSSEE");
  cout << M5 << endl;

  /**
   * TESTING MAZE #6
   * (TESTING SIMPLE AND SMALL MAZE THAT STARTS ON EDGE AND ENDS ON EDGE)
   */
  Maze M6("maze6.txt");
  Creature C6(0, 3);
  cout << "Empty maze6:" << endl << M6;
  cout << "Starting at " << C6 << "and going to (" << M6.getExitRow() << ", "
       << M6.getExitColumn() << ") in maze6.txt" << endl;
  string SolvedPath6 = C6.solve(M6);
  cout << "Path:" << SolvedPath6 << endl;
  assert(SolvedPath6 == "SS");
  cout << M6 << endl;
}
/**
 * @brief driver function to run the tests. If all asserts are passed in the
 * test() function, "Done!" will print to screen
 */
int main() {
  test();
  cout << "Done!" << std::endl;
  return 0;
}