/* This is an IFS for generating the Sierpinski gasket
   It illustrates the affine combination of points.
   Vector operations are defined using operator overloading.
   (Points and vectors are treated here as objects of the same type.) */

#include <math.h>
// was GLUT/glut.h below
#include <GL/glut.h>	// GL/glut.h if not Mac

#define RAD 57.29577951
#define DegToRad(angle)	((angle)/RAD)

struct V2f	// declaration and initialization of the V2f structure: 2D vectors
{
	float x, y;
	V2f(float x1, float y1)
		{x=x1; y=y1;}
 	V2f()
 		{x=0; y=0;}
};

V2f operator+(V2f a, V2f b)			// vector addition
{
	return V2f(a.x+b.x, a.y+b.y);
}

V2f operator*(float c, V2f a)		// scalar multiplied by a vector
{
	return V2f(c*a.x, c*a.y);
}

V2f A(0,0);							// define the initial triangle ABC
V2f B(1,0);
V2f C(0.5, sqrt(3)/2);

void Generate(V2f P, int i)			// the IFS
{
    glVertex2f(P.x, P.y);
	if (i>0) {
		Generate(0.5*(A+P), i-1);
		Generate(0.5*(B+P), i-1);
		Generate(0.5*(C+P), i-1);
	}
	return;
}

void init (void) 					// initialize OpenGL
{
   glClearColor (0.0, 0.0, 0.0, 0.0); 	//select clearing color

   glMatrixMode(GL_PROJECTION);		// initialize viewing
   glLoadIdentity();
   glOrtho(-0.2, 1.2, -0.3, 1.1, -1.0, 1.0);
   glColor3f (1.0, 1.0, 1.0);
}

void display(void)					// define object to be displayed
{
	glClear (GL_COLOR_BUFFER_BIT); 	// clear all pixels

//	float x,y;
	glPointSize(5.0);
	glBegin(GL_POINTS);
	Generate (V2f(0,0), 8);
	glEnd();
	glFlush();
}

/* 
 * Declare initial window size, position, and display mode
 * (single buffer and RGBA).  Open window with the program name
 * in its title bar.  Call initialization routines.
 * Register callback function to display graphics.
 * Enter main loop and process events.
 */
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (750, 750); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[1]);
   init ();
   glutDisplayFunc(display);
   glutMainLoop(); 
   return 0;   /* ANSI C requires main to return int. */
}
