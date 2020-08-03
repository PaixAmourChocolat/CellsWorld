#include "Rule.h"

void Rule::operator()(std::array<bool&, 4> input)
{
	auto index = m_graph.find(lineQuad{input[0], input[1], input[2], input[3]});
	
	if(index != m_graph.end())
	{
		for(std::size_t i = 0; i < 4; ++i)
		{
			input[i] = index->second[i];
		}
	}
}
