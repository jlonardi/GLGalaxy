#include "stdafx.h"
#include "Galaxy/Objects/Star.h"

GLfloat Star::vertex_buffer_data[18] = {
	-1.0f, -1.0f, 0.0f,
	-1.0f, 1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	-1.0f, 1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	1.0f, 1.0f, 0.0f
};

GLfloat Star::uv_buffer_data[12] = {
	0.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	1.0f, 1.0f
};

Star::Star()
{
	float x = ((float)rand() / (RAND_MAX));
	float y = ((float)rand() / (RAND_MAX));
	float z = ((float)rand() / (RAND_MAX));
	model = glm::translate(x, y, 0.0f) * glm::scale(0.5f, 0.5f, 0.5f);
};

Star::Star(GLuint Texture)
{
	texture = Texture;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);

	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(uv_buffer_data), uv_buffer_data, GL_STATIC_DRAW);

	float x = ((float)rand() / (RAND_MAX));
	float y = ((float)rand() / (RAND_MAX));
	float z = ((float)rand() / (RAND_MAX));
	//model = glm::mat4(1.0f) * glm::scale(0.5f, 0.5f, 0.5f);
	model = glm::translate(x, y, z) * glm::scale(0.5f, 0.5f, 0.5f);
};

void Star::render()
{
};

Star::~Star()
{
};