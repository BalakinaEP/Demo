#include <stdio.h>
#include <string.h>

int main()
{
    char* str;
    fgets(str,10,stdin);
    /*int number = 0;
    scanf("%d",&number);*/
    char otherstr[20];
    strcpy(otherstr,"Hello world");
    int lenght = strlen(str);
    printf("%s\n",str);
    printf("%s\n",otherstr);
    printf("%d\n",lenght);

    return 0;
}
