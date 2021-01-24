#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <curl/curl.h>
#include "Def.h"

std::vector<std::string> split(std::string line, char by){
    std::vector<std::string> tokens;std::stringstream check0(line);std::string intermediate;
    while(getline(check0, intermediate, by)) { tokens.push_back(intermediate); }
    return tokens;
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream){
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

void makedir(std::string dirname){
#ifdef __linux__
    system(("mkdir "+dirname).c_str());
#elif __unix || __unix__
    system(("mkdir "+dirname).c_str());
#elif __APPLE__ || __MACH__
    system(("mkdir "+dirname).c_str());
#elif __FreeBSD__
    system(("mkdir "+dirname).c_str());
#elif __WIN32 || __WIN64
    mkdir(dirname);
#else
    #error "Sorry but your OS is not supported. But don't worry, you just need to change a few stuffs in source code."
#endif
}

void download(std::string url, std::string output){
    curl_global_init(CURL_GLOBAL_ALL);

    CURL *handle = curl_easy_init();
    FILE *fp = fopen(output.c_str(), "wb");
    std::cout << output << '\n';

    curl_easy_setopt(handle, CURLOPT_URL, url.c_str());
    curl_easy_setopt(handle, CURLOPT_NOPROGRESS, 0L);
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_data);

    if (fp){
        curl_easy_setopt(handle, CURLOPT_WRITEDATA, fp);
        curl_easy_perform(handle);
        fclose(fp);
    }
    curl_easy_cleanup(handle);
    curl_global_cleanup();
}

void CurseForgeFix(std::string splittedline[]){
    std::string p1 = splittedline[0].substr(0, splittedline[0].length() - 3);
    std::string p2 = splittedline[0].substr(splittedline[0].length() - 3).substr(0, 1).erase(1,1)+ splittedline[0].substr(splittedline[0].length() - 3).substr(1, 3);
    std::string fixedurl = "https://media.forgecdn.net/files/" + p1 + '/' + p2 + '/' + splittedline[1];
    std::cout << "Mod Name: " << splittedline[1] << '\n';
    std::cout << "Download Link: " << fixedurl << '\n';
    download(fixedurl, curdir+'/'+splittedline[1]);
}

void ProcessReport(){

}

void Interpret(){
    if (line.substr(0, 5) == "name:"){
        std::cout << "--------------------------------------------\n";
        std::cout << "Modpack Name: " << line.substr(5) << '\n'; 
        std::cout << "--------------------------------------------\n";
        modpackname = line.substr(5);
        makedir(modpackname);
    } else if (line[0] == '$'){
        curdir = modpackname+'/'+line.substr(1);
        makedir(curdir);
    } else if (line[0] == '>'){
        dlname = line.substr(1);
    } else if (line.substr(0, 4) == "http"){
        download(line, dlname);
    } else if (line[0] == '!'){
        std::string arr[] = {split(line, '/').at(0), split(line, '/').at(1)};
        CurseForgeFix(arr);
    }
}