#ifndef RULE_H
#define RULE_H

#include <array>
#include <map>

using LineQuad = std::array<bool, 4>;

class Rule
{
	public :
		
		Rule() = default;
		// TODO Rule(const std::string&); // read from file
		
		void operator()(LineQuad&);
	
	private :
		
		std::map<LineQuad, LineQuad> m_graph;
};

#endif // RULE_H
