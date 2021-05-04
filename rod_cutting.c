#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>


int basic_recursion(int);

#define LENGTH 8

int prices[LENGTH] = {1, 5, 8, 9, 10, 17, 17, 20};
// int prices[LENGTH] = {3, 5, 8, 9, 10, 17, 17, 20};
// int prices[LENGTH] = {3};


int main()
{

  printf("Basic Recursion: The max sale price of a rod of %d unit(s) is: %d\n", LENGTH, basic_recursion(LENGTH));






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






