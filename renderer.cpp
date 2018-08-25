#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW\glfw3.h>
#include "bus.hpp"
#include "renderer.hpp"


//We are going to init our renderer
void renderer::init(bus* Bus)
{
	// Our engine only needs one renderer, so it's safe to assume its name.
	// We point its node to a bus and call it renderer
	Node = new node(Bus, "renderer");
	// We are enabling experimental glew features to take advantage of modern OpenGL
	glewExperimental = true;
	// We need to initialise GLFW. GLFW is a helpful wrapper that allows for easy window creation
	glfwInit();
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
	// We call the createWindow function. It creates a 1920x1080 window called renderer
	Window = glfwCreateWindow(1920, 1080, "renderer", NULL, NULL);
	glfwMakeContextCurrent(Window);
	// We also initialise glew, which is the GL extension wrangler. Important if we use extensions
	glewInit();
}

// Next is our event handler.
// Right now we don't have any events that we need to handle
// Currently the event handler is just polling for messages and the Command variable reads the messages and separates flags
// In the future we may run into a situation where many events are being sent to the event handler at once.
// In our current setup, we handle one event per "frame" or run of the main loop
// We may need to create a loop that will handle multiple events at once.
// We can do this by checking the number of messages our node currently has and looping through all of them

void renderer::event()
{
	Node->update();
	Command.readString(Node->getMessage());
}

// We have a super simple update function at the moment. Currently we poll for events
// And then we clear the screen, swap buffers, and have glfw poll for any input

void renderer::update()
{
	event();
	glClear(GL_COLOR_BUFFER_BIT);
	// Swap buffers
	glfwSwapBuffers(Window);
	glfwPollEvents();
}
