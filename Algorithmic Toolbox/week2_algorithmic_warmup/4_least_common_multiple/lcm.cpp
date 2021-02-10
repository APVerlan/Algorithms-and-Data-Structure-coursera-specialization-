#include <iostream>
#include <algorithm>
#include <cassert>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
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

long long lcm_fast(long long a, long long b){
   return a * b / gcd_fast(a, b);
}

void test(){
   for(int i = 0; i < 1000; i++){
      long long a = rand() % 10000, b = rand() % 10000;
      assert(lcm_fast(a, b) == lcm_naive(a, b));
      std::cout << "OK\n";
   }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  //test();
  return 0;
}
