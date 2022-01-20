 

Pixel * loadPixel(TGAHeader header, FILE * file)
{
    int width = 0;
    int height = 0;

    memcpy(&width, header.width, 2);
    memcpy(&height, header.height, 2);

    Pixel * pixels = (Pixel *) malloc(sizeof(Pixel) * width * height);
    assert(fread(pixels, sizeof(Pixel) * width * height, 1, file) == 1);
    return pixels;
}

int main()
{
    FILE *file = fopen("carmack.tga", "rb");
    assert(file);

    TGAHeader header = {};
    assert(fread(&header, sizeof(TGAHeader), 1, file) == 1);

    printf("Image type: %d, pixel depth: %d\n", header.image_type, header.depth);

    int width = 0;
    int height = 0;

    memcpy(&width, header.width, 2);
    memcpy(&height, header.height, 2);

    printf("Image width: %d, height: %d\n", width, height);

    Pixel * pixels = loadPixel(header, file);

    for(int i = 0; i < width * height; i++)
    {
        printf("Index: %d, Blue: %d, Green: %d, Red: %d\n", i, pixels[i].blue, pixels[i].green, pixels[i].red);
    }

    free(pixels);

    assert(!fclose(file));
}