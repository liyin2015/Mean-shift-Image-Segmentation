//
// Created by lisulimowiczxx on 8/20/2017.
//

#include "loadImage.h"
#include <iostream>
#include <cstdio>
using namespace std;
//get the fileformat of an image
int CmCGetImageFormat(const char *filename)
{
    if(!filename) return EXE_NULL_PTR;
    FILE *fp = fopen(filename, "rb");
    if(!fp) {
        cout<<"EXE_FILE_READ_ERROR"<<endl;
        return EXE_FILE_READ_ERROR;
    }
    char buf[3];
    if(!fgets(buf, 3, fp)) return EXE_FILE_READ_ERROR;
    fclose(fp);
    int i;
    for(i = 0; i < FILETYPE_NUM-1; i++) {
        if(!strncmp(buf, FILETYPE_HEADER_LIST[i], 2)) return i;
    }
    cout<<"file unknown"<<endl;
    return FILE_UNKNOWN;
}
#include <string.h>

int writePPMImage(const char *filename, unsigned char *image, int height, int width, int depth, char *comments)
{
    cout<<"file1_1"<<endl;
    if(!filename || !image)
    {
        cout<<"file1_2"<<endl;
        return PPM_NULL_PTR;
    }
    FILE *fp = fopen(filename, "wb");
    if(!fp)
    {
        cout<<"file1"<<endl;
        return PPM_FILE_ERROR;
    }

    //********************************************************
    //Write header information and comments.
    //********************************************************

    fprintf(fp, "P6\n", width, height);
    if(comments && strlen(comments) <= 70) fprintf(fp, "%s\n", comments);
    fprintf(fp, "%d %d\n%d\n", width, height, depth);
    cout<<"file1_12"<<endl;
    //********************************************************
    //Output raw image data.
    //********************************************************
    cout<<"file1_13"<<endl;
    int writeCount = fwrite(image, sizeof(unsigned char), height*width*3, fp);
    fclose(fp);
    cout<<"file1_14"<<endl;
    if(writeCount !=height*width*3)
    {
        cout<<"file1_15"<<endl;
        return PPM_FILE_ERROR;
    }
    return PPM_NO_ERRORS;
}

int writePGMImage(const char *filename, unsigned char *image, int height, int width, int depth, char *comments)
{

    if(!filename || !image) return PPM_NULL_PTR;
    FILE *fp = fopen(filename, "wb");
    if(!fp) return PPM_FILE_ERROR;

    //********************************************************
    //Write header information and comments.
    //********************************************************

    fprintf(fp, "P5\n", width, height);
    if(comments && strlen(comments) <= 70) fprintf(fp, "%s\n", comments);
    fprintf(fp, "%d %d\n%d\n", width, height, depth);

    //********************************************************
    //Output raw image data.
    //********************************************************

    int writeCount = fwrite(image, sizeof(unsigned char), height*width, fp);
    fclose(fp);
    if(writeCount !=height*width) return PPM_FILE_ERROR;
    return PPM_NO_ERRORS;
}

//write a PNM image
int writePNMImage(const char *filename , unsigned char *image, int height, int width, int depth, bool color,
                  char *comments)
{
    int error;
    if(color) {
        error = writePPMImage(filename, image, height, width, depth, comments);
    } else {
        error = writePGMImage(filename, image, height, width, depth, comments);
    }
    return error;
}

