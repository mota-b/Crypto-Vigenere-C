#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Moukhtar-lib/chrypto.h"

int cycle ;
int counter = 0;


/* Open and work in a file */
void open_file(FILE* file_src,int argc,char *argv[]);

/*Main Class*/
int main(int argc,char *argv[]) {


    if (argc != 5){
        printf("Syntax ERROR \n\n"
                           "Ex : ./code [option -p/-c] [Key<String>] src.txt dest.txt\n\n");

        return -1;
    }
    else{
        cycle = strlen(argv[2]);

        //Open file with r/w right]
        FILE *file_src = NULL;
        open_file(file_src,argc,argv);

        char a[8+strlen(argv[4])];
        strcpy(a,"gedit ");
        strcat(a,argv[4]);
        strcat(a," &");
        system(a);


        return 0;
    }


}

/* Open and work in a file */
void open_file(FILE* file_src,int argc,char *argv[]){

    // Write in the plain texte
    char a[8+strlen(argv[4])];
    strcpy(a,"gedit ");
    strcat(a,argv[3]);
    system(a);

    char buffer ;
    file_src = fopen(argv[3],"r+");

    // Test if the file is opened
    if (file_src != NULL) {
        printf("Opened : %s\n",argv[3]);
        buffer = (char)fgetc(file_src);

        // Test if the file is not empty
        if(buffer != EOF) {

            // Declarate and open File Dest
            FILE *file_dest = NULL;
            file_dest = fopen(argv[4], "w");


            // Read from file1 ---> chrypte/de-Chrypte ---> Write in file2
            if (strcmp(argv[1],"-c") == 0) {

                do {


                  //fputc(sezar_chrypt(buffer, cnvrt_alpha_key(argv[2])), file_dest);

                    fputc(sezar_chrypt(buffer, cnvrt_alpha_key(argv[2][counter % cycle])), file_dest);
                    printf("Cycle = %d , Counter = %d , count MOD cycle = %d--------> argv[2][count MOD cycle] = %c \n",cycle,counter,counter%cycle,argv[2][counter%cycle]);
                    if ( (buffer >= 'A'  && buffer <= 'Z') || (buffer >= 'a'  && buffer <= 'z') )
                        counter ++;
                    buffer = (char) fgetc(file_src);
                } while (buffer != EOF);
            }
            else if (strcmp(argv[1],"-p") == 0) {
                do {

                    //fputc(sezar_de_chrypt(buffer,cnvrt_alpha_key(argv[2]) ),file_dest);
                    fputc(sezar_de_chrypt(buffer,cnvrt_alpha_key(argv[2][counter % cycle])), file_dest);
                    if ( (buffer >= 'A'  && buffer <= 'Z') || (buffer >= 'a'  && buffer <= 'z') )
                        counter++;
                    buffer = (char)fgetc(file_src);
                } while (buffer != EOF);
            }
            else
                printf(" Not expected option \n");
        }
        else
            printf("Empty file \n");


        fclose(file_src);
        printf("Closed : %s\n",argv[3]);

    }

}

