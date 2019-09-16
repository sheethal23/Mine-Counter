
#include"prog5.h"									 //User defined headerfile
int main()
{
	int size;									//variable declarations
	double prob;
	while(cin>>size>>prob)								//The input from prog5.d is taken
	{
	vector< vector<bool> > vec(size, vector<bool>(size,false));			 //Delaration and initiailization of vector of vector of bools
	buildMineField(vec, prob); 							//Function call to buildMinefield, where the minefield is generated.
	vector< vector<unsigned int> > count(size, vector<unsigned int>(size,0));	//Declaration of and initialization of vector of vector of unsigned integers where mine counts are stored
	fixcounts(vec,count);								//Function call to fixcounts function where the counts of mines corresponding to each loation is calculated
	cout<<"Mine Locations: "<<"size = "<<size<<"x"<<size<<", "<<"prob of mine = "<<prob<<"\n";
	displayMineLocations(vec);							//Function call to displayMineField funtion which prints out the generated mine field
	cout<<"Mine Counts:\n";
	displayMineCounts(count);							//Function call to displayMinecounts function which displays the counts of mines calculated in fixcounts function.
	}
	return 0;
}

/************************************************************************************************************************************
Function buildMineField( vector< vector<bool> > &, double &): Determines if a location in vector of mines has a mine.
*************************************************************************************************************************************/

void buildMineField( vector< vector<bool> > & vec, double & prob)	//This function takes a vector of vector of bools and a double value to generate the mine field
{
	srand(1);							//To initialize the rand() function
	double rnd;
	for(unsigned int i=0; i<vec.size(); i++)			//Logic to generate mine placements
	{
		for(unsigned int j=0; j<vec.size(); j++)
		{
			rnd= rand() /(double (RAND_MAX)+1);
			if(rnd<prob)
			{
				vec[i][j]=true;
			}
		}
	}

}

/************************************************************************************************************************************
Function fixcounts(vector< vector<bool> > &, vector< vector<unsigned int> > &):checks boolean value for each locations and sets value. 
*************************************************************************************************************************************/

void fixcounts(vector< vector<bool> > & vec, vector< vector<unsigned int> > & count)//fix counts function taking a vector of vector of bools and vector of vector of unsigned ints.
{
	int n=vec.size();					// since column and row sizes are same
	for(int i=0;i<n;i++)					//Logic for counting the mines corresponding to their location and neighbouring location
	{

		for(int j=0;j<n;j++)
		{
			if(i+1 >= n || i-1 == -1)
			{
				continue;
			}
			if(j+1 >= n || j-1 == -1)
			{
				continue;
			}
			if(vec[i-1][j-1] == true)
			{

				count[i][j]++;
			}
			if(vec[i-1][j] == true)
			{
				count[i][j]++;
			}
			if(vec[i-1][j+1] == true)
			{
				count[i][j]++;
			}
			if(vec[i][j-1] == true)
			{
				count[i][j]++;
			}
			if(vec[i][j] == true)
			{
				count[i][j]++;
			}
			if(vec[i][j+1] == true)
			{
				count[i][j]++;
			}
			if(vec[i+1][j-1] == true)
			{
				count[i][j]++;
			}
			if(vec[i+1][j] == true)
			{
				count[i][j]++;
			}

			if(vec[i+1][j+1] == true)
			{
				count[i][j]++;
			}

		}
	}
	if(vec[0][0] == true)
	{
		count[0][0]++;
	}
	if(n>1)
	{
		if(vec[0][1] == true)
		{
			count[0][0]++;
		}
		if(vec[1][0] == true)
		{
			count[0][0]++;
		}
		if(vec[1][1] == true)
		{
			count[0][0]++;
		}
		for(int i = 0 ;i<n;i++)
		{
			if(i-1 == -1 or i+1 == n )
			{
				continue;
			}
			if(vec[0][i-1] == true)
			{
				count[0][i]++;
			}
			if(vec[0][i] == true)
			{
				count[0][i]++;
			}
			if(vec[0][i+1] == true)
			{
				count[0][i]++;
			}
			if(vec[1][i-1] == true)
			{
				count[0][i]++;
			}

			if(vec[1][i] == true)
			{
				count[0][i]++;
			}
			if(vec[1][i+1] == true)
			{
				count[0][i]++;
			}
			if(vec[n-1][i]==true)
			{
				count[n-1][i]++;
			}
			if(vec[n-1][i-1] == true)
			{
				count[n-1][i]++;
			}
			if(vec[n-1][i+1]==true)
			{
				count[n-1][i]++;
			}
			if(vec[n-2][i+1] == true)
			{
				count[n-1][i]++;
			}
			if(vec[n-2][i] == true)
			{
				count[n-1][i]++;
			}
			if(vec[n-2][i-1] == true)
			{
				count[n-1][i]++;
			}
		}
		if(vec[0][n-1] == true)
		{
			count[0][n-1]++;
		}
		if(vec[0][n-2] == true)
		{
			count[0][n-1]++;
		}

		if(vec[1][n-1] == true)
		{
			count[0][n-1]++;
		}
		if(vec[1][n-2] == true)
		{
			count[0][n-1]++;
		}

		if(vec[n-1][0] == true)
		{
			count[n-1][0]++;
		}
		if(vec[n-1][1] == true)
		{
			count[n-1][0]++;
		}

		if(vec[n-2][1] == true)
		{
			count[n-1][0]++;
		}
		if(vec[n-2][1] == true)
		{
			count[n-1][0]++;
		}

		if(vec[n-1][n-1] == true)
		{
			count[n-1][n-1]++;
		}
		if(vec[n-1][n-2] == true)
		{
		count[n-1][n-1]++;
		}

		if(vec[n-2][n-1] == true)
		{
			count[n-1][n-1]++;
		}
		if(vec[n-2][n-2] == true)
		{
			count[n-1][n-1]++;
		}
		for(int i = 0; i<n;i++)
		{
			if(i-1 == -1 or i+1 == n)
			{
				continue;
			}

			if(vec[i][0] == true)
			{
				count[i][0]++;
			}
			if(vec[i+1][0] == true)
			{
				count[i][0]++;
			}
			if(vec[i-1][0] == true)
			{
				count[i][0]++;
			}
			if(vec[i-1][1] == true)
			{
				count[i][0]++;
			}
			if(vec[i][1] == true)
			{
				count[i][0]++;
			}
			if(vec[i+1][1] == true)
			{
				count[i][0]++;
			}
			if(vec[i][n-1] == true)
			{
				count[i][n-1]++;
			}
			if(vec[i][n-2] == true)
			{
				count[i][n-1]++;
			}
			if(vec[i-1][n-1] == true)
			{
				count[i][n-1]++;
			}
			if(vec[i-1][n-2] == true)
			{
				count[i][n-1]++;
			}
			if(vec[i+1][n-1] == true)
			{
				count[i][n-1]++;
			}
			if(vec[i+1][n-2] == true)
			{
				count[i][n-1]++;
			}
		}

	}

}

