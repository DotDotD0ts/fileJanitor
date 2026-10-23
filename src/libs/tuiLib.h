#pragma once

#include <termios.h>
#include <stdlib.h>
#include <unistd.h>

extern struct termios default_terminal;
void disableRawMode();
void enableRawMode();

// this define is only for lsp purposes and should be commented when compiling
//#define TUILIB_IMPLEMENTATION
#ifdef TUILIB_IMPLEMENTATION
struct termios default_terminal;

void disableRawMode() {
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &default_terminal);
}

void enableRawMode() {
	tcgetattr(STDIN_FILENO, &default_terminal);
	atexit(disableRawMode);

	struct termios raw_mode_terminal = default_terminal;
	raw_mode_terminal.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw_mode_terminal.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | ISTRIP);
	raw_mode_terminal.c_oflag &= ~(OPOST);
	raw_mode_terminal.c_cflag |= CS8;

	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw_mode_terminal);
}
#endif //TUILIB_IMPLEMENTATION

