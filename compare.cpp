#include <iostream>
#include <fstream>
#include<boost/regex.hpp>
#include"compare.h"
using namespace std;

extern map<string, string> Pre_Conf;

int Judge_Cmpfile_Is_Same(string File_Name, int line, string ret)
{
	string TmpBuffer;
	string expstr = (Pre_Conf["5_export_directory"]);
	//cout << "Judge_Cmpfile_Is_Same" << exp << endl;
	string src;
	string repstr = Pre_Conf["4_src_directory"];
	src = File_Name.replace(File_Name.find(Pre_Conf["5_export_directory"]), strlen(expstr.c_str()), repstr);
	//src = boost::regex_replace(File_Name, reg, rep);
	//cout << "Judge_Cmpfile_Is_Same" << src << endl;
	
	ifstream CmpFile;
	CmpFile.open(src,ios::in);
	if (!CmpFile.is_open())
	{
		cout << "打开文件："<<src<<"出错" << endl;
	}
	while (!CmpFile.eof() && line)
	{
		getline(CmpFile, TmpBuffer);
		line--;
	}
	//cout << "Judge_Cmpfile_Is_Same" << "\t" <<ret << "\t"<<TmpBuffer << endl;
	return strcmp(ret.c_str(), TmpBuffer.c_str());
}
