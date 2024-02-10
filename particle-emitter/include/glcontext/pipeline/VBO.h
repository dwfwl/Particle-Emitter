#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <vector>

#include <glm/glm.hpp>

struct Vertex
{
	glm::vec3 pos;
	glm::vec3 col;
};

struct VBO
{
	uint32_t handle;
};

inline void vbo_create(VBO& self)
{
	glGenBuffers(1, &self.handle);
}

inline void vbo_bind(VBO& self)
{
	glBindBuffer(GL_ARRAY_BUFFER, self.handle);
}

inline void vbo_buffer(VBO& self, std::vector<Vertex> vertices)
{
	vbo_bind(self);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
}

inline void vbo_unbind(VBO& self)
{
	glBindBuffer(0, self.handle);
}

inline void vbo_delete(VBO& self)
{
	glDeleteBuffers(1, &self.handle);
}