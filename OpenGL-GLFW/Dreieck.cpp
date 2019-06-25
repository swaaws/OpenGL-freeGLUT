/**********************************************************************

  OpenGL-Introduction

  June, 7th, 2000

  This tutorial was written by Philipp Crocoll
  Contact: 
	philipp.crocoll@web.de
	www.codecolony.de

  Every comment would be appreciated.

  If you want to use parts of any code of mine:
	let me know and
	use it!

***********************************************************************/

#include <GL/freeglut.h>
#include <math.h>


void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);
		glVertex3f(-0.5,-0.5,-3.0);
		glColor3f(1.0,0.0,0.0);
		glVertex3f(0.5,-0.5,-3.0);
		glColor3f(0.0,0.0,1.0);
		glVertex3f(0.5,0.5,-3.0);
	glEnd();
	glFlush();			//Finish rendering
}

void Reshape(int x, int y){
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat zNear = 0.5f;
    GLfloat zFar = 20.0f;
    GLfloat aspect = float(800)/float(600);
    GLfloat fH = tan( float(40 / 360.0f * 3.14159f) ) * zNear;
    GLfloat fW = fH * aspect;
    glFrustum( -fW, fW, -fH, fH, zNear, zFar );
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);
}

int main (int argc, char **argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(300,300);
	//Create a window with rendering context and everything else we need
	glutCreateWindow("Intro");
	glClearColor(0.0,0.0,0.0,0.0);
	//Assign the two used Msg-routines
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	//Let GLUT get the msgs
	glutMainLoop();
	return 0;
}
