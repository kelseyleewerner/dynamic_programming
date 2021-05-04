#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>


int basic_recursion(int);
int memoized_solution(int);

#define LENGTH 8

int prices[LENGTH] = {1, 5, 8, 9, 10, 17, 17, 20};
// int prices[LENGTH] = {3, 5, 8, 9, 10, 17, 17, 20};
// int prices[LENGTH] = {3};

int mem_table[LENGTH + 1];


int main()
{

  printf("Basic Recursion: The max sale price of a rod of %d unit(s) is: %d\n", LENGTH, basic_recursion(LENGTH));

  mem_table[0] = 0;
  for (int i = 1; i <= LENGTH; ++i) { mem_table[i] = -1; }

  printf("Memoized Solution: The max sale price of a rod of %d unit(s) is: %d\n", LENGTH, memoized_solution(LENGTH));




}


int basic_recursion(int unit_length)
{
  int a,b;
  int max = INT_MIN;

  if (unit_length <= 0) { return 0; }

  for (int i = 0; i < unit_length; ++i) {
    a = max;
    b = prices[i] + basic_recursion(unit_length - 1 - i);
    max = a > b ? a : b;
  }

  return max;
}


int memoized_solution(int unit_length)
{
  int a, b;
  int max = INT_MIN;

  if (mem_table[unit_length] >= 0) { return mem_table[unit_length]; }

  for (int i = 0; i < unit_length; ++i) {
    a = max;
    b = prices[i] + basic_recursion(unit_length - 1 - i);
    max = a > b ? a : b;
  }

  mem_table[unit_length] = max;

  return mem_table[unit_length];
}














