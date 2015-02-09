#pragma once
#include "Galaxy/Core/Context.h"

namespace Key
{
	enum key 
	{
		E, ESC, UNKOWN
	};
}

class IO
{
private:
	GLFWwindow* m_window;
public:
	IO();
	IO(GLFWwindow* window);
	IO(IO& other);
	IO& operator=(IO& other);
	IO(Context& context);
	Key::key read_input();
	~IO();
};
