#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include "features.h"
#include "utils.h"
#include <math.h>
/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}


/**
 * Issue : #25 Get the dimension of an image 
*/

void dimension(char *source_path) {
  unsigned char *data;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Error: %s\n", source_path);
        return;
    }
    printf("dimension: %d, %d\n", width, height);
    free_image_data(data);
}
// close #25

//#24
/*function that give the RGB color of the first pixel in the second line*/
void first_pixel (char *source_path) {
    int width, height, channel_count;
    unsigned char* data;
    int R,G,B;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) !=0){
        R = data[0];
        G = data[1];
        B = data[2];
        printf("first_pixel: %d, %d, %d\n", R, G, B);
    }
    free_image_data(data);
}

/*
 * close #24
    Issue #23
*/
void tenth_pixel(char* source_path) {
    int W;
    int H;
    unsigned char *data=NULL;
    int channel_count;
    
    if (read_image_data(source_path, &data, &W, &H, &channel_count) != 0) {
       printf("tenth_pixel: %d, %d, %d\n", data[27], data[28], data[29]);

    }
    free_image_data(data);
}
//close #23

/*
 * Issue : #22 Get the RGB color of the second line first pixel of an image
*/
void second_line(char *source_path) {
    int width, height, channel_count;
    unsigned char* data;
    
    // Read the image data
    if (read_image_data(source_path, &data, &width, &height, &channel_count) != 0) {
        // Check if the image has at least a height of 2 pixels
        if (height < 2) {
            printf("The image does not have at least a height of 2 pixels.\n");
            return;
        }
        
        unsigned int position = channel_count * (1 * width);
        
        // Extract the RGB values
        unsigned char r = data[position];
        unsigned char g = data[position + 1];
        unsigned char b = data[position + 2];
        
        // Print the RGB values to the output terminal
        printf("second_line: %d, %d, %d\n", r, g, b);
    } else {
        printf("Failed to read the image data.\n");
    }
    free_image_data(data);
}
// close #22

// issue #21
void print_pixel (char *source_path, int x, int y) {
    int width, height, channel_count;
    unsigned char* data;
    int R,G,B;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) !=0){
        unsigned int position = channel_count*(y*width+x);
        R = data[position];
        G = data[position+1];
        B = data[position+2];
        printf("print_pixel (%d,%d): %d, %d, %d\n",x,y, R, G, B);
    }
    free_image_data(data);
}
// close #21


// issue #20
char *max_pixel (char *source_path) {
    int width, height, channel_count;
    unsigned char* data;
    int maxSomme = -1;
    int R, G, B, maxX, maxY, i, j;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) !=0){
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j=j+3){
                unsigned int position = 3*(i*width+j);
                int somme = data[position] + data[position+1] + data[position+2];
                if (somme > maxSomme) {
                    maxSomme = somme;
                    maxX = j;
                    maxY = i;
                    R = data[position];
                    G = data[position+1];
                    B = data[position+2];
                }
            }
        }
    }

    char *result = malloc(50); // Allocate enough space for the result string
    if (result == NULL) {
        printf("Erreur d'allocation de mémoire.\n");
        return NULL;
    }
    printf("max_pixel(%d,%d):%d, %d, %d\n",maxX,maxY,R, G, B);
    sprintf(result, "max_pixel(%d,%d):%d, %d, %d\n",maxX,maxY,R, G, B);
    return result;
    free_image_data(data);
}
//close #20


// issus #19
char *min_pixel(char *source_path) {
    int width, height, channel_count;
    unsigned char* data;
    int minSum = 255 * 3 + 1;
    int R = 0, G = 0, B = 0, minX = 0, minY = 0;
    int i, j;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) != 0) {
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                unsigned int position = 3 * (i * width + j);
                int sum = data[position] + data[position + 1] + data[position + 2];
                if (sum < minSum) {
                    minSum = sum;
                    minX = j;
                    minY = i;
                    R = data[position];
                    G = data[position + 1];
                    B = data[position + 2];
                }
            }
        }
    } else {
        printf("Failed to read image data.\n");
        return NULL;
    }

    char *result = malloc(50); // Allocate enough space for the result string
    if (result == NULL) {
        printf("Memory allocation error.\n");
        return NULL;
    }
    sprintf(result, "min_pixel(%d,%d):%d,%d,%d\n", minX, minY, R, G, B);

    printf("%s", result); // Print the result string

    return result;
}
// close #19


