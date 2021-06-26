/*
Approach:

>> Shift M leftwards by i 

>> Clear bits between [i,j] in N

>> Perform N=M|N

>> Return N in binary format

*/

#include<iostream>
using namespace std;

//utility to convert decimal to binary
void Dec2Bin(int n)                                                        
{
	//Used Bitwise operators bcoz they are faster than arithmetic operators
	//it can also be done by using arrays but it consumes extra space
	
	//ASSUMMING size of integer is 32 bit
	for(int i=31;i>=0;i--)
	{
		//traversing n bitwise
		int k=n>>i;
		if(k&1)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
		
	}
}

int ClearBits(int n,int i,int j)
{
	//I am using masking
	int allones=~0;  //if assumed 8 bits its equal to 11111111
	
	//creating masks to preserve bits on both sides of the interval [i,j] excluded
	int leftmask=allones<<(j+1);   // say i=2,j=4 : we get  11100000
	int rightmask=((1<<i)-1);        //we get 00000011
	
	int mask=leftmask|rightmask;   //we get 11100011
	
	//now its time to clear n. we use Bitwise AND here to preserve all the bits other than [i,j]
	int n_cleared=(n & mask);
	
	return n_cleared;
}

int main()
{
	//Assuming M and N are 32 bits
	
	int M,N,i,j;
	
	cout<<"\nEnter M (number to be inserted)"<<" ";
	cin>>M;
	
	int M_preserved=M;
	
	cout<<"\nEnter second number N (number where M is to be inserted)"<<" ";
	cin>>N;
	
	cout<<"\n\n\tRange(Note that i and j should have sufficient space to accomodate all bits of M)\n\n";

	cout<<"\nEnter lower limit of range"<<" ";
	cin>>i;
	cout<<"\nEnter upper limit of range"<<" ";
	cin>>j;
		
	//check to ensure that i and j should have sufficient space to accomodate all bits of M
	int count=0;
	while(M_preserved!=0)	
	{
		M_preserved=M_preserved>>1;
		count++;
	}
	
	cout<<"\nBits between i and j => "<<(j-i+1);
	cout<<"\nBits in M => "<<count;
	
	if(count<=(j-i+1) && (j>=i))  //bcoz j is upper limit
	{
		cout<<"\nM initial => "; Dec2Bin(M);
		cout<<"\nN initial => "; Dec2Bin(N);
		
		//Shift M leftwards by i
		M=M<<i;
		cout<<"\nM shifted => "; Dec2Bin(M);
	
		//Clear bits between [i,j] in N
		int N_cleared=ClearBits(N,i,j);
		
		cout<<"\nN cleared => "; Dec2Bin(N_cleared);
	
		//Perform N=M|N to get 1s and 0s at their proper places
		N=(M | N_cleared);
		
		cout<<"\nM & N => "; Dec2Bin(N);
	
		//Return N in binary format
		cout<<"\n\n Modified N => ";
		Dec2Bin(N);	
	}
	else
	{
		cout<<"\n\nThere is not enough space between i and j to accomodate all bits of M in N!";
	}
	
		
return 0;	
}
