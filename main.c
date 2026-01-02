#include <stdio.h>
#include <stdlib.h>

#ifndef _WIN32
#include <sys/types.h>
#endif

#ifdef _WIN32
typedef long ssize_t;
#endif


typedef struct {
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void read_input(InputBuffer* input_buffer){

    ssize_t bytes_read = getline(&(input_buffer->buffer),&(input_buffer->buffer_length), stdin);

    if(bytes_read <= 0){
    
        printf("Error reading input\n");
        exit(EXIT_FAILURE);

    }

    input_buffer->input_length = bytes_read-1;
    input_buffer->buffer[bytes_read-1] = 0;

}



InputBuffer* new_input_buffer()
{

    InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    input_buffer -> buffer = NULL;
    input_buffer -> buffer_length = 0;
    input_buffer -> input_length = 0;
    return input_buffer;
}

int main()
{

}