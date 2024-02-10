#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <shader.h>
#include <VAO.h>
#include <VBO.h>
#include <EBO.h>

#include <emitter.h>

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_DECORATED, false);

	GLFWwindow* window = glfwCreateWindow(500, 500, "Particle Emitter - OpenGL", NULL, NULL);
	glfwMakeContextCurrent(window);

	glfwSwapInterval(0);

	glfwSetWindowPos(window, 1000, 500);

	gladLoadGL();

	Emitter emitter(glm::vec3(0.0f));

	VAO vao;
	VBO vbo;
	EBO ebo;
	std::unique_ptr<Shader> shader = std::make_unique<Shader>();

	vao_create(vao);
	vbo_create(vbo);
	ebo_create(ebo);

	vao_bind(vao);
	vbo_buffer(vbo, emitter.vertices);
	ebo_buffer(ebo, emitter.indices);

	vao_attr(vao, 0, 3, GL_FLOAT, 6 * sizeof(float), 0);
	vao_attr(vao, 1, 3, GL_FLOAT, 6 * sizeof(float), 3 * sizeof(float));

	shader_create(shader, "include/glcontext/graphics/glsl/vert.glsl", "include/glcontext/graphics/glsl/frag.glsl");

	while (!glfwWindowShouldClose(window))
	{
		emitter.start();

		shader_use(shader);
		vao_bind(vao);
		vbo_buffer(vbo, emitter.vertices);
		ebo_buffer(ebo, emitter.indices);

		glDrawElements(GL_TRIANGLES, emitter.indices.size(), GL_UNSIGNED_INT, 0);

		emitter.end();
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}