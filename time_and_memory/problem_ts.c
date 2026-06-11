#include <stdio.h>

struct point_t {
    int x, y;
};

struct triangle_t {
    struct point_t pts[3];
};

int double_area(struct triangle_t tr);

int main(void) {
    struct triangle_t my_tr = {
        .pts = {
            { .x = -3, .y = -10 },
            { .x = 8, .y = 8 },
            { .x = 6, .y = -2 }
        }
    };
    printf("%d", double_area(my_tr));

    return 0;

}

int iabs(int x) {return (x < 0) ? -x : x;}

int double_area(struct triangle_t tr) {
    int first_minor = tr.pts[1].x * tr.pts[2].y - tr.pts[2].x * tr.pts[1].y;
    int second_minor = tr.pts[0].x * tr.pts[2].y - tr.pts[2].x * tr.pts[0].y;
    int third_minor = tr.pts[0].x * tr.pts[1].y - tr.pts[1].x * tr.pts[0].y;
    return iabs(first_minor - second_minor + third_minor);
}
