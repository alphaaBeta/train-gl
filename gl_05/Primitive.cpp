#include "Primitive.h"

void Primitive::initVAO() {
    //Create VAO
    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);

    //GEN VBO AND BIND AND SEND DATA
    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), &_vertices[0], GL_STATIC_DRAW);

    //GEN EBO AND BIND AND SEND DATA
    if (_indices.size() > 0) {
        glGenBuffers(1, &_ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(GLuint), &_indices[0], GL_STATIC_DRAW);
    }

    //SET VERTEXATTRIBPOINTERS AND ENABLE (INPUT ASSEMBLY)
    //Position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)offsetof(Vertex, coords));
    glEnableVertexAttribArray(0);
    //Color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);

    //BIND VAO 0
    glBindVertexArray(0);
}



Primitive::Primitive(
    std::vector<Vertex> &vertices,
    const std::vector<GLuint> &indices,
    glm::vec3 position,
    glm::vec3 origin,
    glm::vec3 rotation,
    glm::vec3 scale) {
    _pos = position;
    _origin = origin;
    _rotation = rotation;
    _scale = scale;


    _vertices = vertices;
    _indices = indices;

    initVAO();
    updateModelMatrix();
}



Primitive::~Primitive() {
}

void Primitive::draw() {
	const ShaderProgram* shader = ShaderProgram::usedProgram;
    //updateModelMatrix();
    shader->setMat4fv(_ModelMatrix, "ModelMatrix");
    shader->Use();

    glBindVertexArray(_vao);

    if (_indices.size() == 0) {
        glDrawArrays(GL_TRIANGLES, 0, _vertices.size());
    } else {
        glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
    }

    glBindVertexArray(0);
    glUseProgram(0);
    glActiveTexture(0);
    glBindTexture(GL_TEXTURE_2D, 0);

}


