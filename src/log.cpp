/* ============================================================================
 * Name        : log.cpp
 * Author(s)   : ludkiller, Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : Logging class
 * ============================================================================ */

#include <stdio.h>
#include "log.h"
#include <cstdio>
#include <stdarg.h>
#include <ctime>
#include <cstring>

// The variables for the log class are stored here because the class is used in a statically way.
static char buf[80];
static FILE * fp = NULL;

// Gets the time and date and formats it to a char *
static char * getTime() {
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buf, 80, "%Ex - %EX", timeinfo);
	return buf;
}

// Not using the constructor and deconstructor because the class is used in a statically way.
log::log() {
}

log::~log() {
}

bool log::open(const char * file) {
	// Opens the file for writing. With the flags appending and text.
	fp = fopen(file, "at");
	if (!fp) // If the file didn't exist
		fp = fopen(file, "wt"); // Open it as writing and text.
	if (!fp) {
		error("Failed to open '%s', disregards saving log file.", file.c_str());
		return false;
	}

	return true;
}

void log::close() {
	if (fp) { // If fp isn't NULL
		fclose(fp);
		fp = NULL;
	}
}

void log::info(const char * msg, ...) {
	char buf[512] = "\0";
	va_list va;

	// Get all va_args and put them into va.
	va_start(va, msg);
	// Write the date and time to the buffer
	sprintf(buf, "%-18s [*] ", getTime());
	// Write the message with the va_args and add a new line to the buffer
	vsprintf(buf + strlen(buf), msg, va);
	sprintf(buf + strlen(buf), "\n");
	va_end(va);

	// Write the buffer to console and if fp isn't NULL to the log file.
	printf(buf);
	if (fp) {
		fprintf(fp, buf);
		fflush(fp);
	}
}

void log::error(const char * msg, ...) {
	char buf[512] = "\0";
	va_list va;

	// Get all va_args and put them into va.
	va_start(va, msg);
	// Write the date and time to the buffer
	sprintf(buf, "%-18s [!] ", getTime());
	// Write the message with the va_args and add a new line to the buffer
	vsprintf(buf + strlen(buf), msg, va);
	sprintf(buf + strlen(buf), "\n");
	va_end(va);

	// Write the buffer to console and if fp isn't NULL to the log file.
	printf(buf);
	if (fp) {
		fprintf(fp, buf);
		fflush(fp);
	}
}

void log::warning(const char * msg, ...) {
	char buf[512] = "\0";
	va_list va;

	// Get all va_args and put them into va.
	va_start(va, msg);
	// Write the date and time to the buffer
	sprintf(buf, "%-18s [#] ", getTime());
	// Write the message with the va_args and add a new line to the buffer
	vsprintf(buf + strlen(buf), msg, va);
	sprintf(buf + strlen(buf), "\n");
	va_end(va);

	// Write the buffer to console and if fp isn't NULL to the log file.
	printf(buf);
	if (fp) {
		fprintf(fp, buf);
		fflush(fp);
	}
}
