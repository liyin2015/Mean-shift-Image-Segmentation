#ifndef LOAD_IMAGE_H
#define LOAD_IMAGE_H
#include "defs.h"
//#include <stdio.h>
//#include <stdarg.h>
//#include <stdlib.h>
//#include <string.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <tuple>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/timer.hpp>
#include <boost/program_options.hpp>
#include <boost/tuple/tuple.hpp>
//using namespace std;

//define error constants
enum {
    PPM_NO_ERRORS,
    PPM_NULL_PTR,
    PPM_FILE_ERROR,
    PPM_UNKNOWN_FORMAT,
    PPM_OUT_OF_MEMORY
};

int writePPMImage(const char *filename, unsigned char *image, int height, int width, int depth, char *comments);
int writePGMImage(const char *filename, unsigned char *image, int height, int width, int depth, char *comments);
int writePNMImage(const char *filename, unsigned char *image, int height, int width, int depth, bool color,
                  char *comments);
int readPPMImage(const char *filename, unsigned char **image, int& height, int& width, int& depth);
int readPGMImage(const char *filename, unsigned char **image, int& height, int& width, int& depth);
int readPNMImage(const char *filename, unsigned char **image, int& height, int& width, int& depth, bool& color);
int CmCReadImage(const char *filename, unsigned char **image, int& height, int& width, int& dim);

//converts an image into floating point format
float *CmCConvertToFloat(unsigned char *image, int height, int width, int dim);

//write image data
int CmCWriteImage(const char *filename, unsigned char *image, int height, int width, int dim, int filetype);

int writeImage(const char *filename, unsigned char *image, int *dataPoints, int height_, int width_, int dim_, int n, int filetype);

typedef boost::tuple<std::string, std::vector<std::string> > FileValueTuple;
typedef std::unordered_map<std::string, FileValueTuple > FileMap;

typedef std::unordered_map<std::string, std::string > StringMap;

int dealInputCommand(int argc, char** argv,  FileMap& map);

#endif