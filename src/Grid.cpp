#include "Grid.h"

Grid::Grid(std::size_t size)
: m_size(size)
, m_table(m_size, std::vector<bool>(m_size, false))
{ }

Grid::Grid(std::initializer_list<bool> il, std::size_t size)
: m_size(size)
{ 
	if(size*size != il.size())
	{
		throw std::runtime_error("Size doesn't match with the grid constructor.");
	}
	
	m_table.resize(size);
	
	std::size_t i = 0;
	
	for(bool it : il)
	{
		m_table[i].push_back(it);
		++i;
		
		if(i >= size)
		{
			i = 0;
		}
	}
}

std::size_t Grid::size() const
{
	return m_table.size();
}

std::ostream& operator<<(std::ostream& os, const Grid& grid)
{
	for(int j = 0; j < grid.size(); ++j)
	{
		for(int i = 0; i < grid.size(); ++i)
		{
			os << grid.m_table[i][j];
			os << " ";
		}
		os << std::endl;
	}
	
	return os;
}
