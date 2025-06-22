/**
 * 在 8×8 的国际象棋棋盘上，摆放 8 个皇后，要求任意两个皇后不在同一行、同一列或同一对角线上。
 * 本程序使用穷举法（枚举法）解决八皇后问题。
 * 通过八重循环枚举所有可能的皇后摆放方式，并用check函数判断是否有冲突。
 */
#include <stdio.h>
#include <stdlib.h>

#define N 8     // N is the number of queens and also the size of the chessboard
int col[N];     //col[i] = j 表示第i行的皇后放在第j列
int solution_count = 0; // 记录解的个数


//检查当前所有皇后是否相互不冲突
//返回1表示不冲突，返回0表示冲突
int check(){
    for(int i = 0;i < N; i++){
        for(int j = i + 1; j < N; j++){
            //检查列冲突
            if(col[i] == col[j]){
                return 0;// 检查列冲突
            }
            if(col[j] == col[i] + (j -i)){
                return 0; // 检查主对角线冲突
            }
            if(col[j] == col[i] - (j - i)){
                return 0; // 检查次对角线冲突
            }
        }
    }
    return 1; // 不冲突
}

int main(int argc, char const *argv[])
{
    // 八重循环：完全枚举col[0]到col[7]的所有可能
    for(col[0] = 0;col[0] < N;col[0] ++){
        for(col[1] = 0;col[1] < N;col[1] ++){
            for(col[2] = 0;col[2] < N;col[2] ++){
                for(col[3] = 0;col[3] < N;col[3] ++){
                    for(col[4] = 0;col[4] < N;col[4] ++){
                        for(col[5] = 0;col[5] < N;col[5] ++){
                            for(col[6] = 0;col[6] < N;col[6] ++){
                                for(col[7] = 0;col[7] < N;col[7] ++){
                                    if(check()){
                                        solution_count++;
                                    }
            }}}}}}}}  // 八重循环结束  
  
    //打印最终的解的个数
    printf("Total solutions: %d\n", solution_count);
    return 0;
}
