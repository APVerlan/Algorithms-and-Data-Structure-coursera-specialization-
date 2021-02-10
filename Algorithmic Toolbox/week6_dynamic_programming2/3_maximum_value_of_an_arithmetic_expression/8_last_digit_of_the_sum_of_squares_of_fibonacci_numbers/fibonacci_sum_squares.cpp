#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
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

   int sum = 1;  
   int previous = 0;
   int current  = 1;


   for(int i = 0; i < (n + 1) % period - 1; ++i){
      int tmp_previous = previous;
      previous = current;
      current = (tmp_previous + current) % 10;
   }

   return (current * previous) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fib_fast(n);
}
