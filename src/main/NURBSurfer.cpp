/**************************
*   C++ Project Template by Ryan Molecke, Ph.D.
*   Tuesday, October 28th, 2014
*
*   includes simple CMake build system
*   includes clang scripts
*
*    to build test: from top folder
*       mkdir build
*       cmake ..
*       make
*
***************************/

// memory include to test C++11 build
#include <memory>
#include <iostream>
#include <vector>
#include <gPoint.hpp>

// include SDL so it must be installed on the system!
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/gl.h> 
#include <SDL_image.h>

using namespace std;

int main(int argc, char **argv){

    int windowWidth = 600; //px
    int windowHeight = 800; //px
    int colorDepth = 32;

    SDL_Init(SDL_INIT_EVERYTHING);    
    
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1);    

    SDL_Window *screen = SDL_CreateWindow("My Game Window",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          windowWidth, windowHeight,
                          SDL_WINDOW_OPENGL);

   
    //glClearColor(1,1,1,1); //r,g,b,a color used when clearing the screen
    //glViewport(0,0,windowWidth,windowHeight);
    //glShadeModel(GL_SMOOTH);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    
    int64_t index = 0; // right now points just have a single global int64_t index

    // objects to test the OpenNURBS lib include
    vector<double> coords0 = {0.0, 0.0, 0.0};
    auto point0 = make_shared<gPoint<double>>(coords0, index++);


    
    SDL_Quit();
    
    std::cout
            << "¸.·´¯`·.¸¸.·´ NURBSurfer - Build Test Passed `·.¸¸.·´¯`·.¸\n";
    
}
