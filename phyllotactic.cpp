/* This is a simple procedural model (generation of a spiral
   phyllotactic pattern using Vogel's formula) illustrating rotations
   and scaling operations in 2D.
*/
// http://algorithmicbotany.org/courses/Fall2019/Lecture06/phyllotaxis.c
#include <math.h>
#include <GLUT/glut.h>	// GL/glut.h if not Mac

#define RAD 57.29577951
#define DegToRad(angle)	((angle)/RAD)

void init (void) 		// initialize OpenGL
{
   glClearColor (0.0, 0.0, 0.0, 0.0);   // define clearing color

   glMatrixMode(GL_PROJECTION); 		// initialize viewing 
   glLoadIdentity();
   glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
   glColor3f (1.0, 1.0, 1.0);
}

void display(void)		// define object to be displayed
{
	glClear (GL_COLOR_BUFFER_BIT);		// clear all pixels

	float x,y;
	glPointSize(15.0);
	glBegin(GL_POINTS);
	for (int i=0; i<400; i++) {			// Vogel's formula
		x = 0.045*sqrt(i)*cos(DegToRad(137.5)*i);
		y = 0.045*sqrt(i)*sin(DegToRad(137.5)*i);
      	glVertex2f(x, y);
	}
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
