#include "stdafx.h"
#include "Galaxy/Core/Context.h"

Context::Context()
{
}

Context::Context(Context& other)
{
	m_window = other.m_window;
}

Context& Context::operator=(Context& other)
{
	if (this != &other) 
	{
		m_window = other.m_window;
	}
	return *this;
}

void Context::initialize()
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		exit(EXIT_FAILURE);
	}

	std::cout << "GLFW initialized" << std::endl;
}

void Context::open(int w, int h) {

	// creates a 640 by 480 windowed mode window with an OpenGL context
	GLFWwindow* window = glfwCreateWindow(w, h, "Galaxy Simulator", NULL, NULL);

	// if creating window fails (is NULL), exit
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	m_window = window;

	// set current OpenGL context to be the created window
	glfwMakeContextCurrent(m_window);
	glfwSetInputMode(m_window, GLFW_STICKY_KEYS, 1);

	std::cout << "OpenGL context window opened" << std::endl;

	glewExperimental = true;
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		std::cout << "GLEW init failed with error " << glewGetErrorString(err) << std::endl;
	}

	std::cout << "GLEW initialized" << std::endl;
}

GLFWwindow* Context::getWindow()
{
	GLFWwindow* w = m_window;
	return w;
}

void Context::close()
{
	// closes the window
	glfwDestroyWindow(m_window);
	// temrminates glfw
	glfwTerminate();
}

bool Context::closing()
{
	if (glfwWindowShouldClose(m_window))
	{
		return true;
	}
	else {
		return false;
	}
}

Context::~Context()
{
}