/*************************************************************************************************************************************
Function displayMineLocations(vector< vector<bool> > &): Displays the mine feild and display "X" in each mine location
**************************************************************************************************************************************/

void displayMineLocations(vector< vector<bool> > & vec)			// This function takes  vector of vector of bools and prints out the mine field generated
{
	unsigned int n=vec.size();
	for (unsigned int a = 0; a <n; a++)				//Logic to print out the generate mine field
	{
		cout<<" "<<setfill('-')<<setw(5*n)<<"\n";
		unsigned int p=1;
		while(p<=n)
			{
			cout<<"|"<<"    ";
			p++;
			}
			cout<<"|"<<endl;
			for(unsigned int b=0; b<n; b++)
			{
				if(vec[a][b]==true)
				{
					cout<<"|"<<"  "<<"X"<<" ";
				}
				else
				{
					cout<<"|"<<"  "<<" "<<" ";
				}
			}
			cout<<"|"<<"\n";
			p=1;
			while(p<=n)
			{
				cout<<"|"<<"    ";
				p++;
			}
			cout<<"|"<<endl;
	}
			cout<<" "<<setfill('-')<<setw(5*n)<<"\n";
			cout<<endl<<endl;
}

/**************************************************************************************************************************************
Function displayMineCounts(vector< vector<unsigned int> > &): Displays the minecounts for each mine locations.
***************************************************************************************************************************************/

void displayMineCounts(vector< vector<unsigned int> > & count)	//Display minecounts function takes a vector of vector  unsigned integers and prints out the table containing the counts
{	
	unsigned int n=count.size();				//Declare a variable  initialized to the size of the vector
        for(unsigned int a=0;a<n;a++)				//Logic to print out the table
        {
       	    cout<<" "<<setfill('-')<<setw(5*n)<<"\n";
	    unsigned int p=1;
		while(p<=n)
		{
		cout<<"|"<<"    ";
		p++;
		}
		cout<<"|"<<endl;
		for(unsigned int b=0;b<n;b++)
		{
		cout<<"|"<<"  "<<count[a][b]<<" ";
		}
		cout<<"|"<<"\n";
		p=1;
		while(p<=n)
		{
		cout<<"|"<<"    ";
		p++;
		}
	   cout<<"|"<<endl;
	}
	 cout<<" "<<setfill('-')<<setw(5*n);
         cout<<" "<<setfill('-')<<setw(5*n)<<endl;
	 cout<<endl;
}


