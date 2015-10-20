#include <iostream>
#include <GL/glew.h>		//GLEW.
#include <GLFW/glfw3.h>		//GLFW manages windows and user input.

//Initialization
void init()
{
	std::cout << "init!" << std::endl;		//Debug print initalization.
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	//Sets the color for clear.
}

//Update
void update()
{
	std::cout << "update!" << std::endl;	//Debug print update.
}

//Draw
void draw()
{
	std::cout << "draw" << std::endl;		//Debug print draw.
	glClear(GL_COLOR_BUFFER_BIT);			//Clear the screen.

	glFlush();								//Peforms all draw calls.
}

//Main
int main()
{
	//Initialize GLFW, terminate if failed.
	if (!glfwInit())
	{
		return -1;
	}

	//Create an OpenGL Window, terminate if failed.
	GLFWwindow * window = glfwCreateWindow(320, 200, "OpenGL App", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -2;
	}

	//Make window current context, similar to user clicking on it.
	glfwMakeContextCurrent(window);

	//Sets up GLEW
	glewExperimental = GL_TRUE;		//Makes sure all gwafix cards will be supported.
	if (glewInit() != GLEW_OK)		//Check if GLEW initialized sucessfully, terminate if not.
	{
		glfwTerminate();
		return -1;
	}

	init();							//Initialization before loop
	while (!glfwWindowShouldClose(window))	//Loop
	{
		update();					//Update in loop
		draw();						//Draw in loop
		glfwSwapBuffers(window);	//Swap previous frame for new frame.
		glfwPollEvents();			//Poll events such as windows closing and key presses.
	}

	//End
	glfwTerminate();
	return 0;
}