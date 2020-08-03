#include "Grid.h"

Grid::Grid(std::size_t size)
: m_size(size)
, m_table(m_size, std::vector<bool>(m_size, false))
, m_parity(Even)
{ }

Grid::Grid(std::initializer_list<bool> il, std::size_t size)
: m_size(size)
, m_parity(Even)
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

void Grid::toggleState(std::size_t x, std::size_t y)
{
	if(x >= m_size || y >= m_size)
	{
		throw std::runtime_error("It's invalid : " + std::to_string(x) + " / " + std::to_string(y));
	}
	
	m_table[x][y] = !m_table[x][y];
}

void Grid::toggleParity()
{
	m_parity = (m_parity == Even) ? Odd : Even;
}

void Grid::update()
{
	for(std::size_t i = m_parity; i+1 < m_size; i += 2)
	{
		for(std::size_t j = m_parity; j+1 < m_size; j += 2)
		{
			LineQuad subGrid {m_table[i][j], m_table[i+1][j], m_table[i][j+1], m_table[i+1][j+1]}; 
			
			m_rule(subGrid);
			
			m_table[i][j] = subGrid[0];
			m_table[i+1][j] = subGrid[1];
			m_table[i][j+1] = subGrid[2];
			m_table[i+1][j+1] = subGrid[3];
		}
	}
	// TODO handle toric behaviour
	
	toggleParity();
}

std::ostream& operator<<(std::ostream& os, const Grid& grid)
{
	for(std::size_t j = 0; j < grid.size(); ++j)
	{
		for(std::size_t i = 0; i < grid.size(); ++i)
		{
			os << grid.m_table[i][j];
			os << " ";
		}
		os << std::endl;
	}
	
	return os;
}
