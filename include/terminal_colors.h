#ifndef TERMINAL_COLORS_H
#define TERMINAL_COLORS_H

#define PRINT(color) printf((color))
#define SET_RED PRINT("\033[0;31m")
#define SET_YELLOW PRINT("\033[0;33m")
#define RESET_COLOR PRINT("\033[0m")

#endif //TERMINAL_COLORS_H
