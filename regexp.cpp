#include"regexp.h"
#include"compare.h"
#include"outcsv.h"
#include<fstream>

using namespace std;
extern map<std::string, std::string> Pre_Conf;

string getTime()
{
	time_t timep;
	time(&timep);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
	return tmp;
}

int Get_Conf(map<string, string> &config)
{
	ifstream Conf_File;
	boost::regex reg("^[\\s]*([^:#]*)[:][\\s]*(.*)$");
	boost::regex::icase;
	Conf_File.open("check.conf", ios::in);
	if (!Conf_File.is_open())
	{
		return -1;
	}
	while (!Conf_File.eof())
	{
		string conf_line;
		boost::cmatch ret;
		getline(Conf_File, conf_line);
		if (boost::regex_match(conf_line.c_str(), ret, reg))
		{
			config[ret[1]] = ret[2];
		}
	}
	Conf_File.close();
	return 0;
}

int Regex_line(string RegBuf, string Regexp, char* ret)
{
	boost::regex reg(Regexp);
	boost::regex::icase;
	boost::cmatch res;

	if (boost::regex_search(RegBuf.c_str(), res, reg))
	{
		strncpy_s(ret, 1024, res.str(0).c_str(), strlen(res.str(0).c_str()));
		return 1;
	}
	return 0;
}

int Regex_file(string File_Name)
{
	ifstream Tmp_File;
	string Rd_Buf;
	int line = 0;
	string Regexp;
	char ret[1024];

	Tmp_File.open(File_Name, ios::in);
	if (!Tmp_File.is_open())
	{
		cerr << "[" << getTime() << "]" << "[" << "出错]--------------------------------------------打开检查文件：" << File_Name << endl;
		return -1;
	}
	//cout << "读取文件" << File_Name << endl;
	while (!Tmp_File.eof())
	{
		getline(Tmp_File, Rd_Buf);
		line++;
		//cout << "文件行数：" << line << endl;
		for (map<string, string>::iterator iter = Pre_Conf.find("6_regex_rule1"); iter != Pre_Conf.end(); iter++)
		{
			//cout << "开始匹配规则" << iter->second << endl;
			Regexp = iter->second;
			if (Regex_line(Rd_Buf, Regexp, ret))
			{
				//cout << "匹配结果"<<ret << endl;
				if (0 == Judge_Cmpfile_Is_Same(File_Name, line, Rd_Buf))
				{
					Output_Ret_To_Csv(File_Name, line, ret, Rd_Buf);	
					//continue;
				}
				else
				{
					continue;
				}
				
			}
			continue;
		}
	}
	cerr << "[" << getTime() << "]" << "[" << "成功]--------------------------------------------检查文件：" << File_Name << endl;
	Tmp_File.close();

	return 0;
}