int readPPMImage(const char *filename, unsigned char **image, int& height, int& width, int& depth)
{

    if(!filename) return PPM_NULL_PTR;
    FILE *fp = fopen(filename, "rb");

    //********************************************************
    //Read header information.
    //********************************************************

/*  char buf[70];
  if(!fgets(buf, 70, fp)) return PPM_FILE_ERROR;
  if(strncmp(buf, "P6", 2)) return PPM_UNKNOWN_FORMAT;
  do {
    if(!fgets(buf, 70, fp)) return PPM_FILE_ERROR;
  } while(buf[0] == '#');
  sscanf(buf, "%d %d", &width, &height);
  if(!fgets(buf, 70, fp)) return PPM_FILE_ERROR;
  sscanf(buf , "%d", &depth);
  */

    //!-Start modification by Sushil Mittal for handling different kinds of formats of .ppm file, 05/05/2009
    char buf[70];
    if(!fscanf(fp, "%s", buf)) return PPM_FILE_ERROR;
    if(strncmp(buf, "P6", 2)) return PPM_UNKNOWN_FORMAT;
    fscanf(fp,"s",buf);
    printf("%s\n",buf);
    if(buf[0] == '#')
    {

        while(buf[0] == '#')
        {
            if(!fscanf(fp, "%s", buf)) return PPM_FILE_ERROR;
        }
    }
    else
    {
        if(!fscanf(fp, "%s", buf)) return PPM_FILE_ERROR;
    }
    sscanf(buf,"%d",&width);
    if(!fscanf(fp, "%s", buf)) return PPM_FILE_ERROR;
    sscanf(buf,"%d",&height);
    if(!fscanf(fp, "%s", buf)) return PPM_FILE_ERROR;
    sscanf(buf,"%d",&depth);
    fgets(buf,70,fp);

//!-End modification by Sushil Mittal for handling different kinds of formats of .ppm file, 05/05/2009
    //********************************************************
    //Read raw data information.
    //********************************************************

    *image = new unsigned char [height * width * 3];
    int readCount = fread(*image, sizeof(unsigned char), height*width*3, fp);
    fclose(fp);
    if(readCount != height*width*3) return PPM_FILE_ERROR;
    return PPM_NO_ERRORS;
}

int readPGMImage(const char *filename, unsigned char **image, int& height, int& width, int& depth)
{

    if(!filename) return PPM_NULL_PTR;
    FILE *fp = fopen(filename, "rb");

    //********************************************************
    //Read header information.
    //********************************************************

    char buf[70];
    if(!fgets(buf, 70, fp)) return PPM_FILE_ERROR;
    if(strncmp(buf, "P5", 2)) return PPM_UNKNOWN_FORMAT;
    do {
        if(!fgets(buf, 70, fp)) return PPM_FILE_ERROR;
    } while(buf[0] == '#');
    sscanf(buf, "%d %d", &width, &height);
    if(!fgets(buf, 70, fp)) return PPM_FILE_ERROR;
    sscanf(buf , "%d", &depth);

    //********************************************************
    //Read raw data information.
    //********************************************************

    *image = new unsigned char [height * width];
    int readCount = fread(*image, sizeof(unsigned char), height*width, fp);
    fclose(fp);
    if(readCount != height*width) return PPM_FILE_ERROR;
    return PPM_NO_ERRORS;
}

//read a PNM image
int readPNMImage(const char *filename, unsigned char **image, int& height, int& width, int& depth, bool& color)
{
    color = true; //assume PPM format
    int error = readPPMImage(filename, image, height, width, depth);
    if(error == PPM_UNKNOWN_FORMAT) {
        color = false;
        error = readPGMImage(filename, image, height, width, depth);
    }
    return error;
}
#include <iostream>
using namespace std;
//read image data
int CmCReadImage(const char *filename, unsigned char **image, int& height, int& width, int& dim)
{
    cout<<"get in"<<endl;
    if(!filename) return EXE_NULL_PTR;
    int filetype = CmCGetImageFormat(filename);
    int error = filetype; //possible error in reading file header
    cout<<"get in 1"<<endl;
    switch(filetype) {
        case FILE_PPM:
            error = readPPMImage(filename, image, height, width, dim);
            dim   = 3;
            break;
        case FILE_PGM:
            error = readPGMImage(filename, image, height, width, dim);
            dim   = 1;
            break;
        case FILE_PNM: {
            bool color;
            error = readPNMImage(filename, image, height, width, dim, color);
            if(color) {
                dim = 3;
            } else {
                dim = 1;
            }
            break;
        }
        default:
            cout<<"get in unknown"<<endl;
            if(filetype == FILE_UNKNOWN) return EXE_UNKNOWN_FILE_FORMAT;
    }

    if(!error)
    {
        //due to LUV conversion must always work in 5D
        if(dim == 1) {
            dim = 3;
            unsigned char *rgbImage = new unsigned char [height * width * dim];
            int i;
            for(i = 0; i < height * width; i++) {
                rgbImage[3*i] = rgbImage[3*i+1] = rgbImage[3*i+2] = (*image)[i];
            }
            delete [] *image;
            *image = rgbImage;
        }
        return NO_ERRORS;
    }
    else
        return EXE_FILE_READ_ERROR;
}

