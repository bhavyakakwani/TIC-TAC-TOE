//PROJECT by Bhavya Kakwani
//PROJECT TOPIC: TIC-TAC-TOE GAME

#include<fstream>
#include<iostream>
#include<iomanip>
#include<string.h>
#include<conio.h>

using namespace std;

class tic_tac_toe
{
	private:

	char password[5];
	char username[15];
	int score;
	int played;
	int won;
	int lost;
	int draw;
	float winP;

	public:

	tic_tac_toe()
	{
		score = 0;
		played = 0;
		won = 0;
		lost = 0;
		draw = 0;
		winP = 0;
	}

	void getdata(char u[]);

	void display()
	{

		cout<<setw(17)<<username<<setw(12)<<played<<setw(10)<<won<<setw(8)<<lost<<setw(8)<<draw<<setw(9)<<score<<setw(11);
		if(played == 0)
		{
			cout<<"- \n";
		}
		else
		{
			cout<<fixed<<setprecision(2)<<winP<<"%"<<endl;
		}
	}

	void modify_p();

	char *getUsername()
	{
		return username;
	}

	char *getPassword()
	{
		return password;
	}

	float getScore()
	{
		return score;
	}

	void setScore(float score)
	{
		this->score = score;
	}

	int getPlayed()
	{
		return played;
	}

	int getWon()
	{
		return won;
	}

	int getLost()
	{
		return lost;
	}

	int getDraw()
	{
		return draw;
	}

	void increasePlayed()
	{
		played++;
	}

	void increaseWon()
	{
		won++;
	}

	void increaseLost()
	{
		lost++;
	}

	void increaseDraw()
	{
		draw++;
	}

	void calWinP()
	{
		winP = float(won) / played * 100;
	}

	float getWinP()
	{
		return winP;
	}
};

void addition()
{
	tic_tac_toe t, s;
	int nrec = 1;
	int flag = 0;
	fstream f;
	f.open("project.txt", ios::in|ios::binary|ios::app);
	f.seekg(0, ios::end);
	long int n = f.tellg();
	if(n == 0)
	nrec = 0;
	char u[15];
	cout<<"Enter the username : ";
	cin.sync();
	cin.getline(u, sizeof(u));
	if(nrec == 0)
	{
		t.getdata(u);
		f.write((char*)&t, sizeof(t));
	}
	else
	{
		f.seekg(0, ios::beg);
		while(f.read((char*)&s, sizeof(s)))
		{
			if(strcmpi(u,s.getUsername()) == 0)
			{
				cout<<"Username already exists, retry with another! \n";
				flag = 1;
				addition();
			}
		}
		if(flag == 0)
		{
			f.clear();
			t.getdata(u);
			f.write((char*)&t, sizeof(t));
		}
		f.close();
	}
}

void display(char a[][4])
{
	cout<<"        |      |       "<<endl;
	cout<<"     "<<a[0][0]<<"  |   "<<a[0][1]<<"  |  "<<a[0][2]<<"    "<<endl;
	cout<<"  ______|______|______ "<<endl;
	cout<<"        |      |       "<<endl;
	cout<<"     "<<a[1][0]<<"  |   "<<a[1][1]<<"  |  "<<a[1][2]<<"    "<<endl;
	cout<<"  ______|______|______ "<<endl;
	cout<<"        |      |       "<<endl;
	cout<<"     "<<a[2][0]<<"  |   "<<a[2][1]<<"  |  "<<a[2][2]<<"    "<<endl;
	cout<<"        |      |       "<<endl;
	cout<<endl;
}

void input(char a[][4],char v,int p)
{
	int i, j;
	char c;
	if(p == 1)
		c = '1';
	else if(p == 2)
		c = '2';
	else if(p == 3)
		c = '3';
	else if(p == 4)
		c = '4';
	else if(p == 5)
		c = '5';
	else if(p == 6)
		c = '6';
	else if(p == 7)
		c = '7';
	else if(p == 8)
		c = '8';
	else if(p == 9)
		c = '9';
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if(a[i][j] == c)
			a[i][j] = v;
		}
	}
	display(a);
}

