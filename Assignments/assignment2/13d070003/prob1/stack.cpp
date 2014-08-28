#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

// Global Variables
int N =0;
int stackSize1 = 0;
int stackSize2 = 0;

int stoint(string s) 
{															//convert string to integer
	int l , x , n = 0 , p;
	char c;
	l = s.length();
	for(x = l-1 ; x >=0 ; x--) 
	{
		c = s[x];
		p = c;
		p = p - 48;
		n = n + p*pow(10.0,l-1-x);
	}
	return n;
}

void push(int stackNo, int inputNo, int array[])
{
	// cout << inputNo <<endl;
	if(stackNo==0)
	{	
		if(stackSize1+stackSize2 < N )
		{
		array[stackSize1] = inputNo;
		stackSize1++;
		cout<<1<<endl;
		}

		else
		{
		cout <<-1<<endl;
		}	
	}

	else if(stackNo==1)
	{
		if(stackSize1+stackSize2 < N )
		{
			array[N-stackSize2-1] = inputNo;
			stackSize2++;
			cout <<1<<endl;	
		}

		else
		{
		cout <<-1<<endl;
		}		
	} 
}

void pop(int stackNo, int array[])
{
	if(stackNo==0)
	{
		if(stackSize1==0)
		{
			cout<<-1<<endl;
		}

		else
		{
			cout <<array[stackSize1-1]<<endl;
			array[stackSize1-1]=0;
			stackSize1 = stackSize1 -1;
		}
	}

	else if(stackNo==1)
	{
		if(stackSize2==0)
		{
			cout<<-1<<endl;
		}

		else
		{
		 cout<<array[N-stackSize2]<<endl;
		 array[N-stackSize2]=0;
		 stackSize2 = stackSize2 -1;		
		}	
	}
}

void peek(int stackNo, int array[])
{
	if(stackNo==0)
	{
		if(stackSize1 >0)
		cout<<array[stackSize1-1]<<endl;
		else
		{
			cout<<-1<<endl;	
		}
	}

	else if(stackNo==1)
	{	
		if(stackSize2 >0)
		cout<<array[N-stackSize2]<<endl;
		else
		{
			cout<<-1<<endl;	
		}
	}	

}

void isEmpty(int stackNo,int array[])
{	
	if(stackNo==0)
	{
		if(stackSize1==0)
			cout <<1<<endl;
		else 
		{
			cout<<0<<endl;	
		}
	}
	else if(stackNo==1)
	{
		if(stackSize2==0)
			cout<<1<<endl;
		else 
		{
			cout<<0<<endl;	
		}
	}
}


int main()

{
	cin >> N;
	int array[N];
	//initializing all members to 0

	for(int i =0;i<N;i++)
	{
		array[i] = 0;
	}
	
	// Accepting operations until finish of inputs
	// ifstream file("sample.txt",ios::in);
	int inputLength = 0;
	string input;
	string sn,no;
	while(getline(cin,input,'\n'))
		{ 
			no = "0";
			inputLength = input.length();
			sn = input[2];
			for (int i = 4; i < inputLength; i++)
			{
				no += input[i];	
			}
			if(input[0]=='0')
			{
				push(stoint(sn),stoint(no),array);
				// cout << array[1] <<endl;
			}	
			else if(input[0]=='1')	
			{
				pop(stoint(sn),array);
			}
			else if(input[0]=='2')
			{
				peek(stoint(sn),array);
			}
			else if(input[0]=='3')
			{
				isEmpty(stoint(sn),array);	
			}		

		}


}
