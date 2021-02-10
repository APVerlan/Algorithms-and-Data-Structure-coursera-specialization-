#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using std::priority_queue;
using std::vector;
using std::cin;
using std::cout;
using std::pair;

class JobQueue {
 private:
  long long num_workers_;
  vector<long long> jobs_;

  vector<long long> assigned_workers_;
  vector<long long> start_times_;
	
  void WriteResponse() const {
    for (size_t i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    //vector<long long> next_free_time(num_workers_, 0);
		auto comp = [](pair<long long, long long> lhs, pair<long long, long long> rhs) { 
			if (lhs.second != rhs.second)
				return lhs.second > rhs.second;
			else return lhs.first > rhs.first;
		};
		priority_queue<pair<long long, long long>, std::vector<pair<long long, long long>>, decltype(comp)> threads_time_(comp);

		for (int i = 0; i < num_workers_; ++i)
			threads_time_.push(std::make_pair(i, 0));

    for (int i = 0; i < jobs_.size(); ++i) {
			long long free_time = threads_time_.top().second, thread = threads_time_.top().first;  
			assigned_workers_[i] = thread;
			start_times_[i] = free_time;
      
			threads_time_.pop();
			threads_time_.push(std::make_pair(thread, free_time + jobs_[i]));


			/*int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;*/

    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
 
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
