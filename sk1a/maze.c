/*
*Inspirovane algoritmom Rat in a maze 
*@geeksforgeeks
*/
#include <stdio.h>

#include <string.h>

#include "maze.h"

#include <assert.h>

#include <stdlib.h>

#define PATH_CHAR '*' //Znak pre cestu
#define EMPTY_CHAR ' ' //Znak pre volne miesto
#define WALL_CHAR 'x' //Znak pre stenu

int calculatePosition(int x, int y, int size);
int validIndex(char * maze, int size, int i, int j);
int solveMazeFunction(char * maze, int x, int y, int size);
int solve_maze(char * maze, int size);

/*
*Premeni suradnice x, y na index pola
*@arg suradnica x
*@ard suradnica y
*returns: index pola
*/
int calculatePosition(int x, int y, int size) {

  return (x * size + y);
}

/*
*Skontroluje, ci suradnica nie su mimo bludiska
*@arg pole bludisko
*@arg velkost pola bludisko
*@arg suradnica x
*@arg suradnica y
*returns: 0 ak je suradnica mimo bludiska
*/
int validIndex(char * maze, int size, int i, int j) {

  int position = calculatePosition(i, j, size);
  if (position >= size * size || position < 0 || maze[position] != EMPTY_CHAR) return 0;
  return 1;
}

/*
*Vyriesi bludisko
*@arg bludisko
*@arg suradnica x
*@arg suradnica y
*@arg velkost pola
*returns: 1 ak najde cestu
*/
int solveMazeFunction(char * maze, int x, int y, int size) {

  int position = calculatePosition(x, y, size); 

  //ak som na zaciatocnej pozicii skontrolujem ci som aj na konci
  //ak je size 0, ak nie tak nastavim cestu
  if (position == 0) {
    if (maze[size * size - 1] == WALL_CHAR) return 0;
    else if (maze[size * size - 1] == EMPTY_CHAR && size == 0) maze[position] = PATH_CHAR;
  }
  //ak som na koncovej pozicii skontrolujem ci tam nie je stena
  //ak nie, vratim 1 lebo nasiel cestu	
  if (x == size - 1 && y == size - 1) {
    if (maze[position] == WALL_CHAR) return 0;
    else if (maze[position] == EMPTY_CHAR) {
      maze[position] = PATH_CHAR;
      maze[0] = PATH_CHAR;
      return 1;
    }
  }
  /* skontrolujem vsetky smery */
  if (validIndex(maze, size, x, y)) {
    maze[position] = PATH_CHAR; // nastavim cestu
    //ide dole, kontrola nemusi byt, lebo to skontroluje neskor
    //funckia					
    if (solveMazeFunction(maze, x + 1, y, size)) return 1;
    //skontrolujem ci mozem ist doprava
    if (position % size != (size - 1)) {
      if (solveMazeFunction(maze, x, y + 1, size)) return 1;
    }
    //ide hore
    if (solveMazeFunction(maze, x - 1, y, size)) return 1;
    //skontrolujem ci mozem ist dolava
    if (position % size != 0) {
      if (solveMazeFunction(maze, x, y - 1, size)) return 1;
    }
    //ak nenasiel cestu v ziadnom smere tak vymaze znak cesty
    maze[position] = EMPTY_CHAR;

    return 0;
  }
  return 0;
}

int solve_maze(char * maze, int size) {

  maze[0] = EMPTY_CHAR;

  return solveMazeFunction(maze, 0, 0, size);
}
