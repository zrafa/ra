
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <opencv2/opencv.hpp>
#include <cmath>
#include <iostream>
#include <string>


void dibujar_cubo(float size) {
    size *= 0.5f; // Ajustamos para que el tamaño sea el lado completo

    glColor3f(1.0f, 0.0f, 0.0f); // Color rojo
    glutSolidCube(size * 2); // Dibuja un cubo sólido

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // Color blanco para la rejilla

    for(float i = -size; i <= size; i += size/5.0f) {
        glVertex3f(i, -size, size);
        glVertex3f(i, size, size);

        glVertex3f(-size, i, size);
        glVertex3f(size, i, size);
    }

    for(float i = -size; i <= size; i += size/5.0f) {
        glVertex3f(i, -size, -size);
        glVertex3f(i, size, -size);

        glVertex3f(-size, i, -size);
        glVertex3f(size, i, -size);
    }

    for(float i = -size; i <= size; i += size/5.0f) {
        for(float j = -size; j <= size; j += size/5.0f) {
            glVertex3f(i, j, size);
            glVertex3f(i, j, -size);

            glVertex3f(i, size, j);
            glVertex3f(i, -size, j);

            glVertex3f(size, i, j);
            glVertex3f(-size, i, j);
        }
    }
    glEnd();
}

void dibujar_esfera(float radius, int slices, int stacks) {
    glColor3f(1.0f, 0.0f, 0.0f); // Color rojo
    glutSolidSphere(radius, slices, stacks);

    glColor3f(1.0f, 1.0f, 1.0f); // Color blanco para la rejilla
    glutWireSphere(radius, slices, stacks);
}

void dibujar_cono(float base, float height, int slices, int stacks) {
    glColor3f(1.0f, 0.0f, 0.0f); // Color rojo
    glutSolidCone(base, height, slices, stacks);

    glColor3f(1.0f, 1.0f, 1.0f); // Color blanco para la rejilla
    glutWireCone(base, height, slices, stacks);
}

void dibujar_cilindro(float radius, float height, int slices, int stacks) {
    GLUquadricObj *quadric = gluNewQuadric();

    glColor3f(1.0f, 0.0f, 0.0f); // Color rojo
    gluQuadricDrawStyle(quadric, GLU_FILL);
    glPushMatrix();
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Orientación correcta
    gluCylinder(quadric, radius, radius, height, slices, stacks);
    glPopMatrix();

    glColor3f(1.0f, 1.0f, 1.0f); // Color blanco para la rejilla
    gluQuadricDrawStyle(quadric, GLU_LINE);
    glPushMatrix();
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Orientación correcta
    gluCylinder(quadric, radius, radius, height, slices, stacks);
    glPopMatrix();

    gluDeleteQuadric(quadric);
}

void dibujar_toroide(float innerRadius, float outerRadius, int sides, int rings) {
    glColor3f(1.0f, 0.0f, 0.0f); // Color rojo
    glutSolidTorus(innerRadius, outerRadius, sides, rings);

    glColor3f(1.0f, 1.0f, 1.0f); // Color blanco para la rejilla
    glutWireTorus(innerRadius, outerRadius, sides, rings);
}


void dibujar_taza(float radius, float height, int slices, int stacks) {
    glColor3f(0.9f, 0.9f, 0.9f);

    GLUquadric* quad = gluNewQuadric();
    gluQuadricDrawStyle(quad, GLU_FILL);
    gluCylinder(quad, radius, radius * 0.9, height, slices, stacks); // Parte principal

    glPushMatrix();
        glTranslatef(radius * 1.2, 0.0f, height * 0.4f);
        glRotatef(90, 0, 1, 0);
        glutSolidTorus(radius * 0.1, radius * 0.3, 10, 10); // Asa simple
    glPopMatrix();

    glPushMatrix();
        gluDisk(quad, 0, radius * 0.9, slices, 1); // Base inferior
    glPopMatrix();

    glColor3f(0.3f, 0.3f, 0.3f); // Color del alambre
    gluQuadricDrawStyle(quad, GLU_LINE);
    gluCylinder(quad, radius, radius * 0.9, height, slices, stacks); // Rejilla

    gluDeleteQuadric(quad);
}
