#include"file.h"

int Files_Analys(const char *Input_Exp_Dir, const char *Input_Src_Dir)
{
	path Input_Exp_Path(Input_Exp_Dir);
	if (!exists(Input_Exp_Path))
	{
		cerr << "源文件夹无效，请确认！" << endl;
		return -1;
	}

	recursive_directory_iterator end_iter;
	for (recursive_directory_iterator iter(Input_Exp_Path);iter!=end_iter;iter++)
	{
		if (is_directory(*iter))
		{
			cout << *iter<<"is dir"<< endl;
		}
		else
		{
			SrcFiles.push_back(iter->path().string());
			cout << *iter << "is a file" << endl;
		}
	}
	return 0;
}
