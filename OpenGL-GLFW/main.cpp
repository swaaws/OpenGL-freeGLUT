//
//  main.cpp
//  OpenGL-GLFW
//
//  Created by Sebastian Heitzer on 16.12.15.
//  Copyright © 2015 Sebastian Heitzer. All rights reserved.
//

#include "main.hpp"


int main(){
    GLFWwindow* window;
    
    if (!glfwInit())
        return 1;
    
    
    window = glfwCreateWindow(800, 600, "Created", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return 1;
    }
    glClearColor(1.0f, 1.0f, 1.0f, 0.1);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    
    
    while(!glfwWindowShouldClose(window)){
        float ratio;
        int width, height;
        glClearColor(1.0f, 1.0f, 1.0f, 0.1);
        GLFWAPI glfwSetWindowTitle(window, "Window" );
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glMatrixMode(GL_PROJECTION);
        

        
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        
        glLoadIdentity();
        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        
        glBegin(GL_TRIANGLES);
        
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        
        glEnd();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;

}