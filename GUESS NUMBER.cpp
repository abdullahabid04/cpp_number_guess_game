#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	int number,guess=-1,count=0,limit=5,number_of_games=0,number_of_losses=0,number_of_wins=0;
	char option;
	string result;
	
	while(1)
	{
		srand(time(0));
		number=rand()%10;
		number_of_games++;
		while(number != guess)
		{
			if(count<limit)
			{
				cout<<"Enter your guess : ";
				cin>>guess;
				cout<<endl;
				count++;
			}
			else
			{
				number_of_losses++;
				result = "lose";
				break;
			}
			if(guess == number)
			{
				number_of_wins++;
			    result = "win";
			    break;
			}
		}
		cout<<endl<<endl<<"----------"<<endl;
		cout<<"Statistics"<<endl;
		cout<<"WIN/LOSE : "<<result<<endl;
		cout<<"Total moves "<<count<<endl;
		cout<<"secret number "<<number<<endl;
		if(result == "win")
		{
			cout<<"You guessed the number in "<<count<<" moves"<<endl;
		}
		else if(result == "lose")
		{
			cout<<"You did not guessed the number"<<endl;					
			cout<<"You are out of moves"<<endl;
			cout<<"The number is "<<number<<endl;
		}
		else
		{
			cout<<"invalid result"<<endl;
		}
		cout<<"Enter <N> for play again and <C> for quit"<<endl;
		cin>>option;
		switch(option)
		{
			case 'N':
				count = 0;
				system("cls");
				break;
			case 'C':
				system("cls");
				cout<<"--------------------"<<endl;
				cout<<"Final Statistics"<<endl;
				cout<<"Number of games played "<<number_of_games<<endl;
				cout<<"Number of games won "<<number_of_wins<<endl;
				cout<<"Number of games lost "<<number_of_losses<<endl;
				system("pause");
				exit(0);
		}
	}
}
