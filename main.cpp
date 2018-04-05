#include <iostream>
#include <GLUT/glut.h>

using namespace std;

/* default window dimensions */
GLsizei windowWidth = 1280;
GLsizei windowHeight = 800;

/* exit button size coefficient - used to calculate button width and height as fraction of window dimensions */
const GLsizei exitSizeCoefficient = 10;


/* window title text */
const char *windowTitle = "Fermi Paradox by Roman Smirnov";

/* these define star size in pixels */
const GLfloat SMALL_STAR_SIZE = 1.0f;
const GLsizei MED_STAR_OFFSET = 2;
const GLsizei LARGE_STAR_OFFSET_H = 5;
const GLsizei LARGE_STAR_OFFSET_V = 2;

/* get a random x coordinate from 0 to window width */
int randX() {
    return rand() % windowWidth;
}

/* get a random y coordinate from 0 to window height */
int randY() {
    return rand() % windowHeight;
}

/* get a single random RGB color byte - range is from 175 to 255 to avoid too drastic star shimmer */
uint8_t randRgbByte() {
    return (uint8_t) (175 + (rand() % 80));
}

/* draw small stars - made up of points */
void drawSmallStars() {
    glColor3f(1.0f, 1.0f, 1.0f); //small stars are white
    glPointSize(SMALL_STAR_SIZE);
    glBegin(GL_POINTS);
    /* generate many small star points are random window coordinates */
    int numStars = (int) (windowWidth * windowHeight) / 64;
    for (int i = 0; i < numStars; ++i) {
        glVertex2i(randX(), randY());
    }
    glEnd();
}

/* draw medium stars - made up of triangles */
void drawMediumStars() {
    glColor3f(1.0f, 1.0f, 1.0f);
    /* generate many star triangles at random window coordinates */
    int numStars = (int) (windowWidth * windowHeight) / 512;
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < numStars; ++i) {
        int x = randX();
        int y = randY();
        glVertex2i(x, y);
        glVertex2i(x - MED_STAR_OFFSET, y - MED_STAR_OFFSET);
        glVertex2i(x + MED_STAR_OFFSET, y - MED_STAR_OFFSET);
    }
    glEnd();
}

/* draw large stars - made up of quadrilaterals */
void drawLargeStars() {
    int numStars = (int) (windowWidth * windowHeight) / 2048;
    /* generate many star quadrilaterals at random window coordinates */
    glBegin(GL_QUADS);
    for (int i = 0; i < numStars; ++i) {
        glColor3ub(randRgbByte(), randRgbByte(), randRgbByte());
        int x = randX();
        int y = randY();
        glVertex2i(x - LARGE_STAR_OFFSET_H, y);
        glVertex2i(x + LARGE_STAR_OFFSET_H, y);
        glVertex2i(x, y + LARGE_STAR_OFFSET_V);
        glVertex2i(x, y - LARGE_STAR_OFFSET_V);
    }
    glEnd();
}

/* draw FERMI space void text */
void drawFermiText() {
    glColor3f(0.0f, 0.0f, 0.0f); // black is the color of space void

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    /* measure */
    int width = 0;
    for (auto *c = const_cast<char *>("FERMI"); *c != '\0'; c++) {
        width += glutStrokeWidth(GLUT_STROKE_ROMAN, *c);
    }

    GLfloat scaleFactor = (float)(windowWidth)/(float)(width)/2;
    GLfloat translateX = (windowWidth - width*scaleFactor) / 2;
    GLfloat translateY = windowHeight/2;

    glLineWidth(15.0f*scaleFactor);
    glTranslatef(translateX, translateY, 0.0f);

    glScalef(scaleFactor,scaleFactor,scaleFactor);

    for (auto *c = const_cast<char *>("FERMI"); *c != '\0'; c++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }

    glPopMatrix();
}

