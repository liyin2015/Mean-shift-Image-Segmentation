#ifndef LOAD_IMAGE_H
#define LOAD_IMAGE_H
#include "defs.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
//define error constants
enum {
    PPM_NO_ERRORS,
    PPM_NULL_PTR,
    PPM_FILE_ERROR,
    PPM_UNKNOWN_FORMAT,
    PPM_OUT_OF_MEMORY
};

int writePPMImage(char *filename, unsigned char *image, int height, int width, int depth, char *comments);
int writePGMImage(char *filename, unsigned char *image, int height, int width, int depth, char *comments);
int writePNMImage(char *filename, unsigned char *image, int height, int width, int depth, bool color,
                  char *comments);
int readPPMImage(char *filename, unsigned char **image, int& height, int& width, int& depth);
int readPGMImage(char *filename, unsigned char **image, int& height, int& width, int& depth);
int readPNMImage(char *filename, unsigned char **image, int& height, int& width, int& depth, bool& color);
int CmCReadImage(char *filename, unsigned char **image, int& height, int& width, int& dim);

//converts an image into floating point format
float *CmCConvertToFloat(unsigned char *image, int height, int width, int dim);

//write image data
int CmCWriteImage(char *filename, unsigned char *image, int height, int width, int dim, int filetype);

int writeImage(char *filename, unsigned char *image, int *dataPoints, int height_, int width_, int dim_, int n, int filetype);


#endif