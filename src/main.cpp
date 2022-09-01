/* Includes ------------------------------------------------------------------*/
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include "imagedata.h"
#include <stdlib.h>

/* Entry point ----------------------------------------------------------------*/
void setup()
{
    printf("EPD_2IN13B_V4_test Demo\r\n");
    DEV_Module_Init();

    printf("e-Paper Init and Clear...\r\n");
    EPD_2IN13B_V4_Init();
    EPD_2IN13B_V4_Clear();
    DEV_Delay_ms(500);

    //Create a new image cache named IMAGE_BW and fill it with white
    UBYTE *BlackImage, *RYImage; // Red or Yellow
    UWORD Imagesize = ((EPD_2IN13B_V4_WIDTH % 8 == 0) ? (EPD_2IN13B_V4_WIDTH / 8 ) : (EPD_2IN13B_V4_WIDTH / 8 + 1)) * EPD_2IN13B_V4_HEIGHT;
    if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        while (1);
    }
    if ((RYImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for red memory...\r\n");
        while (1);
    }
    printf("NewImage:BlackImage and RYImage\r\n");
    Paint_NewImage(BlackImage, EPD_2IN13B_V4_WIDTH, EPD_2IN13B_V4_HEIGHT, 270, WHITE);
    Paint_NewImage(RYImage, EPD_2IN13B_V4_WIDTH, EPD_2IN13B_V4_HEIGHT, 270, WHITE);

    //Select Image
//    Paint_SelectImage(BlackImage);
//    Paint_Clear(WHITE);
//    Paint_SelectImage(RYImage);
//    Paint_Clear(WHITE);


    /*Horizontal screen*/
    //1.Draw black image
    printf("Draw black image\r\n");
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);
    Paint_DrawString_CN(5, 15, "你好aaaAAAA", &Font12CN, WHITE, BLACK);
    printf("EPD_Display\r\n");
    EPD_2IN13B_V4_Display(BlackImage, RYImage);
    DEV_Delay_ms(5000);

    printf("Clear...\r\n");
    EPD_2IN13B_V4_Clear();

    printf("Goto Sleep...\r\n");
    EPD_2IN13B_V4_Sleep();
    free(BlackImage);
    free(RYImage);
    BlackImage = NULL;
    RYImage = NULL;


}

/* The main loop -------------------------------------------------------------*/
void loop()
{
    //
}
