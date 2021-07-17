#include<iostream>
#include<vector>
using namespace std;

int n;      //皇后的个数n
int P[20];  //第i列的皇后所在的行数为P[i]
bool hashTable[20] = { false };     //默认所有皇后还没放置
vector<string> temp;            //temp暂存一组n皇后的位置方案
vector<vector<string>> ans;     //ans存放最终结构

void generateP(int index) {
    if (index == n + 1) {
        for (int i = 1; i <= n; i++) {
            string t = "";    //字符串t表示第i行的存储情况
            for (int j = 1; j <= n; j++) {
                if (j == P[i]) {
                    t += "Q";     //(P[i],i)皇后的位置
                }
                else {
                    t += "*";
                }
            }
            temp.push_back(t);  //t存放到temp中
        }
        ans.push_back(temp);    //将得到的一组可行解temp存放到ans中
        temp.clear();           //temp置空
        return;                //递归结束
    }
    for (int x = 1; x <= n; x++) {
        if (hashTable[x] == false) {    //第x行还没有放置皇后
            bool flag = true;         //falg当前放置的皇后是否会与之前放置的皇后产生冲突
            for (int pre = 1; pre < index; pre++) {   //一次遍历index之前的皇后，判断是否会产生冲突
                if (abs(index - pre) == abs(x - P[pre])) {     //两个皇后在同一对角线上
                    flag = false;
                    break;
                }
            }
            if (flag) {           //不会产生冲突
                P[index] = x;     //第index列皇后放置在第x行
                hashTable[x] = true;  //第x行已经放置了皇后
                generateP(index + 1); //递归放置第index+1列的皇后
                hashTable[x] = false; //回溯
            }
        }
    }
}

vector<vector<string>> solveNQueens(int m) {
    n = m;
    generateP(1);
    return ans;
}


int main()
{

    solveNQueens(12);

    for (int k = 0; k < ans.size(); k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ans[i][j] << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << ans.size() << endl;
    return 0;
}