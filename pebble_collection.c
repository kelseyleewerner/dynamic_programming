#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int basic_recursion(int, int);
int memoized_solution(int, int);
int tabular_solution(int, int);

#define ROW 6
#define COLUMN 7

int pebbles[ROW][COLUMN] = {
{0, 0, 0, 0, 0, 0, 0},
{0, 0, 1, 1, 0, 0, 0},
{0, 0, 0, 1, 1, 0, 1},
{0, 1, 0, 0, 0, 0, 0},
{0, 0, 1, 1, 0, 1, 1},
{0, 0, 0, 0, 0, 0, 1}};

// For memoized solution
int table1[ROW][COLUMN] = {
{0, 0, 0, 0, 0, 0, 0},
{0, -1, -1, -1, -1, -1, -1},
{0, -1, -1, -1, -1, -1, -1},
{0, -1, -1, -1, -1, -1, -1},
{0, -1, -1, -1, -1, -1, -1},
{0, -1, -1, -1, -1, -1, -1}};

// For tabular_solution
int table2[ROW][COLUMN];

int main() {

  printf("Using Basic Recusion: The max number of pebbles I can pick up is %d\n", basic_recursion(ROW - 1,COLUMN - 1));

  printf("Using Memoized Solution: The max number of pebbles I can pick up is %d\n", memoized_solution(ROW - 1,COLUMN - 1));

  int i;
  for (i = 0; i < COLUMN; ++i) {
    table2[1][i] = 0;
  }
  for (i = 1; i < ROW; ++i) {
    table2[ROW][1] = 0;
  }
  printf("Using Tabular Solution: The max number of pebbles I can pick up is %d\n", tabular_solution(ROW - 1,COLUMN - 1));

}


int basic_recursion(int row, int column)
{
  int a, b, max;

  // Base Cases
  if (row == 0 || column == 0) { return 0; }
  if (row == 1 && column == 1) { return pebbles[row][column]; }

  a = basic_recursion(row - 1, column);
  b = basic_recursion(row, column - 1);
  max = a > b ? a : b;

  return pebbles[row][column] + max;
}


int memoized_solution(int row, int column)
{
  int a, b, max;

  // Base Cases
  if (row == 0 || column == 0) { return 0; }
  if (row == 1 && column == 1) { return pebbles[row][column]; }

  if (table1[row][column] != -1) { return table1[row][column]; }

  a = memoized_solution(row - 1, column);
  b = memoized_solution(row, column - 1);
  max = a > b ? a : b;

  table1[row][column] = pebbles[row][column] + max;

  return table1[row][column];
}


int tabular_solution(int row, int column)
{
  int a, b, max;

  for (int r = 1; r <= row; ++r) {
    for (int c = 1; c <= column; ++c) {
      a = table2[r - 1][c];
      b = table2[r][c - 1];
      max = a > b ? a : b;

      table2[r][c] = pebbles[r][c] + max;
    }
  }

  return table2[row][column];
}
