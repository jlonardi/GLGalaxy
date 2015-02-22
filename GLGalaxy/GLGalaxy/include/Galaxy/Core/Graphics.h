#pragma once
#include "GL/glew.h"
#include <GLFW/glfw3.h>
#include "Galaxy/Core/Context.h"
#include <glm.hpp>
#include <Galaxy/Objects/Star.h>

class Graphics
{
private:
	Context m_context;
	GLuint ProgramID;
	GLuint Texture;

	GLuint MatrixID;
	GLuint TextureID;

	std::vector<Star> stars;

public:
	Graphics();
	void render(glm::mat4& Camera);
	GLuint load_shaders(const std::string vertex_file_path, const std::string fragment_file_path);
	void initialize_shaders();
	void load_texture();
	GLFWwindow* getWindow();
	void stop();
	~Graphics();
};