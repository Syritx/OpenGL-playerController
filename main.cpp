//
//  main.cpp
//  playerController
//
//  Created by Syritx on 2020-11-21.
//

#include <iostream>

#include "libs.h"
#include "player.h"

void keyboard(GLFWwindow* window, Player player);

int main(int argc, const char * argv[]) {
    if (!glfwInit()) glfwTerminate();

#ifdef __APPLE__
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(1000, 720, "Player controller", NULL, NULL);
    if (!window) glfwTerminate();
    
    glfwMakeContextCurrent(window);
                                  
    glewExperimental = GL_TRUE;
    glewInit();
    
    Player player = Player();
    
    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        
        keyboard(window, player);
        
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}


void keyboard(GLFWwindow* window, Player player) {
    
    float xDir = 0;
    float yDir = 0;
    
    // vertical
         if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) yDir =  .01f;
    else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) yDir = -.01f;
    
    // horizontal
         if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) xDir = -.01f;
    else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) xDir =  .01f;
    
    player.addCoordinatesToPosition(xDir, yDir);
    player.render();
}
