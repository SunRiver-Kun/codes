#include<iostream>
#include<vector>
#include<regex>
using namespace std;
int main()
{
	vector<string> stringlist{ "Tom","Jack","145","-552" };
	regex reg(R"(-?\d+)");  //Êý×Ö
	smatch results;
	for (auto& value : stringlist)
	{
		if (regex_match(value, results, reg))
			cout << results[0] << endl;
	}
}