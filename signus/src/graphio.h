/*
 *  This file is part of Signus: The Artefact Wars
 *  https://github.com/signus-game
 *
 *  Copyright (C) 1997, 1998, 2002, 2003
 *  Vaclav Slavik, Richard Wunsch, Marek Wunsch
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */


//
// Hlavickovy soubor pro GRAPHIO.CPP a VGAKIT.ASM
// Obsah: init, done videa, 
//        prepinani video bank, nastav. palety apod.
//


#ifndef _GRAPHIO_H
#define _GRAPHIO_H



#include "system.h"
#include <SDL.h>





// (in-game) screen resolution:
#define RES_X    800
#define RES_Y    600
//was: extern int ResX, ResY; 



int InitVideo(void);
// inicializace videa
int DoneVideo(void);
// vypnuti videa a obnoveni puvodniho rezimu

void SetPalette(const uint8_t *paldat);
// nastavi barevnou paletu z bufferu
void SetPalettePart(const uint8_t *paldat, int palofs, int palsize);
// nastavi cast palety
void SetRawPalette(const uint8_t *pal);

extern SDL_Surface *GetScreenSurface();

// toggles fullscreen mode
extern void ToggleFullscreen();

// Fast main window redraw (without updating framebuffer)
void redraw_screen(void);

// Full main window redraw (with framebuffer update from drawbuffer)
void UpdateScreen(void);

void set_window_icon(void);

///////////////////////////////////////////////////////
// Funkce vkladajici na obrazovky ruzne vyrezy: 
//


// Vykresli mapu:
extern void DrawMapBuf();

// a tyhle kresli vysec uplne v pohode:
extern void DrawMapBufP(int x, int y, int sx, int sy);
#define     DrawMapBufP32(x, y, sx, sy)                  DrawMapBufP(x, y, sx, sy)

extern void ClearScr();
// Vykresli na celou obrazovku celoobrazovkovou bitmapu:
extern void DrawPicture(void *src);
extern void DrawPictureNB(void *src);
// Vykresli mapicku vpravo nahore:
extern void DrawLitMap();


// Kopirovani bmp do bmp:
extern void CopyBmp(void *tar, int tarwidth, int x, int y, const void *src, int w, int h);
extern void CopyBmpNZ(void *tar, int tarwidth, int x, int y, void *src, int w, int h);
extern void CopyFromBmp(void *src, int srcwidth, int x, int y, void *tar, int w, int h);
// Kresleni do bitmapy:
extern void BarBmp(void *tar, int tarwidth, int x, int y, int w, int h, byte clr);
extern void BarBmpSwap(void *tar, int tarwidth, int x, int y, int w, int h, byte clr1, byte clr2);
extern void PercentBar(void *tar, int width, int height, int x, int y, int w, int h, byte clr1, byte clr2, double value, const char *text);
extern void RectBmp(void *tar, int tarwidth, int x, int y, int w, int h, byte clr1, byte clr2);


// Vykresli obecnou bitmapu:
extern void PutBitmap(int x, int y, const void *data, int w, int h);
extern void PutBitmapNZ(int x, int y, void *data, int w, int h);
#define     PutBitmap32(x, y, data, w, h)                           PutBitmap(x, y, data, w, h)
extern void GetBitmap(int x, int y, void *data, int w, int h);
#define     GetBitmap32(x, y, data, w, h)                           GetBitmap(x, y, data, w, h)
void DrawVideoFrame(const uint8_t *frame, unsigned width, unsigned height);



// Zatmeni a rozsviceni palety:
void FadeOut(const uint8_t *paldat, int dlay);
void FadeIn(const uint8_t *paldat, int dlay);


// converts RGB SDL surface into 8bit palettized image array
extern void paletizeSurface(byte *output, SDL_Surface *surf, const char *tableName);

#endif
