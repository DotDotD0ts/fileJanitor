#pragma once

#include <stdio.h>

bool checkConfigFile(const char* filename);
FILE openConfigFile(const char* filename);
void closeConfigFile(FILE& configFile);
const char* readConfigFile(FILE& configFile);
void writeConfigFile(FILE& configFile, ...);

// this define is only for lsp purposes and should be commented when compiling
#define CONFIGLIB_IMPLEMENTATION
#ifdef CONFIGLIB_IMPLEMENTATION

bool checkConfigFile(const char *filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        
    }
}

#endif //CONFIGLIB_IMPLEMENTATION
