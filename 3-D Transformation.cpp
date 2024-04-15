#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

#define X_MAX 800
#define Y_MAX 600

typedef struct {
    float x, y, z;
} Point3D;

void drawAxes() {
    // Draw X-axis
    line(0, Y_MAX/2, X_MAX, Y_MAX/2);
    outtextxy(X_MAX - 90, Y_MAX / 2 - 10, "X (Translation)");
    // Draw Y-axis
    line(X_MAX/2, 0, X_MAX/2, Y_MAX);
    outtextxy(X_MAX / 2 + 10, 10, "Y (Rotation)");
    // Draw Z-axis
    line(X_MAX/2, Y_MAX/2, X_MAX/2, Y_MAX);
    outtextxy(X_MAX / 2 + 10, Y_MAX - 20, "Z (Scaling)");
}

void drawCube(Point3D* vertices) {
    // Draw lines connecting the vertices to form a cube
    for(int i = 0; i < 4; ++i) {
        line(vertices[i].x, vertices[i].y, vertices[(i + 1) % 4].x, vertices[(i + 1) % 4].y);
        line(vertices[i + 4].x, vertices[i + 4].y, vertices[((i + 1) % 4) + 4].x, vertices[((i + 1) % 4) + 4].y);
        line(vertices[i].x, vertices[i].y, vertices[i + 4].x, vertices[i + 4].y);
    }
}

void translateCube(Point3D* vertices, float tx, float ty, float tz) {
    for(int i = 0; i < 8; ++i) {
        vertices[i].x += tx;
        vertices[i].y += ty;
        vertices[i].z += tz;
    }
}

void rotateCube(Point3D* vertices, float angleX, float angleY, float angleZ) {
    float radX = angleX * (M_PI / 180.0);
    float radY = angleY * (M_PI / 180.0);
    float radZ = angleZ * (M_PI / 180.0);

    for(int i = 0; i < 8; ++i) {
        float x = vertices[i].x;
        float y = vertices[i].y;
        float z = vertices[i].z;

        // Rotate around X-axis
        vertices[i].y = y * cos(radX) - z * sin(radX);
        vertices[i].z = y * sin(radX) + z * cos(radX);

        x = vertices[i].x;
        y = vertices[i].y;
        z = vertices[i].z;

        // Rotate around Y-axis
        vertices[i].x = x * cos(radY) + z * sin(radY);
        vertices[i].z = -x * sin(radY) + z * cos(radY);

        x = vertices[i].x;
        y = vertices[i].y;
        z = vertices[i].z;

        // Rotate around Z-axis
        vertices[i].x = x * cos(radZ) - y * sin(radZ);
        vertices[i].y = x * sin(radZ) + y * cos(radZ);
    }
}

void scaleCube(Point3D* vertices, float sx, float sy, float sz) {
    for(int i = 0; i < 8; ++i) {
        vertices[i].x *= sx;
        vertices[i].y *= sy;
        vertices[i].z *= sz;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Increase window size
    initwindow(X_MAX, Y_MAX, "3D Transformation");

    Point3D vertices[] = {
        {-25, -25, -25}, {25, -25, -25}, {25, 25, -25}, {-25, 25, -25},  // Front vertices
        {-25, -25, 25}, {25, -25, 25}, {25, 25, 25}, {-25, 25, 25}       // Back vertices
    };

    drawAxes();
    translateCube(vertices, X_MAX / 2, Y_MAX / 2, 0); // Translate to center of the screen
    translateCube(vertices, 0, 0, 200); // Translate along z-axis to bring the cube closer
    drawCube(vertices);
    rotateCube(vertices, 45, 45, 45);
    drawCube(vertices);
    scaleCube(vertices, 1.5, 1.5, 1.5);
    drawCube(vertices);

    getch();
    closegraph();
    return 0;
}

