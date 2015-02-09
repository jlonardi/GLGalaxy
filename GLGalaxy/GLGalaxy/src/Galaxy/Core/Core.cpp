#include "stdafx.h"
#include "Galaxy/Core/Core.h"
#include "Galaxy/Core/Context.h"


Core::Core() : m_context(), m_running(true)
{
}


void Core::initialize()
{
	std::cout << "Initializing application window." << std::endl;
	m_context.initialize();

	std::cout << "Opening application window." << std::endl;
	m_context.open();
	io = IO(m_context.getWindow());
}

void Core::handle_input()
{
	Key::key key = io.read_input();

	if (key == Key::ESC) {
		std::cout << "Context was closed.. exiting" << std::endl;
		m_context.close();
		m_running = false;
	}
}

void Core::update()
{

}

void Core::render()
{
	m_context.refresh();
}

bool Core::running()
{
	return m_running;
}

Core::~Core()
{
}