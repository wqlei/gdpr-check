#include<iostream>

using namespace std;

int main()
{
	char Input_Exp_Dir[100];
	char Input_Src_Dir[100];
	cerr<<"输入export文件夹和源文件夹地址："<<endl;
	cin>>Input_Exp_Dir>>Input_Src_Dir;
	if(!Files_Analys(Input_Exp_Dir, Input_Src_Dir))
	{
		cerr<<"读取文件夹失败，请检查输入！"<<endl;
		return 0;
	}
	
	for()
	{
		
	}
}
