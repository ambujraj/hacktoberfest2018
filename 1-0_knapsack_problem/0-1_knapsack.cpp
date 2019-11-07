#include <iostream>
#include<algorithm>
using namespace std;
int knapsack(int* weights, int* values, int n, int maxWeight)
{
  if(weights == nullptr || values == nullptr || maxWeight == 0 || n == 0)
    return 0;
  if(weights[0] > maxWeight)
    return knapsack(weights + 1, values + 1, n - 1, maxWeight);
  int op1 = values[0] + knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]);
  int op2 = knapsack(weights + 1, values + 1, n - 1, maxWeight);
  return max(op1, op2);
}

