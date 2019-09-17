
#include <math.h>
#include <GLUT/glut.h>

#define PI 3.14159

static GLfloat angle = -150;   /* in degrees */
static GLfloat angle2 = 30;   /* in degrees */

static int moving = 0, startx=0, starty=0;

//const float DEG2RAD = 3.14159/180;


void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    /* Setup initial OpenGL rendering state. */
    glEnable(GL_DEPTH_TEST);
    //    glDepthFunc(GL_LESS);
    //    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
}

void drawline(float x, float y) {
    
    glColor3f(1.0,1.0,1.0);
    glLineWidth(0.7);
    glBegin(GL_LINES);
    glVertex2f(x,y);
    if (x < 0)
        glVertex2f(x+0.3,y-0.05);
    else
        glVertex2f(x+ 0.3,y-0.05);
        
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    /* Perform scene rotations based on user mouse input. */
    
    //    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    
    glScalef(1.5f, 1.5f, 1.5f);
    
    
    /* front rectangle */
    //    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.94, 0.81, 0.99);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.0);
    glVertex3f (0.9, 0.1, 0.0);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.0);
    glEnd();
    
    //    /* top rectangle */
    //    glColor3f (0.94, 0.81, 0.99);
    //    glBegin(GL_POLYGON);
    //    glVertex3f (0.2, 0.1, 0.0);
    //    glVertex3f (0.9, 0.1, 0.0);
    //    glVertex3f (0.9, 0.575, 0.0);
    //    glVertex3f (0.2, 0.575, 0.0);
    //    glEnd();
    
    /*back rectangle*/
    glColor3f (0.94, 0.81, 0.99);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.5);
    glVertex3f (0.9, 0.1, 0.5);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.2, 0.575, 0.5);
    
    glEnd();
    
    /* left rectangle */
    //    glColor3f (0.94, 0.81, 0.99);
    glColor3f (0.87, 0.58, 0.98);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.5);
    glVertex3f (0.2, 0.1, 0.0);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.5);
    glEnd();
    
    /* right rectangle */
    glColor3f (0.87, 0.58, 0.98);
    glBegin(GL_POLYGON);
    glVertex3f (0.9, 0.1, 0.5);
    glVertex3f (0.9, 0.1, 0.0);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.5);
    glEnd();
    
    
    /* left triangle */
    glColor3f (0.96, 0.8, 0.69);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.9, 0.8, 0.25);
    glEnd();
    
    /* right triangle */
    //    glColor3f (0.52, 0.39, 0.39);
    glColor3f (0.96, 0.8, 0.69);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.5);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();
    
    /* roof */
    glColor3f (0.52, 0.39, 0.39);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.8, 0.25);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();
    
    /*back roof */
    glColor3f (0.52, 0.39, 0.39);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.575, 0.5);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.9, 0.8, 0.25);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();
    
    /* door */
    glColor3f (0.137255, 0.419608, 0.556863);
    glBegin(GL_POLYGON);
    glEnable ( GL_POLYGON_OFFSET_FILL );
    glPolygonOffset ( 0.f, 1.f );
    glVertex3f(0.47, 0.105, -0.01);
    glVertex3f(0.65, 0.105, -0.01);
    glVertex3f(0.65, 0.46, -0.01);
    glVertex3f(0.47, 0.46, -0.01);
    glEnd();
    
    /* window 1 */
    glColor3f (0.184314, 0.184314, 0.309804);
    glBegin(GL_POLYGON);
    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(0.f, 1.f);
    glVertex3f (0.72, 0.25, -0.01);
    glVertex3f (0.83, 0.25, -0.01);
    glVertex3f (0.83, 0.4, -0.01);
    glVertex3f (0.72, 0.4, -0.01);
    glEnd();
    
    /* window 2 */
    glColor3f (0.184314, 0.184314, 0.309804);
    glBegin(GL_POLYGON);
    glEnable ( GL_POLYGON_OFFSET_FILL );
    glPolygonOffset (0.f, 1.f);
    glVertex3f (0.27, 0.25, -0.01);
    glVertex3f (0.38, 0.25, -0.01);
    glVertex3f (0.38, 0.4, -0.01);
    glVertex3f (0.27, 0.4, -0.01);
    glEnd();
    
    //grass
    glColor3f(0.6,0.8,0.196078);
    glBegin(GL_POLYGON);
    //    glVertex2f(0,2.0);
    //    glVertex2f(0,1.0);
    //    glVertex2f(4.0,1.0);
    glVertex2f(7.0,-0.8);
    glVertex2f(-7.0,-0.8);
    glVertex2f(7.0,0.0);
    glVertex2f(-7.0,0.0);
    glVertex2f(0.0,-7.0);
    glVertex2f(1.7,0.0);
    glVertex2f(0.0,-1.7);
    glEnd();
    
    drawline(0.8, 0.95);
    drawline(0.85, 0.90);
    
    drawline(0, 0.9);
    drawline(0.01, 0.95);
    drawline(0.1, 0.9);
    drawline(0.1, 1.05);
    drawline(0.15, 1.25);
    drawline(0.05, 1.35);
    drawline(0.5, 1.2);
    drawline(0.3, 1.1);
    drawline(0.4, 1.3);
    drawline(0.2, 1.15);
    
    drawline(0.85, 1.0);
    drawline(1.01, 1.2);
    drawline(1.05, 1.3);
    drawline(1.06, 1.25);
    
    
    drawline(-0.9, 1.1);
    drawline(-0.8, 1.2);
    drawline(-0.7, 1.3);
    drawline(-0.6, 0.9);
    drawline(-0.95, 1.15);
    drawline(-0.45, 1.06);
    drawline(-0.35, 1.07);
    
    
