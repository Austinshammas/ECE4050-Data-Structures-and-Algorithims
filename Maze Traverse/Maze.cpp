//This program traverses through a maze by always turning right and putting your right hand on the right
//all. This is done by comparing each “tile” and depending on what the next tile has, it will make a move
//accordingly. This is done through if statements

#include <iomanip>
#include <iostream>

using namespace std;

void showMaze(char maze[12][12]) //because the assignment says to display the maze after each move, we must create a function so our code isn't extremely long
{
 // call the maze after every move
	for (int outter = 0; outter < 12; outter++)
	{
		for (int inner = 0; inner < 12; inner++)
		{

			cout << maze[outter][inner];
		}
		cout << "\n";
	}

}

void mazeTraverse(char maze[12][12], int x, int y) //x will tell us where we are in the row, y will be column
{
	// create variables to move left, right, up and down so we don't have to keep writing this plenty of times in the code

	char R = maze[x][y +1];
	char L = maze[x][y - 1]; 
	char U = maze[x - 1][y];
	char D = maze[x + 1][y];
	char Z = maze[x + 1][y + 1]; // this will be used in order to avoid the intersection where there is no wall (see picture on assignemnt for clarification)

	if (R == '.' ) // move right always when we see a period
	{
		 maze[x][y + 1]=  'X';
		
		showMaze(maze);
		mazeTraverse(maze, x, (y + 1));
	}
	//check to move down
	if (U == '#' && R == '#' && D == '.' || U == 'X' && R == '#' &&  L == '#' && D =='.')
	{
		maze[x + 1][y] = 'X';
		
		showMaze(maze);
		mazeTraverse(maze, (x + 1), y);
	}

	//move up (only used when we  are completely surrounded)
	if (L == '#' && R == '#' && D == '#')
	{
		maze[x - 1][y] = 'X';
		
		showMaze(maze);
		mazeTraverse(maze, (x - 1), y);
	}
	//move up

	if (R == '#' && D == '#')
	{
		maze[x-1][y] = 'X';
		
		showMaze(maze);
		mazeTraverse(maze, (x - 1), y);
	}
	// move up
	 if (R == '#' && L == '#')
	{
		maze[x - 1][y] = 'X';
		
		showMaze(maze);
		mazeTraverse(maze, (x - 1), y);
	}
	/*if (Z == '.') // this will be used in order to avoid the intersection where there is no wall (see picture on assignemnt for clarification)
	{				// this doesn't execute properly, unsure why
		maze[x + 1][y+1] = 'X';
		
		showMaze(maze);
		mazeTraverse(maze, (x + 1), (y + 1));
	}*/
	//moving left
	 if (L == '.' &&  R =='#' && U =='X' || L =='.' && R=='X' && U == '#')
	{

		maze[x][y - 1] = 'X';
		showMaze(maze);
		mazeTraverse(maze, (x), (y - 1));

	}
	if (D == '.' && U == 'X' && L == '#' && R == '#')
		{
			maze[x + 1][y] = 'X';

			showMaze(maze);
			mazeTraverse(maze, (x + 1), y);
		}





	//else if (R != '#' || R != '.')
	//{
		//cout << "Game over! You win";
	//}
	//return maze[x][y];

}


int main()
{
	int start1=10;
	int start2=0;
	char maze[12][12] =
	{
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#' },
		{'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
		{'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
		{'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
		{'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
		{ '#', '.', '.', '.', '#', '.', '.', '.', '.', '.','.', '#'},
		{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},

	};




	maze[start1][start2] = 'X';
	mazeTraverse(maze, start1, start2);




	system("PAUSE");
	return 0;
}
