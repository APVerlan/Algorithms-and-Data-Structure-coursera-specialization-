#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  //write your code here
  int point = -1, counter = 0, curr = 0;
  vector<int> points;

  std::sort(segments.begin(), segments.end(), [](Segment lhs, Segment rhs){return lhs.end < rhs.end;});
  
	while(counter < segments.size()){
    curr = counter;
		point = segments[curr].end;
    points.push_back(point);

		for(int i = curr; i < segments.size(); ++i){
			if (segments[i].start > point){
				counter = i;
				break;
			}
			
			if (i == segments.size() - 1)
				counter = segments.size();
		}
	
  }
  
	return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
