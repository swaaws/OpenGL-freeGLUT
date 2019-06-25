#include <GL/freeglut.h>
#include <math.h>
#include <iostream>
#include <lib3ds.h> //currently not needed.

class block{
private:
    float x;
    float y;
    float z;
    int r;
    int g;
    int b;
public:
    void create(float, float, float);
    void setcolor(int,int,int);
    void draw();
    void move(float,float,float);
 
};

void block::create(float xnew, float ynew, float znew){
    x =xnew;
    y =ynew;
    z =znew;
    this->setcolor(r, g, b);
    this->draw();
}
void block::setcolor(int rnew, int gnew, int bnew){
    r = rnew;
    g = gnew;
    b = bnew;
    
}
void block::move(float xnew, float ynew, float znew){
    x +=xnew;
    y +=ynew;
    z +=znew;
    
}

void block::draw(){




    
    glTranslatef(x,y,z);
  
    
    //Front side - red
    glColor3f(r, g, b);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-0.5,-0.5,0.0);
    glVertex3f(0.5,-0.5,0.0);
    glVertex3f(0.5,0.5,0.0);
    glVertex3f(-0.5,0.5,0.0);
    glVertex3f(-0.5,0.5,0.0);
    glEnd();
    
    //Back side - gelb
   // glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-0.5,-0.5,-1.0);
    glVertex3f(0.5,-0.5,-1.0);
    glVertex3f(0.5,0.5,-1.0);
    glVertex3f(-0.5,0.5,-1.0);
    glVertex3f(-0.5,0.5,-1.0);
    glEnd();
    
    //left side - green
   // glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-0.5,-0.5,0.0);
    glVertex3f(-0.5,0.5,0.0);
    glVertex3f(-0.5,0.5,-1.0);
    glVertex3f(-0.5,-0.5,-1.0);
    glVertex3f(-0.5,-0.5,0.0);
    glEnd();
    
    //right side - blue
   // glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.5,-0.5,0.0);
    glVertex3f(0.5,-0.5,-1);
    glVertex3f(0.5,0.5,-1);
    glVertex3f(0.5,0.5,0.0);
    glVertex3f(0.5,-0.5,0.0);
    glEnd();
    
    //top side - turquoise
   // glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-0.5,0.5,0.0);
    glVertex3f(0.5,0.5,0.0);
    glVertex3f(0.5,0.5,-1.0);
    glVertex3f(-0.5,0.5,-1.0);
    glVertex3f(-0.5,0.5,0.0);
    glEnd();
    
    //down side - pink
   // glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-0.5,-0.5,0.0);
    glVertex3f(-0.5,-0.5,-1.0);
    glVertex3f(0.5,-0.5,-1.0);
    glVertex3f(0.5,-0.5,0.0);
    glVertex3f(-0.5,-0.5,0.0);
    glEnd();
    }




void Display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0,-1.0,-5.0);
    glScalef(1,1,1);
    
    block stein;
    block stein1;
    stein1.setcolor(1, 0, 1);
    stein.setcolor(1, 0, 0);
    stein.create(0, 0, 0);
    stein.setcolor(0, 1, 0);
    stein1.create(-1, 0, 0);
    stein.create(0, 1, 0);
    stein1.create(1, 0, 0);

    glFlush();
    glutSwapBuffers();
    
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

int main (int argc, char **argv){
    //////////////////////////////////////////////////////////////////////////////
	glutInit(&argc, argv);                                                      //
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);                                //
	glutInitWindowSize(800,600);                                                //
 	glutCreateWindow("Cube");                                                   //
    //////////////////////////////////////////////////////////////////////////////
    
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glClearColor(0.0,0.0,0.0,0.0);

    //////////////////////////////////////////////////////////////////////////////
 	glutDisplayFunc(Display);                                                   //
    glutReshapeFunc(Reshape);                                                   //
    glutIdleFunc(Display);                                                      //
	glutMainLoop();                                                             //
    //////////////////////////////////////////////////////////////////////////////
    
    return 0;
}








































