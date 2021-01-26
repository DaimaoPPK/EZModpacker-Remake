#pragma once

#ifdef __linux__
#define MKDIR(dir) system(("mkdir -p "+dir).c_str())
#elif __unix || __unix__
#define MKDIR(dir) system(("mkdir -p "+dir).c_str())
#elif __APPLE__ || __MACH__
#define MKDIR(dir) system(("mkdir -p "+dir).c_str())
#elif __FreeBSD__
#define MKDIR(dir) system(("mkdir -p "+dir).c_str())
#elif __WIN32 || __WIN64
#include <direct.h>
#define MKDIR(dir) mkdir(dir)
#else
#error "Sorry but your OS is not supported. But don't worry, you just need to change a few stuffs in source code."
#endif

#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <curl/curl.h>
#include "Def.h"

