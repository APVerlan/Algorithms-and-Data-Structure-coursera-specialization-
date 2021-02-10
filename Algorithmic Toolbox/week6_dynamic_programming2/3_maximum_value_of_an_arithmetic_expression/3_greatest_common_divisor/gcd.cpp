#include <iostream>
#include <algorithm>
#include <random>
#include <cassert>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

long long gcd_fast(long long a, long long b){
   if (a < b)
      std::swap(a, b); 
   if (a == 0)
      return b;
   if (b == 0)
      return a;

   return gcd_fast(a%b, b);
}

void test(){
   for(int i = 0; i < 10000; i++){
      int a = rand() % 1000000, b = rand() % 1000000;
      assert(gcd_fast(a, b) == gcd_naive(a, b));
      /*std::cout << "a = " << a << "; b = " << b << "; gcd = " 
	      << gcd_fast(a, b) << "\nTEST IS OK" << "\n\n";*/
   }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
