#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>
int main(int argc, char **argv){
    uint32_t a,b, result;
    if(argc!=3){
        printf("Usage: ./add-nbo <bin 1> <bin 2>\n");
        exit(0);
    }
    FILE* file=fopen(argv[1],"rb");
    if(file==NULL){
        printf("cannot open file %s\n",argv[1]);
        exit(0);
    }
    fread(&a, sizeof(a),1,file);
    fclose(file);

    file=fopen(argv[2],"rb");
    if(file==NULL){
        printf("cannot open file %s\n",argv[2]);
        exit(0);
    }
    fread(&b, sizeof(b),1,file);
    fclose(file);
    a=ntohl(a);
    b=ntohl(b);
    result=a+b;
    printf("%d(%#x) + %d(%#x) = %d(%#x)\n",a,a,b,b,result,result);
    return 0;
}