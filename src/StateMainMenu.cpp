#include "StateMainMenu.h"
#include "StateManager.h"

StateMainMenu::StateMainMenu(StateManager* stateManager)
: StateBase(stateManager)
, m_grid(5)
, m_updateTime(sf::seconds(0.05f))
, m_elapsedTime(sf::Time::Zero)
{ }

StateMainMenu::~StateMainMenu()
{ }

void StateMainMenu::create()
{ 
	m_grid.loadFromFile("Assets/Grid/Void30");
}

void StateMainMenu::destroy()
{ }

void StateMainMenu::activate()
{ }

void StateMainMenu::deactivate()
{ }

void StateMainMenu::update(sf::Time dt)
{
	m_elapsedTime += dt;
	
	if(m_elapsedTime >= m_updateTime)
	{
		m_elapsedTime -= m_updateTime;
		m_grid.update();
	}
}

void StateMainMenu::draw()
{
	Window* window = m_stateManager->getContext()->m_window;
	window->draw(m_grid);
}
