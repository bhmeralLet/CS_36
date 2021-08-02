#include <stdio.h>

int main(){

    FILE* userFile;
    char fileName[25];
    char line[80];
    while(1){
        printf("Enter the name of file name including .txt at the end\n");
        scanf_s(" %s",fileName,25);
        if((userFile = fopen(fileName,"w")) == NULL){
            printf("File cannot be opened.");
            break;
        }else{
            printf("Enter what you want to write to text file");
            scanf("%s",line);
            fprintf(userFile,"%s", line);
            puts(line);
            if(line[0] == '0'){
                fclose(userFile);
                break;
            }
        }
    }


}