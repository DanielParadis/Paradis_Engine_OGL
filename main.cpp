#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW\glfw3.h>
#include "bus.hpp"
#include "renderer.hpp"

// This project aims to build an OpenGL renderer for the Paradis Engine.
// All the important code is in renderer.hpp and renderer.cpp

int main()
{
	// We create a main BUS to send messages between each component
	bus BUS;
	// We define our renderer
	renderer Renderer;
	// We initialize out renderer and point it to our main bus
	Renderer.init(&BUS);
	// Main loop
	while (true)
	{
		// Tell the renderer to update
		Renderer.update();
	}
	return 0;
}