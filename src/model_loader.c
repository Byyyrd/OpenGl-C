#include "model_loader.h"
//Count number of Lines with the leading 2 chars
//Expects opened FilePtr and rewinds file after use
int countLines(FILE *fptr,char c1,char c2){
    int count = 0;
    char content[100];
    if(fptr != NULL) {
        while(fgets(content,100,fptr)){
            if(content[0] == c1 && content[1] == c2){
                count++;
            }
        }
        rewind(fptr);
    } else {
        printf("Not able to open the file.\n");
    }
    return count;  
}

void loadVerticesFromLine(char line[],float *vertices,int *verticesIndex){
    int i = 0,j = 0;
    int valueCount = 0;
    char newFloat[9];
    while (valueCount < 3)
    {
        //+2 to skip the identifing char and first empty space
        char ch = line[i + 2];
        if(ch == ' ' || ch == '\n'){
            const char* arr = newFloat;
            float value = atof(arr);
            vertices[*verticesIndex] = value;
            (*verticesIndex)++;
            valueCount++;
            j = -1;
        }else{
            newFloat[j] = ch;
        }
        i++;
        j++;
    }
}
void loadIndicesFromLine(char line[],GLuint *indices,int *indicesIndex){
    //i = 2 to skip the identifing char and first empty space
    int i = 2,j = 0;
    int valueCount = 0;
    char newInt[4];
    while (valueCount < 3){
        char ch = line[i];
        if(ch == ' ' || ch == '\n' || ch == '/'){
            newInt[j] = '\0';
            char* arr = malloc((j+1)*sizeof(char));
            strcpy(arr,newInt);
            const char* vArray = arr;
            //-1, because Obj starts at one and OpenGl at 0
            int value = atoi(vArray) - 1;
            free(arr);
            indices[*indicesIndex] = (unsigned int)value;
            (*indicesIndex)++;
            valueCount++;
            j = -1;
            // if(valueCount == 3){
            //     //skip to one space before normals value (i++ at the end)
            //     while(line[i + 1] == '/'){
            //         i++;
            //     }
            // }else{
                //skip to one space before next Index Value (i++ at the end)
                while(line[i] != ' '){
                    i++;
                }
            //}
            
            
        }else{
            newInt[j] = ch;
        }                 
        i++;
        j++;
    }
}
void loadNormalsFromLine(char line[],float *normals,int *normalsIndex){
    // i = 3 to skip the 2 identifing chars and first empty space
    int i = 3,j = 0;
    int valueCount = 0;
    char newFloat[7];
    while (valueCount < 3)
    {
        char ch = line[i];
        if(ch == ' ' || ch == '\n'){
            const char* arr = newFloat;
            float value = atof(arr);
            normals[*normalsIndex] = value;
            (*normalsIndex)++;
            valueCount++;
            j = -1;
        }else{
            newFloat[j] = ch;
        }
        i++;
        j++;
    }
}


//Including Normals
Model loadFromFile(char *source){
    FILE *fptr;
    
    char *absolutePath;
    asprintf(&absolutePath,"/home/julius/projects/c/open_gl_start/src/resources/%s",source);
    fptr = fopen(absolutePath, "r");
    //create array for line
    char content[100];
    
    //Start reading when file could be opened
    if(fptr != NULL) {
        int verticesCount = countLines(fptr,'v',' ') * 3;
        float *vertices = malloc(verticesCount * sizeof(float));
        int verticesIndex = 0;

        int indicesCount = countLines(fptr,'f',' ') * 4;
        GLuint *indices = malloc(indicesCount * sizeof(GLuint));
        int indicesIndex = 0;

        int normalsCount = countLines(fptr,'v','n') * 3;
        float *normals = malloc(normalsCount * sizeof(float));
        int normalsIndex = 0;
        while(fgets(content,100,fptr)){
            if(content[0] == 'v' && content[1] == ' '){
                loadVerticesFromLine(content,vertices,&verticesIndex);
            }else if(content[0] == 'f' && content[1] == ' '){
                loadIndicesFromLine(content,indices,&indicesIndex);
            }else if(content[0] == 'v' && content[1] == 'n'){
                loadNormalsFromLine(content,normals,&normalsIndex);
            }

        }
        Model model;
        model.vertices = vertices;
        model.verticesSize = verticesCount * sizeof(float);
        model.indices = indices;
        model.indicesSize = indicesCount * sizeof(GLuint);
        model.normals = normals;
        model.normalsSize = normalsCount * sizeof(float);
        
        return model;
    } else {
        printf("Not able to open the file.\n");
    }   
    // Close the file
    fclose(fptr);
    
    Model model;
    return model;
}
Model loadFromFile_raw(char *source){
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
        int verticesCount = countLines(fptr,'v',' ') * 3;
        float *vertices = malloc(verticesCount * sizeof(float));
        int indicesCount = countLines(fptr,'f',' ') * 3;
        GLuint *indices = malloc(indicesCount * sizeof(GLuint));
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
                        const char* arr = newFloat;
                        float value = atof(arr);
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
                int i = 0,j = 0;
                int valueCount = 0;
                char newInt[4];
                while (valueCount < 3)
                {
                    //+2 to skip the identifing char and first empty space
                    char ch = content[i + 2];
                    if(ch == ' ' || ch == '\n'){
                        newInt[j] = '\0';
                        char* arr = malloc((j+1)*sizeof(char));
                        strcpy(arr,newInt);
                        const char* vArray = arr;
                        //-1, because Obj starts at one and OpenGl at 0
                        int value = atoi(vArray) - 1;
                        free(arr);
                        indices[indicesIndex] = (unsigned int)value;
                        indicesIndex++;
                        valueCount++;
                        j = -1;
                    }else{
                        newInt[j] = ch;
                    }
                    i++;
                    j++;
                }
            }

        }
        Model model;
        model.vertices = vertices;
        model.verticesSize = verticesCount * sizeof(float);
        model.indices = indices;
        model.indicesSize = indicesCount * sizeof(GLuint);
        return model;
    } else {
        printf("Not able to open the file.\n");
    }   
    // Close the file
    fclose(fptr);
    
    Model model;
    return model;
}
//Path Relative to src/resources/
Model loadFromFile_uv(char *source){
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
        int verticesCount = countLines(fptr,'v',' ') * 3;
        float *vertices = malloc(verticesCount * sizeof(float));
        int indicesCount = countLines(fptr,'f',' ') * 3;
        GLuint *indices = malloc(indicesCount * sizeof(GLuint));
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
                        //-1, because Obj starts at one and OpenGl at 0
                        int value = atoi((const char*)index) - 1;
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
        model.vertices = vertices;
        model.verticesSize = verticesCount * sizeof(float);
        model.indices = indices;
        model.indicesSize = indicesCount * sizeof(GLuint);
        return model;
    } else {
        printf("Not able to open the file.\n");
    }   
    // Close the file
    fclose(fptr);
    
    Model model;
    return model;
}