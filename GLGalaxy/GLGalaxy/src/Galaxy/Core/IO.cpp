#include "stdafx.h"
#include "Galaxy/Core/IO.h"

IO::IO()
{
}

IO::IO(GLFWwindow* window) 
{
	m_window = window;
}

IO::IO(IO& other)
{
	m_window = other.m_window;
}

IO& IO::operator=(IO& other) {
	if (this != &other)
	{
		std::swap(m_window, other.m_window);
	}
	return *this;
}

Key::key IO::read_input()
{

	glfwPollEvents();
	
	if (glfwGetKey(m_window, GLFW_KEY_E) == GLFW_PRESS) {
		std::cout << "Key was 'E" << std::endl;
		return Key::E;
	}

	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		std::cout << "Key was 'ESC" << std::endl;
		return Key::ESC;
	}

	return Key::UNKOWN;
}

IO::~IO()
{

}