#include <iostream>
using namespace std;

int main(void){

  int Time = 0, M[10][3];
  int Jim[20];

  for(int i= 0; i < 20; i++){
    cin >> Jim[i];
  }
  for(int a = 0; a < 10; a++){
    for(int b = 0; b < 3; b++){
      cin >> M[a][b];
    }
  }

// Some notes:
// 	Jim does three rotations.
// 	Jim lets other people go first. 
// 	Jim does not recover from the last exercise.
// 	Other people may start at negative Time (eg, earlier).
//
//
//  DO WE HAVE TO ALTER THE OFFSET FOR THE OTHER PEOPLE BASED ON HOW LONG JIM TOOK?
//  probably. but we'll try without first...
//  yeah, we def do. 
//
  for(int set = 0; set < 3; set++){
    for(int machine = 0; machine < 10; machine++){
      // Note that the following formula finds how far into the workout + recovery the other person is. 
      int Difference = (Time - M[machine][2])%(M[machine][0] + M[machine][1]);
      
      // If the other person hasn't started using it yet. 
      if(Time < M[machine][2]){
        // We're good to start the workout. 
        Time  += Jim[2*machine] + Jim[2*machine+ 1];

	// But we might have altered their start time.
	if(Time > M[machine][2]){ 
          M[machine][2] = Time - Jim[2*machine+ 1];
	}
      }

      // If the other person is currently resting
      else if((Difference) > M[machine][0]){
        // We're good to start the workout. 
        Time  += Jim[2*machine] + Jim[2*machine+ 1];
	
	// if Jim takes longer than the other person's break
	if(Jim[2*machine] > M[machine][1] - (Difference - M[machine][0])){
	  M[machine][2] += Jim[2*machine] - (M[machine][1] - (Difference - M[machine][0]));
	}
	
      }

      else{
        // We must wait till the machine is free.
	Time -= (Time - M[machine][2])%(M[machine][0] + M[machine][1]);
	Time += M[machine][0];
	// Now the machine is free.
        Time  += Jim[2*machine] + Jim[2*machine+ 1];

	// But maybe Jim's workout took longer than his buddy's break
	if(Jim[2*machine] > M[machine][1]){
          M[machine][2] += Jim[2*machine] - M[machine][1];
	}
      }

    }
  }

  Time -= Jim[19];
  cout << Time << endl;



  return 0;
}
