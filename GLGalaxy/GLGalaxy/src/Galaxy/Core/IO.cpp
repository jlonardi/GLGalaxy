#include "stdafx.h"
#include "Galaxy/Core/IO.h"
#include <gtc/matrix_transform.hpp>
#include <gtx/transform.hpp>

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

glm::mat4 IO::read_input()
{

	glfwPollEvents();

	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		std::cout << "Key was 'ESC" << std::endl;
		exit(0);
	}

	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	// Get mouse position
	double xpos, ypos;
	glfwGetCursorPos(m_window, &xpos, &ypos);

	// Reset mouse position for next frame
	int width, height;
	glfwGetWindowSize(m_window, &width, &height);
	glfwSetCursorPos(m_window, width/2, height/2);

	// Compute new orientation
	horizontalAngle -= mouseSpeed * double(width/2 - xpos);
	verticalAngle += mouseSpeed * double(height/2 - ypos);

	std::cout << horizontalAngle << std::endl;
	std::cout << verticalAngle << std::endl << std::endl;

	// Direction : Spherical coordinates to Cartesian coordinates conversion
	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
		);

	std::cout << direction.x << " " << direction.y << " " << direction.z << std::endl << std::endl;

	// Right vector
	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - 3.14f / 2.0f),
		0,
		cos(horizontalAngle - 3.14f / 2.0f)
		);

	glm::vec3 up = glm::cross(right, direction);

	// Move forward
	if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS){
		position += direction * deltaTime * speed;
	}
	// Move backward
	if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS){
		position -= direction * deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS){
		position += right * deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS){
		position -= right * deltaTime * speed;
	}

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	ProjectionMatrix = glm::perspective(initialFoV, 4.0f / 3.0f, 0.1f, 100.0f);

	// Camera matrix
	ViewMatrix = glm::lookAt(
		position,           // Camera is here
		position + direction, // and looks here : at the same position, plus "direction"
		up                  // Head is up (set to 0,-1,0 to look upside-down)
		);

	// For the next frame, the "last time" will be "now"
	lastTime = currentTime;
	return ViewMatrix;
}

IO::~IO()
{

}