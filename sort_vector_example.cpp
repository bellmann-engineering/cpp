#include <iostream>
#include <iterator> 
#include <vector> 

using namespace std;

struct TwoValues
{
	int a;
	int b;	
};

bool compTwoValues(TwoValues* v1, TwoValues* v2)
{
	return (v1->b < v2->b);	
}

int main()
{
	vector<TwoValues*> v;
	
	TwoValues* t1 = new TwoValues;
	t1->a = 4;
	t1->b = 9;
	v.push_back(t1);
	
	TwoValues* t2 = new TwoValues;
	t2->a = 4;
	t2->b = 1;
	v.push_back(t2);
	
	std::vector<TwoValues*>::const_iterator i;
	for (i = v.begin(); i != v.end(); ++i)
		cout << "a:" << (*i)->a << " b:" << (*i)->b << endl;
	
	sort(v.begin(), v.end(), compTwoValues);
	cout << "Nach der Sortierung" << endl;
	for (i = v.begin(); i != v.end(); ++i)
		cout << "a:" << (*i)->a << " b:" << (*i)->b << endl;
}