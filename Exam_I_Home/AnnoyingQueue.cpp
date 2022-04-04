#include <iostream>
#include <list>
using namespace std;

int main() {
	int num, T;
	cin >> num >> T;
	list<int> queue;

	// list<int> queue(num);
	// this list is already initialized w/ num space and all values are 0!
	
	while (T--) {
		int op, id;
		cin >> op;
		if (op == 0) {
			cin >> id;
			queue.push_back(id);
		} else if (op == 1) {
			if (queue.empty())
				cout << "-1\n";
			else {
				cout << queue.front() << '\n';
				queue.pop_front();
			}
		} else if (op == 2) {
			cin >> id;
			queue.remove(id);
		}
	}
}