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
	cout << "Starting at " << currentVertex << endl;
	int capacity = 3;
	while(!remainingCustomers.empty()){
		int minDistance = currentVertex == 0 ? Distances[0][*remainingCustomers.begin()] : Distances[currentVertex][0];
		int closestVertex = currentVertex == 0 ? *remainingCustomers.begin() : 0;
		for(set <int>::iterator it = remainingCustomers.begin(); it != remainingCustomers.end(); it++)
			if(Distances[currentVertex][*it] < Distances[currentVertex][closestVertex])
			{
				closestVertex = *it;
				minDistance = Distances[currentVertex][closestVertex];
			}
		result += Distances[currentVertex][closestVertex];
		if(closestVertex != 0) capacity--;
		if(capacity == 0 || closestVertex == 0)
		{
			result += Distances[closestVertex][0];
			currentVertex = 0;
			capacity = 3;
			cout << "Returning to base." << endl;
		}
		else {
			cout << "Moving from " << currentVertex << " to " << closestVertex << endl;
			remainingCustomers.erase(closestVertex);
			currentVertex = closestVertex;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	readInput();
	cout << shortestRoute() << endl;
	return 0;
}