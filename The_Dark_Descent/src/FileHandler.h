#pragma once

// MAKE Statoc or singleton??
namespace file_handler
{
	std::string getContentFromFile(const std::string& filepath);

	void writeToFile(const std::string& filepath, const std::string& txt);
	void eraseContentOfFile(const std::string& filepath);
	
}

