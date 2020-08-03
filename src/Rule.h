#ifndef RULE_H
#define RULE_H

#include <array>
#include <map>
#include <fstream>
#include <string>

using LineQuad = std::array<bool, 4>;

class Rule
{
	public :
		
		Rule() = default;
		
		void loadFromFile(const std::string&);
		
		void operator()(LineQuad&);
	
	private :
		
		std::map<LineQuad, LineQuad> m_graph;
};

#endif // RULE_H
