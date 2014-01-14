#include <iostream>
#include "population.hpp"


vector <vector <int> > Distances;
int N;

void readInput() {
	cin >> N;
	Distances.resize(N + 1);
	for(int i = 0; i <= N; i++)
	{
		Distances[i].resize(N + 1);
		for(int j = 0; j <= N; j++)
			cin >> Distances[i][j];
	}
}

int main()
{
 	cout << "Main." << endl;
	srand(time(0));
	Population *p = new Population(N, Distances);
	int iterations = 10000;
	while(iterations--){
		p->iteration();
		cout << p->getBest() << endl;
	}
	return 0;
}
