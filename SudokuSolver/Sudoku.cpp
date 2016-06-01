#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;
void check_row_availablity(int original_matrix[][9], int value_array[][9], int row, int column); // function to check and eliminate elements row wise 
void check_column_availablity(int original_matrix[][9], int value_array[][9], int row, int column);// function to check and eliminate elements column wise
void check_block_availablity(int sudoku_matrix[][9], int possible_value_array[][9],int i,int j);// function to check and eliminate elements block wise
void toprint(int array[][9]); // function to print the possible values array
int check_completeness(int array[][9]); // function to check if sudoku is complete
void to_eliminate_in_box(int original_matrix[][9], int temp[], int row_start, int row_end, int col_start, int col_end); // to take out original box values

void main()
{
	system("cls");
	

	int sudoku_matrix[9][9] = {5,3,0,0,7,0,0,0,0,
								6,0,0,1,9,5,0,0,0,
								0,9,8,0,0,0,0,6,0,
								8,0,0,0,6,0,0,0,3,
								4,0,0,8,0,3,0,0,1,
								7,0,0,0,2,0,0,0,6,
								0,6,0,0,0,0,2,8,0,
								0,0,0,4,1,9,0,0,5,
								0,0,0,0,8,0,0,7,9};


	int possible_value_array[81][9]; // To store all the possible values per node 

	int column = 0, row =0;
	for(int i= 0; i<81; ++i) // to initialize the array with all the possible values i.e 0-9 and to all zeros if there is value already present in original sudoku
	{
		if(sudoku_matrix[row][column] == 0)
		{
			int count = 1;
			for(int j=0; j<9; ++j)
			{
				possible_value_array[i][j] = count;
				count++;
			}
		}
		else
		{
			for(int j=0; j<9; ++j)
			{
				possible_value_array[i][j] = 0;
			}
		}
		if(column<8)
		{
			column++;
		}
		else
		{
			row++;
			column = 0;
		}
	}
	int change = 1;
	int temp = 0;
	for(;;) // infinite loop to loop over the sudoku till any of the two condition fails
	{
		temp++; // just a temporary variable to check how many iterations does it take to solve the whole sudoku 
		if(change == 1) // condition to check if there was atleast one change in previous iteration if not then sudoku cannot be solved
		{
			if(!check_completeness(sudoku_matrix)) // to check if the sudoku is complete or not if yes then it will break 
			{
				change = 0;
				int position = -1;
				int count = 0;
				for(int i=0; i<9; i++)
				{
					for(int j=0; j<9 ; j++)
					{
						if(sudoku_matrix[i][j] == 0)
						{
							int node = i*9 + j;
					
							check_row_availablity(sudoku_matrix, possible_value_array,i,j);
							check_column_availablity(sudoku_matrix, possible_value_array,i,j);
							check_block_availablity(sudoku_matrix, possible_value_array,i,j);
							//toprint(possible_value_array);

						
							for(int k=0; k<9 ; k++)
							{
								if(possible_value_array[node][k] != 0)
								{
									position = k;
									count++;
								}
							}
							if(count == 1 && position != -1 )
							{
								cout<<"\n changing value " <<possible_value_array[node][position]<<" at "<<i<<" "<<j; // just to see what all values are changed
							
								//cout<<"----------------------------------------------------------------";
								sudoku_matrix[i][j] = possible_value_array[node][position];
								possible_value_array[node][position] = 0;
								change = 1;
							}
							position = -1;
							count = 0;
						}
					}
				}
			}
			else
			{
				cout<<"\nsudoku solved \n";
				break;
			}
		}
	else
		{
			cout<<"sudoku cannot be solved\n";
			break;
		}
	}
	//toprint(possible_value_array);
	cout<<"\n"<<temp<<"\n";
	for(int i = 0 ;i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			cout<<sudoku_matrix[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	getch();

}

int check_completeness(int array[][9]) // to check whether the sudoku is complete or not 
{
	int flag = 0;
	for(int i = 0 ;i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			if(array[i][j]==0)
			{
				flag = 1;
			}
		}
	}
	if (flag ==1 )
	{
		return 0;
	}
	else
		return 1;
}



void check_row_availablity(int original_matrix[][9], int value_array[][9], int row, int column) // function to check and cancel the values for a node
{
	int node_value = (row*9) + column;
	//cout<<node_value <<"\n";

	for(int i = 0 ; i<9; i++)
	{
		if(value_array[node_value][i] != 0) // to eliminate the computation for already elements which do not exist
		{
			for(int j = 0 ;j<9; j++) 
			{
				if(value_array[node_value][i] == original_matrix[row][j]) // to check against all the values in possible values array
				{
					value_array[node_value][i] = 0;
				}
			}
		
		}
	}


}



void check_column_availablity(int original_matrix[][9], int value_array[][9], int row, int column) // function to check and cancel the values for a node
{
	int node_value = (row*9) + column;
	//cout<<node_value <<"\n";

	for(int i = 0 ; i<9; i++)
	{
		if(value_array[node_value][i] != 0) // to eliminate the computation for the elements that are already been removed
		{
			for(int j = 0 ;j<9; j++)
			{
				if(value_array[node_value][i] == original_matrix[j][column]) // to check against all thee values in possible values array 
				{
					value_array[node_value][i] = 0;
				}
			}
		
		}
	}

}



void check_block_availablity(int original_matrix[][9], int value_array[][9], int row, int column) // to check and eliminate from the block of 9x9
{
	int temp[] = {0,0,0,0,0,0,0,0,0};
	int count = 0;
	if(row<=2 && column<=2) // for first box
	{
		to_eliminate_in_box(original_matrix, temp, 0,3,0,3);
		
	}

	else if(row<=2 && (column>2 && column<=5)) // for second box
	{
		to_eliminate_in_box(original_matrix, temp, 0,3,3,6);
		
	}

	else if(row<=2 && (column>5 && column<=8)) // for third box
	{
		to_eliminate_in_box(original_matrix, temp, 0,3,6,9);
	}

	else if((row>2 && row <= 5) && (column>=0 && column<=2)) // for fourth box
	{
		to_eliminate_in_box(original_matrix, temp, 3,6,0,3);
	}


	else if((row>2 && row<=5) && (column>2 && column<=5)) // for fifth box
	{
		to_eliminate_in_box(original_matrix, temp, 3,6,3,6);
	}

	else if((row>2 && row<=5) && (column>5 && column<=8)) // for sixth box
	{
		to_eliminate_in_box(original_matrix, temp, 3,6,6,9);
	}

	else if((row>=6 && row <=8) && (column>=0 && column<=2)) // for seventh box
	{
		to_eliminate_in_box(original_matrix, temp, 6,9,0,3);
	}

	else if((row>=6 && row<=8) && (column>2 && column<=5)) // for eighth box
	{
		to_eliminate_in_box(original_matrix, temp, 6,9,3,6);
	}

	else // for ninth box
	{
		to_eliminate_in_box(original_matrix, temp, 6,9,6,9);
	}

	int node = (9*row) + column;

	//cout<<temp[0]<<"\n";
	for(int i=0; i<9 ; i++)
	{
		if(value_array[node][i] != 0)
		{
			for(int j=0; j<9; j++)
			{
				if(temp[j] == value_array[node][i])
				{
					value_array[node][i] = 0;
				}
			}
		}	
	}
}


void to_eliminate_in_box(int original_matrix[][9], int temp[], int row_start, int row_end, int col_start, int col_end) // to store the value of box in a temp array
{
	int count = 0;
		for(int i=row_start; i<row_end; i++)
		{
			for(int j=col_start; j<col_end;j++)
			{
				temp[count] = original_matrix[i][j];
				count++;
			}
		}
}



void toprint(int array[][9])
{
	for(int i= 0; i<81; ++i) 
	{
		//int count = 1;
		for(int j=0; j<9; ++j)
		{
			cout << array[i][j]<<" ";
		}
		cout<<"\n";
	}
}