#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int times[50];
string words[21];
char head;
int n;
int h[21];
int k=1;
int maxx=0;
int smax=0;
void search(char head)//找到每个龙头
{
    for(int i=1;i<=n;i++)
    {
        if(words[i][0]==head)
        {
          h[k++]=i;
        }
    }
}
void compare(int tt)//对每个龙头情况的讨论
{
    int i;
    int countt;
    for( i=1;i<words[tt].length();i++)//遍历单词字母，单词之间不能包含，因而从第二个字母开始比较，避免包含问题出现。
    {
        countt=0;//用于记录参与比较的单词个数
        for(int j=1;j<=n;j++)
        {
            if(times[j]<2)//判断使用次数
            {
            if(words[tt][i]==words[j][0])//如果上一个单词中的非首字母与下一个单词首字母相同
            {
                int ii=i+1,inum=1,ij=1;
                while(ii<words[tt].length())//向下看是否相同
                {
                    if(words[tt][ii]!=words[j][ij])
                    {
                        inum=0;//若有不同则使之为零，等待下一次开始
                        countt++;//单词比较个数加一
                        break;
                    }
                    ii++;
                    ij++;//使向下进行
                    inum++;//记录相同字母
                }
                if(ij!=words[j].length()&&ii==words[tt].length()&&inum!=0)//此处条件inum!=0不加或许可以，但为确保无失误，条件判断尽可能严苛。
                {
                    maxx=maxx+words[j].length()-inum;
                    times[j]++;//符合接龙条件记录长度，单词使用次数加一
                    compare(j);//搜寻下一个符合条件的单词
                    times[j]--;//回溯一步
                    maxx=maxx-words[j].length()+inum;
                }
            }
           else countt++;//容易漏掉
            }
           else countt++;//容易漏掉
        }
        if(countt==n&&i==words[tt].length()-1)//当最后一次搜索时，上一个单词的全部字母都参与比较且每个单词都参与比较，这种情况结束。
        {
            smax=max(smax,maxx);//记录最大值
            return ;
        }
    }

}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>words[i];
    }
    cin>>head;
    search(head);//寻找龙头
    for(int i=1;i<k;i++)
    {
        times[h[i]]++;
        maxx=words[h[i]].length();
        compare(h[i]);//对每个龙头情况讨论
    }
    cout<<smax<<endl;
}


