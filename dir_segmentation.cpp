//
// Created by Li Yin Sulimowicz on 8/30/17.
//

#include "loadImage.h"
#include <iostream>
#include <vector>
#include <string>
#include "call_segment.h"
#include "defs.h"
#include "tdef.h"
using namespace std;

int main(int argc, char* argv[])
{
    cout<<"hello"<<endl;
    FileMap map;
    //argc = 3;
    //argv[0] ="./build/dir_segment";
    //argv[1] = "--I_dir";
    //argv[2]="/Users/yinli/Documents/experiments_crf/edison_source/segm/Images_ppm";
    //argc = 2;
    //argv[1] =
    dealInputCommand(argc,argv,map);

    vector<string>  files= get<1>(map["I_dir"]);
    vector<string>  o_files= get<1>(map["O_dir"]);
    int file_size = files.size();
    SpeedUpLevel speed = MED_SPEEDUP;//NO_SPEEDUP;
    int sigmaS = 10; //bandwidth spatial = 2h+1
    float sigmaR = 9; //bandwidth color = 2*h
    int minRegions = 20;

    for(int i=0;i<file_size;i++)
    {
        StringMap argvs;
        argvs["I_dir"] = files[i];
        argvs["O_dir"] = o_files[i];

        call_segment(argvs, sigmaS, sigmaR, minRegions,speed);

    }
    return 1;
}