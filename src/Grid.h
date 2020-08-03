#ifndef GRID_H
#define GRID_H

#include "Rule.h"
#include <vector>
#include <string>
//#include <SFML/Graphics.hpp>
#include <iostream>

class Grid // : public sf::Drawable
{
	friend std::ostream& operator<<(std::ostream&, const Grid&);
	
	public :
		
		enum Parity
		{
			Even,
			Odd
		};
		
	public :
		
		Grid(std::size_t);
		Grid(std::initializer_list<bool>, std::size_t = 2);
		
		void update();
		std::size_t size() const;
		
	private :
		
		// virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
		
		void toggleState(std::size_t, std::size_t);
		void toggleParity();
		
	private :
		
		const std::size_t m_size;
		std::vector<std::vector<bool>> m_table;
		Rule m_rule;
		Parity m_parity;
};

std::ostream& operator<<(std::ostream&, const Grid&);

#endif // GRID_H
