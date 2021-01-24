#pragma once

std::string modpackname = "";
std::string curdir = "";
std::string line = "";
std::string dlname = "";
long dlcount;
long dircount;

std::vector<std::string> split(std::string line, char by);
size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream);
void makedir();
void download(std::string url, std::string output);
void CurseForgeFix(std::string splittedline[]);
void ProcessReport();
void Interpret();