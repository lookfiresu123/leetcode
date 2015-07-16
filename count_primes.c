#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define max 10000000
//#define min 10000

int countPrimes(int n) {
	int i,j = 0;
	int count_result = 0,count_info = 0;
	int sum = n-2;
	int m = (int)sqrt(n-1)+1;
	if(n <= 2)
		return 0;
	else{
		int *store = (int *)malloc(sum * sizeof(int));
		int *info = (int *)malloc(m * sizeof(int));
		//int *info_next = (int *)malloc(m * sizeof(int));
		int *result = (int *)malloc(sum * sizeof(int));
		// clock_t start_time=clock();
		for(i = 2;i <= n-1;i++)
			store[i-2] = i;
		for(i = 2;i <= m;i++)
			info[i-2] = i;
		// clock_t end_time=clock();
		// clock_t run_time_1 = end_time - start_time;
		// start_time = clock();
		int count_temp = m;
		while(j < count_temp){
			// if(store[j] != 0){
			// 	for(i = j;i <= n-3;i++){
			// 		if(store[i] != 0){
			// 			if(store[i] != store[j] && store[i] % store[j] == 0)
			// 				store[i] = 0;
			// 		}
			// 	}
			// }
			// j++;
			count_result = 0;
			count_info = 0;
			for(i=0;i<=j;i++){
				result[count_result++] = info[i];
				//info_next[count_info++] = info[i];
			}
			count_info = i;
			for(i=j+1;i<=sum-1;i++){
				if(store[i] % info[j] != 0){
					result[count_result++] = store[i];
					if(store[i] <= m)
						//info_next[count_info++] = store[i];
						info[count_info++] = store[i];
				}
			}
			store = result;
			//info = info_next;
			count_temp = count_info;
			sum = count_result;
			j++;

		}
		// end_time = clock();
		// clock_t run_time_2 = end_time - start_time;
		// start_time = clock();
		// for(i = 0;i < n-3;i++){
		// 	if(store[i] != 0){
		// 		//printf("%d\n",store[i]);
		// 		count_result++;
		// 	}
		// }
		// end_time = clock();
		// clock_t run_time_3 = end_time - start_time;
		// clock_t sum_run_time = run_time_1 + run_time_2 + run_time_3;
		//printf("%d\n",count);
		free(store);
	}
	return count_result;
}

int main(void){
	int n;
	int count;
	while(1){
		printf("input n\n");
		scanf("%d",&n);
		count = countPrimes(n);
		printf("%d\n",count);
	}
	return 0;
}
