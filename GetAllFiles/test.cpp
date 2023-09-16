#include "Code/FindFiles.h"

using namespace std;

int main()
{
	string folder = R"(D:\workspace\torch_server\deployment\train\segnet\segdata1)";

	vector<string> names0 = FindFiles::GetFileNames_OneLevel(folder, true);
	for (auto n : names0)
		cout << n << endl;
	cout << endl << endl;

	vector<string> names1 = FindFiles::GetFolderNames_OneLevel(folder, true);
	for (auto n : names1)
		cout << n << endl;
	cout << endl << endl;

	vector<string> names2 = FindFiles::GetFileNames_AllLevel(folder,true);
	for (auto n : names2)
		cout << n << endl;
	cout << endl << endl;

	vector<string> names3 = FindFiles::GetFolderNames_AllLevel(folder,true);
	for (auto n : names3)
		cout << n << endl;
	cout << endl << endl;


	vector<string> names4 = FindFiles::GetNames_OneLevel(folder,true);
	for (auto n : names4)
		cout << n << endl;
	cout << endl << endl;

	vector<string> names5 = FindFiles::GetNames_AllLevel(folder,true);
	for (auto n : names5)
		cout << n << endl;
	cout << endl << endl;



	return 0;
}