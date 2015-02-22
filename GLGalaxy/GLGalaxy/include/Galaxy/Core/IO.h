#pragma once
#include "Galaxy/Core/Context.h"
#include <glm.hpp>

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
	glm::vec3 position = glm::vec3(0, 0, 5);

	glm::mat4 ViewMatrix;
	glm::mat4 ProjectionMatrix;

	double horizontalAngle = 0.0f;
	// Initial vertical angle : none
	double verticalAngle = 3.14f;
	// Initial Field of View
	float initialFoV = 45.0f;
	float speed = 3.0f; // 3 units / second
	double mouseSpeed = 0.0005;
public:
	IO();
	IO(GLFWwindow* window);
	IO(IO& other);
	IO& operator=(IO& other);
	IO(Context& context);
	glm::mat4 read_input();
	~IO();
};