/*
    Issue: #18
*/
char *max_component(char *source_path, char component) {
    int width, height, channel_count;
    unsigned char* data;
    int R = -1, G = -1, B = -1;
    int xR = 0, yR = 0, xG = 0, yG = 0, xB = 0, yB = 0;
    int i, j;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) != 0) {
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                unsigned int position = 3 * (i * width + j);
                if (component == 'R' && R < data[position]) {
                    R = data[position];
                    xR = j;
                    yR = i;
                } else if (component == 'G' && G < data[position + 1]) {
                    G = data[position + 1];
                    xG = j;
                    yG = i;
                } else if (component == 'B' && B < data[position + 2]) {
                    B = data[position + 2];
                    xB = j;
                    yB = i;
                }
            }
        }
    } else {
        printf("Failed to read image data.\n");
        return NULL;
    }

    char *result = malloc(50); // Allocate enough space for the result string
    if (result == NULL) {
        printf("Memory allocation error.\n");
        return NULL;
    }

    if (component == 'R') {
        sprintf(result, "max_component R (%d,%d): %d\n", xR, yR, R);
        printf("max_component R (%d,%d): %d\n", xR, yR, R);
    } else if (component == 'G') {
        sprintf(result, "max_component G (%d,%d): %d\n", xG, yG, G);
        printf("max_component G (%d,%d): %d\n", xG, yG, G);
    } else if (component == 'B') {
        sprintf(result, "max_component B (%d,%d): %d\n", xB, yB, B);
        printf("max_component B (%d,%d): %d\n", xB, yB, B);
    } else {
        sprintf(result, "Error: component must be R, G, or B\n");
        printf("Error: component must be R, G, or B\n");
    }
    free_image_data(data);
    return result;
}

// close #18


/*
    Issue: #17
*/

char *min_component(char *source_path, char component) {
    int width, height, channel_count;
    unsigned char* data;

    int R = 256;
    int G = 256;
    int B = 256;
    // R point coordinate
    int xR = 0;
    int yR = 0;
    // G point coordinate
    int xG = 0;
    int yG = 0;
    // B point coordinate
    int xB = 0;
    int yB = 0;
    int i, j;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) !=0){
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++){
                unsigned int position = 3*(i*width+j);
                if (R > data[position]){
                    R = data[position];
                    xR = j;
                    yR = i;
                }
                if (G > data[position+1]){
                    G = data[position+1];
                    xG = j;
                    yG = i;
                }
                if (B > data[position+2]){
                    B = data[position+2];
                    xB = j;
                    yB = i;
                }

            }
        }
    }

    char *result = malloc(50); // Allocate enough space for the result string
    if (result == NULL) {
        printf("Erreur d'allocation de mémoire.\n");
        return NULL;
    }

    if (component == 'R'){
        sprintf(result, "min_component R (%d,%d): %d\n", xR, yR, R);
        printf("min_component R (%d,%d): %d\n", xR, yR, R);
    }
    else if (component == 'G'){
        sprintf(result, "min_component G (%d,%d): %d\n", xG, yG, G);
        printf("min_component G (%d,%d): %d\n", xG, yG, G);
    }
    else if (component == 'B'){
        sprintf(result, "min_component B (%d,%d): %d\n", xB, yB, B);
        printf("min_component B (%d,%d): %d\n", xB, yB, B);
    }
    else{
        sprintf(result, "Error: %s\n", source_path);
        printf("Error: %s\n", source_path);
    }
    free_image_data(data);
    return result;
}
// close #17

/*
    Issue: #16

    verifier que chaque fonctions renvoient bien les valeurs attendues

    max_pixel  O
    min_pixel  O
    max_component X
    min_component X
    
    
*/

