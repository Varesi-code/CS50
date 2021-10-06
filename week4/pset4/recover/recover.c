#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image.\n");
        return 1;
    }

    else
    {
        //open file
        char *filename = argv[1];
        FILE *file = fopen(filename, "r");
        if (file == NULL)
        {
            printf("Cannot open %s.\n", filename);
            return 2;
        }

        //declare buffer for temporary storage
        BYTE bytes[512];

        //declare output file
        FILE *JPG = NULL;

        //set counter
        int jpgcount = 0;

        //declare filename
        char jpgname[8];

        //read file
        while (fread(&bytes, 512, 1, file) == 1)
        {
            if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
            {
                //if it is not the 1st, close previous so one new can start
                if (!(jpgcount == 0))
                {
                    fclose(JPG);
                }

                //initialise
                sprintf(jpgname, "%03i.jpg", jpgcount);
                JPG = fopen(jpgname, "w");
                jpgcount++;

                //printf("processing file: %s\n", jpgname);
            }

            //if found, write to file
            if (!(jpgcount == 0))
            {
                fwrite(&bytes, 512, 1, JPG);
            }
        }
        fclose(file);
        fclose(JPG);

        return 0;
    }
}
