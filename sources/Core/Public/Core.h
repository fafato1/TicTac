#pragma once
#include <iostream>
#include <source_location>

struct Vector2;

/*
*   0 = Full verbosity
*   1 = Warning or above
*   2 = Error or above
*   3 = Critical only
*/
#define LogVerbosity 0
inline void Log
(
    const int LogLevel,
    const std::string_view message,
    const std::source_location &location = std::source_location::current())
{
    #ifdef _DEBUG
        if (LogLevel >= LogVerbosity && !message.empty())
        {
            std::clog << "file: "
               << location.file_name() << '('
               << location.line() << ':'
               << location.column() << ") `"
               << location.function_name() << "`: "
               << message << '\n';
        }
    #endif
}


class Core {

public:
    static Vector2 GetScreenCenter();
    static float GetBorderOffset() {return 400.f;}
    static float GetLineOffset() { return GetBorderOffset() / 3.f;}
    static float GetCellSize(){ return GetLineOffset() * 2;}

};

