#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

vector <pair <int, int> > coordinates;

int dist(int i, int j) {
    int x = coordinates[i].first - coordinates[j].first;
    int y = coordinates[i].second - coordinates[j].second;
    return (int)sqrt((double)x * x + (double)y * y);
}

int main(int argc, char *argv[]) {
    srand (time(NULL));
    if(argc > 1) {
	int n(atoi(argv[1]));
	coordinates.resize(n + 1);
	for(int i = 0; i <= n; i++)
	    coordinates[i] = make_pair((rand() % 10000), (rand() % 10000));
	cout << n << endl;
	for(int i = 0; i <= n; i++)
	{
	    if(i) cout << endl;
	    for(int j = 0; j <= n; j++)
	      cout << (j ? " " : "") << dist(i,j);
	}
    }
    else cout << "Must specify the number of customers." << endl;
    return 0;
}