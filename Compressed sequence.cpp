#include<iostream>
#include<fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
using namespace std;



int main(int argc, char *argv[])
{
	ifstream file;
	//file.open(argv[1]);
	//for (string line; getline(file, line);)
	{
		string line = "91 91 91 91 70 85 85 85 85 85 85 85 85 85 85 39 39 39 39 90 90 90 90 90 90 90 90 90 70";
		stringstream ss(line);
		int temp, c = 1;
		vector<int> vec;
		bool flag = false;
		while (ss.good())
		{
			ss >> temp;
			vec.push_back(temp);
		}

		for (auto i = vec.begin(); i != vec.end() - 1; i++)
			if (*i == *(i + 1))
				c++;
			else
			{
				cout << c << " " << *i << " "; 
				c = 1;
			}
		cout << c << " " << *(vec.end()-1) << endl;

	}
}

