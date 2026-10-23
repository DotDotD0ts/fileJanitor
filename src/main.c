#define LOG_IMPLEMENTATION
#include "libs/logLib.h"

#include "terminal.h"

int main(int argc, char* argv[]) {
    if (initLog()) {
        return 1;
    }
    LOG("test");
	init();
    //while (1) {
    //    
    //}
    closeLog();
	return 0;
}
