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


//prints the licence
void printLicence();
//prints all flags
void printHelp();
//prints the version
void printVersion();




int main(int argc, char **argv){

  
  //check all flags
  for(int i=0; i<argc; i++){
    std::string thisArg=std::string(argv[i]);
    if(thisArg=="-l" || thisArg=="--licence"){
      printLicence();
      return 0;
    }else if(thisArg=="-h" || thisArg=="--help"){
      printHelp();
      return 0;
    }else if(thisArg=="-v" || thisArg=="--version"){
      printVersion();
      return 0;
    }
  }


}










//FUNCTION DEFINITION

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
  std::cout << "GPLv3\n";
  std::cout << "Colors By Daren Kostov\n";
    
  //Version Major.Minor.Patch
  std::cout << "Version 0.0.0\n";

}

