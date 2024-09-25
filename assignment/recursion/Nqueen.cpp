#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<char>>board,int row,int col){
    int n=board.size();

    //horizontal
    for(int i=0;i<n;i++){
        if(board[row][i]=='Q'){
            return false;
        }
    }

    //vertical
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }

    //diagonal left
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    //diagonal right
    for(int i=row,j=col;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;

}
void printBoard(vector<vector<char>>board){
     int n=board.size();
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
     }
     cout<<"------------------"<<endl;
}

int Nqueen(vector<vector<char>>board,int row){
    int n=board.size();
    if(row==n){
        printBoard(board);
        return 1;
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(isSafe(board,row,i)){
            board[row][i]='Q';
            count+=Nqueen(board,row+1);
            board[row][i]='.';
        }  
    }
    return count;
}

int main(){
    vector<vector<char>>board;
    int n=5;

    for(int i=0;i<n;i++){
        vector<char>newRow;
        for(int j=0;j<n;j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }

    int count=Nqueen(board,0);
    cout<<"Total no. of solution:"<<count<<endl;


    return 0;
}