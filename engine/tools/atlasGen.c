#include "atlasGen.h"

static Image* images;
static int atlasSize;
static int padding;
static char* rootDir;
static char* atlasName;

int main(int argc, char* argv[]) {
    int w, h, rotated, fails, rotations, i, numOfImages;
    Node* root, *n;
    SDL_Surface* atlas;
    SDL_Rect dest;
    cJSON *rootJson, *entryJson;
    char* out;
    char filename[FILENAME_MAX];
    char imagename[FILENAME_MAX];
    FILE *fp;

    fails = 0;
    rotations = 0;

    handleCommandLine(argc, argv);

    SDL_Init(SDL_INIT_VIDEO);

    root = malloc(sizeof(Node));

    root->x = 0;
    root->y = 0;
    root->w = atlasSize;
    root->h = atlasSize;
    root->used = 0;

    atlas = SDL_CreateRGBSurface(0, atlasSize, atlasSize, 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);

    numOfImages = initImages();

    rootJson = cJSON_CreateArray();

    for (i = 0; i < numOfImages; i++) {
        rotated = 0;

        w = images[i].surface->w;
        h = images[i].surface->h;
        
        n = findNode(root, w, h);

        if ( n == NULL) {
            rotated = 1;

            n = findNode(root, h, w);
        }

        if (n != NULL) {
            if (rotated) {
                n->h = w;
                n->w = h;
                rotations++;
            }

            dest.x = n->x;
            dest.y = n->y;
            dest.w = n->w;
            dest.h = n->h;

            if (!rotated) {
                SDL_BlitSurface(images[i].surface, NULL, atlas, &dest);
            } else {
                blitRotated(images[i].surface, atlas, dest.x, dest.y);
            }

            printf("[%04d/ %04d] %s\n", i + 1, numOfImages, images[i].filename);

            entryJson = cJSON_CreateObject();

            cJSON_AddStringToObject(entryJson, "filename", images[i].filename);
            cJSON_AddNumberToObject(entryJson, "x", dest.x);
            cJSON_AddNumberToObject(entryJson, "y", dest.y);
            cJSON_AddNumberToObject(entryJson, "w", dest.w);
            cJSON_AddNumberToObject(entryJson, "h", dest.h);
            cJSON_AddNumberToObject(entryJson, "rotated", rotated);

            cJSON_AddItemToArray(rootJson, entryJson);

        } else {
            printf("[ERROR] Couldn't add '%s'\n", images[i].filename);
            fails++;
        }
        SDL_FreeSurface(images[i].surface);
        free(images[i].filename);
    }

    out = cJSON_Print(rootJson);
    
    strcpy(filename, "assets/");
    strcat(filename, atlasName);
    strcat(filename, ".json");

    printf("filename: %s\n", filename);
    
    fp = fopen(filename, "wb");
    fprintf(fp, "%s", out);
    fclose(fp);

    strcpy(imagename, "assets/");
    strcat(imagename, atlasName);
    strcat(imagename, ".png");

    printf("imagename: %s\n", imagename);

    IMG_SavePNG(atlas, imagename);
    
    free(images);

    SDL_FreeSurface(atlas);

    free(root);

    cJSON_Delete(rootJson);
    
    free(out);

    printf("Images: %d, Failures: %d, Rotations: %d\n", numOfImages, fails, rotations);

    SDL_Quit();
}

static void handleCommandLine(int argc, char* argv[]) {
    int i;
    atlasSize = 256;
    rootDir = "assets";
    atlasName = "atlas";
    padding = 1;

    for (i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-size") == 0) {
            atlasSize = atoi(argv[i + 1]);
        
        } else if (strcmp(argv[i], "-dir") == 0) {
            rootDir = argv[i + 1];

        } else if (strcmp(argv[i], "-name") == 0) {
            atlasName = argv[i + 1];
            printf("name: %s\n", atlasName);

        } else if (strcmp(argv[i], "-padding") == 0) {

            padding = atoi(argv[i + 1]);
        }
    }
}

static int initImages(void) {
    int numOfImages, i;
    i = 0;
    numOfImages = countImages(rootDir);
    
    images = malloc(sizeof(Image) * numOfImages);
    memset(images, 0, sizeof(Image) * numOfImages);

    loadImageData(&i, rootDir);

    qsort(images, i, sizeof(Image), imageComparator);

    return i;
}