void stat_report(char *source_path){
    char *filename = "stat_report.txt";

    FILE *fptr;
 
    fptr = fopen(filename, "w");
    if (fptr == NULL){
        fptr = fopen(filename, "a+");
    }

    fprintf(fptr, "max_pixel:\n");
    fprintf(fptr,max_pixel(source_path));
    fprintf(fptr, "\nmin_pixel:\n");
    fprintf(fptr,min_pixel(source_path));
    fprintf(fptr, "\nmax_component R:\n");
    fprintf(fptr,max_component(source_path, 'R'));
    fprintf(fptr, "\nmax_component G:\n");
    fprintf(fptr,max_component(source_path, 'G'));
    fprintf(fptr, "\nmax_component B:\n");
    fprintf(fptr,max_component(source_path, 'B'));
    fprintf(fptr, "\nmin_component R:\n");
    fprintf(fptr,min_component(source_path, 'R'));
    fprintf(fptr, "\nmin_component G:\n");
    fprintf(fptr,min_component(source_path, 'G'));
    fprintf(fptr, "\nmin_component B:\n");
    fprintf(fptr, min_component(source_path, 'B'));
    fclose(fptr);

}
// close #16

/* 
* Issue: #15
*/
void color_red(char *source_path){
    int width, height, channel_count;
    unsigned char* data;
    // destionation path : image_out.bmp
    char *destination_path = "image_out.bmp";

    if (read_image_data(source_path, &data, &width, &height, &channel_count) !=0){
        int i, j;
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++){
                unsigned int position = 3*(i*width+j);
                data[position+1] = 0;
                data[position+2] = 0;
            }
        }
    }
    write_image_data(destination_path, data, width, height);
    free_image_data(data);
}
// close #15

/*
 issue: #14

*/

void color_green(char *source_path){
    int width, height, channel_count;
    unsigned char* data;
    // destionation path : image_out.bmp
    char *destination_path = "image_out.bmp";

    if (read_image_data(source_path, &data, &width, &height, &channel_count) !=0){
        int i, j;
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++){
                unsigned int position = 3*(i*width+j);
                data[position]= 0;
                data[position+2] = 0;
            }
        }
    }
    write_image_data(destination_path, data, width, height);
    free_image_data(data);
}
// close #14   

/*
 issue: #13
*/

void color_blue(char *source_path){
    int width, height, channel_count;
    unsigned char* data;
    // destionation path : image_out.bmp
    char *destination_path = "image_out.bmp";

    if (read_image_data(source_path, &data, &width, &height, &channel_count) !=0){
        int i, j;
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++){
                unsigned int position = 3*(i*width+j);
                data[position] = 0;
                data[position+1] = 0;
            }
        }
    }
    write_image_data(destination_path, data, width, height);
    free_image_data(data);
}

// close #13

/*
 issue: #12
*/

void  color_gray(char *source_path){
    int width, height, channel_count;
    unsigned char* data;
    
    // image_out.bmp
    char *destination_path = "image_out.bmp";
    unsigned char gray = 0;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) !=0){
        int i, j;
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++){
                unsigned int position = 3*(i*width+j);
                gray = (data[position] + data[position+1] + data[position+2])/3;
                data[position] = gray;
                data[position+1] = gray;
                data[position+2] = gray;
            }
        }
    }

    write_image_data(destination_path, data, width, height);
    free_image_data(data);

}
// close #12

/*
 issue: #11
*/
void invert(char *source_path){
    int width, height, channel_count;
    unsigned char* data;
    
    // image_out.bmp
    char *destination_path = "image_out.bmp";
        if (read_image_data(source_path, &data, &width, &height, &channel_count) !=0){
        int i, j;
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++){
                unsigned int position = 3*(i*width+j);
                data[position] = 255 - data[position];
                data[position+1] = 255 - data[position+1];
                data[position+2] = 255 - data[position+2];
            }
        }
    }

    write_image_data(destination_path, data, width, height);
free_image_data(data);
}

// close #11

/*
 issue: #10
 TODO: repair the function gray_luminance
*/

