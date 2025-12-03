#include<stdio.h>
#include<stdlib.h>
#define INFINITY 9999
#define SIZE 10
int main()
{
int cost[SIZE][SIZE},distance[SIZE],pred[SIZE];
int visited[SIZE],count,mindist,nextnode,i,j;
int startnode,n;
printf("Enter no of vertices:");

