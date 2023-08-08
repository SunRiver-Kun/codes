/*  dp9环形数组的连续子数组最大和
描述
给定一个长度为 nn 的环形整数数组，请你求出该数组的 非空 连续子数组 的最大可能和 。

环形数组 意味着数组的末端将会与开头相连呈环状。例如，对于数组 [1,3,-5,2,-4][1,3,−5,2,−4]而言，第一个数 11的前一个数是最后一个数 -4−4。
*/

#include<cstdio>
#include<cstdlib>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int sum=0;
		int maxm=INT_MIN;
		int minm=INT_MAX;
		int cur_max=0,cur_min=0;
		int *num=(int *)malloc(sizeof(int)*(n+1));
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i]);
		}
		for(int i=1;i<=n;i++){
			cur_max=max(num[i],cur_max+num[i]);
			cur_min=min(num[i],cur_min+num[i]);
			maxm=max(cur_max,maxm);
			minm=min(cur_min,minm);
			sum+=num[i];
		}
		printf("%d\n",sum==minm ? maxm : max(maxm,sum-minm));
	}
}