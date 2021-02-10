#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int find_major(vector<int>& v, int left, int right, int ft, int sd){
   int count_f = 0;
   int count_s = 0;

   for (int i = left; i <= right; ++i){
      if (v[i] == ft){
         count_f++;
      }

      if (v[i] == sd){
         count_s++;
      }
   }

   int flag = 0;
   if (left == 0) {
	   flag = 1;
   }

   if (count_f > ( right - left + flag) / 2 ){
      return ft;
   }
   if (count_s > ( right - left + flag) / 2 ){
      return sd;
   }

   return -1;
}

int get_majority_element(vector<int>& a, int left, int right) {
   //write your code here
   if (left == a.size())
	  return -1;
   if(right - left == 0)
      return a[left];

   int mid = left + ( right - left ) / 2;

   int f_path = get_majority_element(a, left, mid);
   int s_path = get_majority_element(a, mid + 1, right);

   return find_major(a, left, right, f_path, s_path);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size() - 1 ) != -1) << '\n';
}
