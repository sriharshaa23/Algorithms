#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>



int main()
{
    char a[10][10]={"..........",
        ".@@.......",
        "@@@.......",
        ".@@.......",
        "..........",
        "..........",
        "......@@@.",
        "........@.",
        "..........",
        "..........",
    };
    char b[10][10]={"..........",
        ".@@.......",
        "@@@.......",
        ".@@.......",
        "..........",
        "..........",
        "......@@@.",
        "........@.",
        "..........",
        "..........",
    };
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("%c  ",a[i][j]);
        }
        printf("\n");
    }
    //finding neighbours of a
    system("cls");

    while(1!=0)
    {


    for(int i=1;i<9;i++)
    {

        for(int j=1;j<9;j++)
        {
            int count=0;
            if(a[i-1][j]=='@')
            {
                count++;
            }
            if(a[i-1][j-1]=='@')
            {
                count++;
            }
            if(a[i-1][j+1]=='@')
            {
                count++;
            }
            if(a[i+1][j]=='@')
            {
                count++;
            }
            if(a[i+1][j-1]=='@')
            {
                count++;
            }
            if(a[i+1][j+1]=='@')
            {
                count++;
            }
            if(a[i][j-1]=='@')
            {
                count++;
            }
            if(a[i][j+1]=='@')
            {
                count++;
            }
            if(a[i][j]=='@')
            {
                if(count<2)
                {
                    b[i][j]='.';
                }
                else if(count==2 || count==3)
                {
                    continue;
                }
                else if(count>3)
                {
                    b[i][j]='.';
                }
            }
            if(a[i][j]=='.')
            {
                if(count==3)
                {
                    b[i][j]='@';
                }
            }
        }
    }
    // for printing


    printf("\n\n\n\n");
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("%c  ",b[i][j]);
        }
        printf("\n");
    }
    system("cls");
    //for copying
    for(int i=1;i<9;i++)
    {
        for(int j=1;j<9;j++)
        {
            a[i][j]=b[i][j];
        }
    }

    //for finding neighbours of b
    for(int i=1;i<9;i++)
    {

        for(int j=1;j<9;j++)
        {
            int count=0;
            if(b[i-1][j]=='@')
            {
                count++;
            }
            if(b[i-1][j-1]=='@')
            {
                count++;
            }
            if(b[i-1][j+1]=='@')
            {
                count++;
            }
            if(b[i+1][j]=='@')
            {
                count++;
            }
            if(b[i+1][j-1]=='@')
            {
                count++;
            }
            if(b[i+1][j+1]=='@')
            {
                count++;
            }
            if(b[i][j-1]=='@')
            {
                count++;
            }
            if(b[i][j+1]=='@')
            {
                count++;
            }
            if(b[i][j]=='@')
            {
                if(count<2)
                {
                    a[i][j]='.';
                }
                else if(count==2 || count==3)
                {
                    continue;
                }
                else if(count>3)
                {
                    a[i][j]='.';
                }
            }
            if(b[i][j]=='.')
            {
                if(count==3)
                {
                    a[i][j]='@';
                }
            }
        }
    }


    // for printing
    printf("\n\n\n\n");
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("%c  ",a[i][j]);
        }
        printf("\n");
    }
    system("cls");
    for(int i=1;i<9;i++)
    {
        for(int j=1;j<9;j++)
        {
            b[i][j]=a[i][j];
        }
    }
    Sleep(500);
    }
}
