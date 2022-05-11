#include "FileManager.h"
#pragma once

void FileManager::openFile(std::ofstream& file, const char* fileName, std::ios_base::openmode mode)
{
	file.open(fileName, mode);
	if (!file.is_open()) {
		perror("file error");
		exit(1);
	}
}

void FileManager::openFile(std::ifstream& file, const char* fileName, std::ios_base::openmode mode)
{
	file.open(fileName, mode);
	if (!file.is_open()) {
		perror("file error");
		exit(1);
	}
}

void FileManager::openFile(std::fstream& file, const char* fileName, std::ios_base::openmode mode)
{
	file.open(fileName, mode);
	if (!file.is_open()) {
		perror("file error");
		exit(1);
	}
}

void FileManager::openFile(std::ofstream& file, const char* fileName)
{
	openFile(file, fileName, std::ios::out | std::ios::trunc);
}

void FileManager::openFile(std::ifstream&file, const char* fileName)
{
	openFile(file, fileName, std::ios::in);
}
