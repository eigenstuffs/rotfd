/* fn_80238180: Bresenham line into the 16-bit index raster (Bitmap_Z
 * neighbour of fn_802383D8/fn_802385C0). The endpoints are truncated to
 * integers and ordered by y; the encoded color (fn_80238900) is plotted at
 * every step along the major axis.
 * Matching notes: all locals are declared without initializers in this exact
 * order (it fixes CodeWarrior's coloring of y0/y1 and of the steep branch's
 * error/twice pair); the steep branch reads `twice` for its initial error and
 * steps y0 itself (a ctr loop), the shallow branch steps a separate x. */
struct Raster {
    char unknown00[0xC];
    unsigned short* indices;
    char unknown10[0x20];
    int width, height;
};
struct Point {
    float x, y;
};

extern int fn_80238900(struct Raster*, const void*);

void fn_80238180(struct Raster* self, const struct Point* first,
    const struct Point* last, const void* color)
{
    int c;
    int x0;
    int error;
    int y0;
    int change;
    int twice;
    int y1;
    int x;
    int x1;
    int dx;
    int dy;
    int direction;
    int row;
    unsigned short* indices;
    int swap;

    c = fn_80238900(self, color);
    x0 = (int)first->x;
    y0 = (int)first->y;
    x1 = (int)last->x;
    y1 = (int)last->y;
    if (y0 > y1) {
        swap = x0;
        x0 = x1;
        x1 = swap;
        swap = y0;
        y0 = y1;
        y1 = swap;
    }
    if (x1 >= x0) {
        dx = x1 - x0;
        direction = 1;
    } else {
        direction = -1;
        dx = x0 - x1;
    }
    dy = y1 - y0;
    row = y0 * self->width;
    indices = self->indices;
    if (dy > dx) {
        twice = 2 * dx;
        error = twice - dy;
        change = 2 * (dx - dy);
        indices[row + x0] = c;
        for (; y0 != y1; y0++) {
            if (error < 0)
                error += twice;
            else {
                error += change;
                x0 += direction;
            }
            row += self->width;
            indices[row + x0] = c;
        }
    } else {
        twice = 2 * dy;
        change = 2 * (dy - dx);
        indices[row + x0] = c;
        error = 2 * dy - dx;
        for (x = x0; x != x1;) {
            if (error < 0)
                error += twice;
            else {
                error += change;
                row += self->width;
            }
            x += direction;
            indices[row + x] = c;
        }
    }
}
