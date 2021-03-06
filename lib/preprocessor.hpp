
#pragma once

#ifdef __linux__
#define MKDIR(dir) system(("mkdir -p "+dir).c_str())
#elif __unix || __unix__
#define MKDIR(dir) system(("mkdir -p "+dir).c_str())
#elif __APPLE__ || __MACH__
#define MKDIR(dir) system(("mkdir -p "+dir).c_str())
#elif __FreeBSD__
#define MKDIR(dir) system(("mkdir -p "+dir).c_str())
#else
#error "Sorry but your OS is not supported. But don't worry, you just need to change a few stuffs in source code."
#endif

#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <curl/curl.h>
