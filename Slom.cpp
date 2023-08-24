#include <iostream>
#include <string>
#include <vector>

using namespace std;
// This code works by finding and storing the "next position" of any locaiton in the string based on the problem
// description. From that, we can find the period over which it returns to the original string.
// 	Note that we failed to find a nice mathematical solution to this - I just brute forced it.
// Finally, we calculate how many more times the string needs to be put through the formula to return to the 
// original string based on the above period and number of iterations. 
//
// I despise this question. 
int main(void){
  long long int blinks;
  string k1,k2;
  int Length, period;
  vector<int> position;

  // Take input
  cin >> blinks;
  cin >> k1;
  k2 = k1;
  Length = k1.length();


  // Store the next positions based on string size. 
  position.push_back(0);
  for(int i = 1; i < Length; i++){
    if(i < (Length+1)/2){
      position.push_back(2*i);
    }
    else if(i >= Length/2){
      position.push_back(Length - (Length+1)%2 - 2*(i - Length/2));
    }
  }


  // Find the period
    int range = 0;
    string k3 = k1;
    while(1){
      for(int b = 0; b < Length; b++){
        k2[position[b]] = k1[b];
      }
      k1 = k2;
      range++;
      if(k1 == k3){
        break;
      }
    }
    period = range;



  // put the string through the formula the correct amount of times to return the original string. 
  for(int a = 0; a < (period - blinks%period); a++){
    for(int b = 0; b < Length; b++){
      k2[position[b]] = k1[b];
    }
    k1 = k2;
  }




  cout << k1 << endl;

  return 0;
}




