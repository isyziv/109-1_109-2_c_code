/* This program reads a bitmap image file. It converts a
   colored bitmap image to a four-color filter banded bitmap image.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct BitmapHeader {
  char		Type[2];
  unsigned	Size;
  char		Reserved[4];
  unsigned	OffsetBits;
  unsigned    InfoSize;
  unsigned    Width;
  unsigned    Height;
  short unsigned	Planes;
  short unsigned	BitPerPixel;
  unsigned    Compression;
  unsigned    ImageSize;
  unsigned    XResolution;
  unsigned    YResolution;
  unsigned    Colors;
  unsigned    ImportantColors;
} Header;

int main(int argc, char *argv[]) {
  FILE *fptr;
  Header	header;
  unsigned char	*palette;
  unsigned char	*imageData;
  int i, j, k, fillings, rowSize;
  int firstFilter, filter, bandwidth, weight;
  

  if (argc==1) {
    printf("Please enter the image file name.\n");
    system("pause");
    return 1;
  }
  else if (argc>3) {
    printf("Too many image file names entered.\n");
    system("pause");
    return 1;
  }

  fptr = fopen(argv[1], "rb");
  if (fptr==NULL) {
    printf("File %s does not exist.\n", argv[1]);
    system("pause");
    return 1;
  }  

 /* Input the colored image file. */
  fread(&header.Type, 1, 2, fptr);
  fread(&header.Size, 4, 1, fptr);
  fread(&header.Reserved, 1, 4, fptr);	
  fread(&header.OffsetBits, 4, 1, fptr);
  fread(&header.InfoSize, 4, 1, fptr);
  fread(&header.Width, 4, 1, fptr);
  fread(&header.Height, 4, 1, fptr);
  fread(&header.Planes, 2, 1, fptr);
  fread(&header.BitPerPixel, 2, 1, fptr);
  fread(&header.Compression, 4, 1, fptr);
  fread(&header.ImageSize, 4, 1, fptr);
  fread(&header.XResolution, 4, 1, fptr);
  fread(&header.YResolution, 4, 1, fptr);
  fread(&header.Colors, 4, 1, fptr);
  fread(&header.ImportantColors, 4, 1, fptr);

/*===================================================================*/
/* For every entry in the palette, four bytes are used to describe   */
/* the RGB values of the color in the following way:                 */
/*   1 byte for blue component                                       */
/*   1 byte for green component                                      */
/*   1 byte for red component                                        */
/*   1 byte filter which is set to 0 (zero)                          */
/* Constant 14 is the lenght of the file header.                     */
/*===================================================================*/
  palette = (unsigned char *) malloc(header.OffsetBits - header.InfoSize - 14);
  fread(palette, header.OffsetBits - header.InfoSize - 14, 1, fptr);

