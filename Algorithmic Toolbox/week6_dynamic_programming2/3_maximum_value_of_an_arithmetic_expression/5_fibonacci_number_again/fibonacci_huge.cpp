#include <iostream>
#include <cassert>
#include <random>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long  current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }

    return current;
}

long long pisano_period(long long m){
   long previous = 0;
   long current  = 1;

   for(long long i = 0;; ++i){
      long long tmp_previous = previous;
      previous = current;
      current = (tmp_previous + current) % m;

      if(previous == 0 && current == 1)
         return i + 1;
   }
}

long long get_fib_fast(long long n, long long m){
   long period = pisano_period(m);

   long long previous = 0;
   long long  current  = 1;
   
   if(n % period <= 1)
	   return n % period;

   for (long long i = 0; i < (n % period) - 1; ++i) {
       long long tmp_previous = previous;
       previous = current;
       current = (tmp_previous + current) % m;
   }

   return current;
}

void test(){
   for(int i = 0; i < 10000; ++i){
      int n = rand() % 10000000, m = rand() % 1000;
      if (get_fib_fast(n, m) == get_fibonacci_huge_naive(n, m))
         std::cout << "OK\n";
      else {
	 std::cout << "TEST ERROR\nn = " << n << "; m = " << m
		 << "; naive = " << get_fibonacci_huge_naive(n, m) <<  "; fast = " << get_fib_fast(n, m) << "; period = " << pisano_period(m) << "\n";
	break;
      } 
   }
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fib_fast(n, m) << '\n';
    

    return 0;
}
