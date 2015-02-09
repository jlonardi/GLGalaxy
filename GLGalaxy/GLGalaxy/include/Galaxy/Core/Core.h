#pragma once
#include "Galaxy/Core/Context.h"
#include "Galaxy/Core/IO.h"

class Core
{
private:
	Context m_context;
	IO io;
	bool m_running;
public:
	Core();
	void initialize();
	void handle_input();
	void update();
	void render();
	bool running();
	~Core();
};