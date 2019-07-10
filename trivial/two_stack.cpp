/*
	a implementation of Dijkstra's dual stack algorithm for expression evaluation
	need insert () in expression to work properly, thus a naive calculator for 0-9
*/
#include<string>
#include<iostream>
#include<stack>
using namespace std;

class Eval 
{
	public int evalExp(string token)
	{
		//two stacks
		stack<int> oprand;
		stack<string> opert;

		for (auto i : token)
		{
			if (i == "(");
			else if (i == "+" || i == "-" || i == "*" || i == "/")
				opert.push(i);
			else if (char(i) >= '0' && char(i) <= '9')
				oprand.push(char(i) - '0');
			else if (i == ")")
			{
				//compute the value
				string t = opert.top();
				int val = char(oprand.top()) - '0';
				if (t == "+") 
			}
		}
	}
};

int main(void)
{
	cout << "11" << endl;
}