#ifndef GRID_H
#define GRID_H

#include "Rule.h"
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class Grid : public sf::Drawable
{
	public :
		
		enum Parity
		{
			Even,
			Odd
		};
		
	public :
		
		Grid(std::size_t); // TODO rectangles instead of squares ?
		
		// TODO setRule
		
		// TODO Rule alteration
		
		void loadFromFile(const std::string&);
		
		void update();
		std::size_t size() const;
		
	private :
		
		void resize(std::size_t);
		
		void toggleState(std::size_t, std::size_t);
		void toggleParity();
		
		void draw(sf::RenderTarget&, sf::RenderStates) const override;
		
	private :
		
		std::size_t m_size;
		std::vector<std::vector<bool>> m_table;
		Rule m_rule;
		Parity m_parity;
};

#endif // GRID_H
