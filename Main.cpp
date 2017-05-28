#include <cairo.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main() {
    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_RGB24, 400, 400);
    cairo_t *cr = cairo_create(surface);
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_paint(cr);
    cairo_set_source_rgb(cr, 0, 0, 0);
    for (int i = 0; i <= 10000; i++) {
        double x = 200 + cos(2 * M_PI * i / 500) * 70 + cos(2 * M_PI * i / 10000) * 110;
        double y = 200 + sin(2 * M_PI * i / 500) * 70 + sin(2 * M_PI * i / 10000) * 110;
        if (i == 0)
            cairo_move_to(cr, x, y);
        else
            cairo_line_to(cr, x, y);
    }
    cairo_close_path(cr);
    cairo_stroke(cr);
    cairo_surface_write_to_png(surface, "spiral.png");
    cairo_destroy(cr);
    cairo_surface_destroy(surface);
    return 0;
}
