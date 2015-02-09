#pragma once
#define GLEW_STATIC // use static GLEW library glew32s.lib
#include "GL/glew.h"
#include <GLFW/glfw3.h>
// Wrapper class for GLFW
class Context
{

private:
	GLFWwindow* m_window;
public:
	Context();
	Context(Context& context);
	Context& operator=(Context& other);
	void initialize();
	void open(int w = 640, int h = 480);
	GLFWwindow* getWindow();
	void refresh();
	bool closed();
	void close();
	~Context();
};

