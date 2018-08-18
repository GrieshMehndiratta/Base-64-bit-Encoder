#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    const char arr[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    char str[100];
    printf("Enter the string you want to encode : ");
    gets(str);
    int inlen= strlen(str);
    int outlen= 4*((inlen+2)/3);
    int j=0;
    char* result= malloc(outlen);
    for(int i= 0; i< inlen; )
    {
        int n= i<inlen? str[i++]<<16 : 0;
        n+= i<inlen? str[i++]<<8 : 0;
        n+= i<inlen? str[i++] : 0;
        int n3= n&63;
        int n2= (n>>6)&63;
        int n1= (n>>12)&63;
        int n0= (n>>18)&63;

        result[j++]=arr[n0];
        result[j++]=arr[n1];
        result[j++]=arr[n2];
        result[j++]=arr[n3];
    }
    result[j]=0;
    int pad= inlen%3;
    if(pad> 0)
    {
        for( ; pad<3; pad++)
        {
            result[--j]='=';
        }
    }
    printf("\nEncoded output...\n\n");
    printf("%s",result);
    return 0;
}
