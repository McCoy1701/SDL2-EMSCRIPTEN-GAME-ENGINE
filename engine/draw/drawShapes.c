#include "draw.h"

void drawPoint(int x, int y) {
    SDL_RenderDrawPoint(app.renderer, x, y);
}

void drawLine(int x1, int y1, int x2, int y2) {
    SDL_RenderDrawLine(app.renderer, x1, y1, x2, y2);
}

void drawHoriLine(int x1, int x2, int y) {
    SDL_RenderDrawLine(app.renderer, x1, y, x2, y);
}

void drawVertLine(int y1, int y2, int x) {
    SDL_RenderDrawLine(app.renderer, x, y1, x, y2);
}

void drawRect(SDL_Rect* src, int value) {
    if (!value) {
        SDL_RenderDrawRect(app.renderer, src);
    }

    else {
        SDL_RenderFillRect(app.renderer, src);
    }
}

void drawCircle(int x, int y, int radius) {
   int centerX;
   int centerY;

   for (int i = 0; i < 360; i++)  {
    centerX = x + radius * cos(i);
    centerY = y + radius * sin(i);
    SDL_RenderDrawPoint(app.renderer, centerX, centerY);
   }
}

SDL_Rect createRect(int x, int y, int w, int h) {
    SDL_Rect temp;
    temp.x = x;
    temp.y = y;
    temp.w = w;
    temp.h = h;
    return temp;
}
