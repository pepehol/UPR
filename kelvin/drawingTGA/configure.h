#ifndef _CONFIGURE_H_
#define _CONFIGURE_H_

#define PARAM_IN_FILE "-f"
#define PARAM_OUT_FILE "-o"
#define PARAM_WIDTH_PIC "-w"
#define PARAM_HEIGHT_PIC "-h"

#define TGA_EXTENSIONS ".tga"

#define PARAM_RECTANGLE "-r"
#define PARAM_RECTANGLE_NUM 8

#define PARAM_CIRCLE "-c"
#define PARAM_CIRCLE_NUM 7

#define PARAM_TRIANGLE "-t"
#define PARAM_TRIANGLE_NUM 7

#define ASCI_NUL 0
#define ASCI_NEW_LINE 10
#define ASCI_SPACE 32
#define ASCI_ZERO 48
#define ASCI_NINE 57
#define ASCI_MINUS 45

#define REQUIRED_NUM_PARAMS 9
#define CONF_PARAMS 7

#define ERROR_INPUT "Error input parameter. Check README file.\n"
#define ERROR_MISS_MAIN_PAR "The main parameters are missing. Check README file.\n"
#define ERROR_DUPLICATE "Error duplicate parameter. Check README file.\n"
#define ERROR_PARAM_O "Problem with -o parameter. Check README file.\n"
#define ERROR_PARAM_W "Problem with -w parameter. Check README file.\n"
#define ERROR_PARAM_H "Problem with -h parameter. Check README file.\n"
#define ERROR_WRONG_CONF_REC "Wrong assignment for the rectangle. Check README file.\n"
#define ERROR_WRONG_CONF_CIR "Wrong assignment for the circle. Check README file.\n"
#define ERROR_WRONG_CONF_TRIA "Wrong assignment for the triangle. Check README file.\n"
#define ERROR_OFF_COORD_REC "Off-coordinate rectangle.\n"
#define ERROR_OFF_COORD_CIR "Off-coordinate circle.\n"
#define ERROR_OFF_COORD_TRIA "Off-coordinate triangle.\n"
#define ERROR_RGBA_REC "Wrong color format for the rectangle.\n"
#define ERROR_RGBA_CIR "Wrong color format for the circle.\n"
#define ERROR_RGBA_TRIA "Wrong color format for the triangle.\n"


#define COLOR_DEPTH 255


#endif
