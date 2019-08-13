#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int PNT(double prime){
   return static_cast<int>(prime/(log(prime)));
}

bool prime_find(int num){
   int check = 5;
   while(pow(check,2) <= num){
      if(num % check == 0 || num % (check + 2) == 0){ //using a defined algorithm
         return false;
      }
      check = check + 6;
   }
   return true;
}

int primer(int num_prime){
   int count = 0;
   ofstream primeTXT;
   primeTXT.open("Primes.txt");
   primeTXT << 2 << endl << 3 << endl << 5 << endl;
   for(int i = 7; i <= num_prime;i=i+2){
      if((i % 5!= 0) && (i % 3 != 0)){
         if(prime_find(i)){
            ++count;
            primeTXT << i << endl;
         }
      }
   }
   primeTXT.close();
   return count;
}

int main(){
   int num_primes = 0;
   int prime_count = 0;
   cout << "Calculate the primes not exceeding what integer? ";
   cin >> num_primes;
   prime_count = primer(num_primes);
   cout << "The primes up to " << num_primes << " have been printed to 'Primes.txt'." << endl;
   cout << "Per the Prime Number Theorem, there are approximately " << PNT(num_primes) << " primes not exceeding " << num_primes << "." << endl;
   cout << "In reality, there are " << prime_count << " primes not exceeding " << num_primes << ".";
   return 0;
}
