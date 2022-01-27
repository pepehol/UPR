# Semester project.

- Subject : Introduction to Programming (UPR)
- Project : Kreslení TGA obrázku
- Student : HOL0125 - Josef Holiš
- Semester : 2021/2022 Winter
- URL : [GitHub](https://github.com/pepehol/UPR/tree/main/kelvin/drawingTGA)

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

**Drawing shapes:**

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

Instead of writing individual shape into the CLI. We can use the file
parameter (`-f [FILE]`) where the individual parameters for the shapes
will be on separate lines.

**Examples of use**

1. Input from CLI
`./drawingTGA -o output.tga -w 200 -h 200 -r 10,10,100,100,255,255,0,128 
-c 30,30,20,0,255,255,128 -t 50,50,40,0,0,255,255`
2. Input from file
`./drawingTGA -o -w 200 -h 200 -f p.txt`

Contents of the file *p.txt*:
`-r 10,10,100,100,255,0,0,255`

### Notes

**Colors**
The standard RGB model is used for the selected colours. Individual elements
can have values from 0 to 255. Alpha channel is used for pixel transparency and
have values from 0 to 255.
[Description on wiki](https://en.wikipedia.org/wiki/RGBA_color_model)
[RGB Calculator](https://www.w3schools.com/colors/colors_rgb.asp)

**Shapes**
Drawing of individual shapes is based on Cartesian coordinate system. The orogin
of the coordinates starts from the top left corner [xs, ys].

Each shape is assembled into a rectangle but the picture shows the actual shape.

It is therefore a good idea to keep this in mind when entering commands.
Check picture below:

```text
xs,ys
I----------|
|xxxxxxxxxx|
|xxxxxxxxxx|
|xxxxxxxxxx|
|xxxxxxxxxx|
|xxxxxxxxxx|
|xxxxxxxxxx|
|xxxxxxxxxx|
|xxxxxxxxxx|
|xxxxxxxxxx|
|xxxxxxxxxx|
|----------I
           xe,ye
```


```text
xs,ys
I-------|
|  ***  |
| ***** |
|*******|
|***r***|
|*******|
| ***** |
|  ***  |
|-------| 
```


```text
xs,ys x0,y0
I----I----|
|    *    |
|   * *   |
|  * * *  |
| * * * * |
|* * * * *|
I---------I
x1,y1     x2,y2
```

## Launching the program

The program is run in the terminal of the Linux enviroment.

**Usage:**
`./program [OPTION] ... [FILE] ...`

**Examples:**
`./drawingTGA p1 p1Value p2 p2Value p3 p3Value p4 p4Value`


The position of the parameters and their values can be freely arranged. 
In addition to the parameters for drawing shapes (-r, -c, -t). 
These must be at the end after the main ones.

**Examples of use**
1. Drawing shapes from CLI
`./drawingTGA -o FILE -w Pix -h Pix -r VALUE -t VALUE`

2. Drawing shapes from file
`./drawingTGA -o FILE -f FILE -w Pix -h Pix`