static int countImages(const char* dir) {
    DIR* d;
    struct dirent* ent;
    char* path;
    int i;

    i = 0;

    if ((d = opendir(dir)) != NULL) {
        while ((ent = readdir(d)) != NULL) {
            if (ent->d_type == DT_DIR) {
                if (ent->d_name[0] != '.') {
                    path = malloc(strlen(dir) + strlen(ent->d_name) + 2);
                    sprintf(path, "%s/%s", dir, ent->d_name);
                    i += countImages(path);
                    free(path);
                }
            }
            else {
                i++;
            }
        }
        closedir(d);
    }
    return i;
}

static void loadImageData(int* i, const char* dir) {
    DIR *d;
    struct dirent* ent;
    char* path;

    if ((d = opendir(dir)) != NULL) {
        while ((ent = readdir(d)) != NULL) {
            path = malloc(strlen(dir) + strlen(ent->d_name) + 2);

            if (ent->d_type == DT_DIR) {
                if (ent->d_name[0] != '.') {
                    sprintf(path, "%s/%s", dir, ent->d_name);
                    loadImageData(i, path);
                }
            } else {
                sprintf(path, "%s/%s", dir, ent->d_name);
                images[*i].surface = IMG_Load(path);
                if (images[*i].surface) {
                    images[*i].filename = malloc(strlen(path) + 1);

                    strcpy(images[*i].filename, path);
                    SDL_SetSurfaceBlendMode(images[*i].surface, SDL_BLENDMODE_NONE);
                    *i = *i + 1;
                }
            }
            free(path);
        }
        closedir(d);
    }
}

static int imageComparator(const void* a, const void* b) {
    Image *i1 = (Image*)a;
    Image *i2 = (Image*)b;
    return i2->surface->h - i1->surface->h;
}

static Node* findNode(Node* root, int w, int h) {
    if (root->used) {
        Node *n = NULL;

        if ((n = findNode(&root->child[0], w, h)) != NULL || (n = findNode(&root->child[1], w, h)) != NULL) {
            return n;
        }

    } else if (w <= root->w && h <= root->h) {
        splitNode(root, w, h);
        return root;
    }

    return NULL;
}

static void splitNode(Node* node, int w, int h) {
    node->used = 1;

    node->child = malloc(sizeof(Node) * 2);
    memset(node->child, 0, sizeof(Node) * 2);

    node->child[0].x = node->x + w + padding;
    node->child[0].y = node->y;
    node->child[0].w = node->w - w - padding;
    node->child[0].h = h;

    node->child[1].x = node->x;
    node->child[1].y = node->y + h + padding;
    node->child[1].w = node->w;
    node->child[1].h = node->h - h - padding;
}

static void blitRotated(SDL_Surface* src, SDL_Surface* dest, int destx, int desty) {
    int x, y, p, dx, dy;

    dy = 0;

    for (x = 0; x < src->w; x++) {
        dx = src->h - 1;

        for (y = 0; y < src->h; y++) {
            p = getPixel(src, x, y);
            putPixel(destx + dx, desty + dy, p, dest);
            dx--;
        }

        dy++;
    }
}

static int getPixel(SDL_Surface* surface, int x, int y) {
    int bpp;
    Uint8 *p;

    bpp = surface->format->BytesPerPixel;
    p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;

    switch (bpp) {
        case 1:
            return *p;
        case 2:
            return *(Uint16*)p;
        case 3:
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
                return p[0] << 16 | p[1] << 8 | p[2];
            } else {
                return p[0] | p[1] << 8 | p[2] << 16;
            }
        case 4:
            return *(Uint32 *)p;
        
        default:
            return 0;
    }
}

static void putPixel(int x, int y, Uint32 pixel, SDL_Surface* dest) {
    int bpp;
    Uint8* p;

    bpp = dest->format->BytesPerPixel;
    p = (Uint8 *)dest->pixels + y * dest->pitch + x * bpp; 

    switch (bpp) {
        case 1:
            *p = pixel;
            break;

        case 2:
            *(Uint16 *)p = pixel;
            break;

        case 3:
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
                p[0] = (pixel >> 16) & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = pixel & 0xff;
            } else {
                p[0] = pixel & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = (pixel >> 16) & 0xff;
            }
            break;

        case 4:
            *(Uint32 *)p = pixel;
            break;
    }
}
