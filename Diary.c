#include<stdio.h>

#define MaxEntries 1000
#define MaxCharacter 100

char diary[MaxEntries][MaxCharacter];

void EncryptEntry(int index);
void DecryptEntry(int index);

int main()
{

    return 0;
}

void EncryptEntry(int index)
{
    for(int i=0;i<MaxCharacter;i++)
    {
        if(diary[index][i]!='\0')
        {
            diary[index][i]=diary[index][i]+2;
        }
        else
        {
            break;
        }
    }
}

void DecryptEntry(int index)
{
    for(int i=0;i<MaxCharacter;i++)
    {
        if(diary[index][i]!='\0')
        {
            diary[index][i]=diary[index][i]-2;
        }
        else
        {
            break;
        }
    }
}
