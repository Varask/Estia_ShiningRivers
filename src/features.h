#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();

void tenth_pixel(char* source_path);

void dimension(char *source_path);

void first_pixel (char *source_path);

void print_pixel (char *source_path, int x, int y);

int read_image_data(const char *filename, unsigned char **data, int *width, int *height, int *channel_count);

char *max_pixel(char *source_path);

void second_line(char *source_path);

char *min_pixel(char *source_path);

char *max_component(char *source_path, char component);

char *min_component(char *source_path, char component);

void stat_report(char *source_path);

void color_green(char *source_path);

void color_blue(char *source_path);

void color_gray(char *source_path);

void invert(char *source_path);

void color_grey_luminance(char *source_path);

void color_red(char *source_path);

void color_desaturate(char *source_path);

void rotate_cw(char *source_path);

void rotate_acw(char *source_path);

void mirror_vertical(char *source_path);

void mirror_horizontal(char *source_path);

void mirror_total(char*source_path);

void scale_nearest(char *source_path,double scale_factor);

void scale_bilinear(char *source_path,double scale_factor);

#endif
