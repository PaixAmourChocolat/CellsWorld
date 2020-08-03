#include "StateMainMenu.h"
#include "StateManager.h"

StateMainMenu::StateMainMenu(StateManager* stateManager)
: StateBase(stateManager)
, m_grid(5)
, m_updateTime(sf::seconds(1.f))
, m_elapsedTime(sf::Time::Zero)
{ }

StateMainMenu::~StateMainMenu()
{ }

void StateMainMenu::create()
{ }

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
	std::cout << m_grid << std::endl;
}