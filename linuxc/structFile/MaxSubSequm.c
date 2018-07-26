/*
给定K个整数组成的序列{ N
​1
​​ , N
​2
​​ , ..., N
​K
​​  }，“连续子列”被定义为{ N
​i
​​ , N
​i+1
​​ , ..., N
​j
​​  }，其中 1≤i≤j≤K。“最大子列和”则被定义为所有连续子列元素的和中最大者。例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续子列{ 11, -4, 13 }有最大的和20。现要求你编写程序，计算给定整数序列的最大子列和。

本题旨在测试各种不同的算法在各种数据情况下的表现。各组测试数据特点如下：

数据1：与样例等价，测试基本正确性；
数据2：102个随机整数；
数据3：103个随机整数；
数据4：104个随机整数；
数据5：105个随机整数；
输入格式:
输入第1行给出正整数K (≤100000)；第2行给出K个整数，其间以空格分隔。

输出格式:
在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。

输入样例:
6
-2 11 -4 13 -5 -2
输出样例:
20
*/

int MaxSubSequm1(int A[],int N);
int MaxSubSequm2(int A[],int N);
int MaxSubSequm3(int A[],int N);
int MaxSubSequm4(int A[],int N);
//算法复杂度O(N^3)
int MaxSubSequm1(int A[],int N)
{
	int thissum,maxsum = 0;
	int i,j,k;
	for(i=0;i<N;i++ ){//子列左端
		for(j=i;j<N;j++){//子列右端
			for(k=i;k<j;k++){
				thissum+=A[k];
			}
			if(thissum>maxsum)
				maxsum=thissum;
		}
	}
	return maxsum;
}
//算法复杂度O(N^2)
int MaxSubSequm2(int A[],int N)
{
	int thissum,maxsum = 0;
	int i,j,k;
	for(i=0;i<N;i++ ){//子列左端
		for(j=i;j<N;j++){//子列右端
				thissum+=A[j];
		if(thissum>maxsum)
			maxsum=thissum;
		}
	}
	return maxsum;
}

//算法复杂度0(N)
//在线处理，核心思想每输入一个数据就立即处理，任何一个地方终止输入，都能正确给我出当前解
int MaxSubSequm3(int A[],int N)
{
	int thissum,maxsum=0;
	int i;
	for(i=0;i<N;i++){
		thissum+=A[i];
		if(thissum>maxsum)
			maxsum=thissum;
		else if(thissum<0)
			thissum=0;
	}
	return maxsum;
}
//分而治之
int max3(int A,int B,int C)
{
	return A>B?A>C?A:C:B>C?B:C;
}
int DivideAndConquer(int List[],int left,int right)
{
	//初始化
	int maxleftsum,maxrightsum;//存放左右子问题的解
	int maxleftbordersum,maxrightbordersum;//存放跨分界线的结果
	
	int leftbordersum,rightbordersum;
	int center,i;

	if(left==right){//递归的终止条件，子列只有一个数字
		if(List[left]>0)
			return List[left];
		else
			return 0;
	}

	//分
	center = (left+right)/2;//找到中分点
	//递归求两边的最大子列和
	maxleftsum=DivideAndConquer(List,left,center);
	maxrightsum=DivideAndConquer(List,center+1,right);

	//跨分界线的最大子列和
	maxleftbordersum=0;
	leftbordersum=0;

	for(i=center;i>=left;i--)//中线向左扫描
	{
		leftbordersum+=List[i];
		if(leftbordersum>=maxleftbordersum)
			maxleftbordersum=leftbordersum;
	}

	maxrightbordersum=0;
	rightbordersum=0;

	for(i=center+1;i<=right;i++)//中线向左扫描
	{
		rightbordersum+=List[i];
		if(rightbordersum>=maxrightbordersum)
			maxrightbordersum=rightbordersum;
	}
	//递归结束时已经获取到了左，右，和边界三个地方的最大子列和,取最大值
	return max3(maxleftsum,maxrightsum,maxleftbordersum+maxrightbordersum);
}


int MaxSubSequm4(int List[],int N)
{
	return DivideAndConquer(List,0,N-1);
}

int main()
{
	int N;
	printf("请输入正整数K:");
	scanf("%d",&N);
	getchar();
	int List[N];
	printf("the list len is %d\n",sizeof(List)/sizeof(List[0]));
	printf("请输入具体K个正整数:");
	printf("the N is %d\n",N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&List[i]);
	}
	getchar();
	int sum=0;
	sum=MaxSubSequm4(List,N);
	printf("%d\n",sum);

}


