#include <iostream>
#include <random>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current % 10;
        current = (tmp_previous + current) % 10;
        sum += current;
	sum %= 10;
    }

    return sum;
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

long fib_fast(long long n){
   int period = pisano_period(10);

   int sum_cycle = 1;  
   int previous = 0;
   int current  = 1;


   for(int i = 0; i < period - 1; ++i){
      int tmp_previous = previous;
      previous = current;
      current = (tmp_previous + current) % 10;

      sum_cycle = (sum_cycle + current) % 10;
   }

   previous = 0;
   current  = 1;
   int sum_end;
   
   if(n % period <= 1)
      sum_end = n % period;
   else {
      sum_end = 1;
      for(int i = 0; i < n % period - 1; ++i){
         int tmp_previous = previous;
         previous = current;
         current = (tmp_previous + current) % 10;

         sum_end = (sum_end + current) % 10;
      }
   }

   return (sum_cycle * n / period) % 10 + sum_end;  
}


void test(){
   for(int i = 0; i < 10000; ++i){
      int n = rand() % 1000000000;
      if (fib_fast(n) == fibonacci_sum_naive(n))
         std::cout << "OK\n";
      else {
	 std::cout << "TEST ERROR\nn = " << n 
		 << fibonacci_sum_naive(n) <<  "; fast = " 
		 << fib_fast(n) << "; period = " << pisano_period(10) << "\n";
	break;
      } 
   }
}

int main() {
    long long n = 0;
    //test();
    std::cin >> n;
    std::cout << fib_fast(n) << "\n";
}
