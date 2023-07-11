#include<iostream>
using namespace std;
int arr[500010],temp[500010];
long long ans;								//��¼���������
//�鲢����
void merge_sort(int arr[], int temp[], int left, int mid, int right)
{
	int i = left, j = mid + 1;
	int k = left;
	//���ָ�ɵ����������������򣬲���������ĸ���
	while (i <= mid && j <= right)
	{
		if (arr[i] > arr[j])
		{
			ans += mid - i + 1;
			temp[k++] = arr[j++];
		}
		else
		{
			temp[k++] = arr[i++];
		}
	}
	//�ж����������е�Ԫ���Ƿ�ȫ��������������������
	while (i <= mid)
	{
		temp[k++] = arr[i++];
	}
	while (j <= right)
	{
		temp[k++] = arr[j++];
	}
	//����
	for (i = left; i <= right; i++)
	{
		arr[i] = temp[i];
	}
	return;
}
//������ָ�����򣬼��ָ���ֻ��һ��Ԫ��
void merge(int arr[], int left, int right, int temp[])
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge(arr, left, mid, temp);
		merge(arr, mid + 1, right,temp);
		merge_sort(arr, temp,left, mid, right);
	}
}
int main()
{
	int n;
	cin >> n;
	int i;
	for (i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	merge(arr, 1, n, temp);
	cout << ans << endl;
	return 0;
}

