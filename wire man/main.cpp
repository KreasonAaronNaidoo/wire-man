#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

float angle = 0;
int time = 0;

int lat = 10;
int lon = 10;

void drawGridLines()
{
    // draw some axis in grey to get a better feel
    glColor3ub(240, 240, 240); // uses unsigned bytes for RGB values
    float step = 0.1;
    for(float x=-1; x<=1; x+=step)
        for(float y=-1; y<=1; y+=step)
        {
            glBegin(GL_LINES);
            glVertex3f(-1,y,0); // horizontal grid line
            glVertex3f(1,y,0);
            glVertex3f(x, -1, 0); // vertical grid line
            glVertex3f(x, 1, 0);
            glEnd();
            
        }
}

static void render(void)
{
    
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);      // To operate on Model-View matrix
    glLoadIdentity();
    
    drawGridLines();
    
    glRotatef(angle,0,5,0);
    
    glColor3ub(0, 0, 255);
    
    glPushMatrix(); // head
        glScalef(0.7,1,0.7);
        glTranslatef(0.0f, 0.53f, 0.0f);
        glRotatef(90,1,0,0);
        glutWireSphere(0.2,lon,lat);
    glPopMatrix();
    
    glPushMatrix(); // neck
        glScalef(0.5,1, 0.5);
        glTranslatef(0.0f, 0.32f, 0.0f);
        glutWireSphere(0.03, lon, lat);
    glPopMatrix();
    
    glPushMatrix(); // body
        glScalef(0.5,1,0.3);
        glRotatef(90,1,0,0);
        glutWireSphere(0.3,lon,lat);
    glPopMatrix();
    
    glPushMatrix(); // left leg
        glTranslatef(-0.06f, -0.5f, 0.0f);
        glScalef(1,5,1);
        glRotatef(90,1,0,0);
        glutWireSphere(0.05f,lon,lat);
    glPopMatrix();
    
    glPushMatrix(); // right leg
        glTranslatef(0.06f, -0.5f, 0.0f);
        glScalef(1,5,1);
        glRotatef(90,1,0,0);
        glutWireSphere(0.05f,lon,lat);
    glPopMatrix();
    
    glPushMatrix(); // left arm
        glTranslatef(0.22f, 0.14f, 0);
        glRotatef(45,0,0,1);
        glScalef(1, 4, 1);
        glRotatef(90,1,0,0);
        glutWireSphere(0.05,lon,lat);
    glPopMatrix();
    
    glPushMatrix(); // right arm
        glTranslatef(-0.22f, 0.14f, 0);
        glRotatef(-45,0,0,1);
        glScalef(1, 4, 1);
        glRotatef(90,1,0,0);
        glutWireSphere(0.05,lon,lat);
    glPopMatrix();
    
    glutSwapBuffers();
    glFlush();
}

void idle(){
    glutPostRedisplay(); // called when there is now other event
}

void update(){
    
    time = glutGet(GLUT_ELAPSED_TIME);
    angle = time/10;
}

void display(){
    
    update();
    render();
}

void key (unsigned char key, int x, int y){
    
    if(key == 27){
        exit(0);
    }
    
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    
    glutCreateWindow("Animated Open GL Wire Frame Man");
    
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(key);
    
    
    glClearColor(1,1,1,1);
    
    glutMainLoop();
    
    return EXIT_SUCCESS;
}
