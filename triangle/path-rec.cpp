#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
    vector<vector<int>> triangle;
    int pathLeastSum(int i,int j) {
         if(i==triangle.size()) return 0;//递归结束
         return //当前结点可以向左走，也可以向右走 
            triangle[i][j]+min(pathLeastSum(i+1,j),pathLeastSum(i+1,j+1));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
         this->triangle=triangle;
         return pathLeastSum(0,0);//从(0,0)开始出发
    }
};
int main(){
    vector<vector<int>> triangle={
         {1},
        {3,1},
     {-1,-2,-3},
        {9,7,6,8}
    };
    cout<<Solution().minimumTotal(triangle);
    return 0;
}