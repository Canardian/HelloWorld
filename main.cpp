#include <GLFW/glfw3.h>

void DrawTriangle()
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(-0.6f, -0.4f, 0.f);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(0.6f, -0.4f, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(0.f, 0.6f, 0.f);
	glEnd();
}

int main()
{
    GLFWwindow* window;
    int     frame = 0;
    bool    running = true;

    glfwInit();

	window = glfwCreateWindow( 512, 512, "GLFW Application", NULL, NULL);

    if( !window )
    {
        glfwTerminate();
        return 0;
    }
    glfwMakeContextCurrent(window);
    while(running)
    {
		frame++;

		float ratio;
		int width, height;

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

		DrawTriangle();

        glfwSwapBuffers(window);
        glfwPollEvents();
        // exit if ESC was pressed or window was closed
        running = !glfwWindowShouldClose(window);
    }
    glfwTerminate();
    return 0;
}
