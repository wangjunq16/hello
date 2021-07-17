#include<iostream>
#include<vector>
using namespace std;

int n;      //�ʺ�ĸ���n
int P[20];  //��i�еĻʺ����ڵ�����ΪP[i]
bool hashTable[20] = { false };     //Ĭ�����лʺ�û����
vector<string> temp;            //temp�ݴ�һ��n�ʺ��λ�÷���
vector<vector<string>> ans;     //ans������սṹ

void generateP(int index) {
    if (index == n + 1) {
        for (int i = 1; i <= n; i++) {
            string t = "";    //�ַ���t��ʾ��i�еĴ洢���
            for (int j = 1; j <= n; j++) {
                if (j == P[i]) {
                    t += "Q";     //(P[i],i)�ʺ��λ��
                }
                else {
                    t += "*";
                }
            }
            temp.push_back(t);  //t��ŵ�temp��
        }
        ans.push_back(temp);    //���õ���һ����н�temp��ŵ�ans��
        temp.clear();           //temp�ÿ�
        return;                //�ݹ����
    }
    for (int x = 1; x <= n; x++) {
        if (hashTable[x] == false) {    //��x�л�û�з��ûʺ�
            bool flag = true;         //falg��ǰ���õĻʺ��Ƿ����֮ǰ���õĻʺ������ͻ
            for (int pre = 1; pre < index; pre++) {   //һ�α���index֮ǰ�Ļʺ��ж��Ƿ�������ͻ
                if (abs(index - pre) == abs(x - P[pre])) {     //�����ʺ���ͬһ�Խ�����
                    flag = false;
                    break;
                }
            }
            if (flag) {           //���������ͻ
                P[index] = x;     //��index�лʺ�����ڵ�x��
                hashTable[x] = true;  //��x���Ѿ������˻ʺ�
                generateP(index + 1); //�ݹ���õ�index+1�еĻʺ�
                hashTable[x] = false; //����
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