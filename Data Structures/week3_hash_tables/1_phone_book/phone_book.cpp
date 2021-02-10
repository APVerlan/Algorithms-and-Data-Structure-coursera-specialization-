#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, name;
    int number;
};

class PhoneBook {
	public:

		void add(int number, const string& name) { number_to_name_[number] = name; };
		
		void del(int number) { 	
			if ( number_to_name_.count(number) )
				number_to_name_.erase(number); 
		};
		
		string find(int number) const { 
			if ( number_to_name_.count(number) )
				return number_to_name_.at(number);
			else
				return "not found";
		}

	private:
		std::unordered_map<int, string> number_to_name_;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    PhoneBook book;
		vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
						book.add(queries[i].number, queries[i].name);
				} else if (queries[i].type == "del") {
					book.del(queries[i].number);
				} else {
					result.push_back(book.find(queries[i].number));
				}

		return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
