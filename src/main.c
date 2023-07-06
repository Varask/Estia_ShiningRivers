#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include "utils.h"
#include "argsparse.h"

int main(int argc, char **argv) {
  /*To use debug mode: 
   - add --debug: freud.exe --debug -f images/input/image.jpeg
   or 
   - Simply run your compiled project with start button on the blue menu bar at the bottom of the VS Code window.
   */

  /*DO NOT EDIT THIS PART*/
  Config configuration ;
  parse_arguments( argc, argv, &configuration ) ;
  check_debug_mode(configuration);
  check_file();
  /* END */

  /* Use "if ( strncmp( command, <commandname>, 9 ) == 0 )" to check if your <commandname> is called by program.*/
  /* Example with helloworld command
   * If helloworld is a called command: freud.exe -f images/input/image.jpeg -c helloworld 
   */
  if ( strncmp( configuration.command, "helloworld", 10 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    helloWorld();
  }

  // issue 25 : Get the dimension of an image
  if ( strncmp( configuration.command, "dimension", 10 ) == 0 ) {
    dimension(configuration.filenames[0]);
  }

  // issue 24 : Get the color of the first pixel
  if ( strncmp( configuration.command, "first_pixel", 11 ) == 0 ) {
    first_pixel(configuration.filenames[0]);
  }

  // issue 23 : Get the color of the tenth pixel
  if ( strncmp( configuration.command, "tenth_pixel", 11 ) == 0 ) {
    tenth_pixel(configuration.filenames[0]);
  }

  // issue 22 : Get the color of the second line first pixel
  if ( strncmp( configuration.command, "second_line", 11 ) == 0 ) {
    second_line(configuration.filenames[0]);
  }

  // issue 21 : Access a pixel of an image with its coordinates
  if ( strncmp( configuration.command, "print_pixel", 11 ) == 0 ) {
    // Accéder aux arguments 6 et 7
    // de la ligne de commande
    int inputX = atoi(configuration.arguments[0]);
    int inputY = atoi(configuration.arguments[1]);
    print_pixel(configuration.filenames[0], inputX, inputY);
  }

// issue 20 : maximum pixel sum of RGB
  if ( strncmp( configuration.command, "max_pixel", 9 ) == 0 ) {
    max_pixel(configuration.filenames[0]);
  }


// issue 19 : minimum pixel sum of RGB
  if ( strncmp( configuration.command, "min_pixel", 9 ) == 0 ) {
    min_pixel(configuration.filenames[0]);
  }

// issue 18 : Max component of RGB
  if ( strncmp( configuration.command, "max_component", 13 ) == 0 ) {
    max_component(configuration.filenames[0], configuration.arguments[0][0]);
  }

// issue 17 : Min component of RGB
  if ( strncmp( configuration.command, "min_component", 13 ) == 0 ) {
    min_component(configuration.filenames[0], configuration.arguments[0][0]);
  }
// issue 16 : Print a report in a file stat_report.txt
  if ( strncmp( configuration.command, "stat_report", 12 ) == 0 ) {
    stat_report(configuration.filenames[0]);
  }

//issue #15 : Color in RED
  if ( strncmp( configuration.command, "color_red", 9 ) == 0 ) {
    color_red(configuration.filenames[0]);
  }
  
// issue 14 : Color green
  if ( strncmp( configuration.command, "color_green", 11 ) == 0 ) {
    color_green(configuration.filenames[0]);
  }

// issue 13: Color blue
  if ( strncmp( configuration.command, "color_blue", 10 ) == 0 ) {
    color_blue(configuration.filenames[0]);
  }

// issue 12 : Color gray
  if ( strncmp( configuration.command, "color_gray", 10 ) == 0 ) {
    color_gray(configuration.filenames[0]);
  }


// issue 11: Color invert 
  if ( strncmp( configuration.command, "color_invert", 10 ) == 0 ) {
    invert(configuration.filenames[0]);
  }

// Issue 10 : Color in gray luminance
  if( strncmp( configuration.command, "color_gray_luminance", 20) == 0) {
    color_grey_luminance(configuration.filenames[0]);
  }

// Issue 9: Rotate 90° clockwise
  if ( strncmp( configuration.command, "rotate_cw", 9 ) == 0 ) {
    rotate_cw(configuration.filenames[0]);
  }

// Issue 8: Rotate 90° counter clockwise
  if ( strncmp( configuration.command, "rotate_acw", 10 ) == 0 ) {
    rotate_acw(configuration.filenames[0]);
  }
  
// Issue 7 : Mirror effect - 
  if( strncmp( configuration.command, "mirror_horizontal", 17 ) == 0 ) {
    mirror_horizontal(configuration.filenames[0]);
  } 

// Issue 6 : Mirror effect - vertical symmetry
  if( strncmp( configuration.command, "mirror_vertical", 15 ) == 0 ) {
    mirror_vertical(configuration.filenames[0]);
  } 

// Issue 5 : Mirror effect - vertical symmetry and horizontal symmetry
  if( strncmp( configuration.command, "mirror_total",13 ) == 0 ) {
    mirror_total(configuration.filenames[0]);
  } 
// Issue 3 : Scale via Nearest-neighbor interpolation
  if( strncmp( configuration.command, "scale_nearest",17 ) == 0 ) {
    scale_nearest(configuration.filenames[0],atof(configuration.arguments[0]));
  } 
// Issue 2 : Scale via Bilinear interpolation
  if( strncmp( configuration.command, "scale_bilinear",15 ) == 0 ) {
    scale_bilinear(configuration.filenames[0],atof(configuration.arguments[0]));
  } 
// Issue 1: Desaturate
  if ( strncmp( configuration.command, "color_desaturate", 9 ) == 0 ) {
    color_desaturate(configuration.filenames[0]);
  }



  return 0;
}


