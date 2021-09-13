#include "pch.h"
#include "FileHandler.h"


namespace file_handler
{
	std::string getContentFromFile(const std::string& filepath)
	{
		std::ifstream file{ filepath };
		std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
		
		return content;
	}

	void writeToFile(const std::string& filepath, const std::string& txt)
	{
		std::ofstream file;
		file.open(filepath, std::fstream::in | std::fstream::out | std::fstream::app);
		file << txt;
		file.close();
	}

	void eraseContentOfFile(const std::string& filepath)
	{
		std::ofstream file;
		file.open(filepath, std::ofstream::out | std::ofstream::trunc);
		file.close();
	}

}