int checkwin(char a[][4])
{
	int flag = 0;
	if(a[0][0] == 'O' && a[1][0] == 'O' && a[2][0] == 'O')
	{
		flag = 1;
	}
	else if(a[0][1] == 'O' && a[1][1] == 'O' && a[2][1] == 'O')
	{
		flag = 1;
	}
	else if(a[0][2] == 'O' && a[1][2] == 'O' && a[2][2] == 'O')
	{
		flag = 1;
	}
	else if(a[0][0] == 'O' && a[0][1] == 'O' && a[0][2] == 'O')
	{
		flag = 1;
	}
	else if(a[1][0] == 'O' && a[1][1] == 'O' && a[1][2] == 'O')
	{
		flag = 1;
	}
	else if(a[2][0] == 'O' && a[2][1] == 'O' && a[2][2] == 'O')
	{
		flag = 1;
	}
	else if(a[0][0] == 'O' && a[1][1] == 'O' && a[2][2] == 'O')
	{
		flag = 1;
	}
	else if(a[0][2] == 'O' && a[1][1] == 'O' && a[2][0] == 'O')
	{
		flag = 1;
	}
	else if(a[0][0] == 'X' && a[1][0] == 'X' && a[2][0] == 'X')
	{
		flag = -1;
	}
	else if(a[0][1] == 'X' && a[1][1] == 'X' && a[2][1] == 'X')
	{
		flag = -1;
	}
	else if(a[0][2] == 'X' && a[1][2] == 'X' && a[2][2] == 'X')
	{
		flag = -1;
	}
	else if(a[0][0] == 'X' && a[0][1] == 'X' && a[0][2] == 'X')
	{
		flag = -1;
	}
	else if(a[1][0] == 'X' && a[1][1] == 'X' && a[1][2] == 'X')
	{
		flag = -1;
	}
	else if(a[2][0] == 'X' && a[2][1] == 'X' && a[2][2] == 'X')
	{
		flag = -1;
	}
	else if(a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == 'X')
	{
		flag = -1;
	}
	else if(a[0][2] == 'X' && a[1][1] == 'X' && a[2][0] == 'X')
	{
		flag = -1;
	}
	return flag;
}

void play(char u1[],char u2[])
{
	tic_tac_toe t2;
	int i, j, k, flag = 0;
	char a[3][4] = {"123", "456", "789"}, v;
	int p[9]={0, 0, 0, 0, 0, 0, 0, 0, 0};
	for(k=0; k<9; k++)
	{
		system("cls");
		display(a);
		if(k%2 == 0)
		{
			cout<<"Chance for player 1"<<"("<<u1<<")(O)"<<endl;
			v = 'O';
		}
		else
		{
			cout<<"Chance for player 2"<<"("<<u2<<")(X)"<<endl;
			v = 'X';
		}
		cout<<"Enter a position(1-9) : ";
		cin>>p[k];
		cout<<endl;
		while(p[k]>9 || p[k]<1)
		{
			cout<<"Enter a valid position(1-9) : ";
			cin>>p[k];
		}
		for(i=0; i<k; i++)
		{
			while(p[i] == p[k])
			{
				cout<<"Enter a valid position(1-9) : ";
				cin>>p[k];
			}
		}
		input(a, v, p[k]);
		flag = checkwin(a);
		if(flag == 1 || flag == -1)
			break;
	}
	if(flag == 1)
	{
		cout<<'"'<<u1<<'"'<<" WINS! \n";
		tic_tac_toe t;
		ifstream if1;
		if1.open("project.txt", ios::binary);
		ofstream of1;
		of1.open("temp.txt", ios::binary);
		while(if1.read((char*)&t, sizeof(t)))
		{
			if(strcmp(u1, t.getUsername()) == 0)
			{
				float score = t.getScore();
				score += 2;
				t.setScore(score);
				t.increasePlayed();
				t.increaseWon();
				t.calWinP();
			}
			if(strcmp(u2, t.getUsername()) == 0)
			{
				float score = t.getScore();
				score--;
				t.setScore(score);
				t.increasePlayed();
				t.increaseLost();
				t.calWinP();
			}
			of1.write((char*)&t, sizeof(t));
		}
		if1.close();
		of1.close();
		remove("project.txt");
		rename("temp.txt", "project.txt");
	}
	else if(flag==-1)
	{
		cout<<'"'<<u2<<'"'<<" WINS! \n";
		tic_tac_toe t;
		ifstream if1;
		if1.open("project.txt", ios::binary);
		ofstream of1;
		of1.open("temp.txt", ios::binary);
		while(if1.read((char*)&t, sizeof(t)))
		{
			if(strcmp(u2, t.getUsername()) == 0)
			{
				float score = t.getScore();
				score += 2;
				t.setScore(score);
				t.increasePlayed();
				t.increaseWon();
				t.calWinP();
			}
			if(strcmp(u1, t.getUsername()) == 0)
			{
				float score = t.getScore();
				score--;
				t.setScore(score);
				t.increasePlayed();
				t.increaseLost();
				t.calWinP();
			}
			of1.write((char*)&t, sizeof(t));
		}
		if1.close();
		of1.close();
		remove("project.txt");
		rename("temp.txt", "project.txt");
	}
	else
	{
		cout<<"Match Drawn! \n";
		tic_tac_toe t;
		ifstream if1;
		if1.open("project.txt", ios::binary);
		ofstream of1;
		of1.open("temp.txt", ios::binary);
		while(if1.read((char*)&t, sizeof(t)))
		{
			if(strcmp(u1, t.getUsername()) == 0 || strcmp(u2, t.getUsername()) == 0)
			{
				float score = t.getScore();
				score++;
				t.setScore(score);
				t.increasePlayed();
				t.increaseDraw();
				t.calWinP();
			}
			of1.write((char*)&t, sizeof(t));
		}
		if1.close();
		of1.close();
		remove("project.txt");
		rename("temp.txt", "project.txt");
	}
}

