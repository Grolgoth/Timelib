#ifndef DEFINES_H_INCLUDED
#define DEFINES_H_INCLUDED

#ifdef __unix__

#define OS_Linux

#elif defined(_WIN32) || defined(__MINGW32__)

#define OS_Windows

#endif // OS defs

#endif // DEFINES_H_INCLUDED
