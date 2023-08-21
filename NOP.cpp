#include <iostream>
using namespace std;


int main(void){
  char holder;

  int nops = 0;
  int params = 1;
  cin >> holder;
  
  while(cin >> holder){
    if(holder - 'Z' <= 0){
      // It's an instruction
      if(params%4 !=0)
        nops += 4-params%4;

      params = 0;
      
    }

    params++;
  }
cout << nops << endl;


}
