#include <iostream>
#include <vector>
using namespace std;
/*
Problem: https://leetcode.com/problems/gas-station/
This is one of the best Greedy problem with small trick

Approach:
* If total gas is less than total cost, we can not complete journey wherver we start.
* If tatal gas is >= total cost
    * Say X is the station where it has minium amount of gas before we reach there.
    * Since we never have less than this amount of gas we started at at X, we can start at X so that we have 0 gas at the end.
*/

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
  int stationCount = gas.size();
  int totalGas = 0, totalCost = 0;
  for (int ind = 0; ind < stationCount; ind++)
  {
    totalGas += gas[ind];
    totalCost += cost[ind];
  }
  if (totalGas < totalCost)
    return -1;

  struct StartingStation
  {
    int stationInd = 0, remainingGas = 0;
  };
  StartingStation startingStationPair;

  int remainingGas = 0;

  for (int ind = 1; ind < stationCount; ind++)
  {
    remainingGas += gas[ind - 1] - cost[ind - 1];
    if (remainingGas < startingStationPair.remainingGas)
    {
      startingStationPair = {ind, remainingGas};
    }
  }

  return startingStationPair.stationInd;
}

int main()
{
  int stationCount;
  cin >> stationCount;
  vector<int> gas(stationCount), cost(stationCount);

  for (int ind = 0; ind < stationCount; ind++)
    cin >> gas[ind];
  for (int ind = 0; ind < stationCount; ind++)
    cin >> cost[ind];

  cout << canCompleteCircuit(gas, cost) << endl;
  return 0;
}
