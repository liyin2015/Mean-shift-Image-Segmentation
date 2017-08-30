//
// Created by lisulimowiczxx on 8/20/2017.
//
#include "msImageProcessor.h"
#include "loadImage.h"

#include <iostream>

using namespace std;

int main()
{
    cout<<"hello"<<endl;
    char* filename = "/Users/yinli/Documents/experiments_crf/edison_source/segm/5_2_s.ppm";
    unsigned char* image;
    int h,w,d;
    int turn = CmCReadImage(filename, &image, h, w, d);
    cout<<turn<<" "<<h<<" "<<w<<" "<<d<<endl;
    msImageProcessor iProc;
    iProc.DefineImage(image,COLOR,h,w);
    int sigmaS = 10; //bandwidth spatial = 2h+1
    float sigmaR = 9; //bandwidth color = 2*h
    SpeedUpLevel speed = NO_SPEEDUP;
    int minRegion = 20;

    //filter the image
    iProc.Filter(sigmaS, sigmaR, speed);
    //iProc.Segment(sigmaS, sigmaR,30,speed);
    if(iProc.ErrorStatus) {
        cout<<"wrong"<<endl;
        return EXE_ERROR;
    }


    unsigned char* filterImage_ = new unsigned char [h * w * d];
    iProc.GetResults(filterImage_);
    char* o_filename = "/Users/yinli/Documents/experiments_crf/edison_source/segm/5_2_s_f.ppm";
    CmCWriteImage(o_filename,filterImage_,h,w,d, FILE_PPM);
    //fuse regions
    iProc.DefineImage(filterImage_,COLOR,h,w);
    iProc.FuseRegions(sigmaR, minRegion);
    if(iProc.ErrorStatus) {
        return EXE_ERROR;
    }
    unsigned char* segImage_ = new unsigned char [h * w * d];
    iProc.GetResults(segImage_);
    char* o_s_filename = "/Users/yinli/Documents/experiments_crf/edison_source/segm/5_2_s_s.ppm";
    CmCWriteImage(o_s_filename,segImage_,h,w,d, FILE_PPM);

    //define the boundaries
    RegionList* regionList = iProc.GetBoundaries();
    int* regionIndeces = regionList->GetRegionIndeces(0);
    int numRegions = regionList->GetNumRegions();

    int numBoundaries_;
    for(int i=0;i<numRegions;i++)
    {
        numBoundaries_+=regionList->GetRegionCount(i);
    }
    int* boundaries = new int [numBoundaries_];
    for(int i=0;i<numBoundaries_;i++)
    {
        boundaries[i] = regionIndeces[i];
    }
    char* b_s_filename = "/Users/yinli/Documents/experiments_crf/edison_source/segm/5_2_s_b.ppm";
    writeImage(b_s_filename, image, boundaries, h,w,d,numBoundaries_,FILE_PPM);
}