int enterp(char uname[])
{
	tic_tac_toe t;
	char p[5];
	int flag=0,i;
	ifstream i1;
	i1.open("project.txt",ios::binary);
	cout<<"Enter your password : ";
	for(i=0;i<4;i++)
	{
		p[i]=getch();
		cout<<"*";
	}
	p[i]='\0';
	cout<<endl;
	while(i1.read((char*)&t,sizeof(t)))
	if(strcmp(uname,t.getUsername())==0)
	if(strcmp(p,t.getPassword())==0)
	{
		flag=1;
		break;
	}
	if(flag==0)
	{
		cout<<"Password entered is incorrect! \n";
	}
	i1.close();
	return flag;
}

int checkuser(char u[])
{
	int x = 0, flag = 0;
	ifstream i;
	i.open("project.txt", ios::binary);
	tic_tac_toe t;
	while(i.read((char*)&t, sizeof(t)))
	{
		if(strcmp(u, t.getUsername()) == 0)
		{
			flag = 1;
			break;
		}
	}
	i.close();
	if(flag == 1)
	{
		while(x == 0)
		x = enterp(u);
	}
	if(flag == 0)
	{
		cout<<"Username entered is incorrect! \n";
		cout<<"Enter a correct Username : ";
		cin.getline(u, sizeof(u));
	}
	return flag;
}

void sortrank()
{
	int i, j;
	ifstream if1;
	if1.open("project.txt", ios::binary);
	tic_tac_toe t[20];
	int n = 0;
	while(if1.read((char*)&t[n], sizeof(t[n])))
		n++;
	if1.close();
	tic_tac_toe c;
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-1; j++)
		if(t[j].getScore() < t[j+1].getScore())
		{
			c = t[j];
			t[j] = t[j+1];
			t[j+1] = c;
		}
	}
	ofstream of1;
	of1.open("project.txt", ios::binary);
	i = 0;
	while(i < n)
	{
		of1.write((char*)&t[i], sizeof(t[i]));
		i++;
	}
	of1.close();
}

void change_p(char n[])
{
	tic_tac_toe t;
	ifstream if1;
	if1.open("project.txt", ios::binary);
	ofstream of1;
	of1.open("temp.txt", ios::binary);
	while(if1.read((char*)&t, sizeof(t)))
	{
		if(strcmp(n, t.getUsername()) == 0)
		t.modify_p();
		of1.write((char*)&t, sizeof(t));
	}
	if1.close();
	of1.close();
	remove("project.txt");
	rename("temp.txt", "project.txt");
}

void delete_r(char n[])
{
	tic_tac_toe t;
	ifstream if1;
	if1.open("project.txt", ios::binary);
	ofstream of1;
	of1.open("temp.txt", ios::binary);
	while(if1.read((char*)&t, sizeof(t)))
	{
		if(strcmp(n, t.getUsername()) != 0)
		of1.write((char*)&t, sizeof(t));
	}
	if1.close();
	of1.close();
	remove("project.txt");
	rename("temp.txt", "project.txt");
}

