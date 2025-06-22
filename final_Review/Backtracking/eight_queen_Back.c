#include <stdio.h>
#include <stdlib.h>

#define N 8     // N is the number of queens and also the size of the chessboard
int col[N];     //col[i] = j 表示第i行的皇后放在第j列
int solution_count = 0; // 记录解的个数


//向上检查当前行的皇后是否可以放置
//返回1表示可以放置，返回0表示不可以放置
// 这里的row表示当前行
int is_safe(int row){
    for(int i = 0; i < row; i++){
        // 检查列冲突
        if(col[i] == col[row]) return 0;
        // 检查主对角线冲突
        if(col[i] - i == col[row] - row) return 0;
        // 检查次对角线冲突
        if(col[i] + i == col[row] + row) return 0;
    }
    return 1; // 如果没有冲突，返回1表示可以放置
}
// 回溯函数:尝试放置第row行的皇后
void solve(int row){
    if(row == N){
        solution_count++; // 找到一个解，增加解的计数
        return;
    }
    for(int j = 0;j < N; j++){
        col[row] =j; // 尝试将第row行的皇后放在第j列
        if(is_safe(row)){
            solve(row + 1);
        }
    }
}

int main(){
    
    solve(0); // 从第0行开始尝试放置皇后
    
    printf("Total solutions for %d-Queens problem: %d\n", N, solution_count);
    
    return 0;
}
