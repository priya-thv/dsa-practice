#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here'
	priority_queue<int,vector<int>>pq;
	pq.push(3);
	pq.push(1);
	pq.push(2);
	cout<<pq.top();
	//in stl library max heap is already implemented that why we use greater<int>to reverse it into stl library basically just a method to convert min into max in stl l
	//vector<int>is container for both min and max heap
	priority_queue<int,vector<int>,greater<int>>pqm;
	pqm.push(3);
	pqm.push(1);
	pqm.push(2);
	cout<<pqm.top();
	return 0;
}
