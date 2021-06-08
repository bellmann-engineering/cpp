#include <iostream>
#include <iterator> 
#include <vector> 
#include <queue>
// ggf. <algorithm>

using namespace std;

struct TwoValues
{
	int a;
	int b;	
};

struct compTwoValues 
{
	bool operator()(TwoValues* v1, TwoValues* v2)
	{
		return (v1->b < v2->b);	
	}
};

int main()
{
	priority_queue<TwoValues*, vector<TwoValues*>, compTwoValues> queue;
	
	TwoValues* t1 = new TwoValues;
	t1->a = 4;
	t1->b = 9;	
	queue.push(t1);
	
	TwoValues* t2 = new TwoValues;
	t2->a = 4;
	t2->b = 1;
	queue.push(t2);
	
	while(!queue.empty())
	{
        TwoValues* v = queue.top();
        queue.pop();
        
		cout << "a:" << v->a << " b:" << v->b << endl;
    }

}