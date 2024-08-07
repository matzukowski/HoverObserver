#include "utilities.h"
#include <windows.h>

bool isMouseInsideConsole() {
    POINT cursorPos;
    GetCursorPos(&cursorPos);

    HWND consoleWindow = GetConsoleWindow();
    RECT consoleRect;
    GetWindowRect(consoleWindow, &consoleRect);

    return cursorPos.x >= consoleRect.left &&
        cursorPos.x <= consoleRect.right &&
        cursorPos.y >= consoleRect.top &&
        cursorPos.y <= consoleRect.bottom;
}