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
void search(char head)//�ҵ�ÿ����ͷ
{
    for(int i=1;i<=n;i++)
    {
        if(words[i][0]==head)
        {
          h[k++]=i;
        }
    }
}
void compare(int tt)//��ÿ����ͷ���������
{
    int i;
    int countt;
    for( i=1;i<words[tt].length();i++)//����������ĸ������֮�䲻�ܰ���������ӵڶ�����ĸ��ʼ�Ƚϣ��������������֡�
    {
        countt=0;//���ڼ�¼����Ƚϵĵ��ʸ���
        for(int j=1;j<=n;j++)
        {
            if(times[j]<2)//�ж�ʹ�ô���
            {
            if(words[tt][i]==words[j][0])//�����һ�������еķ�����ĸ����һ����������ĸ��ͬ
            {
                int ii=i+1,inum=1,ij=1;
                while(ii<words[tt].length())//���¿��Ƿ���ͬ
                {
                    if(words[tt][ii]!=words[j][ij])
                    {
                        inum=0;//���в�ͬ��ʹ֮Ϊ�㣬�ȴ���һ�ο�ʼ
                        countt++;//���ʱȽϸ�����һ
                        break;
                    }
                    ii++;
                    ij++;//ʹ���½���
                    inum++;//��¼��ͬ��ĸ
                }
                if(ij!=words[j].length()&&ii==words[tt].length()&&inum!=0)//�˴�����inum!=0���ӻ�����ԣ���Ϊȷ����ʧ�������жϾ������Ͽ���
                {
                    maxx=maxx+words[j].length()-inum;
                    times[j]++;//���Ͻ���������¼���ȣ�����ʹ�ô�����һ
                    compare(j);//��Ѱ��һ�����������ĵ���
                    times[j]--;//����һ��
                    maxx=maxx-words[j].length()+inum;
                }
            }
           else countt++;//����©��
            }
           else countt++;//����©��
        }
        if(countt==n&&i==words[tt].length()-1)//�����һ������ʱ����һ�����ʵ�ȫ����ĸ������Ƚ���ÿ�����ʶ�����Ƚϣ��������������
        {
            smax=max(smax,maxx);//��¼���ֵ
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
    search(head);//Ѱ����ͷ
    for(int i=1;i<k;i++)
    {
        times[h[i]]++;
        maxx=words[h[i]].length();
        compare(h[i]);//��ÿ����ͷ�������
    }
    cout<<smax<<endl;
}


