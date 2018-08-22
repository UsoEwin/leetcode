#include <stack>
#include <vector>
#include <string> 
#include <utility> //for pairs
#include <iostream>
using namespace std;

void testfunc (std::vector<int> & v) {
	if (v.empty())
	{
		cout<<"the vector is empty!"<<endl;
	}
	return;
}

int main(int argc, char const *argv[])
{
	//vector is actually the array
	std::vector<int> v(10);
	vector<vector<int > > v2;
	cout<<"the size of v is "<<v.size()<<endl;
	for (int i = 0; i < 10; ++i)
	{
		v[i] = (i+1)*(i-1);
	}
	//vector<int> v[10] is a array of 10 vectors
	//aka (vector<int> v)[10]
	for (int i = 0; i < 10; ++i)
	{
		cout<<v[i]<<endl;
	}

	//resise
	v.resize(25);
	for (int i = 20; i < 25; ++i)
	{
		v.push_back(i);
	}
	for (int i = 0; i < 30; ++i)
	{
		cout<<"iteration "<<i<<" value "<<v[i]<<endl;
	}
	//to make a vector empty, use
	//v.clear();

	//initialize v3 using v
	std::vector<int> v3(v);
	for (int i = 0; i < 10; ++i)
	{
		cout<<"v3 "<<v3[i]<<endl;
	}

	//initialize it with 20 unknows
	std::vector<string> str(20,"unknow");
	for (int i = 0; i < 20; ++i)
	{
		cout<<str[i]<<endl;
	}

	//creating a matrix, can skip the name and directly initialize the 
	//vector
	vector<vector<int > > matrix(4, vector<int>(3,-1));
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}

	//see the function
	std::vector<int> v4;
	testfunc(v4);

	//end of vectors

	//pairs template
	/*
	template< typename T1, typename T2 > struct pair {
	T1 first;
	T2 second;
	};
	*/
	pair < int, int> p1(1,2);
	cout<<p1.first<<" "<<p1.second<<endl;
	pair < string, pair<int,int > > p2("str1", pair<int, int> (1,2));
	cout<<p2.first<<" "<<p2.second.first<<" "<<p2.second.second<<endl;

	//iterator
	//iterator is actually a pointer
	
	return 0;
}