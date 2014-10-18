#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <sstream>
#include <math.h>
#include <stack>
#include <vector>

using namespace std;

void append(int x, bool y);
long long toBinary(string str);

stringstream ssa;



int main(int argc, char* argv[])
{

	ifstream file;
	file.open(argv[1]);
	for (string line; getline(file, line);)
	{
	//	string line = "0 000000 0 00 0 000 0 000 0 0000 0 00 0 000 0 0000 0 0 0 000 0 0000 0 000 0 00000 00 0000 0 0 00 0000000 0 0 00 0 0 00 00 0 0 000 00 00 0 0 00 00 0 00 00 00 0 0 00 0 0 0";
		vector<string> vec;
		stack <int> stack;
		stringstream ss(line);
		string temp;
		while (ss.good())
		{
			ss >> temp;
			vec.push_back(temp);
		}
		int c = 0;
		for (auto i = vec.begin(); i != vec.end(); ++i)
		{
			c++;
			if (c % 2 != 0)
			if (*i == "0")
			append((*(i + 1)).size(), false);
			else
			append((*(i + 1)).size(), true);
		}

		string str = ssa.str();
		cout  << toBinary(str) << endl;
	}
}

void append(int x, bool y)
{
	

	if (y)
		for (int i = 0; i < x; i++)
			ssa << 1;
	else
		for (int i = 0; i < x; i++)
			ssa << 0;
}

long long toBinary(string str)
{
	int c = 0;long long sum = 0;
	while (!str.empty())
	{
		if (str.at(str.size() - 1) == '1')
			sum += pow(2, c);
		c++;
		str.pop_back();
	}
	ssa.str(std::string());
	return sum;
}