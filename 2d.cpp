#include <stdio.h>
#include <math.h>

// Function to perform translation
void translate(float points[][2], int n, float tx, float ty) {
    int i;
    for (i = 0; i < n; i++) {
        points[i][0] += tx;
        points[i][1] += ty;
    }
}

// Function to perform rotation
void rotate(float points[][2], int n, float angle) {
    int i;
    float theta = angle * (M_PI / 180.0); // Convert angle to radians
    float cos_theta = cos(theta);
    float sin_theta = sin(theta);

    for (i = 0; i < n; i++) {
        float x = points[i][0];
        float y = points[i][1];
        points[i][0] = x * cos_theta - y * sin_theta;
        points[i][1] = x * sin_theta + y * cos_theta;
    }
}

// Function to perform scaling
void scale(float points[][2], int n, float sx, float sy) {
    int i;
    for (i = 0; i < n; i++) {
        points[i][0] *= sx;
        points[i][1] *= sy;
    }
}

// Function to perform shearing
void shear(float points[][2], int n, float shx, float shy) {
    int i;
    for (i = 0; i < n; i++) {
        float x = points[i][0];
        float y = points[i][1];
        points[i][0] = x + shx * y;
        points[i][1] = y + shy * x;
    }
}

// Function to perform reflection about X-axis
void reflectX(float points[][2], int n) {
    int i;
    for (i = 0; i < n; i++) {
        points[i][1] = -points[i][1];
    }
}

// Function to perform reflection about Y-axis
void reflectY(float points[][2], int n) {
    int i;
    for (i = 0; i < n; i++) {
        points[i][0] = -points[i][0];
    }
}

// Function to perform reflection about X=Y axis
void reflectXY(float points[][2], int n) {
    int i;
    for (i = 0; i < n; i++) {
        float temp = points[i][0];
        points[i][0] = points[i][1];
        points[i][1] = temp;
    }
}

// Function to display points
void displayPoints(float points[][2], int n) {
    int i;
    printf("Transformed points:\n");
    for (i = 0; i < n; i++) {
        printf("(%0.2f, %0.2f)\n", points[i][0], points[i][1]);
    }
}

int main() {
    float points[][2] = {{1, 1}, {2, 2}, {3, 3}}; // Initial points
    int n = sizeof(points) / sizeof(points[0]); // Number of points

    // Perform transformations
    translate(points, n, 2, 2);
    rotate(points, n, 45);
    scale(points, n, 2, 2);
    shear(points, n, 1, 0);
    reflectX(points, n);
    reflectY(points, n);
    reflectXY(points, n);

    // Display transformed points
    displayPoints(points, n);

    return 0;
}

