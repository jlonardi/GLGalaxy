#include "stdafx.h"
#include "Galaxy/Core/Core.h"

Core::Core() : m_graphics(), m_running(true), m_camera()
{
}


void Core::initialize()
{
	std::cout << "Initializing core." << std::endl;

	io = IO(m_graphics.getWindow());
	m_graphics.load_shaders("shaders/star.vertexshader", "shaders/star.fragmentshader");
	m_graphics.initialize_shaders();
}

void Core::handle_input()
{
	m_camera = io.read_input();
}

void Core::update()
{

}

void Core::render()
{
	m_graphics.render(m_camera);
}

bool Core::running()
{
	return m_running;
}

Core::~Core()
{
}