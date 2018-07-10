#include"regexp.h"
#include"check_files.h"
#include"outcsv.h"

using namespace std;

map<string, string> Pre_Conf;
extern vector<string> SrcFiles;


int main()
{
	int FilesNum = 0;
	struct tm *StartTime, *EndTime;
	time_t s_now, e_now;
	time(&s_now);
	StartTime = localtime(&s_now);
	int S_min = StartTime->tm_min;
	int S_sec = StartTime->tm_sec;
	
	//cerr << "[开始]--------------------------------------------开始读取配置" << endl;
	if (Get_Conf(Pre_Conf)<0)
	{
		cerr << "["<<getTime()<<"]"<<"["<<"出错]--------------------------------------------读取配置" << endl;
		exit(-1);
	}
	else
	{
		cerr << "[" << getTime() << "]" << "[" << "成功]--------------------------------------------读取配置" << endl;
	}

	/*cout << "读取的配置有：" << endl;
	for (map<string, string>::iterator iter = Pre_Conf.begin(); iter != Pre_Conf.end(); iter++)
		cout << iter->second << endl;*/

	//cerr << "[开始]----------------------------------------读取检查文件" << endl;
	if (Files_Analys(Pre_Conf["5_export_directory"], Pre_Conf["4_src_directory"])<0)
	{
		cerr << "[" << getTime() << "]" << "[" << "出错]--------------------------------------------读取检查文件" << endl;
		exit(-1);
	}
	else
	{
		cerr << "[" << getTime() << "]" << "[" << "成功]--------------------------------------------读取检查文件" << endl;
	}

	Creat_Out_Csv();
	/*cout << "读取的文件有：" << endl;
	for(vector<string>::iterator iter = SrcFiles.begin();iter!=SrcFiles.end();iter++)
		cout << *iter << endl;*/
	for (vector<string>::iterator iter = SrcFiles.begin(); iter != SrcFiles.end(); iter++)
	{
		//cout << "开始正则文件：" <<*iter<< endl;
		Regex_file(*iter);
		FilesNum++;
	}
	time(&e_now);
	EndTime = localtime(&e_now);
	int E_min = EndTime->tm_min;
	int E_sec = EndTime->tm_sec;
	cerr << "检查结束，文件数：" << FilesNum << "\t" << "耗时：" << E_min - S_min -1<< "min" << E_sec + 60 - S_sec << "sec" << endl;
	system("pause");
	return 0;
}
