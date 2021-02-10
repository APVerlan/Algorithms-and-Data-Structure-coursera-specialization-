#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using std::vector;

struct Item {
   int value;
   int weight;
   double density;
};

double get_optimal_value(int capacity, vector<int>& weights, vector<int>& values) {
  double value = 0.0;

  // write your code here
  std::list<Item> items; 
  for (size_t i = 0; i < values.size(); ++i) {
     if (items.size() == 0)
	items.push_front({values[i], weights[i], (double) values[i] / weights[i]});     
     else {
        for (auto it = items.begin();; ++it) {
	   if (it->density < (double) values[i] / weights[i]){
	      items.insert(it, {values[i], weights[i], (double) values[i] / weights[i]});
              break;
	   }	      

	   if (it == std::prev(items.end())){
	      items.push_back({values[i], weights[i], (double) values[i] / weights[i]});
	      break;
	   }
	}
     }
  }
  
  //if (items.size() == 3)
     //std::cout << "DONE LIST FULLING\n";

  for (auto iter = items.begin(); iter != items.end(); ++iter) {
     if (capacity == 0)
        break;

     int weight;
     
     if (iter->weight > capacity)
        weight = capacity;
     else
	weight = iter->weight;
       
     value += iter->density * weight;
     capacity -= weight;
     //std::cout << value << " " << capacity << "\n";
  }

  //std::cout << "DONE PROGRAMM\n";

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
  //std::cout << "DONE\n"; 
  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
