#pragma once
#include "Galaxy/Core/IO.h"
#include "Galaxy/Core/Graphics.h"
#include "Galaxy/Objects/Star.h"

class Core
{
private:
	IO io;
	Graphics m_graphics;
	std::vector<Star> stars;
	bool m_running;
	glm::mat4 m_camera;
public:
	Core();
	void initialize();
	void handle_input();
	void update();
	void render();
	bool running();
	~Core();
};