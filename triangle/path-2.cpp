#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        //定义路径和数组path,每一行记录当前走到的最短路径
        vector<vector<int>> path(m,vector<int>(m));//path数组为m行m列
        //初始状态
        path[0][0]=triangle[0][0];
        //记下来由上一行更新这一行的结果
        //注意特点：当前行最左一定是上一行最左到达的，当前行最右一定是上一行最右到达的
        //除左右两端，中间的数可有两种，需要计算取最小
        for(int i=1;i<m;i++)//从第二行开始，第一行是初始状态
        {
           path[i][0]=path[i-1][0]+triangle[i][0];
           for(int j=1;j<i;j++)//遍历该行
           {
               path[i][j]=min(path[i-1][j-1],path[i-1][j])+triangle[i][j];
           }
           path[i][i]=path[i-1][i-1]+triangle[i][i];
        }
        //取path的最后一行的最小值
        return *min_element(path[m-1].begin(),path[m-1].end());}
};
int main(){
    vector<vector<int>> triangle={
        {2},
        {1,3},
        {5,4,7},
        {9,2,6,1}
    };
    cout<<Solution().minimumTotal(triangle);
    return 0;
}