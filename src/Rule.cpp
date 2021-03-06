#include "Rule.h"
#include <iostream>

void Rule::operator()(LineQuad& input)
{
	auto index = m_graph.find(input);
	
	if (index != m_graph.end())
	{
		input = index->second;
	}
}

void Rule::loadFromFile(const std::string& filename)
{
	m_graph.clear();
	
	std::ifstream file (filename);
	if (!file.is_open())
	{
		throw std::runtime_error ("Failed to load " + filename);
	}
	
	std::string delimiter = ":";
	
	std::string line;
	std::getline(file, line);
	
	while (!file.eof())
	{
		std::size_t delimPos = line.find(delimiter);
		std::string inputStr = line.substr(0, delimPos);
		std::string outputStr = line.substr(delimPos + delimiter.size());
		
		LineQuad input;
		LineQuad output;
		
		try
		{
			for (std::size_t i = 0; i < 4; ++i)
			{
				input[i] = (inputStr[i] == '1');
				output[i] = (outputStr[i] == '1');
				std::cout << input[i] << " --> " << output[i] << std::endl;
			}
			std::cout << "------------" << std::endl;
		}
		catch (std::exception& err)
		{
			throw std::runtime_error ("Corrupted file : " + filename);
		}
		
		m_graph[input] = output;
		std::getline(file, line);
	}
}