/*===================================================================*/
/* The image pixels are stored in the row major order from left      */
/* to right and from bottom to top. That is, the last row from the   */
/* top is stored at the beginning of the data area and the first row */
/* from the top is stored at the end of the data area. Each pixel is */
/* represendted in three bytes as its RGB values. The RGB values are */
/* stored in the order of Blue, Green, and Red starting from the     */
/* first byte.                                                       */
/* The total number of bytes for the pixels in a row must be a       */
/* multiple of four. If the total number is not a multiple of four,  */
/* the trailing bytes are padded by zeros (hexdecimal).              */
/* ==================================================================*/
  imageData = (unsigned char *) malloc(header.ImageSize);
  fread(imageData, header.ImageSize, 1, fptr);
	
  fclose(fptr);
  
  // Select the stating filter.
  do {
    printf("Select the starting filter (0: gray-level, 1: blue, 2: green, 3: red): ");
    scanf("%u", &firstFilter);
  } while (firstFilter>3);  
  printf("\n");
  
  // Set the bandwdth.
  do {
    printf("Enter the bandwidth (between 0 and %d): ", header.Width);
    scanf("%u", &bandwidth);
  } while (bandwidth>header.Width);  
  printf("\n");
  
  // Set the weight of the filtering effect.
  do {
    printf("Enter the filter weight(between 0 and 255): ");
    scanf("%u", &weight);
  } while (weight>255);  
  printf("\n");

  fillings = (4 - (header.Width * 3) % 4) % 4; // The number of filling bytes at the end of a row.
  rowSize = header.Width * 3 + fillings; // The number of bytes in a row.
  for (i = 0; i < header.Height; i++) { // Go through all rows.
    for (j = 0; j < header.Width; j++) { // Go through all pixels in row i.
      k = i * rowSize + j * 3; // The starting index in imageData of the pixel to be transformed.
      filter = (j / bandwidth + firstFilter) % 4; // Calculate the filter for the transformed pixel.
      switch (filter) {
        case 0: { // gray-level filter
          if (weight!=0) {
            imageData[k] = (imageData[k] * weight * 20 + imageData[k+1] * weight * 50 + 
                            imageData[k+2] * weight * 30) / (weight * 100);
            imageData[k+1] = imageData[k];
            imageData[k+2] = imageData[k];
          }
          break;
        }
        case 1: { // blue-colored filter
          imageData[k] = imageData[k] < 255 - weight ? imageData[k] + weight : weight;
          break;
        }
        case 2: { // green-colored filter
          imageData[k+1] = imageData[k+1] < 255 - weight ? imageData[k+1] + weight : weight;
          break;
        }
        case 3: { // red-colored filter
          imageData[k+2] = imageData[k+2] < 255 - weight ? imageData[k+2] + weight : weight;
          break;
        }
      }
    }
  }
  
  /* Output to the band filtered image. */
  if (argc==3) {
    fptr = fopen(argv[2], "wb");
    printf("\nThe band filtered image is \"%s\".\n\n", argv[2]);
  } 
  else {
    fptr = fopen("banded_filter.bmp", "wb");
    printf("\nThe banded-filtered image is \"banded-filter.bmp\".\n\n");
  }  
  fwrite(&header.Type, 1, 2, fptr);
  fwrite(&header.Size, 4, 1, fptr);
  fwrite(&header.Reserved, 1, 4, fptr);	
  fwrite(&header.OffsetBits, 4, 1, fptr);
  fwrite(&header.InfoSize, 4, 1, fptr);
  fwrite(&header.Width, 4, 1, fptr);
  fwrite(&header.Height, 4, 1, fptr);
  fwrite(&header.Planes, 2, 1, fptr);
  fwrite(&header.BitPerPixel, 2, 1, fptr);
  fwrite(&header.Compression, 4, 1, fptr);
  fwrite(&header.ImageSize, 4, 1, fptr);
  fwrite(&header.XResolution, 4, 1, fptr);
  fwrite(&header.YResolution, 4, 1, fptr);
  fwrite(&header.Colors, 4, 1, fptr);
  fwrite(&header.ImportantColors, 4, 1, fptr);
  fwrite(palette, 1, header.OffsetBits - header.InfoSize - 14, fptr);
  fwrite(imageData, 1, header.ImageSize, fptr);

  fclose(fptr);
 
  printf("Type:             %c%c\n", header.Type[0], header.Type[1]);
  printf("Size:             %u\n", header.Size);
  printf("Resserved:        %c%c%c%c\n", header.Reserved[0], header.Reserved[1], 
                                         header.Reserved[2], header.Reserved[3]);
  printf("OffsetBits:       %u\n", header.OffsetBits);
  printf("InfoSize:         %u\n", header.InfoSize);
  printf("Width:            %u\n", header.Width);
  printf("Height:           %u\n", header.Height);
  printf("Planes:           %d\n", header.Planes);
  printf("BitPerPixel:      %d\n", header.BitPerPixel);
  printf("Compression:      %u\n", header.Compression);
  printf("ImageSize:        %u\n", header.ImageSize);
  printf("XResolution:      %u\n", header.XResolution);
  printf("YResolution:      %u\n", header.YResolution);
  printf("Colors:           %u\n", header.Colors);
  printf("ImportantColors:  %u\n", header.ImportantColors);
/* End of output commands */

  free(palette);
  free(imageData);
  system("pause");
  return 0;
}
