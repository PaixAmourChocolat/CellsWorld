#include "Rule.h"

void Rule::operator()(LineQuad& input)
{
	auto index = m_graph.find(input);
	
	if(index != m_graph.end())
	{
		input = index->second;
	}
}
