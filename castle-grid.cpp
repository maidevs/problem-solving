/**
   https://www.hackerrank.com/challenges/castle-on-the-grid/problem
   By the time that I've solved this problem, there were some issues with wrong outputs, like no solution inputs or with the wrong answer.
   But I've tested this algorithm with several test cases to be sure that it was producing the right answers.

   This is the coordinate system for this problem, the author assumes that x = row and y = column ¯\_(ツ)_/¯

   a00 a01 a02
   a10 a11 a12
   a20 a21 a22
*/

#include <bits/stdc++.h>
#include<queue>

using namespace std;

bool visited[100][100];
int xGoal = 0;
int yGoal = 0;
int mSize = 0;
vector<string> dmap;

class Coord
{
public:
    int x;
    int y;
    int dist;

    Coord(int x, int y, int dist = 0)
    {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }

    bool isEqual(Coord b)
    {
        return this->x == b.x && this->y == b.y;
    }
};

bool isValid(int x, int y) 
{ 
    return (y >= 0) && (y < mSize) && 
           (x >= 0) && (x < mSize) && 
           !visited[x][y] && dmap[x][y] != 'X'; 
} 

bool isGoal(int x , int y)
{
    return x == xGoal && y == yGoal;
}

Coord moveHorizontal(Coord start, int dir)
{
    int x = start.x;
    int y = start.y;

    int newX = x;

    while(true)
    {
        newX += dir;

        if(!isValid(newX, y))
            return Coord(x,y);
        if(isGoal(newX,y))
            return Coord(newX, y);

        visited[newX][y] = true;
        x = newX;
    }

    return Coord(x,y);
}

Coord moveVertical(Coord start, int dir)
{
    int x = start.x;
    int y = start.y;

    int newY = y;

    while(true)
    {
        newY += dir;

        if(!isValid(x, newY))
            return Coord(x,y);
        if(isGoal(x,newY))
            return Coord(x, newY);
        
        visited[x][newY] = true;
        y = newY;
    }

    return Coord(x,y);
}

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    
    dmap = grid;
    mSize = grid.size();

    memset(visited, false, sizeof visited);
    visited[startX][startY] = true;

    xGoal = goalX;
    yGoal = goalY;

    queue<Coord> qu;
    qu.push(Coord(startX,startY));

    while(!qu.empty())
    {
        Coord currentCoord = qu.front();
        qu.pop();

        if(isGoal(currentCoord.x, currentCoord.y))
        {
            return currentCoord.dist;
        }

        Coord left = moveHorizontal(currentCoord, -1);
        if(!left.isEqual(currentCoord))
        {
            visited[left.x][left.y] = true;
            left.dist = currentCoord.dist + 1;
            qu.push(left);
        }
        
        Coord down = moveVertical(currentCoord, 1);
        if(!down.isEqual(currentCoord))
        {
            visited[down.x][down.y] = true;
            down.dist = currentCoord.dist + 1;
            qu.push(down);
        }


        Coord right = moveHorizontal(currentCoord, 1);
        if(!right.isEqual(currentCoord)){
            visited[right.x][right.y] = true;
            right.dist = currentCoord.dist + 1;
            qu.push(right);
        }
        
        Coord up = moveVertical(currentCoord, -1);
        if(!up.isEqual(currentCoord))
        {
            visited[up.x][up.y] = true;
            up.dist = currentCoord.dist + 1;
            qu.push(up);
        }

    }

    return -1;
}