void color_grey_luminance(char *source_path){
    int width, height, channel_count;
    unsigned char* data;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) !=0){
        int i, j;
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++){
                unsigned int position = 3*(i*width+j);
                unsigned char gray = 0.2126*data[position] + 0.7152*data[position+1] + 0.0722*data[position+2];
                data[position] = gray;
                data[position+1] = gray;
                data[position+2] = gray;
            }
        }
    }
    free_image_data(data);
}
// close #10
// Issue #9
// rotate image clockwise of 90 degrees
void rotate_cw(char *source_path){
    int width, height, channel_count;
    int new_width, new_height;
    unsigned char* data;
    char *destination_path = "image_out.bmp";
    if (read_image_data(source_path, &data, &width, &height, &channel_count) !=0){
        new_width = height;
        new_height = width;
        unsigned char* new_data = malloc(new_width*new_height*channel_count);
        int i, j;
        for (i = 0; i < new_height; i++) {
            for (j = 0; j < new_width; j++){
                unsigned int position = channel_count*(i*width+j);
                unsigned int new_position = channel_count*(j*new_height+(new_height-i-1));
                new_data[new_position] = data[position];
                new_data[new_position+1] = data[position+1];
                new_data[new_position+2] = data[position+2];
            }
        }
        write_image_data(destination_path, new_data, new_width, new_height);
        free_image_data(new_data);
    }
    free_image_data(data);
}
// close #9

// Issue #8
// rotate image counter clockwise of 90 degrees
void rotate_acw(char *source_path){
    int width, height, channel_count;
    int new_width, new_height;
    unsigned char* data;
    char *destination_path = "image_out.bmp";
    if (read_image_data(source_path, &data, &width, &height, &channel_count) !=0){
        new_width = height;
        new_height = width;
        unsigned char* new_data = malloc(new_width*new_height*channel_count);
         int i, j;
        for (i = 0; i < new_height; i++) {
            for (j = 0; j < new_width; j++){
                int position = channel_count*(i*width+j);
                int new_position = channel_count*((new_width-j-1)*new_height+i);
                new_data[new_position] = data[position];
                new_data[new_position+1] = data[position+1];
                new_data[new_position+2] = data[position+2];
            }
        }
        write_image_data(destination_path, new_data, new_width, new_height);
    }
    free_image_data(data);
}
// close #8
// Issue #7
void mirror_horizontal(char *source_path) {
    int width, height, channel_count;
    unsigned char* data;
    char* destination_path = "image_out.bmp";
    
    if (read_image_data(source_path, &data, &width, &height, &channel_count) != 0) {
        int i, j;
        for (i = 0; i < height; i++) {
            for (j = 0; j < width / 2; j++) { // Only go up to half the width
                int mirror_j = width - j - 1;
                unsigned int position = channel_count * (i * width + j);
                unsigned int mirror_position = channel_count * (i * width + mirror_j);
                int k;
                for (k = 0; k < channel_count; k++) {
                    unsigned char temp = data[position + k];
                    data[position + k] = data[mirror_position + k];
                    data[mirror_position + k] = temp;
                }
            }
        }
        write_image_data(destination_path, data, width, height);
    }
    free_image_data(data);
}
// close #7

// issue:#6 
void mirror_vertical(char *source_path) {
    int width, height, channel_count;
    unsigned char* data;
    char* destination_path = "image_out.bmp";
    
    if (read_image_data(source_path, &data, &width, &height, &channel_count) != 0) {
        int i, j;
        for (i = 0; i < height / 2; i++) { // Only go up to half the height
            int mirror_i = height - i - 1;
            for (j = 0; j < width; j++) {
                unsigned int position = channel_count * (i * width + j);
                unsigned int mirror_position = channel_count * (mirror_i * width + j);
                int k;
                // Swap the pixels
                for (k = 0; k < channel_count; k++) { 
                    unsigned char temp = data[position + k];
                    data[position + k] = data[mirror_position + k];
                    data[mirror_position + k] = temp;
                }
            }
        }
        if (write_image_data(destination_path, data, width, height)==0){
            printf("Error writing image data\n");
        }
    }
}   

// issue #5
void mirror_total(char* source_path) {
    int width, height, channel_count;
    unsigned char* data;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) != 0) {
        // Mirror vertically
        mirror_vertical(source_path);          
        // Mirror horizontally         
        mirror_horizontal("image_out.bmp");

        free(data);
    }
    else printf("\nerror\n");
}



// close #5

/*necessary functions for issue #1*/

int min(int a, int b, int c) {
    int smallest = a;
    if (b < smallest) {
        smallest = b;
    }
    if (c < smallest) {
        smallest = c;
    }
    return smallest;
}

