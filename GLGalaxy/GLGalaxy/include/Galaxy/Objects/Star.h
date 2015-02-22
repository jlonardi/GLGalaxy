#pragma once
#include <stdafx.h>
#include "GL/glew.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtx/transform.hpp>

class Star
{
private:
	

public:
	GLuint texture;
	GLuint vertexbuffer;
	GLuint uvbuffer;
	glm::mat4 model;

	static GLfloat vertex_buffer_data[18];
	static GLfloat uv_buffer_data[12];

	Star();
	//Star(Star& other);
	//Star& operator=(Star& other);
	Star(GLuint Texture);
	void render();
	~Star();
};