int main()
{
	int c;
	char ch[4];
	do
	{
		cout<<"TIC-TAC-TOE \n\n";
		cout<<"Menu of choices :\n";
		cout<<"1) Create a new Account \n";
		cout<<"2) Play the Game \n";
		cout<<"3) Display your Record \n";
		cout<<"4) Display the Leaderboard \n";
		cout<<"5) Change your Password \n";
		cout<<"6) Remove your Account \n";
		cout<<"7) Exit \n";
		cout<<endl;
		cout<<"Enter your choice : ";
		cin>>c;
		system("cls");
		switch(c)
		{
			case 1:
				addition();
				cout<<"Account successfully created! \n";
				cout<<endl;
				break;
			case 2:
			{
				char u1[15], u2[15];
				int flag = 0;
				cout<<"Enter the username of player 1 : ";
				cin.sync();
				cin.getline(u1, sizeof(u1));
				while(flag == 0)
				flag = checkuser(u1);
				flag = 0;
				system("cls");
				cout<<"Enter the username of player 2 : ";
				cin.sync();
				cin.getline(u2, sizeof(u2));
				while(strcmp(u1, u2) == 0)
				{
					cout<<"'"<<u2<<"'"<<" already logged in! \n";
					cout<<"Try with another username! \n";
					cout<<"Enter the username of player 2 : ";
					cin.sync();
					cin.getline(u2, sizeof(u2));
				}
				while(flag == 0)
					flag = checkuser(u2);
				system("cls");
				play(u1, u2);
				cout<<endl;
				break;
			}
			case 3:
			{
				char c[15];
				cout<<"Enter your username : ";
				cin.sync();
				cin.getline(c, sizeof(c));
				int flag = 0;
				tic_tac_toe t;
				while(flag == 0)
				flag = checkuser(c);
				ifstream if1;
				if1.open("project.txt", ios::binary);
				cout<<endl;
				while(if1.read((char*)&t, sizeof(t)))
				if(strcmp(t.getUsername(), c) == 0)
				{
					cout<<" Username : "<<t.getUsername()<<endl;
					cout<<" Played   : "<<t.getPlayed()<<endl;
					cout<<" Won      : "<<t.getWon()<<endl;
					cout<<" Lost     : "<<t.getLost()<<endl;
					cout<<" Draw     : "<<t.getDraw()<<endl;
					cout<<" Score    : "<<t.getScore()<<endl;
					cout<<" Win%     : ";
					if(t.getPlayed() == 0)
					cout<<"- \n";
					else
					{
						cout<<fixed<<setprecision(2)<<t.getWinP()<<"%"<<endl;
					}
				}
				if1.close();
				cout<<endl;
				break;
			}
			case 4:
			{
				sortrank();
				tic_tac_toe t;
				int i = 1;
				cout<<"___________________________________________________________________________________\n";
				cout<<"| Rank |     Username     |   Played   |  Won  | Lost |  Draw  | Score |   Win%   |\n";
				cout<<"-----------------------------------------------------------------------------------\n";
				ifstream if1;
				if1.open("project.txt", ios::binary);
				while(if1.read((char*)&t, sizeof(t)))
				{
					cout<<setw(5)<<i;
					t.display();
					i++;
				}
				if1.close();
				cout<<"-----------------------------------------------------------------------------------\n";
				cout<<endl;
				break;
			}
			case 5:
			{
				char u[15];
				int flag = 0;
				cout<<"Enter your Username : ";
				cin.sync();
				cin.getline(u, sizeof(u));
				while(flag == 0)
					flag = checkuser(u);
				change_p(u);
				cout<<endl;
				break;
			}
			case 6:
			{
				char u[15], c[5];
				int flag = 0;
				cout<<"Enter your Username : ";
				cin.sync();
				cin.getline(u, sizeof(u));
				while(flag == 0)
					flag=checkuser(u);
				cout<<"Are you sure you want to proceed(Yes/No) : ";
				cin.sync();
				cin.getline(c, sizeof(c));
				if(strcmpi(c, "yes")==0)
				{
					delete_r(u);
					cout<<endl<<"Your Account has been successfully removed! \n";
				}
				cout<<endl;
				break;
			}
			case 7:
				exit(0);
			default :
				cout<<"Invalid Choice! \n";
				cout<<endl;
		}
		cout<<"Do you want to continue(Yes/No) : ";
		cin.sync();
		cin.getline(ch, sizeof(ch));
		system("cls");
	}while(strcmpi("yes", ch) == 0);
	return 0;
}

void tic_tac_toe::getdata(char u[])
{
	int i;
	strcpy(username, u);
	cout<<"Enter your 4 character Password : ";
	for(i=0; i<4; i++)
	{
		password[i] = getch();
		cout<<"*";
	}
	password[i] = '\0';
	cout<<endl;
}

void tic_tac_toe::modify_p()
{
	int i;
	cout<<"Enter your new password : ";
	for(i=0; i<4; i++)
	{
		password[i] = getch();
		cout<<"*";
	}
	password[i] = '\0';
	cout<<endl;
	cout<<"Your Password has been changed! \n";
}
