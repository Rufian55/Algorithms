#include<vector>
#include<iostream>
using std::vector;
using std::cout;

int findNext(vector<int> hotels, int cur, int traveled, int maxDist) {
	int dist = traveled + maxDist;
	unsigned int i = cur;
	while (i < hotels.size() && dist >= hotels.at(i)) {
		i++;
	}
	return i - 1;
}

vector<int> hotelStops(vector<int> hotels, int maxDist) {
	int traveled = 0;
	int nextStop = 0;
	int destination = hotels.back();

	vector<int> stops;

	while (traveled != destination) {
		nextStop = findNext(hotels, nextStop, traveled, maxDist);
		stops.push_back(hotels.at(nextStop));
		traveled = stops.back();
	}

	return stops;
}

int main() {
	vector<int> hotels = { 500, 800, 1200, 1320, 1400, 1600, 2000, 2300, 2500, 2800 };
	vector<int> result = hotelStops(hotels, 520);
	char comma = ',';
	for (int stop : result) {
		if (stop == hotels.back()) {
			comma = ' ';
		}
		cout << stop << comma << " ";
	}
	cout << '\n';
	return 0;
}