#include <iostream>
using namespace std;

int main(void){
  long long int total = 0;
  int contests, holder;

  cin >> contests;
  for(int a = 0; a < contests; a++){
    cin >> holder;
    total += holder;
  }

  if(!(total%3)){
    cout << "yes" << endl;
  }
  else{
    cout << "no" << endl;
  }


}
