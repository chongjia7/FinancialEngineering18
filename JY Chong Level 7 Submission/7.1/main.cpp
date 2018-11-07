#include <list>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int main()
{
	// A list
	list<double> list1;
	for (int i = 0; i < 10; i++) {list1.push_back(i + 0.1);}
	cout << "The first element: " << list1.front() << ", the last element: " << list1.back() << endl;

	// A vector
	vector<double> vector1(5); // first 5 are zeros
	for (int i = 0; i < 10; i++) {vector1.push_back(i + 0.1);}
	for (int i = 0; i < vector1.size(); i++) {cout << vector1[i] << ",";}
	cout << endl;

	// A map
	map<string, double> map1;
	string str[4] = { "0", "1", "2", "3" };

	for (int i = 0; i < 4; i++) {map1[str[i]] = i + 0.1;}
	for (int i = 0; i < map1.size(); i++) {cout << map1[str[i]] << ",";}

	return 0;
	}
