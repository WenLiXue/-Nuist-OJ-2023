#include<iostream>
using namespace std;
int nums[1000000];
int main(){
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>nums[i];
    }
    int preDiff=0;
    int curDiff=0;
    int result=1; // ����Ϊ2����ʹ������������ȣ������г���Ҳ��һ��
    for (i=1;i<n;i++){
        curDiff = nums[i]-nums[i-1];
        // ���㵱ǰλ�õı仯����
        if ((curDiff<0 && preDiff>=0) || (curDiff>0 && preDiff<=0)){  
            // �����ǰλ�ú�ǰ��λ�õı仯�����෴
            //���г��ȼ�1������¼�仯����
            result++;
            preDiff = curDiff;
        }
    }
    cout<<n-result<<endl;
    return 0;
}

