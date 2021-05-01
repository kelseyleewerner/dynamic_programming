#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int tabular_solution(int);

#define LO_COIN 1
#define MID_COIN 3
#define HI_COIN 4

int * t;


int main()
{
  int n;

  printf("Please provide a total number of pennies (>=1): ");
  scanf("%d", &n);

  t = malloc(sizeof(int) * (n + 1));
  h[0] = 0;
  h[1] = 1;
  h[2] = 2;
  h[3] = 1;

  printf("Using Tabular Solution: The number of coins to make exact least change for %d pennies is %d\n", n, tabular_solution(n));

  free(t);
}




int tabular_solution(int n)
{
  int a, b, c, min;

  if (n < HI_COIN - 1) { return h[n]; }

  for (int i = HI_COIN; i <= n; ++i) {
    a = h[i - LO_COIN];
    b = h[i - MID_COIN];
    c = h[i - HI_COIN];

    min = a;
    if (b < min) { min = b; }
    if (c < min) { min = c; }

    h[i] = 1 + min;
  }

  return h[n];
}








