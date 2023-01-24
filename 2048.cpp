#include<bits/stdc++.h>
#include <conio.h>
#include <fstream>
using namespace std;
void save(int ** tablica)
{
    ofstream plik;
	plik.open("test1.txt");
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++)
        plik<<tablica[i][j]<<" ";

    }
    cout<<"Zapisano";
    plik.close();

}
void load(int ** tablica)
{
	ifstream plik;
	plik.open("test1.txt");
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			plik>>tablica[i][j];
		}
	}
	plik.close();
}
void upmove(int ** tablica)
{
	int i,j,li,ri;
	for(j=0;j<4;j++)
	{
		li=0,ri=j;
		for(i=1;i<4;i++)
		{
			if(tablica[i][j]!=0)
			{
				if(tablica[i-1][j]==0 || tablica[i-1][j]==tablica[i][j])
				{
					if(tablica[li][ri]==tablica[i][j])
					{
						tablica[li][ri]*=2;
						tablica[i][j]=0;
					}
					else
					{
						if(tablica[li][ri]==0)
						{
							tablica[li][ri]=tablica[i][j];
							tablica[i][j]=0;
						}
						else
						{
							tablica[++li][ri]=tablica[i][j];
							tablica[i][j]=0;
						}
					}
				}
				else li++;
			}
		}
	}
}

void downmove(int ** tablica)
{
	int i,j,li,ri;
	for(j=0;j<4;j++)
	{
		li=3,ri=j;
		for(i=2;i>=0;i--)
		{
			if(tablica[i][j]!=0)
			{
				if(tablica[i+1][j]==0 || tablica[i+1][j]==tablica[i][j])
				{
					if(tablica[li][ri]==tablica[i][j])
					{
						tablica[li][ri]*=2;
						tablica[i][j]=0;
					}
					else
					{
						if(tablica[li][ri]==0)
						{
							tablica[li][ri]=tablica[i][j];
							tablica[i][j]=0;
						}
						else
						{
							tablica[--li][ri]=tablica[i][j];
							tablica[i][j]=0;
						}
					}
				}
				else li--;
			}
		}
	}
}

void leftmove(int ** tablica)
{
	int i,j,li,ri;
	for(i=0;i<4;i++)
	{
		li=i,ri=0;
		for(j=1;j<4;j++)
		{
			if(tablica[i][j]!=0)
			{
				if(tablica[i][j-1]==0 || tablica[i][j-1]==tablica[i][j])
				{
					if(tablica[li][ri]==tablica[i][j])
					{
						tablica[li][ri]*=2;
						tablica[i][j]=0;
					}
					else
					{
						if(tablica[li][ri]==0)
						{
							tablica[li][ri]=tablica[i][j];
							tablica[i][j]=0;
						}
						else
						{
							tablica[li][++ri]=tablica[i][j];
							tablica[i][j]=0;
						}
					}
				}
				else ri++;
			}
		}
	}
}

void rightmove(int ** tablica)
{
	int i,j,li,ri;
	for(i=0;i<4;i++)
	{
		li=i,ri=3;
		for(j=2;j>=0;j--)
		{
			if(tablica[i][j]!=0)
			{
				if(tablica[i][j+1]==0 || tablica[i][j+1]==tablica[i][j])
				{
					if(tablica[li][ri]==tablica[i][j])
					{
						tablica[li][ri]*=2;
						tablica[i][j]=0;
					}
					else
					{
						if(tablica[li][ri]==0)
						{
							tablica[li][ri]=tablica[i][j];
							tablica[i][j]=0;
						}
						else
						{
							tablica[li][--ri]=tablica[i][j];
							tablica[i][j]=0;
						}
					}
				}
				else ri--;
			}
		}
	}
}

void addblock(int ** tablica)
{
	int li,ri;
	srand(time(0));
	while(1)
	{
		li=rand()%4;
		ri=rand()%4;
		if(tablica[li][ri]==0)
		{
			tablica[li][ri]=pow(2,li%2 + 1);
			break;
		}
	}

}

void disp(int ** tablica)
{
	cout<<"\n\t\tPress ESC to quit the game";
	cout<<"\n\t\tq-save game in file";
	
	cout<<"\n\n\n\n";
	int i,j;
	for(i=0;i<4;i++)
	{
		cout<<"\t\t\t\t-----------------\n\t\t\t\t";
		for(j=0;j<4;j++)
		{
			if(tablica[i][j]==0) cout<<"|   ";
			else
				cout<<"| "<<tablica[i][j]<<" ";
		}
		cout<<"|"<<endl;
	}
	cout<<"\t\t\t\t-----------------\n";
}

int check(int tmp[4][4],int ** tablica)
{
	int fl=1,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(tmp[i][j]!=tablica[i][j])
    		{
    			fl=0;
    			break;
			}
	return fl;
}

int checkover(int ** tablica)
{
	int fl=0,gl=0,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(tablica[i][j]==0)
    		{
    			fl=1;
				break;
			}

	for(i=0;i<3;i++)
    	for(j=0;j<3;j++)
    		if(tablica[i+1][j]==tablica[i][j] || tablica[i][j+1]==tablica[i][j])
    		{
    			gl=1;
    			break;
			}

	if(fl || gl) return 1;
	else return 0;
}


int main()
{
	cout<<"\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress any key to continue";
	getch();
	system("cls");
	int i1,i2,i3,i4,i,j;
	int ** tablica = new int * [4];
	tablica[0] = new int [4];   // wskaźnik tablica[0] wskazuje na nową tablicę
	tablica[1] = new int [4];   // wskaźnik tablica[1] wskazuje na nową tablicę
	tablica[2] = new int [4];
	tablica[3] = new int [4];
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			tablica[i][j]=0;
		}
	}
	int tmp[4][4]={0};
	srand(time(0));
	i1=rand()%4;
	i2=rand()%4;
	while(1)
	{
		i3=rand()%4;
		i4=rand()%4;
		if(i3!=i1 && i4!=i2) break;
	}
	tablica[i1][i2]=2;
	tablica[i3][i4]=4;
	disp(tablica);

	int ch;
	while (1)
    {
    	for(i=0;i<4;i++)
    		for(j=0;j<4;j++)
    			tmp[i][j]=tablica[i][j];
    	ch=getch();
    	system("cls");
    	cout<<ch;
    	if(ch==72) upmove(tablica);
    	if(ch==80) downmove(tablica);
    	if(ch==75) leftmove(tablica);
    	if(ch==77) rightmove(tablica);
    	if(ch==113) save(tablica);
    	
		if(ch==27) break;
        
		if(!check(tmp,tablica))
			addblock(tablica);
		disp(tablica);
	    if(ch==119) load(tablica);
		if(!checkover(tablica))
		{
			cout<<"\n\n\t\t\tGAME OVER!!\n\n\n";
			getch();
			break;
		}
	}
	delete [] tablica[0];
	delete [] tablica[1];
	delete [] tablica[2];
        delete [] tablica [3];
        delete [] tablica;
	return 0;
}
