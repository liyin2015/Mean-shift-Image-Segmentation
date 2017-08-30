//
// Created by Li Yin Sulimowicz on 8/30/17.
//

#include "call_segment.h"
#include "msImageProcessor.h"
#include "loadImage.h"
#include <iostream>
#include <string>
using namespace std;
int call_segment(StringMap& argv, float sigmaS, float sigmaR, int minRegion, SpeedUpLevel& speed)
{
    unsigned char* image;
    int h,w,d;
    int turn = CmCReadImage(argv["I_dir"].c_str(), &image, h, w, d);
    cout<<turn<<" "<<h<<" "<<w<<" "<<d<<endl;
    msImageProcessor iProc;
    iProc.DefineImage(image,COLOR,h,w);

    //filter the image
    iProc.Filter(sigmaS, sigmaR, speed);
    //iProc.Segment(sigmaS, sigmaR,30,speed);
    if(iProc.ErrorStatus) {
        cout<<"wrong"<<endl;
        return EXE_ERROR;
    }


    unsigned char* filterImage_ = new unsigned char [h * w * d];
    iProc.GetResults(filterImage_);
    //fuse regions
    iProc.DefineImage(filterImage_,COLOR,h,w);
    iProc.FuseRegions(sigmaR, minRegion);
    if(iProc.ErrorStatus) {
        return EXE_ERROR;
    }
    unsigned char* segImage_ = new unsigned char [h * w * d];
    iProc.GetResults(segImage_);
    CmCWriteImage(argv["O_dir"].c_str(),segImage_,h,w,d, FILE_PPM);
    cout<<argv["O_dir"].c_str()<<endl;
    delete[] filterImage_;
    delete[] segImage_;
    delete[] image;

    return 0;
}