//converts an image into floating point format
float *CmCConvertToFloat(unsigned char *image, int height, int width, int dim)
{
    float *data = new float[height * width * dim];
    if(!data) return (float *) NULL;
    int i;
    for(i = 0; i < height * width * dim; i++) {
        data[i] = (float)(image[i]);
    }
    return data;
}


//converts an image from color to grayscale
const double W1 = 0.299;
const double W2 = 0.587;
const double W3 = 0.114;
unsigned char *CmCConvertToGrayscale(unsigned char *image, int height, int width)
{
    unsigned char *data = new unsigned char [height * width];
    if(!data) return (unsigned char *) NULL;
    int i;
    double r, g, b;
    for(i = 0; i < height * width; i++) {
        r = (double)(image[3*i]);
        g = (double)(image[3*i+1]);
        b = (double)(image[3*i+2]);
        data[i] = (unsigned char)(r*W1 + g*W2 + b*W3);
    }
    return data;
}

//write Matlab ASCII file
int CmCWriteMFile(const char *filename, float *data, int rows, int cols, int n)
{
    if(!filename || !data) return EXE_NULL_PTR;
    FILE *fp = fopen(filename, "wb");
    if(!fp) return EXE_FILE_WRITE_ERROR;
    int i, j, k;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols-1; j++) {
            for(k = 0; k < n; k++) {
                fprintf(fp, "%f ", data[n*(rows*i+j)+k]);
            }
        }
        for(k = 0; k < n-1; k++) {
            fprintf(fp, "%f ", data[n*(rows*i+cols-1)+k]);
        }
        fprintf(fp, "%f\n", data[n*(rows*i+cols-1)+n-1]);
    }
    fclose(fp);
    return NO_ERRORS;
}
//write image data
int CmCWriteImage(const char *filename, unsigned char *image, int height, int width, int dim, int filetype)
{
    int error, i;
    unsigned char *data;
    switch(filetype) {
        case FILE_PPM:
            data = image;
            if(dim == 1) {
                data = new unsigned char [height * width * 3];
                if(!data) return EXE_OUT_OF_MEMORY;
                for(i = 0; i < height*width; i++) {
                    data[3*i] = data[3*i+1] = data[3*i+2] = image[i];
                }
            }
            error = writePPMImage(filename, data, height, width, 255, (char *) NULL);
            if(data != image) delete [] data;
            break;
        case FILE_PGM:
            data = image;
            if(dim == 3) {
                data = CmCConvertToGrayscale(image, height, width);
                if(!data) return EXE_OUT_OF_MEMORY;
            }
            error = writePGMImage(filename, data, height, width, 255, (char *) NULL);
            if(data != image) delete [] data;
            break;
        case FILE_PNM: {
            bool color;
            if(dim == 3) {
                color = true;
            } else {
                color = false;
            }
            error = writePNMImage(filename, image, height, width, 255, color, (char *) NULL);
            break;
        }
        case FILE_MATLAB_ASCII: {
            float *fdata = CmCConvertToFloat(image, height, width, dim);
            if(!fdata) return EXE_OUT_OF_MEMORY;
            error = CmCWriteMFile(filename, fdata, height, width, dim);
            delete [] fdata;
            break;
        }
        default:
            return EXE_UNSUPPORTED_FILE_FORMAT;
    }
    if(!error)
        return NO_ERRORS;
    else
        return EXE_FILE_WRITE_ERROR;
}