/* draw title text at top right*/
void drawTitleText() {

    glLineWidth(1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    int width = 0;

    for (auto *c = const_cast<char *>("Fermi Paradox"); *c != '\0'; c++) {
        width += glutStrokeWidth(GLUT_STROKE_ROMAN, *c);
    }

    GLfloat scaleFactor = (float)(windowWidth)/(float)(width)/6;
    GLfloat translateX = windowWidth-(width*scaleFactor+10);
    GLfloat translateY = windowHeight - 30;

    glTranslatef(translateX, translateY, 0.0f);

    glScalef(scaleFactor,scaleFactor,scaleFactor);
    for (auto *c = const_cast<char *>("Fermi Paradox"); *c != '\0'; c++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }

    glPopMatrix();
}

/* draw title text at top right*/
void drawNameText() {

    glLineWidth(1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    int width = 0;

    for (auto *c = const_cast<char *>("by Roman Smirnov"); *c != '\0'; c++) {
        width += glutStrokeWidth(GLUT_STROKE_ROMAN, *c);
    }

    GLfloat scaleFactor = (float)(windowWidth)/(float)(width)/6;
    GLfloat translateX = windowWidth-(width*scaleFactor+10);
    GLfloat translateY = windowHeight - 60;

    glTranslatef(translateX, translateY, 0.0f);

    glScalef(scaleFactor,scaleFactor,scaleFactor);
    for (auto *c = const_cast<char *>("by Roman Smirnov"); *c != '\0'; c++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }

    glPopMatrix();
}

/* draw title text at top right*/
void drawExitButtonText() {

    glLineWidth(4.0f);
    glColor3f(1.0f, 0.0f, 0.0f); //red text

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    int width = 0;

    for (auto *c = const_cast<char *>("EXIT"); *c != '\0'; c++) {
        width += glutStrokeWidth(GLUT_STROKE_ROMAN, *c);
    }

    GLfloat scaleFactor = (float)windowWidth/(float)width/exitSizeCoefficient;

    GLfloat translateX = windowWidth-width*scaleFactor;
    GLfloat translateY = 5;

    glTranslatef(translateX, translateY, 0.0f);

    glScalef(scaleFactor,scaleFactor,scaleFactor);

    for (auto *c = const_cast<char *>("EXIT"); *c != '\0'; c++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }

    glPopMatrix();
}

/* draw all the stuff on the screen here */
void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble) windowWidth, 0.0, (GLdouble) windowHeight);

    drawSmallStars();
    drawMediumStars();
    drawLargeStars();
    drawFermiText();
    drawTitleText();
    drawNameText();

    drawExitButtonText();

    glFlush();
}

/* handle mouse click events */
void clickListener(int button, int state, int x, int y) {
    /* do stuff on left mouse click */
    cout << x << " " << y << endl;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        /* calc exit button edges - these are in canvas coord (origin top left) */
        int exitLeftX = windowWidth - windowWidth/exitSizeCoefficient;
        int exitRightX = windowWidth;
        int exitBottomY =  windowHeight-windowHeight/exitSizeCoefficient;
        int exitTopY = windowHeight;

        /* check if click was made within exit button coordinates */
        if (x >= exitLeftX && y >= exitBottomY && x <= exitRightX && y <= exitTopY) {
            exit(EXIT_SUCCESS);
        }
    }
}

/* handle window resize and rehsape */
void winReshape(GLint newWidth, GLint newHeight) {
    windowWidth = newWidth;
    windowHeight = newHeight;
    glViewport(0, 0, newWidth, newHeight);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, windowWidth ,0, windowHeight);
}

/* main function*/
int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    /* create window and set window title */
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(((glutGet(GLUT_SCREEN_WIDTH) - windowWidth) / 2), ((glutGet(GLUT_SCREEN_HEIGHT) - windowHeight) / 2));

    glutCreateWindow(windowTitle);

    /* draw the screen objects*/
    glutDisplayFunc(display);
    /* handle window reshape*/
    glutReshapeFunc(winReshape);
    /* handle mouse click events*/
    glutMouseFunc(clickListener);

    glutMainLoop();
    return 0;
}
