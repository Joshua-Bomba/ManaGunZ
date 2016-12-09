#ifndef _ISO_H
#define _ISO_H

#define USE_64BITS_LSEEK 1

#include "ntfs.h"

#ifdef USE_64BITS_LSEEK
int get_iso_file_pos(int fd, char *path, u32 *flba, u64 *size);
#else
int get_iso_file_pos(FILE *fp, char *path, u32 *flba, u64 *size);
#endif

char *get_extension(char *path);

unsigned char build_iso_data[53248];

int create_fake_file_iso(char *path, char *filename, u64 size);
u8 *create_fake_file_iso_mem(char *filename, u64 size);

int makeps3iso(char *g_path, char *f_iso, int split);
int extractps3iso(char *f_iso, char *g_path, int split);
int patchps3iso(char *f_iso);

int delps3iso(char *f_iso);

void UTF8_to_UTF16(u8 *stb, u16 *stw);
void UTF16_to_UTF8(u16 *stw, u8 *stb);

u64 get_disk_free_space(char *path);

#endif

