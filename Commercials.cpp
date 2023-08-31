#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
  long long int array[100010];
  long long int max;
  int number, cost;
  cin >> number >> cost;

  cin >> array[0];
  array[0] -= cost;
  if(array[0] < 0){
    array[0] = 0;
  }

  for(int a = 1; a < number; a++){
    cin >> array[a];
    array[a] = array[a] - cost + array[a-1];
    if(array[a] < 0) array[a] = 0;
    if(array[a] > max) max = array[a];
  }

  sort(array, array + number, greater<int>());
  cout << array[0];



  return 0;
}
