//
//  player.h
//  playerController
//
//  Created by Syritx on 2020-11-21.
//

#ifndef player_h
#define player_h

#include "shader.h"
#include "playerShaders.h"
#include <iostream>

class Player {
public:
    Shader shader = Shader(vertexShader, fragmentShader, start_vertices);
    
    void addCoordinatesToPosition(float new_x, float new_y) {
        position = Position(position.x + new_x, position.y + new_y);
    }
    
    void render() {
        float vertices[] = {
            start_vertices[0]+position.x, start_vertices[1]+position.y, start_vertices[2],
            start_vertices[3]+position.x, start_vertices[4]+position.y, start_vertices[5],
            start_vertices[6]+position.x, start_vertices[7]+position.y, start_vertices[8],
        };
        
        shader.set_vertices(vertices);
        shader.use();
    }
};

#endif /* player_h */
