#pragma once
#include <iostream>
#include <string>
#include <vector>


class FindFiles
{
public:
	//completePath true:����·���� false:�ļ���
	//��ȡ��ǰ�ļ����������ļ���
	static std::vector<std::string> GetFileNames_OneLevel(std::string folder, bool completePath = false, std::string secName = ".*");
	//��ȡ��ǰ�ļ����������ļ�����
	static std::vector<std::string> GetFolderNames_OneLevel(std::string folder, bool completePath = false, std::string secName = ".*");
	//��ȡ�ļ����������ļ���
	static std::vector<std::string> GetFileNames_AllLevel(std::string folder, bool completePath = false, std::string secName = ".*");
	//��ȡ�ļ����������ļ�����
	static std::vector<std::string> GetFolderNames_AllLevel(std::string folder, bool completePath = false, std::string secName = ".*");
	//��ȡ��ǰ�ļ����������ļ����ļ�����
	static std::vector<std::string> GetNames_OneLevel(std::string folder, bool completePath = false, std::string secName = ".*");
	//��ȡ�ļ����������ļ����ļ�����
	static std::vector<std::string> GetNames_AllLevel(std::string folder, bool completePath = false, std::string secName = ".*");


};