//    drawline(-0.975,0.843);
    
    
    //quad star1
    glColor3f(1.0,1.0,1.0);
    glLineWidth(15.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.575,0.853);
    glVertex2f(-0.570,0.845);
    glVertex2f(-0.580,0.845);
    glVertex2f(-0.575,0.842);
    glVertex2f(-0.570,0.850);
    glVertex2f(-0.580,0.850);
    glEnd();
    
    //quad star2
    glColor3f(1.0,1.0,1.0);
    glLineWidth(15.0);
    glBegin(GL_LINE_LOOP);
    glLineWidth(20.0);
    glVertex2f(-0.975,0.843);
    glVertex2f(-0.970,0.835);
    glVertex2f(-0.980,0.835);
    glVertex2f(-0.975,0.832);
    glVertex2f(-0.970,0.840);
    glVertex2f(-0.980,0.840);
    glEnd();
    //
    //quad star3
    glColor3f(1.0,1.0,1.0);
    glLineWidth(15.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.875,0.943);
    glVertex2f(-0.870,0.935);
    glVertex2f(-0.880,0.935);
    glVertex2f(-0.875,0.932);
    glVertex2f(-0.870,0.940);
    glVertex2f(-0.880,0.940);
    glEnd();
    //
    //quad star4
    glColor3f(1.0,1.0,1.0);
    glLineWidth(15.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.375,0.998);
    glVertex2f(-0.370,0.990);
    glVertex2f(-0.380,0.990);
    glVertex2f(-0.375,0.987);
    glVertex2f(-0.370,0.995);
    glVertex2f(-0.380,0.995);
    glEnd();
    //
    //quad star5
    glColor3f(1.0,1.0,1.0);
    glLineWidth(15.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.750,0.828);
    glVertex2f(-0.745,0.820);
    glVertex2f(-0.755,0.820);
    glVertex2f(-0.750,0.818);
    glVertex2f(-0.745,0.825);
    glVertex2f(-0.755,0.825);
    glEnd();
    
    
    glPopMatrix();
    glutSwapBuffers();
}


static void
mouse(int button, int state, int x, int y)
{
    /* Rotate the scene with the left mouse button. */
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP) {
            moving = 0;
        }
    }
}

/* ARGSUSED1 */
static void
motion(int x, int y)
{
    if (moving) {
        angle = (angle + (x - startx));
        angle2 = (angle2 + (y - starty));
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}

void myReshape(int w, int h)
{
    glViewport(0,0, w, h);
}

int main(int argc, char **argv)
{
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    
    glutCreateWindow("House rotate by mouse");
    
    /* Register assorted GLUT callback routines. */
    init();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    
    /* Enter GLUT's main loop; callback dispatching begins. */
    glutMainLoop();
    return 0;             /* ANSI C requires main to return int. */
}
