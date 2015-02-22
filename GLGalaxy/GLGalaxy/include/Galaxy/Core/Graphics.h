#pragma once
#include "GL/glew.h"
#include <GLFW/glfw3.h>
#include "Galaxy/Core/Context.h"
#include <glm.hpp>

class Graphics
{
private:
	Context m_context;
	GLuint ProgramID;
	GLuint CameraRight_worldspace_ID;
	GLuint CameraUp_worldspace_ID;
	GLuint ViewProjMatrixID;
	GLuint TextureID;
	GLuint Texture;
	GLfloat g_vertex_buffer_data[18];
	GLfloat g_uv_buffer_data[12];
	GLfloat* g_particule_position_size_data;
	GLubyte* g_particule_color_data;

	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint billboard_vertex_buffer;
	GLuint particles_position_buffer;
	GLuint particles_color_buffer;

	int max_particles;
public:
	Graphics();
	void render(glm::mat4& Camera);
	void init();
	GLuint load_shaders(const std::string vertex_file_path, const std::string fragment_file_path);
	void initialize_shaders();
	void load_texture();
	void load_data();
	GLFWwindow* getWindow();
	void stop();
	~Graphics();
};