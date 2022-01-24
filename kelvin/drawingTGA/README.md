# Semester project.

- Subject : Introduction to Programming (UPR)
- Project : Kreslení TGA obrázku
- Student : HOL0125 - Josef Holiš
- Semester : 2021/2022 Winter

## Description

The Program creates a `.tga` image according to the input parameters. We have
three objects to render.

1. rectangle
2. circle
3. triangle

## Input parameters

To run the program correctly, you need to enter the input parameters:

- `-o out.tga` parameter for saving the image
- `-w px` parameter for width picture in pixels
- `-h px` parameter for height picture in pixels

Drawing shapes:

- `-r x,y,width,height,r,g,b,a` draws a rectangle
    - `x,y` - as position in cartesian coordinate system
    - `width` - as width
    - `height` - as height
    - `r,g,b,a` as color, `r` = red, `g` = green, `b` = blue, `a` = alpha
- `-c x,y,p,r,g,b,a` draws a circle
    - `x,y` - as position in cartesian coordinate system
    - `p` - radius
    - `r,g,b,a` as color, `r` = red, `g` = green, `b` = blue, `a` = alpha
- `-t x,y,s,r,g,b,a` draws a triangle
    - `x,y` - as position in cartesian coordinate system
    - `s` - the length of the side
    - `r,g,b,a` as color, `r` = red, `g` = green, `b` = blue, `a` = alpha

Instead of writing individual parameters into the CLI. We can use the file
parameter (`-f [FILE]`) where the individual configuratins for the shapes
will be on separate lines.

## Launching the program

The program is run in the terminal of the Linux enviroment.

```console
Usage: ./program [OPTION] ... [FILE] ...

Examples:
./program p1 p1Value p2 p2Value p3 p3Value p4 p4Value
```

The position of the parameters and their values can be freely arranged.
In addition to the parameters for drawing shapes. These must be at the end after
the main ones.