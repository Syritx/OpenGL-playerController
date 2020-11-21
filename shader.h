//
//  shader.h
//  playerController
//
//  Created by Syritx on 2020-11-21.
//

#ifndef shader_h
#define shader_h
#include "libs.h"

class Shader {
public:
    GLuint program;
    GLuint vao, vbo;
        
    Shader(const char* vertexShaderSource, const char* fragmentShaderSource, float vertices[]) {
        
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER),
               fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), vertices, GL_STATIC_DRAW);
        
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
        
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(vertexShader);
        glCompileShader(fragmentShader);
        
        program = glCreateProgram();
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);
    }
    
    void set_vertices(float vertices[]) {
        glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), vertices, GL_STATIC_DRAW);
    }
    
    void use() {
        glUseProgram(program);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
};

#endif /* shader_h */
