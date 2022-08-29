#include <iostream>
#include <cstring>
using namespace std;

void createtable(char table[][4])
{
	int p = 49;
	for (int i = 0; i <= 3; i++)
		for (int j = 0; j <= 3; j++)
			if (i == 0 && j == 0)
				table[i][j] = ' ';
			else if (i == 0 || j == 0)
			{
				if (i == 0)
				{
					table[i][j] = toascii(p);
					p++;
					if (p == 52)
						p = 49;
				}
				else
				{
					table[i][j] = toascii(p);
					p++;
					if (p == 53)
						p = 49;
				}
			}
			else
			table[i][j] = '-';
	
	

	        
}



void showtable(char table[][4])
{
	
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
			cout << table[i][j]<<" ";
		cout << endl;
	}
	
	
}

void insert(char table[][4],int n)
{
	int x, y; 
	cout << "rand:" << " "; cin >> x;
	cout << "coloana:" << " "; cin >> y;
	if (table[x][y] == 'X' || table[x][y] == '0')
		cout << "Wrong" << endl;
	else if (n % 2 == 0)
		table[x][y] = 'X';
	     else
		    table[x][y] = '0';
	
}

bool win(char table[][4])
{
	if(table[1][1] == table[1][2] && table[1][1] == table[1][3] && table[1][1] !='-') //line1
	    return 1;
	if (table[2][1] == table[2][2] && table[2][1] == table[2][3] && table[2][1] != '-') //line2
		return 1;
	if (table[3][1] == table[3][2] && table[3][1] == table[3][3] && table[3][1] != '-') //line3
		return 1;
	if (table[1][1] == table[2][1] && table[1][1] == table[3][1] && table[1][1] != '-') //col1
		return 1;
	if (table[1][2] == table[2][2] && table[1][2] == table[3][2] && table[1][2] != '-') //col2
		return 1;
	if (table[1][3] == table[2][3] && table[1][3] == table[3][3] && table[1][3] != '-') //col3
		return 1;
	if (table[1][1] == table[2][2] && table[1][1] == table[3][3] && table[1][1] != '-') //diagp
		return 1;
	if (table[1][3] == table[2][2] && table[1][3] == table[3][1] && table[1][3] != '-') //diags
		return 1;
	return 0;
}




int main()
{
	char table[4][4];
	createtable(table);
	showtable(table);
	for (int i = 1; i <= 9; i++)
	{
		insert(table, i);
		showtable(table);
		if (win(table) == 1)
		{
			cout << "win";
			break;
		}
		

	}
    if (win(table) == 0)
		cout << "draw" << endl;


		return 0;

	}


