#include <iostream>

using namespace std;

int main(void){
    int primes[100];
    primes[0] = 2;
    
    int next_prime = 1;
    int potential_prime = primes[next_prime-1] + 1;
    while(next_prime != 100){
        int is_prime = 1;
        for(int a = 0; a < next_prime; a++){
            if(potential_prime % primes[a] == 0){
                is_prime = 0;
                break;
            }
        }
        if(is_prime){
            primes[next_prime] = potential_prime;
            next_prime++;
        }
        potential_prime++;
    }
    
    for(int a = 0; a < 100; a++){
        cout << primes[a] << endl;
    }
    
    return 0;
}
