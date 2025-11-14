#include <stdio.h>
#include <stddef.h> //NULL
#include <string.h> //memset()
#include <stdlib.h> //malloc()

#define new(type, fpinit) *(type*)(InitStruct(sizeof(type), fpinit))

void* InitStruct(int nsize, void (*fpinit)(void*))
{
    void* pstruct = malloc(nsize);
    
    if (fpinit != NULL)
    {
        fpinit(pstruct);
    }
    else
    {
        memset(pstruct, 0, nsize);
    }
    
    return pstruct;
}

//
typedef struct {} TYPE, *PTYPE;
//

void InitTemp(void* pstruct)
{
    PTYPE ptype = (PTYPE)pstruct;
    
    //Initialize struct
}


//使用例
typedef struct
{
    char* teststr;
    int testnum;
} TEST, *PTEST;

void InitTest(void* pstruct)
{
    PTEST ptest = (PTEST)pstruct;
    TEST test = *ptest;
    
    ptest -> teststr = "Hello world!";
    ptest -> testnum = 114514;
}

int main()
{
    TEST test = new(TEST, InitTest);
    printf("%s \n%d \n\n", test.teststr, test.testnum); //Hello world! / 114514
    
    test = new(TEST, NULL);
    printf("%s \n%d", test.teststr, test.testnum); //(null) / 0
}
//