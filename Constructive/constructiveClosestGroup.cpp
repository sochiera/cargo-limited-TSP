#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector <vector <int> > Distances;
set <int> remainingCustomers;
int N;

void readInput() {
	cin >> N;
	for(int i = 1; i <= N; i++)
		remainingCustomers.insert(i);
	Distances.resize(N + 1);
	for(int i = 0; i <= N; i++)
	{
		Distances[i].resize(N + 1);
		for(int j = 0; j <= N; j++)
			cin >> Distances[i][j];
	}
}

int shortestRoute() {
	int result = 0;
	int currentVertex = 0;
	int capacity;
	cout << "Starting at " << currentVertex << endl;
	while(!remainingCustomers.empty()){
		if(capacity == 0)
		{
			result += Distances[currentVertex][0];
			cout << "Returning to base." << endl;
			currentVertex = 0;
		}
		if(currentVertex == 0) capacity = 3;
		int minDistance = currentVertex == 0 ? Distances[0][*remainingCustomers.begin()] : Distances[currentVertex][0];
		int closestVertex = currentVertex == 0 ? *remainingCustomers.begin() : 0;
		cout << "Currently at " << currentVertex << " min is " << minDistance << " at " << closestVertex << endl;
		for(set <int>::iterator it = remainingCustomers.begin(); it != remainingCustomers.end(); it++) {
			cout << "Comparing with distance to " << *it << " which is " << Distances[currentVertex][*it] << endl;
			if(Distances[currentVertex][*it] < minDistance)
			{
				cout << "New minDistance = " << Distances[currentVertex][*it] << " (to " << *it << ")" << endl;
				closestVertex = *it;
				minDistance = Distances[currentVertex][closestVertex];
			}
		}
		result += Distances[currentVertex][closestVertex];
		if(closestVertex != 0) {
			capacity--;
			cout << "Moving from " << currentVertex << " to " << closestVertex << endl;
			remainingCustomers.erase(closestVertex);
			currentVertex = closestVertex;
		}
		else currentVertex = 0;
	}
	return result + Distances[currentVertex][0];
}

int main() {
	ios_base::sync_with_stdio(0);
	readInput();
	cout << shortestRoute() << endl;
	return 0;
}