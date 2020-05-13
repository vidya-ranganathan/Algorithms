#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int n=4, m=5;
int visited[4][5];

#define FALSE 0
#define TRUE 1

int DFS(int x, int y, int visited[n][m], int n, int m, int mat[n][m], int dest_x, int dest_y)
{
    if(x == dest_x && y == dest_y)
        return TRUE;
    if(x >= n || y >= m)
        return FALSE;
    if(x < 0 || y < 0)
        return FALSE;
    if(visited[x][y] == TRUE)
        return FALSE;
    if(mat[x][y] == FALSE)
        return FALSE;

    visited[x][y] = TRUE;
    if(DFS(x+1, y, visited, n, m, mat,  dest_x, dest_y) == TRUE)
        return TRUE;
    if(DFS(x-1, y, visited, n, m, mat,  dest_x, dest_y) == TRUE)
        return TRUE;
    if(DFS(x, y+1, visited, n, m, mat,  dest_x, dest_y) == TRUE)
        return TRUE;
    if(DFS(x, y-1, visited, n, m, mat,  dest_x, dest_y) == TRUE)
        return TRUE;
    return FALSE;
}

int main()
{
  memset(visited, FALSE, n*m*sizeof(int));
  int maze[4][5] = { \
      { 1, 0, 1, 1, 0 }, \
      { 1, 0, 1, 0, 1 }, \
      { 0, 1, 0, 1, 1 }, \
      { 1, 1, 1, 1, 1 } 
      };
  int dest_x = 2, dest_y = 3;
  int x = 0, y = 0;

  int rc = DFS(x, y, visited, n, m, maze, dest_x, dest_y);
  if(rc)
  {
    printf("path exits...\n");
  }
  else
  {
    printf("path does NOT exists ...\n");
  }

  return 0;
}  
