#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>

#define pause system("pause")
#define clear system("cls")

using namespace std;

int main()
{
	int number,guess=0,count=0,limit=5,number_of_games=0,number_of_losses=0,number_of_wins=0;
	bool moves_left = true;
	char option;
	string result;
	
	cout<<"\n\n\n\n\n\t\t\t\t\tWELCOME\n\n\t\t\t\t";
	pause;
	clear;
	
	while(1)
	{
		srand(time(0));
		number=rand()%10;
		number_of_games++;

		while(moves_left)
		{
			cout<<"Enter your guess : ";
			cin>>guess;
			cout<<endl;
			count++;

			if(guess == number)
			{
				number_of_wins++;
			    result = "win";
			    break;
			}
			else
			{
				if(count == limit)
				{
					moves_left = false;
				}
				else
				{
					cout<<"\nYour guess did not match the number.Try again\n\n";		
				}
			}
		}
		
		if(moves_left == false)
		{
			result = "lose";
			number_of_losses++;
		}	

		cout<<endl<<endl<<"----------"<<endl;
		cout<<"Statistics"<<endl;
		cout<<"WIN/LOSE : "<<result<<endl;
		cout<<"Total moves : "<<count<<endl;
		cout<<"secret number : "<<number<<endl;
		
		cout<<"Enter <N> for play again and <C> for quit"<<endl;
		cin>>option;

		switch(option)
		{
			case 'N':
				count = 0;
				moves_left = true;
				system("cls");
				break;
			case 'C':
				clear;
				cout<<"--------------------"<<endl;
				cout<<"Final Statistics"<<endl;
				cout<<"Number of games played : "<<number_of_games<<endl;
				cout<<"Number of games won : "<<number_of_wins<<endl;
				cout<<"Number of games lost : "<<number_of_losses<<endl;
				pause;
				clear;
				cout<<"\n\n\n\n\n\t\t\t\t\tGOOD BYE!";
				exit(0);
		}
	}
	
	return 0;
}
