#include "Grid.h"

Grid::Grid(std::size_t size)
: m_size(size)
, m_table(m_size, std::vector<bool>(m_size, false))
, m_parity(Even)
{ }

std::size_t Grid::size() const
{
	return m_table.size();
}

void Grid::resize(std::size_t newSize)
{
	m_table.resize(newSize);
	
	for(auto& vect : m_table)
	{
		vect.resize(newSize, false);
	}
}

void Grid::loadFromFile(const std::string& filename)
{
	m_table.clear();
	
	std::ifstream file (filename);
	if (!file.is_open())
	{
		throw std::runtime_error ("Failed to load " + filename);
	}
	
	std::string ruleFile;
	std::getline(file, ruleFile);
	m_rule.loadFromFile(ruleFile);
	
	std::string sizeStr;
	std::getline(file, sizeStr);
	m_size = static_cast<std::size_t>(std::stoi(sizeStr));
	resize(m_size);
	
	try
	{
		for (std::size_t j = 0; j < m_size; ++j)
		{
			std::string line;
			std::getline(file, line);
			
			for (std::size_t i = 0; i < m_size; ++i)
			{
				m_table[i][j] = (line[i] == '1');
			}
		}
	}
	catch (std::exception& err)
	{
		throw std::runtime_error ("Corrupted file : " + filename);
	}
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

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape rectangle;
	
	for (std::size_t i = 0; i < m_size; ++i)
	{
		for (std::size_t j = 0; j < m_size; ++j)
		{
			rectangle.setSize({860.f/m_size, 640.f/m_size});
			rectangle.setPosition(i*860.f/m_size, j*640.f/m_size);
			rectangle.setOutlineColor(sf::Color::Blue);
			rectangle.setOutlineThickness(-1.f);
				
			if (m_table[i][j])
			{
				rectangle.setFillColor(sf::Color::White);
			}
			else
			{
				rectangle.setFillColor(sf::Color::Black);
			}
			
			target.draw(rectangle, states);
		}
	}
	
	/*
	sf::RectangleShape vert;
	vert.setFillColor(sf::Color::Red);
	vert.setSize({2.f, 640.f});
	
	sf::RectangleShape horiz;
	horiz.setFillColor(sf::Color::Red);
	horiz.setSize({860.f, 2.f});
	
	for(std::size_t i = m_parity; i < m_size; i += 2)
	{
		vert.setPosition(i*860.f/m_size + 1.f, 0);
		target.draw(vert, states);
	}
	
	for(std::size_t j = m_parity; j < m_size; j += 2)
	{
		horiz.setPosition(0, j*640.f/m_size + 1.f);
		target.draw(horiz, states);
	}
	*/
}
