/*
 *   Simple Rubik Simulator v0.1
 */

#include <stdio.h>

#define AREA_SIZE 6
#define AREA_BOX_SIZE 16
#define AREA_ROW_LENGTH 4

char**
shift(int area, int row, char rubik[AREA_SIZE][AREA_BOX_SIZE])
{   
    //todo implement shift row
    return rubik;
}

void
print(char rubik[AREA_SIZE][AREA_BOX_SIZE])
{    
    // test print box color value 
    printf("%c\n", rubik[0][1]);
    printf("%c\n", rubik[3][2]);
    printf("%c\n", rubik[2][4]);
}

int 
main()
{    
    char rubik[AREA_SIZE][AREA_BOX_SIZE] = {
                                            {'R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R'},
                                            {'G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G'},
                                            {'B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B'},
                                            {'O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O'},
                                            {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'},
                                            {'Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y'}
                                           };                   
    print(rubik);
    printf("shifting...!\n");
    shift(2,3, rubik);
    print(rubik);             
    printf("hello RubikSim!\n");
    return 0;
}