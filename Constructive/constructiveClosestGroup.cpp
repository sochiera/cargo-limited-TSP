#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int INF = 2147483647;

vector <vector <int> > Distances;
set <int> remainingCustomers;
int N;

int groupDistance(int first, int second, int third) {
	return Distances[first][second] + Distances[second][third] + Distances[third][first];
}

int minDistanceForGroup(int first, int second, int third) {
	if(!first) {
	    if(!second)
		return Distances[0][third] * 2;
	    else
		return Distances[0][second] + Distances[second][third] + Distances[third][0];
	}
	else
	    return min(Distances[0][first] + Distances[first][second] + Distances[second][third] + Distances[third][0],
		      min(Distances[0][second] + Distances[second][third] + Distances[third][first] + Distances[first][0],
			    Distances[0][third] + Distances[third][first] + Distances[first][second] + Distances[second][0]));
}

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
	vector <int> chosen(3);
	while(!remainingCustomers.empty()) {
	    int minDistance = INF;
	    for(set <int>::iterator it = remainingCustomers.begin(); it != remainingCustomers.end(); it++)
		if(minDistance > groupDistance(0, 0, *it))
		    minDistance = groupDistance(chosen[0] = 0, chosen[1] = 0, chosen[2] = *it);
	    for(set <int>::iterator it = remainingCustomers.begin(); it != remainingCustomers.end(); it++)
	    {
		set <int>::iterator it2 = it;
		it2++;
		while(it2 != remainingCustomers.end()) {
		    if(minDistance > groupDistance(0, *it2, *it))
			minDistance = groupDistance(chosen[0] = 0, chosen[1] = *it2, chosen[2] = *it);
		    it2++;
		}
	    }
	    for(set <int>::iterator it = remainingCustomers.begin(); it != remainingCustomers.end(); it++)
	    {
		set <int>::iterator it2 = it;
		it2++;
		while(it2 != remainingCustomers.end()) {
		    set <int>::iterator it3 = it2;
		    it3++;
		    while(it3 != remainingCustomers.end()) {
			if(minDistance > groupDistance(*it3, *it2, *it))
			      minDistance = groupDistance(chosen[0] = *it3, chosen[1] = *it2, chosen[2] = *it);
			it3++;
		    }
		    it2++;
		}
	    }
	    result += minDistanceForGroup(chosen[0], chosen[1], chosen[2]);
	    for(int i = 0; i < 3; i++)
		remainingCustomers.erase(chosen[i]);
	    cout << "removing chosen: " << chosen[0] << " " << chosen[1] << " " << chosen[2] << endl;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	readInput();
	cout << shortestRoute() << endl;
	return 0;
}