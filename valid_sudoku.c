/* 若行有效且列有效且块有效，则该位有效，若所有位都有效，则整个有效 */
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9
#define BLOCKROWSIZE 3
#define BLOCKCOLSIZE 3

typedef struct NODE Node;
struct NODE {
    char value;
    int count;
};

/* 初始化temp */
void init_Temp (Node *temp, int temp_size) {
    int i;
    for (i = 0 ; i < temp_size ; i++) {
        temp[i].value = '1' + i;
        temp[i].count = 0;
    }
}

/* 判断单行有效性 */
bool isValidOne_row (char **board, int num_row, int boardColSize) {
    int j;
    Node temp[SIZE];
    // 初始化temp
    init_Temp(temp, SIZE);
    // 根据行分配temp
    int var;
    for (j = 0 ; j < boardColSize ; j++)
        if ( (var = board[num_row][j]) != '.')
            temp[var - '1'].count ++;
    // 决定是否有效
    for (j = 0 ; j < SIZE ; j++)
        if (temp[j].count > 1)
            return false;
    return true;
}

/* 判断单列有效性 */
bool isValidOne_column (char **board, int num_col, int boardRowSize) {
    int i;
    Node temp[SIZE];
    // 初始化temp
    init_Temp(temp, SIZE);
    // 根据列分配temp
    int var;
    for (i = 0 ; i < boardRowSize ; i++)
        if ( (var = board[i][num_col]) != '.')
            temp[var - '1'].count ++;
    // 决定是否有效
    for (i = 0 ; i < SIZE ; i++)
        if (temp[i].count > 1)
            return false;
    return true;

}

bool isValidOne_block (char **board, int num_row, int num_col, int blockrowsize, int blockcolsize) {
    // 计算所在块
    int var_row = num_row / blockrowsize;
    int var_col = num_col / blockcolsize;
    int block_row_start = var_row * blockrowsize;
    int block_row_end = var_row * blockrowsize + blockrowsize - 1;
    int block_col_start = var_col * blockcolsize;
    int block_col_end = var_col * blockcolsize + blockcolsize - 1;

    int i, j;
    Node temp[SIZE];
    // 初始化temp
    init_Temp(temp, SIZE);
    // 根据块分配temp
    int var;
    for (i = block_row_start ; i <= block_row_end ; i++)
        for (j = block_col_start ; j <= block_col_end ; j++)
            if ((var = board[i][j]) != '.')
                temp[var].count ++;
    // 决定是否有效
    for (i = 0 ; i < SIZE ; i++)
        if (temp[i].count > 1)
            return false;
    return true;
}

bool isValidOne (char **board, int i, int j, int boardRowSize, int boardColSize) {
    if (! isValidOne_row(board, i, boardColSize) ||
        ! isValidOne_column(board, j, boardRowSize) ||
        ! isValidOne_block(board, i, j, BLOCKROWSIZE, BLOCKCOLSIZE))
        return false;
    return true;
}

bool isValidSudoku (char** board, int boardRowSize, int boardColSize) {
    // 建立9个结点，其中value为'1'～'9'，而count为value的个数
    int i, j;
    for (i = 0 ; i < boardRowSize ; i++) {
        for (j = 0 ; j < boardColSize ; j++) {
            if(! isValidOne(board, i, j, boardRowSize, boardColSize))
                return false;
        }
    }
    return true;
}


