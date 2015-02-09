#include "stdafx.h"
#include "Galaxy/Galaxy.h"


Galaxy::Galaxy() : m_core()
{
}

void Galaxy::run() {
	
	m_core.initialize();

	while (m_core.running())
	{
		m_core.handle_input();
		m_core.update();
		m_core.render();
	}
}

Galaxy::~Galaxy() 
{
}