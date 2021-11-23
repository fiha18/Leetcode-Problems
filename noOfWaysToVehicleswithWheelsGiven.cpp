/*
Given an integer denoting a total number of wheels, help Amazon Logistics find the number of different ways to choose a fleet of vehicles from an infinite supply of two-wheeled and four wheeled vehicles such that the group of chosen vehicles has that exact total number of wheels. Two ways of choosing vehicles are considered to be different if and only if they contain different numbers of two-wheeled or four-wheeled vehicles.

For example, if our array wheels = [4.5.6] our return array would be res=[2,0,2]. Case by case, we can have 1 four-wheel or 2 two-wheel to have 4 wheels. We cannot have 5 wheels. We can have 1 four-wheel and 1 two-wheel or 3 two-wheel vehicles in the final case
*/

/*
Approach :
No of vehicles for 0 wheel = 0
No of vehicles for 1 wheel = 0
No of vehicles for 2 wheels = 1(1 vechicle with 2 wheels)
No of vehicles for 3 wheels = 0
No of vehicles for 4 wheels = 2(2 vechicle with 2 wheels amd 1 vechicle with 4 wheels)
No of vehicles for 5 wheels = 0
No of vehicles for 6 wheels = 2((2 + 1) vehicle with 2 wheels and (1 vechicle with 4 wheels and 1 vechicle with 2 wheels))
No of vehicles for 7 wheels = 0
No of vehicles for 8 wheels = 3((2 + 2) vehicle with 2 wheels and (1 vechicle with 4 wheels and 1+1 vechicle with 2 wheels) and 2 vechicle with 4 wheels )

The pattern we are getting here is:
 		if n is odd then 0 vehicles ,
		if n is even but not multiple of 4 then no of vehicle is equal to vehicles of nearest smaller multiple of 4(except for 0),
		if n is multiple of 4 then no of vehicle is equal to vehicles of nearest smaller multiple of 4(except for 0) increased by 1.

Declaring global vector vehicle to maintain the no of vehicles required for wheels equal to index

if the target is less then the size of vehicles vector means value has been calculated previously instantly return that value.

let size = size of input list of no of wheels and max = maximum number in the list
Time Complexity = O(size*max)
Space Complexity = O(max)
Both the complexity are linear.

*/


#include <bits/stdc++.h>
using namespace std;
vector<int> vehicles;
int noOfVehicles(vector<int> vehicles,int target)
{
	if(target < vehicles.size())
		return vehicles[target];
	for (int i = 5; i <= target ; ++i)
	{
		if(i%2)
			vehicles[i] = 0;
		else if(i%2 == 0 && i%4 != 0)
			vehicles[i] = vehicles[i-2];
		else
			vehicles[i] = vehicles[i-4] + 1;
	}
	return vehicles[target];
}
int main()
{
	int n;
	cin >> n;
	vector<int> wheels;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		wheels.push_back(x);
	}
	vehicles.push_back(0);
	vehicles.push_back(0);
	vehicles.push_back(1);
	vehicles.push_back(0);
	vehicles.push_back(2);
	for (int i = 0; i < n; ++i)
	{
		cout << noOfVehicles(vehicles,wheels[i]) << endl;
	}
	return 0;
}