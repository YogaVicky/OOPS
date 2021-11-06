#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define M 3
#define N 3
#define K 2
int a[M][K]={{2,2},{2,2},{3,6}};
int b[K][N]={{8,7,6},{5,4,3}};
int c[M][N];
struct v{
	int i;
	int j;
};
void *runner(void *param){
	v *data = (v*)param;
	int n,sum=0;
	for(n=0;n<K;n++){
		sum+=a[data->i][n]*b[n][data->j];
	}
	c[data->i][data->j]=sum;
	pthread_exit(0);
}
int main(int argc,char *argv[]){
	int i,j,count=0;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			v *data = (v *)malloc(sizeof(struct v));
			data->i = i;
			data->j = j;
			pthread_t tid;
			pthread_attr_t attr;
			pthread_attr_init(&attr);
			pthread_create(&tid,&attr,runner,data);
			pthread_join(tid,NULL);
		}
	}
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%d\n", c[i][j]);
		}
	}
}