#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int basic_recursion(int, int);
int memoized_solution(int, int);
int tabular_solution(int);

#define HEIGHT 4

int triangle[HEIGHT + 1][HEIGHT + 1] = {{0, 0, 0, 0, 0},
                                        {0, 8, 6, 9, 6},
                                        {0, 1, 4, 7, 0},
                                        {0, 5, 4, 0, 0},
                                        {0, 2, 0, 0, 0}};

//int triangle[HEIGHT + 1][HEIGHT + 1] = {{0, 0, 0, 0, 0},
  //                                      {0, 4, 1, 8, 3},
    //                                    {0, 6, 5, 7, 0},
      //                                  {0, 3, 4, 0, 0},
        //                                {0, 2, 0, 0, 0}};

//int triangle[HEIGHT + 1][HEIGHT + 1] = {{0, 0, 0, 0, 0, 0},
  //                                      {0, 1, 1, 1, 1, 1},
    //                                    {0, 8, 6, 9, 6, 0},
      //                                  {0, 1, 4, 7, 0, 0},
        //                                {0, 5, 4, 0, 0, 0},
          //                              {0, 2, 0, 0, 0, 0}};

//int triangle[HEIGHT + 1][HEIGHT + 1] = {{0, 0},
  //                                      {0, 2}};

int mem_table[HEIGHT + 1][HEIGHT + 1];
int tab_table[HEIGHT + 1][HEIGHT + 1];


int main() {

  printf("Basic Recursion: The minimum sum after descending the triangle is %d\n", basic_recursion(HEIGHT, 1));

  for (int i = 0; i <= HEIGHT; ++i) {
    for (int j = 0; j <= HEIGHT; ++j) {
      mem_table[i][j] = 0;
    }
  }

  printf("Memoized Solution: The minimum sum after descending the triangle is %d\n", memoized_solution(HEIGHT, 1));

  for (int i = 0; i <=HEIGHT; ++i) {
    tab_table[0][i] = 0;
    tab_table[1][i] = triangle[1][i];
  }

  printf("Tabular Solution: The minimum sum after descending the triangle is %d\n", tabular_solution(HEIGHT));

}


int basic_recursion(int row, int column)
{
  int a, b, min;

  if (row == 0) { return 0; }

  a = basic_recursion(row - 1, column);
  b = basic_recursion(row - 1, column + 1);
  min = a < b ? a : b;

  return triangle[row][column] + min;
}


int memoized_solution(int row, int column)
{
  int a, b, min;

  if (row == 0) { return 0; }

  if (mem_table[row][column] > 0) { return mem_table[row][column]; }

  a = basic_recursion(row - 1, column);
  b = basic_recursion(row - 1, column + 1);
  min = a < b ? a : b;

  mem_table[row][column] = triangle[row][column] + min;

  return mem_table[row][column];
}


int tabular_solution(int height)
{
  int a, b, min;
  int column = height - 1;

  if (height == 1) { return tab_table[1][1]; }

  for (int r = 2; r <= height; ++r, --column) {
    for (int c = 1; c <= column; ++c) {
      a = tab_table[r - 1][c];
      b = tab_table[r - 1][c + 1];
      min = a < b ? a : b;

      tab_table[r][c] = triangle[r][c] + min;
    }
  }

  return tab_table[height][1];
}






















