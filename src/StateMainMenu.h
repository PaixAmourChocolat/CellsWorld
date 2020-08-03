#ifndef STATEMAINMENU_H
#define STATEMAINMENU_H

#include "StateBase.h"
#include "EventManager.h"
#include "Grid.h"

class StateMainMenu : public StateBase
{
	public:
		
		StateMainMenu(StateManager*);
		~StateMainMenu();
		
		void create() override;
		void destroy() override;
		
		void activate() override;
		void deactivate() override;
		
		void update(sf::Time) override;
		void draw() override;
		
	private:
		
		Grid m_grid;
		
		sf::Time m_updateTime;
		sf::Time m_elapsedTime;
};

#endif // STATEMAINMENU_H
