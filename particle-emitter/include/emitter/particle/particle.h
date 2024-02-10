#include <glad/glad.h>
#include <vector>
#include <VBO.h>
#include <glm/glm.hpp>

class Particle
{ public:
	std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;

	void square(const glm::vec3& size, const glm::vec3& pos, const glm::vec3& col);
	Particle(const glm::vec3& size, const glm::vec3& pos, const glm::vec3& col);
	void update(const glm::vec3& size, const glm::vec3& pos, const glm::vec3& col);

	Particle(Particle&& other) noexcept
		: vertices(std::move(other.vertices)), indices(std::move(other.indices))
	{
		other.vertices.clear();
		other.indices.clear();
	}

	Particle(const Particle& other) noexcept
		:vertices(other.vertices), indices(other.indices) {}

	~Particle()
	{
		vertices.clear();
		indices.clear();
	}
};