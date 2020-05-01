#include<bits/stdc++.h>
using namespace std;
 const int N = 9; 
bool isvalidlocation(int grid[N][N], int row, int col, int num)
{
	bool a = true;
	for(int i=0;i<9;i++)
	{
		if(num==grid[row][i])
		a=false;
		if(num==grid[i][col])
		a=false;
	}
	
	int remr=row%3;
	int remc=col%3;
	row-=remr;
	col-=remc;
	
	for(int i=row;i<row+3;i++)
	{
		for(int j=col;j<col+3;j++)
		{
			if(grid[i][j]==num)
			a=false;
		}
	}
	
	return a;
}

bool findvoidcell(int grid[N][N], int &row, int &col)
{

	while(grid[row][col]!=0)
	{
		col++;
		if(col==8 && grid[row][col]!=0)
		{
			row+=1;
			col=0;
		}	
		
		if(row==9)
		break;
	}
	
	if(row==9)
	return false;
	else
	return true;
} 

bool mainsolver(int grid[N][N])
{
	int row=0,col=0;
	
	if(findvoidcell(grid,row,col)==0)
	return true;
	
	for(int num=1;num<=9;num++)
	{
		if(isvalidlocation(grid,row,col,num)==true)
		{
			grid[row][col]=num;
			
			if(mainsolver(grid))
			return true;
			
			grid[row][col]=0;
		}
	}
	return false;
}
 
void displaygrid(int grid[N][N])
{
	cout<<"|"<<grid[0][0]<<grid[0][1]<<grid[0][2]<<"|"<<grid[0][3]<<grid[0][4]<<grid[0][5]<<"|"<<grid[0][6]<<grid[0][7]<<grid[0][8]<<"|"<<endl;
	cout<<"|"<<grid[1][0]<<grid[1][1]<<grid[1][2]<<"|"<<grid[1][3]<<grid[1][4]<<grid[1][5]<<"|"<<grid[1][6]<<grid[1][7]<<grid[1][8]<<"|"<<endl;
	cout<<"|"<<grid[2][0]<<grid[2][1]<<grid[2][2]<<"|"<<grid[2][3]<<grid[2][4]<<grid[2][5]<<"|"<<grid[2][6]<<grid[2][7]<<grid[2][8]<<"|"<<endl;
	cout<<"--------------"<<endl;
	cout<<"|"<<grid[3][0]<<grid[3][1]<<grid[3][2]<<"|"<<grid[3][3]<<grid[3][4]<<grid[3][5]<<"|"<<grid[3][6]<<grid[3][7]<<grid[3][8]<<"|"<<endl;
	cout<<"|"<<grid[4][0]<<grid[4][1]<<grid[4][2]<<"|"<<grid[4][3]<<grid[4][4]<<grid[4][5]<<"|"<<grid[4][6]<<grid[4][7]<<grid[4][8]<<"|"<<endl;
	cout<<"|"<<grid[5][0]<<grid[5][1]<<grid[5][2]<<"|"<<grid[5][3]<<grid[5][4]<<grid[5][5]<<"|"<<grid[5][6]<<grid[5][7]<<grid[5][8]<<"|"<<endl;
	cout<<"--------------"<<endl;
	cout<<"|"<<grid[6][0]<<grid[6][1]<<grid[6][2]<<"|"<<grid[6][3]<<grid[6][4]<<grid[6][5]<<"|"<<grid[6][6]<<grid[6][7]<<grid[6][8]<<"|"<<endl;
	cout<<"|"<<grid[7][0]<<grid[7][1]<<grid[7][2]<<"|"<<grid[7][3]<<grid[7][4]<<grid[7][5]<<"|"<<grid[7][6]<<grid[7][7]<<grid[7][8]<<"|"<<endl;
	cout<<"|"<<grid[8][0]<<grid[8][1]<<grid[8][2]<<"|"<<grid[8][3]<<grid[8][4]<<grid[8][5]<<"|"<<grid[8][6]<<grid[8][7]<<grid[8][8]<<"|"<<endl;
	cout<<"--------------"<<endl;
}
 
int main()
{
	
	int grid[N][N] = {
		  {5,3,0,0,7,0,0,0,0},
		  {6,0,0,1,9,5,0,0,0},
		  {0,9,8,0,0,0,0,6,0},
		  {8,0,0,0,6,0,0,0,3},
		  {4,0,0,8,0,3,0,0,1},
		  {7,0,0,0,2,0,0,0,6},
		  {0,6,0,0,0,0,2,8,0},
		  {0,0,0,4,1,9,0,0,5},
		  {0,0,0,0,8,0,0,7,9},
		};
	
	if(mainsolver(grid)==true)
	{
		displaygrid(grid);
	}
	else
	cout<<"Solution does not exist";
	
	return 0;
}
