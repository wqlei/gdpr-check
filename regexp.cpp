#include<iostream>
#include<boost/regex.hpp>
#include<string>

using namespace std;

int regexp()
{
	boost::regex reg("tel:[\\*#+\\d]+");
	string correct = "tel:+86252277";
	string incorrect = "sip:+86252277@zte.com.cn";
	boost::cmatch res;

	if (boost::regex_match(correct.c_str(),res,reg))
	{
		cout << "correct match:"<< res[0]<<endl;
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

	/*const char* mail = "tengxun@qq.com";
	boost::cmatch res;
	//建立3个子表达式
	boost::regex reg("(\\w+)@(\\w+).(\\w+)");
	if (boost::regex_match(mail, res, reg))
	{
		//既可以通过迭代器获取数据， 也可以通过数组方式获取数据
		for (boost::cmatch::iterator pos = res.begin(); pos != res.end(); ++pos)
		{
			std::cout << *pos << std::endl;
		}
		//res[0]存放匹配到的完整字符串
		std::cout << "name:" << res[1] << std::endl;
	}*/
	return 0;
}
