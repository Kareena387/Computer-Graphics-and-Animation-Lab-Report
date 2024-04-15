#include <stdio.h>
#include <graphics.h>

void floodFill8(int x, int y, int fill_color, int old_color) {
    if (getpixel(x, y) == old_color) {
        putpixel(x, y, fill_color);
        floodFill8(x + 1, y, fill_color, old_color);
        floodFill8(x - 1, y, fill_color, old_color);
        floodFill8(x, y + 1, fill_color, old_color);
        floodFill8(x, y - 1, fill_color, old_color);
        floodFill8(x + 1, y + 1, fill_color, old_color);
        floodFill8(x - 1, y + 1, fill_color, old_color);
        floodFill8(x - 1, y - 1, fill_color, old_color);
        floodFill8(x + 1, y - 1, fill_color, old_color);
    }
}

int main() {
    int gd = DETECT, gm;
    int x, y, fill_color, old_color;

    initgraph(&gd, &gm, "");

    // Drawing a shape (e.g., a rectangle)
    rectangle(50, 50, 100, 100);

    // User input
    printf("Enter the starting coordinates (x y): ");
    scanf("%d %d", &x, &y);

    printf("Enter the fill color: ");
    scanf("%d", &fill_color);

    // Get the old color at the starting coordinates
    old_color = getpixel(x, y);

    // Perform 8-connected flood fill
    floodFill8(x, y, fill_color, old_color);

    delay(10000);
    getch();
    closegraph();

    return 0;
}

