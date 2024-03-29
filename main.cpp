// sudo apt-get update
// sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
// www.codebind.com/linux-tutorials/install-opengl-ubuntu-linux/
// 18.07.2020 15:54:42
#include <GL/glut.h>
// 8/1/2022   or sudo apt install freeglut3-dev
// see https://www.includehelp.com/linux/how-to-install-opengl-in-ubuntu-linux.aspx
void
displayMe (void)
{
  glClear (GL_COLOR_BUFFER_BIT);
  glBegin (GL_LINE_LOOP);	// GL_POINTS ,  GL_POLYGON , GL_LINES , GL_LINE_LOOP
/*
 *      glVertex3f(0.5, 0.0, 0.5);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
        glVertex3f(0.0, 0.0, 0.5);
  */
  glVertex3f (0.5, 0.5, 0.0);
  glVertex3f (0.5, -0.5, 0.0);
  glVertex3f (-0.5, -0.5, 0.0);
  glVertex3f (-0.5, 0.5, 0.0);
  glVertex3f (-0.25, 0.5, 0.0);
  glVertex3f (-0.25, 0.25, 0.0);
  glVertex3f (0.25, 0.25, 0.0);
  glVertex3f (0.25, 0.5, 0.0);
//  could read points from an array or list - then process for max and min 
// then could do some recursion 
  glEnd ();
  glFlush ();
}

int
main (int argc, char **argv)
{
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE);
  glutInitWindowSize (400, 300);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Hello world!");
  glutDisplayFunc (displayMe);
  glutMainLoop ();
  return 0;
}
