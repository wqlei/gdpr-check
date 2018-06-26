#include<iostream>
#include<boost/regex.hpp>
#include<string>

using namespace std;

int main()
{
	boost::regex reg("tel:[\\*#+\\d]+");
	string correct = "tel:+86252277";
	string incorrect = "sip:+86252277@zte.com.cn";
	if (boost::regex_match(correct,reg))
	{
		cout << "correct match"<< endl;
	}
	else
	{
		cout << "correct not match"<< endl;
	}

	if (boost::regex_match(incorrect, reg))
	{
		cout << "incorrect match" << endl;
	}
	else
	{
		cout << "incorrect not match" << endl;
	}
}
