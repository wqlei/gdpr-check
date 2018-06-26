
/** visitdir.cpp **/
#include <iostream>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;
using namespace std;

void print_files(const path &full_path)
{
	if (exists(full_path))
	{
		directory_iterator item_begin(full_path);
		directory_iterator item_end;

		for (; item_begin != item_end; ++item_begin)
		{
			if (is_directory(*item_begin))
			{
				cout << item_begin->path().string() << "\t[dir]" << endl;
				print_files(item_begin->path());
			}
			else
			{
				cout << item_begin->path().string() << endl;
			}
		}
	}
}

int check()
{
	char input[100];
	cerr << "Input Directory Path: "<< endl;
	cin >> input;

	path full_path(input);
	print_files(full_path);
	system("pause");
	return 0;
}
