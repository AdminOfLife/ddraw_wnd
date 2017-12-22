#include <stdio.h>
#include "ddraw_dll.h"
#include <ddraw.h>

/************ GLOBALS *************/
extern ddraw_dll ddraw;
extern FILE *log;
extern LPDIRECTDRAW glp_DirectDraw;
extern LPDIRECTDRAW4 glp_DirectDraw4;

/************ DEFINES *************/
#define NAKEDCALL __declspec(naked)
// Logging
#define LOG(a) fprintf(log, a##"\n")
#define LOG_NAME "log.txt"
#define LOG_CREATE() FILE *log;\
	log = (FILE*)fopen(LOG_NAME, "w");



