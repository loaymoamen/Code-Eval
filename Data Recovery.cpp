//Sample code to read in test cases:
#include<iostream>
#include<fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <unordered_map>
using namespace std;

int main(int argc, char *argv[])
{
	ifstream file;
	file.open(argv[1]);
	for (string line; getline(file, line);)
	{
		unordered_map<int, string> ordered_sentence;
		vector<int> order;
		vector<string> sentence;
		unordered_map<int, int> numbers;
		unordered_map<int, int>::const_iterator finder;
		unordered_map<int, string>::const_iterator printer;
		int i1, size;
		string stringToken, temp, s1;
		stringstream ss(line);
		getline(ss, stringToken, ';');
		stringstream ss1(stringToken);
		getline(ss, stringToken, ';');
		stringstream ss2(stringToken);
		while (ss1.good())
		{
			ss1 >> temp;
			sentence.push_back(temp);
		}
		while (ss2.good())
		{
			ss2 >> temp;
			order.push_back(stoi(temp));
		}

		for (auto i = order.begin(); i != order.end(); ++i)
		{
			numbers.emplace(*i, *i);
		}
		size = order.size();
		for (int i = 1; i <= order.size(); ++i)
		{
			finder = numbers.find(i);
			if (finder == numbers.end())
			{
				order.push_back(i);
				break;
			}
		}
		if (size == order.size())
			order.push_back(size + 1);
		size++;
		while (!order.empty())
		{
			i1 = *order.begin();
			s1 = *sentence.begin();
			ordered_sentence.emplace(i1, s1);
			order.erase(order.begin());
			sentence.erase(sentence.begin());
		}


		for (int i = 1; i <= size; ++i)
		{
			printer = ordered_sentence.find(i);
			cout << printer->second << " ";

		}

		cout << endl;

	}
}