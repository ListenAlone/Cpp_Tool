#pragma once
#include <iostream>
#include <string>
#include <vector>


class FindFiles
{
public:
	//completePath true:完整路径名 false:文件名
	//获取当前文件夹下所有文件名
	static std::vector<std::string> GetFileNames_OneLevel(std::string folder, bool completePath = false, std::string secName = ".*");
	//获取当前文件夹下所有文件夹名
	static std::vector<std::string> GetFolderNames_OneLevel(std::string folder, bool completePath = false, std::string secName = ".*");
	//获取文件夹下所有文件名
	static std::vector<std::string> GetFileNames_AllLevel(std::string folder, bool completePath = false, std::string secName = ".*");
	//获取文件夹下所有文件夹名
	static std::vector<std::string> GetFolderNames_AllLevel(std::string folder, bool completePath = false, std::string secName = ".*");
	//获取当前文件夹下所有文件和文件夹名
	static std::vector<std::string> GetNames_OneLevel(std::string folder, bool completePath = false, std::string secName = ".*");
	//获取文件夹下所有文件和文件夹名
	static std::vector<std::string> GetNames_AllLevel(std::string folder, bool completePath = false, std::string secName = ".*");


};

