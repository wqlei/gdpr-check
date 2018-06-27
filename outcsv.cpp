#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ofstream outcsv;
	outcsv.open("CheckRet.csv", ios::out);
	outcsv << "filename" << ',' << "line" << ',' << "matched" << endl;
	outcsv << "test1.txt" << ',' << 18 << ',' << "tel:+1234567" << endl;
	outcsv << "test2.txt" << ',' << 25 << ',' << "0x8E123456" << endl;
	outcsv << "test3.txt" << ',' << 21 << ',' << "sip:+123456@abc.com" << endl;
	outcsv.close();
}
