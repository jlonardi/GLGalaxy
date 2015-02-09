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

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		std::cout << "GLEW init failed with error " << glewGetErrorString(err) << std::endl;
	}

	std::cout << "GLEW initialized" << std::endl;
}

void Context::refresh()
{
	if (closing())
	{
		close();
		return;
	}
	float ratio;
	int width, height;
	glfwGetFramebufferSize(m_window, &width, &height);
	ratio = width / (float)height;
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef((float)glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
	glBegin(GL_TRIANGLES);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(-0.6f, -0.4f, 0.f);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(0.6f, -0.4f, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(0.f, 0.6f, 0.f);
	glEnd();
	glfwSwapBuffers(m_window);
}
;
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
