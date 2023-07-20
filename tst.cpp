#include<iostream>
#include<cstdlib>
#include "vector.h"
using namespace std;




int main()
{
	
		
	vector<int>vec(10);

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i + 1);
	}

	for (int i = 0; i < 10; i++)
	{
		vec[i] = i + 1;
	}

	for (int i = 0; i < vec.getsize(); i++)
	{
		cout << vec[i] << " ";
	}

	vector<int> tst(10);

	for (int i = 0; i < 10; i++)
	{
		tst.push_back(i + 1);
	}

	for (int i = 0; i < 10; i++)
	{
		tst[i] = i + 1;
	}

	cout << tst << endl;

	tst.clear();

	if (tst.is_empty()) cout << " vector is empty" << endl;

	cout << tst << "empty vector" << endl;

	for (int i = 0; i < 10; i++)
	{
		tst.push_back(i + 1);
	}

	cout << tst << endl;


	for (int i = 0; i < 5; i++)
	{
		tst.pop_back();
	}

	cout << tst << endl << tst.front() << " " << tst.back() << endl;
	cout << tst.getsize() << endl;

	for (int i = 0; i < 15; i+=2)
	{
		tst.insert(i, -1);
	}
	cout << tst.getsize() << endl;

	cout << tst << endl;

	tst.reverse();
	cout << tst << endl;

	for (int i = 0; i < tst.getsize(); i++)
	{
		cout << tst[i] << " , ";
	}
	cout << endl;

	vector<int> tst2(tst);

	cout << tst2 << endl;

	vector<int> tst3;

	tst3 = tst;

	cout << tst3 << endl;

	tst[0] = 111;
	cout << tst << endl << tst2 << endl << tst3 << endl;
	tst2[0] = 222;
	cout << tst << endl << tst2 << endl << tst3 << endl;
	tst3[0] = 333;

	cout << tst << endl << tst2 << endl << tst3 << endl;

}



