/******************************************************************************
* Program minTravelDist.cpp
* See comment block at end of program for program purpose.
* Compile: g++ minTravelDist.cpp -o minTrav -g -Wall -std=c++0x
******************************************************************************/
#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <deque>
using std::deque;
#include <string>
using std::string;
#include<random>
#include <ctime>

// Prototypes.
int randomDistance();
void showNames(vector<char> &hotels);
void showDistances(vector<int> &distances);
void showStays(vector<char> &hotels_stayed);
void showIncDist(vector<int> &incDist);

int main() {
	srand(time(NULL));
	int position = 0;				// Your starting position.
	int n = 10;					// Number of nodes to traverse.
	int drivingRange = 11;			// Max distance you can drive in one day.
	int numDays = 0;				// The number of travel days to be minimized.
	vector<char> hotels_stayed;		// Hotels stayed container.
	vector<char> hotels;			// Hotels "along the way".
	vector<int> distances;			// Travel distances to each hotel.
	vector<int> incDist;			// Incremental distance to next node.
	char name = 'A';				// Lazy way to name hotels.

	// Populate the distances deque.
	int firstHotelDist = randomDistance();
	distances.push_back(firstHotelDist);
	for (int i = 1; i < n; i++) {
		int nextDistance = randomDistance();
		distances.push_back(distances.back() + nextDistance);
	}

	// Populate incremental distances to incDist.
	incDist.push_back(distances.front());
	for (int i = 1; i < distances.size(); i++) {
		incDist[i] = distances[i] - distances[i];
	}

//	showIncDist(incDist);


	// Populate hotels vector.
	for (int i = 0; i < n; i++) {
		hotels.push_back(name);
		name++;
	}

	// Populate hotels_stayed vector - first element only.
	hotels_stayed.push_back('x');

	showNames(hotels);
	showDistances(distances);

	int temp, index = 0;
/*	for (char i = 'A'; i < hotels_stayed.back(); i++) {
		temp = distances[1] - distances[0];
		while (temp <= drivingRange) {
			temp += distances.front();
			if (temp <= drivingRange) {
				distances.pop_front();
				index++;
			}
			if (temp >= drivingRange)
				break;
		}
		hotels_stayed.push_back(hotels[index - 1]);
	}
*/		/*
		temp = 0;
		while (temp <= drivingRange) {
			temp += distances.front();
			if (temp <= drivingRange) {
				distances.pop_front();
				index++;
			}
			if (temp >= drivingRange)
				break;
		}
		hotels_stayed.push_back(hotels[index - 1]);
		*/
	showDistances(distances);


/*	for (int i = 0; i < n; i++) {
		if ((distances[i+1] - distances[i]) < drivingRange) {
			cout << "ok2iter\n" << i << '\n';
		}
	}
*/

	showStays(hotels_stayed);

	return 0;
}

// Returns a random int between 1 and 10 inclusive.
// The formula is (rand() % (max - min + 1)) + min.
int randomDistance() {
	return (rand() % 10) + 1;
}

// Prints to stdout hotels vector.
void showNames(vector<char> &hotels) {
	cout << "Hotel Names: ";
	for (unsigned int i = 0; i < hotels.size(); i++) {
		cout << hotels[i] << " ";
	}
	cout << '\n';
}

// Prints to stdout distances vector.
void showDistances(vector<int> &distances) {
	cout << "Distances: ";
	for (unsigned int i = 0; i < distances.size(); i++) {
		cout << distances[i] << " ";
	}
	cout << '\n';
}

void showIncDist(vector<int> &incDist) {
	cout << "Incremental Distances: ";
	for (unsigned int i = 0; i < incDist.size(); i++) {
		cout << incDist[i] << " ";
	}
	cout << '\n';
}


// Prints to stdout hotels stayed vector.  Note index start == 1.
void showStays(vector<char> &hotels_stayed) {
	cout << "Hotels Stayed: ";
	for (unsigned int i = 1; i < hotels_stayed.size(); i++) {
		cout << hotels_stayed[i] << " ";
	}
	cout << '\n';
}


/*

You’re going on a road trip with friends. Unfortunately, your headlights are
broken, so you can only drive in the daytime. Therefore, on any given day you
can drive no more than "drivingRange miles. You have a map with "hotels" along the way and the
"distances" from your start point to each hotel x1< x2< ... < xn. Your final
destination is the last hotel. Describe an algorithm that determines which
hotels you should stay in if you want to minimize the number of days it takes
you to get to your destination.

position = 0
hotels_stayed = []
while not at destination
target = position + d
find stop_hotel with largest dist where dist <= target
position = dist of stop_hotel
add stop_hotel to hotels_stayed
return hotels_stayed
*/