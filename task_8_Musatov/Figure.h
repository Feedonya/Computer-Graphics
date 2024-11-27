#pragma once
#include <glm\glm.hpp>
#include <vector>
#include <glad\glad.h>

class path {
public:
	std::vector<glm::vec3> vertices; // ������������������ �����
	glm::vec3 color; // ����, �������� �� ������������ RGB
	float thickness; // ������� �����
	GLuint vertexArray; // ��������� ������ (������ OpenGL)

	path(std::vector<glm::vec3> verts, glm::vec3 col, float thickn) {
		vertices = verts;
		color = col;
		thickness = thickn;
		setupPath();
	}

private:
	GLuint vertexBuffer; // ��������� ����� (������ OpenGL)
	void setupPath() {
		// ������� ��������� ������ � ��������� �����
		glGenVertexArrays(1, &vertexArray); // ������� ��������� ������
		glGenBuffers(1, &vertexBuffer); // ������� ��������� �����
		glBindVertexArray(vertexArray); // ������ ��������� ������ ��������
		// ��������� vertexBuffer c GL_ARRAY_BUFFER
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		// �������� ���������� vertices � ��������� ����� vertexBuffer
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
		// �������� ������������ ��������� ���������� ������� � ��������� ������
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (GLvoid*)0);
		glEnableVertexAttribArray(0); // ��������� ��������� 0 ��� �������
		glBindBuffer(GL_ARRAY_BUFFER, 0); // ������� ��������� �������
		glBindVertexArray(0); // ���������� ���������� �������
	}
};

class model {
public:
	std::vector<path> figure; // ������������ �������
	glm::mat4 modelM; // ��������� �������
	model(std::vector<path> fig, glm::mat4 mat) {
		figure = fig;
		modelM = mat;
	}
};