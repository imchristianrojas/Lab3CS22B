//
//  main.cpp
//  CS22BLab3Mac
//
//  Created by Christian on 2/25/20.
//  Copyright © 2020 Christian Rojas. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "rectangle.h"

int main() {
      
    
    std::ofstream outputFile;
    outputFile.open("output3.txt");
    
    if(outputFile.fail()){
            std::cerr<<"File cannot be open! "<<std::endl;
            exit(1);
    }
    
    char cond = 'y';
  
    while(cond == 'y' || cond == 'Y')
    {
        
        Rectangle a,b,addedRect,subRect;
        std::cin>>a;
        std::cin>>b;
        addedRect = a+b;
        subRect = a-b;
    
        std::cout<<a;
        outputFile<<a;
        std::cout<<b;
        outputFile<<b;
        
        std::cout<<"Adding your two rectangles together........."<<std::endl;
        outputFile<<"Adding your two rectangles together........."<<std::endl;
        std::cout<<addedRect<<std::endl;
        outputFile<<addedRect<<std::endl;
        
        std::cout<<"Subtracting your rectangels together........."<<std::endl;
        outputFile<<"Subtracting your rectangles together........."<<std::endl;
        std::cout<<subRect<<std::endl;
        outputFile<<subRect<<std::endl;
        
        std::cout<<"Do you want to try another two rectangles input 'y' for yes or 'n' for no"<<std::endl;
        outputFile<<"Do you want to try another two rectangles input 'y' for yes or 'n' for no"<<std::endl;
        
        std::cin>>cond;
        outputFile<<"UserInput: "<<cond<<std::endl;
        
    }
    
    std::cout<<"Okay have a good day"<<std::endl;
    outputFile<<"Okay have a good day "<<cond<<std::endl;
    
    outputFile.close();
    system("pause");
    
    
    
    return 0;
}
