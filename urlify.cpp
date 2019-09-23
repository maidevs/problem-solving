//Solution to replace all the spaces with %20 in O(n) time by creating a string buffer

#include <iostream>
#include <vector>

using namespace std;

void append(vector<char> &vec, string s)
{
	for(auto &c: s)
	{
		vec.push_back(c);
	}
}

string urlify(string s)
{
	vector<char> buffer;
    
	for(auto &c: s)
	{
		if (c == ' ')
			append(buffer, "%20");
		else
			buffer.push_back(c);
	}

	return string(buffer.begin(), buffer.end());
}

int main()
{
	string s = "My name is Maida";
	cout << urlify(s) << endl;
}