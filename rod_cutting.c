#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>


int basic_recursion(int);
int memoized_solution(int);
int tabular_solution(int);

#define LENGTH 8

int prices[LENGTH] = {1, 5, 8, 9, 10, 17, 17, 20};
// int prices[LENGTH] = {3, 5, 8, 9, 10, 17, 17, 20};
// int prices[LENGTH] = {3};
// int prices[LENGTH] = {1,2};

int mem_table[LENGTH + 1];
int tab_table[LENGTH + 1];


int main()
{

  printf("Basic Recursion: The max sale price of a rod of %d unit(s) is: %d\n", LENGTH, basic_recursion(LENGTH));

  mem_table[0] = 0;
  for (int i = 1; i <= LENGTH; ++i) { mem_table[i] = -1; }

  printf("Memoized Solution: The max sale price of a rod of %d unit(s) is: %d\n", LENGTH, memoized_solution(LENGTH));

  tab_table[0] = 0;
  tab_table[1] = prices[0];

  printf("Tabular Solution: The max sale price of a rod of %d unit(s) is: %d\n", LENGTH, tabular_solution(LENGTH));

}


int basic_recursion(int section_length)
{
  int a,b;
  int max = INT_MIN;

  if (section_length <= 0) { return 0; }

  for (int i = 0; i < section_length; ++i) {
    a = max;
    b = prices[i] + basic_recursion(section_length - 1 - i);
    max = a > b ? a : b;
  }

  return max;
}


int memoized_solution(int section_length)
{
  int a, b;
  int max = INT_MIN;

  if (mem_table[section_length] >= 0) { return mem_table[section_length]; }

  for (int i = 0; i < section_length; ++i) {
    a = max;
    b = prices[i] + memoized_solution(section_length - 1 - i);
    max = a > b ? a : b;
  }

  mem_table[section_length] = max;

  return mem_table[section_length];
}


int tabular_solution(int section_length)
{
  int a, max;

  if (section_length < 2) { return tab_table[section_length]; }

  for (int i = 2; i <= section_length; ++i) {
    max = INT_MIN;

    for (int j = 1; j <= i; ++j) {
      a = prices[j - 1] + tab_table[i - j];
      if (a > max) { max = a; }
    }

    tab_table[i] = max;
  }

  return tab_table[section_length];
}























