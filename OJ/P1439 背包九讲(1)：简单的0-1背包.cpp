//������һ�������dp��Ŀ
#include<iostream>
using namespace std;
typedef struct box						//��¼ÿ����Ʒ�����������
{
	int val;
	int weight;
}box;
box arr[100];							//�洢���е���Ʒ
int dp[100][20000];						//dp[i][j]�����ڱ�������Ϊj������£�װi����Ʒ������ֵ
int main()
{
	int n, v;
	while (cin >> v >> n)
	{
		int i, j;
		for (i = 1; i <= n; i++)
		{
			cin >> arr[i].weight >> arr[i].val;
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 0; j <= v; j++)
			{
			//�˴���dp�ľ������ڣ�����д״̬ת�Ʒ��̣�������������dp[i][j]������Ǳ�������Ϊj������£�װi����Ʒ������ֵ
			//Ҳ���Ƕ��ڵ�i����Ʒ�����ǿ���ѡ��װ���߲�װ���������Ҫװ��i����Ʒ�Ļ�����������Ҫ��֤��ǰ�ı��������㹻װ�µ�i����Ʒ����ô��ʱ����Ѽ�ֵӦ����dp[i-1][j-arr[i].weight]+arr[i].val.
			//�����װ����ô�͵���dp[i-1][j]
			//ȡ���ߵ����ֵ������dp[i][j]�����dp[n][v]��������ֵ
				if (j >= arr[i].weight)		dp[i][j] = max(dp[i - 1][j], arr[i].val + dp[i - 1][j - arr[i].weight]);
				else									dp[i][j] = dp[i - 1][j];
			}
		}
		cout << dp[n][v] << endl;
		for (i = 1; i <= n; i++)			//�����Ƕ������룬����ÿһ��ѭ���󣬾�Ҫ��dp�������
		{
			for (j = 0; j <= v; j++)
			{
				dp[i][j] = 0;
			}
		}
	}
	
	return 0;
}

