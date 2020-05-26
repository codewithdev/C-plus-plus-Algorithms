#include<iostream>
using namespace std;
bool checkQueen(int board[][10], int i, int j, int n){
	for(int row=0;row<i;row++){
		if(board[i][j]==1){
			return false;
		}
	}
	//check for Left Diagonal

	int x=i;
	int y=j;
	while(x>=0 and y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y--;
	}

        x=i;
	    y=j;
	while(x>=0 and y<n){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y++;
	}
	return true;
}

bool solveNqueen(int board[][10], int i, int n){
	if(i==n){
       for(int i=0;i<n;i++){
       	for(int j=0;j,n;j++){
       		if(board[i][j]==1){
       			cout<<" Q";
       		}
       		else{
       			cout<<"_ ";
       		}
       	}
       	cout<<endl;
       }
		//Print the Board

		return true;
	}
	for(int j=0;j<n;j++){
		if(checkQueen(board,i,j,n)){
			board[i][j]=1;
			bool nextQueenRakhpaye= solveNqueen(board,i+1,n);
			if(nextQueenRakhpaye){
				return true;
			}
			board[i][j]=0;
		}
	}
	return false;

	//Recursive Case
}
int main()
{
	int n;cin>>n;
	int board[10][10]={0};
    solveNqueen(board,0,n);
    return 0;
}