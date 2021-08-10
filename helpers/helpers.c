#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    float x;
    for(int i = 0;i<height;i++){
        for(int j = 0;j<width;j++){
        x = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) ;
        avg = roundf(x/3);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;

        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    float sepiaRed;
    float sepiaGreen;
    float sepiaBlue;
    float x ,y , z;
    for(int i = 0;i<height;i++){
        for(int j = 0;j<width;j++){
            x = image[i][j].rgbtRed;
            y = image[i][j].rgbtGreen;
            z = image[i][j].rgbtBlue;
            sepiaRed = 0.393*x + 0.769*y + 0.189*z;
            sepiaGreen = 0.349*x + 0.686*y + 0.168*z;
            sepiaBlue = 0.272*x + 0.534*y + 0.131*z;

            if(sepiaRed > 255){
                image[i][j].rgbtRed = 255;

            }
            else{
                image[i][j].rgbtRed = roundf(sepiaRed);

            }

            if(sepiaGreen > 255){
                image[i][j].rgbtGreen = 255;

            }
            else{
                image[i][j].rgbtGreen = roundf(sepiaGreen);

            }

            if(sepiaBlue > 255){
                image[i][j].rgbtBlue = 255;

            }else{
                image[i][j].rgbtBlue = roundf(sepiaBlue);

            }


        }
    }


}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp;
    for(int i = 0;i<height;i++){
        for(int j = 0;j<width/2;j++){
            tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image2[height][width];
    float avgr,avgg,avgb;
    float sumr,sumg,sumb;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            // top left corner (done)
            if(i == 0 && j == 0){
                sumr = image[i][j].rgbtRed +   image[i+1][j].rgbtRed +   image[i][j+1].rgbtRed +   image[i+1][j+1].rgbtRed;
                sumg = image[i][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j+1].rgbtGreen;
                sumb = image[i][j].rgbtBlue +  image[i+1][j].rgbtBlue +  image[i][j+1].rgbtBlue +  image[i+1][j+1].rgbtBlue;

                avgr = sumr/4;
                avgg = sumg/4;
                avgb = sumb/4;

            }
            // bottom left corner (done)
            else if(i == height-1 && j == 0){
                sumr = image[i][j].rgbtRed +   image[i-1][j].rgbtRed +   image[i][j+1].rgbtRed +   image[i-1][j+1].rgbtRed;
                sumg = image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j+1].rgbtGreen;
                sumb = image[i][j].rgbtBlue +  image[i-1][j].rgbtBlue +  image[i][j+1].rgbtBlue +  image[i-1][j+1].rgbtBlue;

                avgr = sumr/4;
                avgg = sumg/4;
                avgb = sumb/4;
            }
            // top right corner (done)
            else if(i == 0 && j == width-1){
                sumr = image[i][j].rgbtRed +   image[i+1][j].rgbtRed +   image[i][j-1].rgbtRed +   image[i+1][j-1].rgbtRed;
                sumg = image[i][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i+1][j-1].rgbtGreen;
                sumb = image[i][j].rgbtBlue +  image[i+1][j].rgbtBlue +  image[i][j-1].rgbtBlue +  image[i+1][j-1].rgbtBlue;

                avgr = sumr/4;
                avgg = sumg/4;
                avgb = sumb/4;
            }
            // bottom right corner (done)
            else if(i == height-1 && j == width-1){
                sumr = image[i][j].rgbtRed +   image[i-1][j].rgbtRed +   image[i][j-1].rgbtRed +   image[i-1][j-1].rgbtRed;
                sumg = image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j-1].rgbtGreen;
                sumb = image[i][j].rgbtBlue +  image[i-1][j].rgbtBlue +  image[i][j-1].rgbtBlue +  image[i-1][j-1].rgbtBlue;

                avgr = sumr/4;
                avgg = sumg/4;
                avgb = sumb/4;
            }
            // top edge (done)
            else if(i == 0){
                sumr = image[i][j].rgbtRed +   image[i][j-1].rgbtRed +   image[i][j+1].rgbtRed +   image[i+1][j].rgbtRed +    image[i+1][j-1].rgbtRed +   image[i+1][j+1].rgbtRed ;
                sumg = image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen +  image[i+1][j-1].rgbtGreen + image[i+1][j+1].rgbtGreen ;

                sumb = image[i][j].rgbtBlue +  image[i][j-1].rgbtBlue +  image[i][j+1].rgbtBlue +  image[i+1][j].rgbtBlue +   image[i+1][j-1].rgbtBlue +  image[i+1][j+1].rgbtBlue ;

                avgr = sumr/6;
                avgg = sumg/6;
                avgb = sumb/6;
            }
            // bottom edge (done)
            else if(i == height-1){
                sumr = image[i][j].rgbtRed +   image[i][j-1].rgbtRed +   image[i][j+1].rgbtRed +   image[i-1][j].rgbtRed +    image[i-1][j-1].rgbtRed +   image[i-1][j+1].rgbtRed ;
                sumg = image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j].rgbtGreen +  image[i-1][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen ;
                sumb = image[i][j].rgbtBlue +  image[i][j-1].rgbtBlue +  image[i][j+1].rgbtBlue +  image[i-1][j].rgbtBlue +   image[i-1][j-1].rgbtBlue +  image[i-1][j+1].rgbtBlue ;

                avgr = sumr/6;
                avgg = sumg/6;
                avgb = sumb/6;
            }
            // left edge (done)
            else if(j == 0) {
                sumr = image[i][j].rgbtRed +   image[i][j+1].rgbtRed +   image[i-1][j].rgbtRed +   image[i-1][j+1].rgbtRed +    image[i+1][j].rgbtRed +   image[i+1][j+1].rgbtRed ;
                sumg = image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen +  image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen ;
                sumb = image[i][j].rgbtBlue +  image[i][j+1].rgbtBlue +  image[i-1][j].rgbtBlue +  image[i-1][j+1].rgbtBlue +   image[i+1][j].rgbtBlue +  image[i+1][j+1].rgbtBlue ;

                avgr = sumr/6;
                avgg = sumg/6;
                avgb = sumb/6;
            }
            // rigth edge (done)
            else if(j == width-1){
                sumr = image[i][j].rgbtRed +   image[i][j-1].rgbtRed +   image[i-1][j].rgbtRed +   image[i-1][j-1].rgbtRed +    image[i+1][j].rgbtRed +   image[i+1][j-1].rgbtRed ;
                sumg = image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen +  image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen ;
                sumb = image[i][j].rgbtBlue +  image[i][j-1].rgbtBlue +  image[i-1][j].rgbtBlue +  image[i-1][j-1].rgbtBlue +   image[i+1][j].rgbtBlue +  image[i+1][j-1].rgbtBlue ;

                avgr = sumr/6;
                avgg = sumg/6;
                avgb = sumb/6;
            }
            // the rest of the photo
            else {
                sumr = image[i][j].rgbtRed +   image[i][j-1].rgbtRed +   image[i][j+1].rgbtRed +   image[i-1][j].rgbtRed +    image[i-1][j-1].rgbtRed +   image[i-1][j+1].rgbtRed +   image[i+1][j].rgbtRed +    image[i+1][j-1].rgbtRed +   image[i+1][j+1].rgbtRed ;
                sumg = image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j].rgbtGreen +  image[i-1][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i+1][j].rgbtGreen +  image[i+1][j-1].rgbtGreen + image[i+1][j+1].rgbtGreen ;
                sumb = image[i][j].rgbtBlue +  image[i][j-1].rgbtBlue +  image[i][j+1].rgbtBlue +  image[i-1][j].rgbtBlue +   image[i-1][j-1].rgbtBlue +  image[i-1][j+1].rgbtBlue + image[i+1][j].rgbtBlue +    image[i+1][j-1].rgbtBlue +  image[i+1][j+1].rgbtBlue ;

                avgr = sumr/9;
                avgg = sumg/9;
                avgb = sumb/9;
            }
            image2[i][j].rgbtRed=roundf(avgr);
            image2[i][j].rgbtGreen=roundf(avgg);
            image2[i][j].rgbtBlue=roundf(avgb);        
        }
    }
    
    for(int i =0;i<height;i++){
        for(int j =0;j<width;j++){
            image[i][j] = image2[i][j];
        }
        
    }
}

