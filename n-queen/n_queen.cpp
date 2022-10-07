#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
private:
    //私有函数--棋盘n*n以及返回结果res
    int n;
    vector<vector<string>> res;
    vector<bool> row;
    //对角线
    vector<bool> dig1;
    vector<bool> dig2;
    //函数---把棋子位置做改变
    vector<string> getOneRes(vector<int>& p){
        vector<string> board(n,string(n,'.'));//borad全是.
        for(int i=0;i<n;i++){
            board[i][p[i]]='Q';//p[i]--当前列的正确位置
        }
        return board;
    }
    void putCorrectPos(int index,vector<int>& p){
        if(index==n){
            //把一个正确结果存放到res中
            res.push_back(getOneRes(p));
            return;
        }
        for(int i=0;i<n;i++){
        if(!row[i]&&!dig1[index+i]&&!dig2[index-i+n-1]){//不冲突
            p.push_back(i);//取当前i
            row[i]=true;
            dig1[index+i]=true;
            dig2[index-i+n-1]=true;
            putCorrectPos(index+1,p);//递归
            //递归结束，还原标志
            row[i]=false;
            dig1[index+i]=false;
            dig2[index-i+n-1]=false;
            p.pop_back();
        }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
       this->n=n;
       if(n<=0) return res;
       row=vector<bool>(n,false);
       dig1=vector<bool>(2*n-1,false);
       dig2=vector<bool>(2*n-1,false);
       vector<int> p;//存放每一行需要放置的列的标号
       putCorrectPos(0,p);//index记录当前行号，用于结束递归
       return res;
    }
};
int main(){
    int n=5;
    vector<vector<string>> aa=Solution().solveNQueens(n);
    for(auto mm=aa.begin();mm!=aa.end();mm++){
       for(auto nn=(*mm).begin();nn!=(*mm).end();nn++)
       cout<<(*nn)<<endl;
       cout<<"******"<<endl;
    }
    return 0;
}