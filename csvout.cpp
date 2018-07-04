#include<iostream>
#include<fstream>

using namespace std;

void Creat_Out_Csv()
{
	ofstream outcsv;
	outcsv.open(".\\CheckRet.csv", ios::out);
	outcsv << "文件名" << ',' << "行号" << ',' << "匹配参考"<<',' << "内容" << endl;
}

void Output_Ret_To_Csv(std::string File_Name, int line, const char* ret, std::string Rd_Buf)
{
	ofstream outcsv;
	outcsv.open(".\\CheckRet.csv", ios::app);
	//cout << "开始outcsv" << File_Name.c_str()<< line<< ret<< Rd_Buf.c_str() << endl;
	outcsv << File_Name.c_str() << ',' << line << ',' << ret << ',' << Rd_Buf.c_str()<<endl;
	outcsv.close();
}
