//
//  playerShaders.h
//  playerController
//
//  Created by Syritx on 2020-11-21.
//

#ifndef playerShaders_h
#define playerShaders_h

class Position {
public:
    float x;
    float y;
    
    Position(float x, float y) {
        this->x = x;
        this->y = y;
    }
};

Position position = Position(0,0);
float start_vertices[] = {
    0.0f,  0.2f,  0.0f,
    0.2f, -0.2f,  0.0f,
   -0.2f, -0.2f,  0.0f
};

const char* vertexShader =
"#version 400\n"
"in vec3 vp;"
"void main() {"
"  gl_Position = vec4(vp, 1.0);"
"}";
;

const char* fragmentShader =
"#version 400\n"
"out vec4 frag_colour;"
"void main() {"
"  frag_colour = vec4(0.45, 0.0, 0.75, 1.0);"
"}";

#endif /* playerShaders_h */
