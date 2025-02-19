/*****************************************************************************
 * Plus42 -- an enhanced HP-42S calculator simulator
 * Copyright (C) 2004-2022  Thomas Okken
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see http://www.gnu.org/licenses/.
 *****************************************************************************/

#ifndef SHELL_MAIN_H
#define SHELL_MAIN_H 1

#include <gtk/gtk.h>

#define FILENAMELEN 256

extern GtkWidget *calc_widget;
extern bool allow_paint;
extern int disp_rows, disp_cols;

#define SHELL_VERSION 8

struct state_type {
    int extras;
    int printerToTxtFile;
    int printerToGifFile;
    char printerTxtFileName[FILENAMELEN];
    char printerGifFileName[FILENAMELEN];
    int printerGifMaxLength;
    char mainWindowKnown, printWindowKnown, printWindowMapped;
    int mainWindowX, mainWindowY;
    int printWindowX, printWindowY, printWindowHeight;
    char skinName[FILENAMELEN];
    int singleInstance;
    char coreName[FILENAMELEN];
    bool matrix_singularmatrix;
    bool matrix_outofrange;
    bool auto_repeat;
    bool old_repaint;
    // formerly 'allow big stack'; can't get rid of it completely
    // because the way we're reading state_type doesn't allow
    // for it to shrink.
    bool dummy;
};

extern state_type state;

extern char free42dirname[FILENAMELEN];


#define KEYMAP_MAX_MACRO_LENGTH 31
struct keymap_entry {
    bool ctrl;
    bool alt;
    bool shift;
    bool cshift;
    guint keyval;
    unsigned char macro[KEYMAP_MAX_MACRO_LENGTH + 1];
};

keymap_entry *parse_keymap_entry(char *line, int lineno);

#endif
