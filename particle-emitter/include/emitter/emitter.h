#include <particle.h>
#include <glad/glad.h>
#include <Windows.h>

#include <random>

class Emitter
{
public:

	std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;

	Emitter(glm::vec3 EmitterPoint) : EmitterPoint(EmitterPoint) {};

	void start()
	{
		if (particleCount < 10000)
		{
			particleCount++;
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<float> dis(-1.0f, 1.0f);
			std::uniform_real_distribution<float> col(0, 1.0f);

			Particle _new(glm::vec3(0.002f), glm::vec3(dis(gen), dis(gen), dis(gen)), glm::vec3(1.0f, 0.0f, 0.0f));
			particles.push_back(_new);
		}

		vertices.clear();
		indices.clear();
		for (auto& a : particles)
		{
			for (auto& b : a.vertices)
			{
				vertices.push_back(b);
			}

			for (auto& b : a.indices)
			{
				indices.push_back(b);
			}
		}
	};

	void end()
	{
		particles.clear();
	};
private:
	std::vector<Particle> particles;
	glm::vec3 EmitterPoint;

	int particleCount = 0;

	bool shouldEmmit = true;
};