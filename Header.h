#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int CreateFile(char*);
int OpenFile(char*, int);
void ReadFile(char*);
void WriteFile(char*);
void DeleteFile(char*);