int writeImage(const char *filename, unsigned char *image, int *dataPoints, int height_, int width_, int dim_, int n, int filetype)
{
    unsigned char *data = new unsigned char [height_ * width_ * dim_];
    if(!data) return EXE_OUT_OF_MEMORY;
    memset(data, 0, height_*width_*dim_*sizeof(unsigned char));
    if(image) memcpy(data, image, height_*width_*dim_*sizeof(unsigned char));
    if(dataPoints) {
        int i, j, x, y;
        for(i = 0; i < n; i++) {
            //if(dataPoints[i]==)
            data[dim_*dataPoints[i]+0]=255;
            data[dim_*dataPoints[i]+1]=0;
            data[dim_*dataPoints[i]+2]=0;

        }
    }
    int error = CmCWriteImage(filename, data, height_, width_, dim_, filetype);
    delete [] data;
    return error;
}
using namespace std;

int dealInputCommand(int argc, char** argv,  FileMap& map)
{
    cout<<"here1"<<endl;
    boost::program_options::options_description desc("Allowed options");
    desc.add_options()
            ("help", "produce help message")
            ("I_dir", boost::program_options::value<std::string>(), "the I folder to process")
            ("O_dir", boost::program_options::value<std::string>()->default_value("output"), "the O folder to process")
            ;

    boost::program_options::positional_options_description positionals;
    positionals.add("I_dir", 1);
    cout<<"here12"<<endl;
    boost::program_options::variables_map parameters;
    boost::program_options::store(boost::program_options::command_line_parser(argc, argv).options(desc).positional(positionals).run(), parameters);
    boost::program_options::notify(parameters);

    if(argc==1)
    {
        cout<<"need more parameters"<<endl;
        return -1;
    }

    if (parameters.find("help") != parameters.end()) {
        std::cout << desc << std::endl;
        return 1;
    }
    cout<<"here13"<<endl;
    //check output directory
    boost::filesystem::path outputDir(parameters["O_dir"].as<std::string>());
    if (!boost::filesystem::is_directory(outputDir)) {
        boost::filesystem::create_directory(outputDir);
    }
    FileValueTuple o_dir = boost::make_tuple(outputDir.string(), vector<string>() );
    map["O_dir"]=o_dir;
    cout<<"here14"<<endl;
    //vector<boost::filesystem::path> paths(KeySet.size());

    if(parameters["I_dir"].as<std::string>().empty())
    {

        cout<<"input directory is empty"<<endl;
        return -1;
    }
    else
    {
        boost::filesystem::path inputDir(parameters["I_dir"].as<std::string>());
        cout<<"I_dir"<<": "<<inputDir<<endl;
        if (!inputDir.empty() &&!boost::filesystem::is_directory(inputDir)) {
            std::cout << "Image directory not found ..." <<inputDir.string()<< std::endl;
            return -1;
        }
        string current_dir = inputDir.string();
        std::vector<boost::filesystem::path> pathVector;
        std::copy(boost::filesystem::directory_iterator(current_dir), boost::filesystem::directory_iterator(), std::back_inserter(pathVector));

        std::sort(pathVector.begin(), pathVector.end());

        std::string extension;
        int count = 0;

        std::vector<string> file_paths, O_path;
        //check the vector
        for (std::vector<boost::filesystem::path>::const_iterator iterator (pathVector.begin()); iterator != pathVector.end(); ++iterator) {
            if (boost::filesystem::is_regular_file(*iterator)) {

                // Check supported file extensions.
                extension = iterator->extension().string();
                //cout<<"extension"<<extension<<endl;
                std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

                if (extension == ".png" || extension == ".jpg" || extension == ".jpeg" || extension == ".tiff" || extension==".tif"
                    || extension == ".bmp" || extension == ".ppm") {
                    file_paths.push_back((*iterator).string());
                    cout<<(*iterator).string()<<endl;
                    cout<<iterator->filename()<<endl;
                    O_path.push_back(outputDir.string()+"/"+(iterator->filename()).string());
                    cout<<outputDir.string()+"/"+(iterator->filename()).string()<<endl;
                }
            }
        }
        FileValueTuple dir_value = boost::make_tuple(inputDir.string(), file_paths );
        map["I_dir"]=dir_value;
        get<1>(map["O_dir"]) = O_path;
    }

    return 1;
}