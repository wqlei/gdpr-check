#include <iostream>
#include <fstream>
#include<string>

using namespace std;

int Judge_Cmpfile_Is_Same(string cmpfile, int cmpline,string checkbuffer)
{
	int Ret = 0;
	string TmpBuffer;
	ifstream CmpFile(cmpfile);
	if (!CmpFile.is_open())
	{
		cout << "Open CmpFile Fail" << endl;
	}
	while (!CmpFile.eof() && cmpline)
	{
		getline(CmpFile, TmpBuffer);
		cmpline--;
	}
	Ret = strcmp(checkbuffer.c_str(), TmpBuffer.c_str());
	return Ret;
}

int cmp()
{
	string filename1, filename2;
	string buffer;
	int linenum = 1;
	bool need_cmp = false;
	cerr << "Input FileNane:" << endl;
	cin >> filename1 >> filename2;
	ifstream checkfile(filename1);

	if (!checkfile.is_open())
	{
		cout << "Open File Fail" << endl;
	}

	while (!checkfile.eof())
	{
		getline(checkfile, buffer);

		if (0 == strcmp(buffer.c_str(), "hjkl"))
			need_cmp = true;

		if (need_cmp)
		{
			if (0 != Judge_Cmpfile_Is_Same(filename2, linenum, buffer))
			cout << buffer << "\t" << linenum << endl;
			break;
		}
		linenum++;
	}
	return 0;
}
