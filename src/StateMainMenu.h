#ifndef STATEMAINMENU_H
#define STATEMAINMENU_H

#include "StateBase.h"
#include "EventManager.h"

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
		
		
};

#endif // STATEMAINMENU_H
