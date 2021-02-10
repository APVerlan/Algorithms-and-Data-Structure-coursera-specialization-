#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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

int fib_from_to(long long from, long long to){
   int m_sum = fib_fast(from - 1), n_sum = fib_fast(to);
   
   if(from == 0)
      m_sum = fib_fast(from);

   if(n_sum >= m_sum)
      return n_sum - m_sum;
   else
      return 10 - m_sum + n_sum;  
} 

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << fib_from_to(from, to) << '\n';
}
