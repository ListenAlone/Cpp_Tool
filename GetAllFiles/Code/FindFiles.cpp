#include "FindFiles.h"
#include <Windows.h>
#include <direct.h>

using namespace std;

vector<string> FindFiles::GetFileNames_OneLevel(string folder, bool completePath, string secName)
{
	vector<string> fileNames;

	string szFind;
	string szFile;

	WIN32_FIND_DATAA FindFileData;

	szFind = folder;
	szFind = szFind + "\\*";
	szFind = szFind + secName;

	HANDLE hFind = ::FindFirstFileA(szFind.c_str(), &FindFileData);

	if (INVALID_HANDLE_VALUE == hFind)
	{
		cout << "Empty folder!" << endl;
		return vector<string>();
	}

	do
	{
		if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))  //如果不是目录
		{
			string file_name = FindFileData.cFileName;
			if (completePath)
				file_name = folder + "\\" + file_name;

			fileNames.push_back(file_name);
		}
	} while (::FindNextFileA(hFind, &FindFileData));

	::FindClose(hFind);
	return fileNames;
}

vector<string> FindFiles::GetFolderNames_OneLevel(string folder, bool completePath, string secName)
{
	vector<string> fileNames;
	string szFind;
	string szFile;

	WIN32_FIND_DATAA FindFileData;

	szFind = folder;
	szFind = szFind + "\\*";
	szFind = szFind + secName;

	HANDLE hFind = ::FindFirstFileA(szFind.c_str(), &FindFileData);

	if (INVALID_HANDLE_VALUE == hFind)
	{
		cout << "Empty folder!" << endl;
		return vector<string>();
	}

	do
	{
		if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)  //如果是目录
		{
			if (FindFileData.cFileName[0] != '.')  //是目录，但不是.当前目录
			{
				string file_name = FindFileData.cFileName;
				if (completePath)
					file_name = folder + "\\" + file_name;

				fileNames.push_back(file_name);
			}
		}

	} while (::FindNextFileA(hFind, &FindFileData));

	::FindClose(hFind);
	return fileNames;
}

vector<string> FindFiles::GetFileNames_AllLevel(string folder, bool completePath, string secName)
{
	vector<string> fileNames;
	vector<string> level_fileNames = FindFiles::GetFileNames_OneLevel(folder,completePath,secName);
	if (!level_fileNames.empty())
	{
		fileNames.insert(fileNames.end(), level_fileNames.begin(), level_fileNames.end());
	}

	vector<string> level_folderNames = FindFiles::GetFolderNames_OneLevel(folder,true, secName);
	for (auto folderName : level_folderNames)
	{
		auto files = GetFileNames_AllLevel(folderName, completePath, secName);
		fileNames.insert(fileNames.end(), files.begin(), files.end());
	}
	return fileNames;
}

vector<string> FindFiles::GetFolderNames_AllLevel(string folder, bool completePath, string secName)
{
	vector<string> fileNames;
	vector<string> complete_folder_vecs;//完整路径名

	vector<string> level_folderNames = FindFiles::GetFolderNames_OneLevel(folder, completePath, secName);
	for (auto folderName : level_folderNames)
	{
		string complete_folder = folderName;
		if (!completePath)
			complete_folder = folder + "\\" + folderName;

		complete_folder_vecs.push_back(complete_folder);

		if(!completePath)
			fileNames.push_back(folderName);
		else
			fileNames.push_back(complete_folder);
	}

	for (auto folderName : complete_folder_vecs)
	{
		vector<string> folderNames = GetFolderNames_AllLevel(folderName, completePath, secName);
		fileNames.insert(fileNames.end(), folderNames.begin(), folderNames.end());
	}

	return fileNames;
}

vector<string> FindFiles::GetNames_OneLevel(string folder, bool completePath, string secName)
{
	vector<string> fileNames; 
	vector<string> level_fileNames = FindFiles::GetFileNames_OneLevel(folder, completePath, secName);
	if (!level_fileNames.empty())
	{
		fileNames.insert(fileNames.end(), level_fileNames.begin(), level_fileNames.end());
	}

	vector<string> level_folderNames = FindFiles::GetFolderNames_OneLevel(folder, completePath, secName);
	if (!level_folderNames.empty())
	{
		fileNames.insert(fileNames.end(), level_folderNames.begin(), level_folderNames.end());
	}

	return fileNames;
}

vector<string> FindFiles::GetNames_AllLevel(string folder, bool completePath, string secName)
{
	vector<string> fileNames;
	vector<string> level_names = GetNames_OneLevel(folder, completePath, secName);
	if (!level_names.empty())
	{
		fileNames.insert(fileNames.end(), level_names.begin(), level_names.end());
	}

	vector<string> level_folderNames = GetFolderNames_OneLevel(folder, true, secName);
	for (auto names : level_folderNames)
	{
		vector<string> level_next_names = GetNames_AllLevel(names, completePath, secName);
		if (!level_next_names.empty())
		{
			fileNames.insert(fileNames.end(), level_next_names.begin(), level_next_names.end());
		}
	}

	return fileNames;
}
