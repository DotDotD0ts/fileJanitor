#pragma once

#include <stdarg.h>
#include <stdio.h>

#define LOG_FILENAME "fileJanitor.log"
void _log(const char* filename, unsigned int line, const char* message, ...);

#define LOG(message, ...) (_log)(__FILE__, __LINE__, message, ##__VA_ARGS__)

typedef struct {
    const char* filename;
    FILE* file;
} Log;

bool initLog();
void closeLog();

// this define is only for lsp purposes and should be commented when compiling
//#define LOG_IMPLEMENTATION
#ifdef LOG_IMPLEMENTATION

Log appLog = {
    .filename = LOG_FILENAME,
    .file = NULL
};

bool initLog() {
    appLog.file = fopen(appLog.filename, "a");
    if (appLog.file == NULL) {
        fprintf(stderr, "Couldn't open/create the log file for filename: %s", appLog.filename);
        return true;
    }
    LOG("============= Log file initialized =============");
    return false;
}

void closeLog() {
    fclose(appLog.file);
}

void _log(const char* filename, unsigned int line, const char* message, ...) {
    va_list args;
    va_start(args, message);
    fprintf(appLog.file, "%s - %u: ", filename, line);
    vfprintf(appLog.file, message, args);
    fprintf(appLog.file, "\n");
    va_end(args);
}

#endif //LOG_IMPLEMENTATION
