#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector <vector <int> > Distances;
set <int> remainingCustomers;
int N, result;

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
	result = 0;
	int currentVertex = 0;
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
		
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	readInput();
	cout << shortestRoute() << endl;
	return 0;
}