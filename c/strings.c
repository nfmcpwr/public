#include <stdio.h>
#include <string.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

BOOL IsContains(char* str, char* value)
{
    BOOL r;

    for (int i = 0; i < strlen(str) - strlen(value); i++)
    {
        r = TRUE;
        
        for (int j = 0; j < strlen(value); j++)
        {
            if (str[j + i] != value[j])
            {
                r = FALSE;
                break;
            }
        }
    }
    
    return r;
}

BOOL IsStartsWith(char* str, char* value)
{
    BOOL r = TRUE;
    
    for (int i = 0; i < strlen(value); i++)
    {
        if (str[i] != value[i])
        {
            r = FALSE;
            break;
        }
    }
    
    return r;
}

BOOL IsEndsWith(char* str, char* value)
{
    BOOL r = TRUE;
    
    for (int i = 0; i < strlen(value); i++)
    {
        if (str[i + (strlen(str) - strlen(value))] != value[i])
        {
            r = FALSE;
            break;
        }
    }
    
    return r;
}

int main()
{
    printf("%d", IsContains("abcdef", "cde"));
    printf("%d", IsStartsWith("abcdef", "abc"));
    printf("%d", IsEndsWith("abcdef", "def"));
}