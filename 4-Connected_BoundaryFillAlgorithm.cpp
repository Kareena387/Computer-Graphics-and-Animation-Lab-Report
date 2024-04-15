#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void boundaryfill(int x, int y, int fillcolor, int boundrycolor) {
    if(getpixel(x, y) != boundrycolor && getpixel(x, y) != fillcolor) {
        putpixel(x, y, fillcolor);
        boundaryfill(x + 1, y, fillcolor, boundrycolor);
        boundaryfill(x, y + 1, fillcolor, boundrycolor);
        boundaryfill(x - 1, y, fillcolor, boundrycolor);
        boundaryfill(x, y - 1, fillcolor, boundrycolor);
    }
}

int main() {
    int gm, gd = DETECT, radius = 30;
    int x, y, fillcolor;

    printf("Enter the coordinates (x, y): ");
    scanf("%d %d", &x, &y);

    printf("Enter the fill color: ");
    scanf("%d", &fillcolor);

    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    circle(x, y, radius);
    boundaryfill(x, y, fillcolor, 15); 
    getch();
    closegraph();
    return 0;
}

