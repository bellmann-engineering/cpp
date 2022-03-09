#include <iostream>
#include <vector>
#include <iterator> 

using namespace std;

void findInteger(vector<int>& arr, int k)
{
	vector<int>::const_iterator i;
	for(i = arr.begin(); i != arr.end(); ++i)
	{
		if( (*i) == k )
		{
			cout << k << " gefunden" << endl;
			return;
		}
	}
	cout << k << " nicht gefunden" << endl;
}

int main()
{
	static const int arr[] = {1, 2, 3, 4} ;
	vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]));
	
	findInteger(vec, 5);
	
	return 0;
}
