#include "stdafx.h"
#include "Galaxy/Galaxy.h"


Galaxy::Galaxy() : m_core()
{
}

void Galaxy::run() {
	
	m_core.initialize();

	double lastTime = glfwGetTime();
	double fps = 1.0f / 60;

	while (m_core.running())
	{
		double currentTime = glfwGetTime();

		if (currentTime - lastTime > fps) {
			m_core.handle_input();
			m_core.update();
			m_core.render();
			lastTime = glfwGetTime();
		}
	}
}

Galaxy::~Galaxy() 
{
}