#include "particle.h"

void Particle::square(const glm::vec3& size, const glm::vec3& pos, const glm::vec3& col)
{
	vertices = {
		Vertex{glm::vec3(pos.x - size.x, pos.y + size.y, pos.z), col},
		Vertex{glm::vec3(pos.x - size.x, pos.y - size.y, pos.z), col},
		Vertex{glm::vec3(pos.x + size.x, pos.y - size.y, pos.z), col},
		Vertex{glm::vec3(pos.x + size.x, pos.y + size.y, pos.z), col}
	};

	indices = {
		0, 1, 2,
		0, 3, 2
	};
}

Particle::Particle(const glm::vec3& size, const glm::vec3& pos, const glm::vec3& col)
{
	square(size, pos, col);
}

void Particle::update(const glm::vec3& size, const glm::vec3& pos, const glm::vec3& col)
{
	vertices.clear();
	indices.clear();

	square(size, pos, col);
}
