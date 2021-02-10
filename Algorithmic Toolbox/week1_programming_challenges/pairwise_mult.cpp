#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseMult(vector<long long>& items);
template <typename T>
void PrintVector(vector<T> vec);

int main(){
   size_t n;
   cin >> n;

   vector<long long> items(n);
   
   for(size_t i = 0; i < n; i++){
	cin >> items[i];
   }

   cout << MaxPairwiseMult(items) << "\n";

   return 0;   
}

long long MaxPairwiseMult(vector<long long>& items){
   
   long long max = -1, premax = -1;	
   for(size_t i = 0; i < items.size(); i++){
      if(items[i] > max){
	 premax = max;
	 max = items[i];
      } else if(items[i] > premax){
         premax = items[i];
      }
   }
   
   return max * premax;
}
