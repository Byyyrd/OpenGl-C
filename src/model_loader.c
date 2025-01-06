#include "model_loader.h"
//Count number of Lines with the leading char type
//Expects opened FilePtr and rewinds file after use
int countLines(FILE *fptr,char type){
    int count = 0;
    char content[100];
    if(fptr != NULL) {
        while(fgets(content,100,fptr)){
            if(content[0] == type && content[1] == ' '){
                count++;
            }
        }
        rewind(fptr);
    } else {
        printf("Not able to open the file.\n");
    }
    return count;  
}


//Path Relative to src/resources/
Model loadFromFile(char *source){
    FILE *fptr;
    
    char *absolutePath;
    asprintf(&absolutePath,"/home/julius/projects/c/open_gl_start/src/resources/%s",source);
    fptr = fopen(absolutePath, "r");
    
    //find out file lenght
    //fseek(fptr, 0L, SEEK_END);
    //long size = ftell(fptr);
    //Go Back to File start
    //rewind(fptr);

    //create array for line
    char content[100];
    
    //Start reading when file could be opened
    if(fptr != NULL) {
        int verticesCount = countLines(fptr,'v');
        float vertices[verticesCount * 3];
        int indicesCount = countLines(fptr,'f');
        GLuint indices[indicesCount * 3];
        int vertexIndex = 0;
        int indicesIndex = 0;
        while(fgets(content,100,fptr)){
            if(content[0] == 'v' && content[1] == ' '){
                int i = 0,j = 0;
                int valueCount = 0;
                char newFloat[9];
                while (valueCount < 3)
                {
                    //+2 to skip the identifing char and first empty space
                    char ch = content[i + 2];
                    if(ch == ' ' || ch == '\n'){
                        float value = atof(newFloat);
                        vertices[vertexIndex] = value;
                        vertexIndex++;
                        valueCount++;
                        j = -1;
                    }else{
                        newFloat[j] = ch;
                    }
                    i++;
                    j++;
                }
                
            }else if(content[0] == 'f' && content[1] == ' '){
                int i = 0,k = 0;
                int valueCount = 0;
                char newInt[9];
                while (valueCount < 3)
                {
                    //+2 to skip the identifing char and first empty space
                    char ch = content[i + 2];
                    if(ch == ' ' || ch == '\n'){
                        int indexLenght = 0;
                        while(newInt[indexLenght] != '/'){
                            indexLenght++;
                        }
                        char index[indexLenght];
                        for(int j = 0; j<indexLenght;j++){
                            index[j] = newInt[j];
                        }
                        c_printArray(index,indexLenght);
                        int value = atoi((const char*)index);
                        indices[indicesIndex] = (GLuint) value;
                        indicesIndex++;
                        valueCount++;
                        k = -1;
                    }else{
                        newInt[k] = ch;
                    }
                    i++;
                    k++;
                }
            }

        }
        Model model;
        model.vertices =(float *) vertices;
        model.verticesCount = verticesCount * 3;
        model.indices = (GLuint *)indices;
        model.indicesCount = indicesCount * 3;
        return model;
    } else {
        printf("Not able to open the file.\n");
    }   
    // Close the file
    fclose(fptr);
    
    Model model;
    return model;
}