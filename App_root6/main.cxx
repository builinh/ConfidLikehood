/*******************************************************************************
* 
* VINAGAMMA-DANANG
* Author: Le Tuan Anh ; Created: Feb 2020
* email: letuananh.nuclphys@gmail.com
*
*******************************************************************************/
#include <iostream>
#include "TApplication.h"
#include "ConfiLikelihood.h"
#include <TVirtualX.h>

#include <sys/stat.h> 
#include <sys/types.h> 
#include <cstdio>
#include <iostream> 
#include <unistd.h>
#include <bits/stdc++.h> 
int main(int argc,char** argv)
{
    /*
    UInt_t w,h;
    Int_t x,y;
    auto window = gClient->GetRoot();
    gVirtualX->GetWindowSize(window->GetId(),x,y,w,h);
    double fwidth = w;double fhight=h;
*/

    int fCreateFolderCheck = mkdir("ConfidOutput",0777);
    TApplication theApp("App", &argc, argv);
    double fwidth=gClient->GetDisplayWidth();
    double fhight=gClient->GetDisplayHeight();
    new ConfidenceLikelihood(gClient->GetRoot(),fwidth, fhight); 

    theApp.Run();
    
   // std::cout<<"Hello World"<<std::endl;
    
    return 0;
}