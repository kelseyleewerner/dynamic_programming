#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int basic_recursion(int, int);
int memoized_solution(int, int);
int tabular_solution(int, int);


#define N 5
#define K 3


int mem_table[N + 1][K + 1];
int tab_table[N + 1][K + 1];


int main()
{

  printf("Basic Recursion: How many combinations of size %d are there in a set of size %d? %d\n", K, N, basic_recursion(N, K));

  for (int i = 0; i <= N; ++i) {
    mem_table[i][0] = 1;

    for (int j = 1; j <= K; ++j){
      mem_table[i][j] = 0;
    }
  }

  printf("Memoized Solution: How many combinations of size %d are there in a set of size %d? %d\n", K, N, memoized_solution(N, K));

  for (int i = 0; i <= N; ++i) {
    tab_table[i][0] = 1;
    if (i + 1 <= K) { tab_table[i][i + 1] = 0; }
  }

  printf("Tabular Solution: How many combinations of size %d are there in a set of size %d? %d\n", K, N, tabular_solution(N, K));

}


int basic_recursion(int n, int k)
{
  if (n == k || k == 0) { return 1; }
  if (k == 1) { return n; }

  return basic_recursion(n - 1, k - 1) + basic_recursion(n - 1, k);
}


int memoized_solution(int n, int k)
{
  if (n == k || k == 0) { return 1; }
  if (k == 1) { return n; }

  if (mem_table[n][k] > 0) { return mem_table[n][k]; }

  mem_table[n][k] = memoized_solution(n - 1, k - 1) + memoized_solution(n - 1, k);

  return mem_table[n][k];
}


int tabular_solution(int n, int k)
{
  if (k == 0 || n == 0) { return tab_table[n][k]; }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= i && j <= K; ++j) {
      tab_table[i][j] = tab_table[i - 1][j - 1] + tab_table[i - 1][j];
    }
  }

  return tab_table[n][k];
}




























