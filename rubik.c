/*
 *   Simple Rubik Simulator v0.1
 */

#include <stdio.h>

#define AREA_SIZE       6
#define AREA_BOX_SIZE  16
#define AREA_ROW_LENGTH 4

#define LEFT_SIDE_INDEX   0
#define RIGHT_SIDE_INDEX  1
#define FRONT_SIDE_INDEX  2
#define BACK_SIDE_INDEX   3
#define TOP_SIDE_INDEX    4
#define BOTTOM_SIDE_INDEX 5

enum SHIFT_TYPE {
                   FRONT_LEFT_SHIFT = 0x00, 
                   FRONT_TOP_SHIFT  = 0x01, 
                   TOP_LEFT_SHIFT   = 0x02
                };

void
shift(enum SHIFT_TYPE shift_type, int row, char rubik[AREA_SIZE][AREA_BOX_SIZE])
{   
    if(row <= 0){
        row = 1;
    }
    
    if(row > AREA_ROW_LENGTH){
        row = AREA_ROW_LENGTH;
    }
    
    int start_index = 0;
    int end_index   = 0;
    
    if(shift_type == FRONT_TOP_SHIFT) {        
        start_index = row - 1;
        end_index = start_index + 3;
    } else {
        start_index = (row - 1) * AREA_ROW_LENGTH;
        end_index   = (start_index + AREA_ROW_LENGTH) - 1;
    }
    
    char current_value;
    char next_value;
    int i = 0;
    
    switch(shift_type) 
    {
        case FRONT_LEFT_SHIFT:            
            i = 0;           
                
                for(i = start_index; i <= end_index; i++){
                    current_value = rubik[LEFT_SIDE_INDEX][i];
                    rubik[LEFT_SIDE_INDEX][i] =  rubik[FRONT_SIDE_INDEX][i];
                    
                    next_value = rubik[BACK_SIDE_INDEX][i];
                    rubik[BACK_SIDE_INDEX][i] = current_value;
                    
                    current_value = rubik[RIGHT_SIDE_INDEX][i];
                    rubik[RIGHT_SIDE_INDEX][i] =  next_value;
                    
                    rubik[FRONT_SIDE_INDEX][i] =  current_value;
                }                
                        
            break;
            
        case FRONT_TOP_SHIFT:
            i = 0;
            int box_index = start_index;
                
                for(i = start_index; i <= end_index; i++){
                    current_value = rubik[TOP_SIDE_INDEX][box_index];
                    rubik[TOP_SIDE_INDEX][box_index] =  rubik[FRONT_SIDE_INDEX][box_index];
                    
                    next_value = rubik[BACK_SIDE_INDEX][box_index];
                    rubik[BACK_SIDE_INDEX][box_index] = current_value;
                    
                    current_value = rubik[BOTTOM_SIDE_INDEX][box_index];
                    rubik[BOTTOM_SIDE_INDEX][box_index] =  next_value;
                    
                    rubik[FRONT_SIDE_INDEX][box_index] =  current_value;
                    box_index = box_index + 4;
                }                
                        
            break;    
            
         case TOP_LEFT_SHIFT:
            i = 0;
                
                for(i = start_index; i <= end_index; i++){
                    current_value = rubik[LEFT_SIDE_INDEX][i];
                    rubik[LEFT_SIDE_INDEX][i] =  rubik[TOP_SIDE_INDEX][i];
                    
                    next_value = rubik[BOTTOM_SIDE_INDEX][i];
                    rubik[BOTTOM_SIDE_INDEX][i] = current_value;
                    
                    current_value = rubik[RIGHT_SIDE_INDEX][i];
                    rubik[RIGHT_SIDE_INDEX][i] =  next_value;
                    
                    rubik[TOP_SIDE_INDEX][i] =  current_value;
                }                
                        
            break;
    }
}

void
print(char rubik[AREA_SIZE][AREA_BOX_SIZE])
{    
    int i = 0;
    int last_index = 0;
    
    printf("     +----+   \r\n");
    for(i = 0; i < 4; i++ ) {
        printf("     |%c%c%c%c|   \r\n", rubik[TOP_SIDE_INDEX][last_index], 
                                       rubik[TOP_SIDE_INDEX][last_index + 1], 
                                       rubik[TOP_SIDE_INDEX][last_index + 2], 
                                       rubik[TOP_SIDE_INDEX][last_index + 3]);
        last_index = (last_index + 3) + 1;                                            
    }
            
    last_index = 0;
    printf("+----+----+----+----+\r\n");
    for(i = 0; i < 4; i++ ) {
        printf("|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|\r\n", rubik[LEFT_SIDE_INDEX][last_index], 
                                                       rubik[LEFT_SIDE_INDEX][last_index + 1], 
                                                       rubik[LEFT_SIDE_INDEX][last_index + 2], 
                                                       rubik[LEFT_SIDE_INDEX][last_index + 3],
                                                       rubik[FRONT_SIDE_INDEX][last_index], 
                                                       rubik[FRONT_SIDE_INDEX][last_index + 1], 
                                                       rubik[FRONT_SIDE_INDEX][last_index + 2], 
                                                       rubik[FRONT_SIDE_INDEX][last_index + 3],
                                                       rubik[RIGHT_SIDE_INDEX][last_index], 
                                                       rubik[RIGHT_SIDE_INDEX][last_index + 1], 
                                                       rubik[RIGHT_SIDE_INDEX][last_index + 2], 
                                                       rubik[RIGHT_SIDE_INDEX][last_index + 3],
                                                       rubik[BACK_SIDE_INDEX][last_index], 
                                                       rubik[BACK_SIDE_INDEX][last_index + 1], 
                                                       rubik[BACK_SIDE_INDEX][last_index + 2], 
                                                       rubik[BACK_SIDE_INDEX][last_index + 3]);
        last_index = (last_index + 3) + 1;                                            
    }
     
    last_index = 0;
    printf("+----+----+----+----+\r\n");
    for(i = 0; i < 4; i++ ) {
        printf("     |%c%c%c%c|    \r\n", rubik[BOTTOM_SIDE_INDEX][last_index], 
                                       rubik[BOTTOM_SIDE_INDEX][last_index + 1], 
                                       rubik[BOTTOM_SIDE_INDEX][last_index + 2], 
                                       rubik[BOTTOM_SIDE_INDEX][last_index + 3]);
        last_index = (last_index + 3) + 1;                                            
    }
    printf("     +----+   \r\n");
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
    printf("shifting...!\n\n");
    shift(FRONT_LEFT_SHIFT, 3, rubik);
    print(rubik);             
    printf("shifting...!\n\n");
    shift(FRONT_TOP_SHIFT, 2, rubik);    
    print(rubik);             
    printf("shifting...!\n\n");
    shift(TOP_LEFT_SHIFT, 1, rubik);
    print(rubik);
    printf("shifting...!\n\n");
    shift(FRONT_TOP_SHIFT, 4, rubik);
    print(rubik);
    printf("hello RubikSim!\n");
    return 0;
}