int max(int a, int b, int c) {
    int largest = a;
    if (b > largest) {
        largest = b;
    }
    if (c > largest) {
        largest = c;
    }
    return largest;
}

// issue:#3
void scale_nearest(char* source_path, double scale_factor) {
    int width, height, channel_count;
    unsigned char* source_data;
    char* destination_path = "image_out.bmp";

    if (read_image_data(source_path, &source_data, &width, &height, &channel_count) != 0) {
        int new_width = (int)round(width * scale_factor);
        int new_height = (int)round(height * scale_factor);
        unsigned char* destination_data = (unsigned char*)malloc(new_width * new_height * channel_count);

        int i, j;
        for (i = 0; i < new_height; i++) {
            for (j = 0; j < new_width; j++) {
                int source_x = (int)round(j / scale_factor);
                int source_y = (int)round(i / scale_factor);
                unsigned int source_position = channel_count * (source_y * width + source_x);
                unsigned int destination_position = channel_count * (i * new_width + j);
                int k;
                for (k = 0; k < channel_count; k++) {
                    destination_data[destination_position + k] = source_data[source_position + k];
                }
            }
        }

        write_image_data(destination_path, destination_data, new_width, new_height);
        free(destination_data);
    }
}
// close #3

/*
    issue: #2
*/
void scale_bilinear(char *source_path, double scale_factor){
    int width, height, channel_count;
    unsigned char* source_data;
    char* destination_path = "image_out.bmp";

    if (read_image_data(source_path, &source_data, &width, &height, &channel_count) != 0) {
        int new_width = (int)round(width * scale_factor);
        int new_height = (int)round(height * scale_factor);
        unsigned char* destination_data = (unsigned char*)malloc(new_width * new_height * channel_count);

        int i, j;
        for (i = 0; i < new_height; i++) {
            for (j = 0; j < new_width; j++) {
                double source_x = (j / scale_factor);
                double source_y = (i / scale_factor);

                int x1 = fmin(floor(source_x), width - 1);
                int y1 = fmin(floor(source_y), height - 1);
                int x2 = fmin(ceil(source_x), width - 1);
                int y2 = fmin(ceil(source_y), height - 1);

                unsigned int destination_position = channel_count * (i * new_width + j);
                int k;
                for (k = 0; k < channel_count; k++) {
                    unsigned int source_position_1 = channel_count * (y1 * width + x1) + k;
                    unsigned int source_position_2 = channel_count * (y1 * width + x2) + k;
                    unsigned int source_position_3 = channel_count * (y2 * width + x1) + k;
                    unsigned int source_position_4 = channel_count * (y2 * width + x2) + k;

                    double P1 = (x2 - source_x) * source_data[source_position_1] + (source_x - x1) * source_data[source_position_2];
                    double P2 = (x2 - source_x) * source_data[source_position_3] + (source_x - x1) * source_data[source_position_4];

                    if (x1 == x2) {
                        P1 = source_data[source_position_1];
                        P2 = source_data[source_position_4];
                    }

                    double P = (y2 - source_y) * P1 + (source_y - y1) * P2;
                    destination_data[destination_position + k] = round(P);
                }
            }
        }

        write_image_data(destination_path, destination_data, new_width, new_height);
        free(destination_data);
    }
}


// close #2


/*
 issue: #1
*/
void color_desaturate(char *source_path){
    
    int width, height, channel_count;
    unsigned char* data;
    // destionation path : image_out.bmp
    char *destination_path = "image_out.bmp";
    int R,G,B,new_val;
    /*using new_val = (min(R, G, B) + max(R, G, B)) / 2;*/
    if (read_image_data(source_path, &data, &width, &height, &channel_count) !=0){
        int i, j;
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++){
                unsigned int position = 3*(i*width+j);
                R=data[position] ;
                G=data[position+1] ;
                B=data[position+2] ;
                new_val = (min(R, G, B) + max(R, G, B)) / 2;
		        data[position] = new_val;
                data[position+1] = new_val;
                data[position+2] = new_val;
            }
        }
    } 
    write_image_data(destination_path, data, width, height);
}
// close #1
