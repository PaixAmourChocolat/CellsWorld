#ifndef RULE_H
#define RULE_H

#include <array>
#include <map>

using lineQuad = std::array<bool, 4>;

class Rule
{
	public :
		
		void operator()(std::array<bool&, 4>);
	
	private :
		
		std::map<lineQuad, LineQuad> m_graph;
};

#endif // RULE_H
