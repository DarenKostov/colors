/*
Colors By Daren Kostov
Copyright (c) 2023 Daren Kostov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.


*/

#include <iostream>
#include <cstring>



enum ColorFormat{
  Unknown,
  RGB,
  HEX,
  HSL
};

struct Color{
  unsigned char r;
  unsigned char g;
  unsigned char b;
  Color(unsigned char r, unsigned char g, unsigned char b): r(r), g(g), b(b){}
  Color(){};
};


//prints the licence
void printLicence();
//prints all flags
void printHelp();
//prints the version
void printVersion();

Color rgbStringToColor(std::string);
Color hexStringToColor(std::string);
Color hslStringToColor(std::string);


std::string colorToRgbString(Color);
std::string colorToHexString(Color);
std::string colorToHslString(Color);


int main(int argc, char **argv){

  ColorFormat inputFormat=Unknown;
  ColorFormat outputFormat=Unknown;
  std::string inputColor="";
  std::string outputColor="";

  
  for(int i=0; i<argc; i++){
    //is the flag even long enough
    if(argv[i][0]=='\0')
      continue;
    
    //check & get all flags
    if(argv[i][0]=='-'){

      switch(argv[i][1]){
        //licence flag
        case 'l':
          printLicence();
          return 0;
          break;
        //help flag
        case 'h':
          printHelp();
          return 0;
          break;
        //version flag
        case 'v':
          printVersion();
          return 0;
          break;
        //input flag
        case 'i':
          //is the flag even long enough
          if(argv[i][2]=='\0'){
            std::cout << "What input format?\n";
            return 0;
          }
          switch(argv[i][2]){
            case 'r':
              inputFormat=RGB;
              break;          
            case 'x':
              inputFormat=HEX;
              break;          
            case 'h':
              inputFormat=HSL;
              break;          
            default:
              std::cout << "unknown input format\n";
              return 0;
              break;          
          
          }
          break;
        //output flag
        case 'o':
          //is the flag even long enough
          if(argv[i][2]=='\0'){
            std::cout << "What output format?\n";
            return 0;
          }
          switch(argv[i][2]){
            case 'r':
              outputFormat=RGB;
              break;          
            case 'x':
              outputFormat=HEX;
              break;          
            case 'h':
              outputFormat=HSL;
              break;          
            default:
              std::cout << "unknown output format\n";
              return 0;
              break;          
          
          }
          break;
        //no idea what this flag is
        default:
          std::cout << "unknown flag\n";
          return 0;
          break;
      
      }

      
      //check & get all long(?) flags
      if(argv[i][1]=='-'){
        
        std::string thisArg=std::string(argv[i]);
        if(thisArg=="--licence"){
          printLicence();
          return 0;
        }else if(thisArg=="--help"){
          printHelp();
          return 0;
        }else if(thisArg=="--version"){
          printVersion();
          return 0;
        //no idea what this flag is
        }else{
          std::cout << "unknown flag\n";
          return 0;
        }
      }

    //potentially the input color
    }else{
      inputColor=std::string(argv[i]);
    }
  }
  //^^^end of collecting flags^^^

  // std::cout << inputFormat << ":" << outputFormat << "\n";


  Color workingColor;
  
  //do the conversion
  switch(inputFormat){
    case RGB:
      workingColor=rgbStringToColor(inputColor);
      break;
    case HEX:
      workingColor=hexStringToColor(inputColor);
      break;
    case HSL:
      workingColor=hslStringToColor(inputColor);
      break;
  }

  //output the conversion
  switch(outputFormat){
    case RGB:
      outputColor=colorToRgbString(workingColor);
      break;
    case HEX:
      outputColor=colorToHexString(workingColor);
      break;
    case HSL:
      outputColor=colorToHslString(workingColor);
      break;
  }
  
  std::cout << outputColor << "\n";
  return 0;
}


//from string conversion functions:

Color rgbStringToColor(std::string in){
  // char allNums[]="0123456789";

  // Color out;
  // unsigned char* colorChannel[3]={&out.r, &out.g, &out.r};
  // int currentChanelIndex=0;
  
  // for(int i=0; i<(int)in.size(); i++){
  //   //
  //   if(in.at(i)=='\0'){
  //     break;
  //   }
    
  //   //the given char is not a digit
  //   if(std::strchr(allNums,in.at(i))==nullptr){
  //     continue;
  //   }
      
    
    
  // }

}


//https://stackoverflow.com/questions/3723846/convert-from-hex-color-to-rgb-struct-in-c
Color hexStringToColor(std::string in){
  unsigned char r, g, b;
  sscanf(in.c_str(), "%2hhx%2hhx%2hhx", &r, &g, &b);
  return Color(r, g, b);
}


Color hslStringToColor(std::string){}

//from color conversion functions

std::string colorToRgbString(Color in){
  return std::to_string(in.r)+" "+std::to_string(in.g)+" "+std::to_string(in.b);
}
std::string colorToHexString(Color){}
std::string colorToHslString(Color){}


//INFO FUNCTION DEFINITION

void printHelp(){
  std::cout << "-h, --help: this help\n";
  std::cout << "-l, --licence: print the licence\n";
  std::cout << "-v, --version: prints the version\n";

  std::cout << "\n";

  std::cout << "-i<r|x|h>: specifies the input color format Rgb, heX, or Hsl\n";
  std::cout << "-o<r|x|h>: specifies the output color format Rgb, heX, or Hsl\n";

  std::cout << "\n";
  
  std::cout << "<rgb color>: 3 values separated by any symbol(s) that are not numbers\n";
  std::cout << "<hex color>: 3 hex values, can be lowercase or upper case, no separators and you can include or omit the \"#\"\n";
  std::cout << "<hsl color>: 3 values separated by any symbol(s) that are not numbers\n";
  std::cout << "\n";
  std::cout << "Examples:\n";
  std::cout << "colors -ir -ox \"255 100 0\"\n";
  std::cout << "colors -ih -or \"hsl(255, 100, 0)\"\n";
  std::cout << "colors -ix -oh \"#ff00a2\"\n";
  
}


void printVersion(){
  std::cout << "Copyright (c) Daren Kostov\n";
  std::cout << "GPLv3 or later\n";
  std::cout << "Colors By Daren Kostov\n";
    
  //Version Major.Minor.Patch
  std::cout << "Version 0.0.0\n";

}

