#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(void){
    int T;
    long N;
    int cnt=0,minm=0;
    char temp;
    scanf("%d",&T);
    long i;
    char* arr;
    char* tarr;
    int ocntr,ecntr,bflag,gflag;
    while(T>0){
        scanf("%ld",&N);
        arr= new char[2*N];
        tarr= new char[2*N];
        for(i=0;i<=2*N;i++)
            scanf("%c",&arr[i]);
        for(i=0;i<=2*N;i++)
            tarr[i]=arr[i];
        ocntr=1; ecntr=2;
        bflag=0; gflag=0;
        while(ocntr<=(2*N-1) && ecntr<=2*N){
            if(arr[ocntr]=='G'){
                gflag=1;
            }
            if(arr[ecntr]=='B'){
                bflag=1;
            }
            if(bflag==1 && gflag==1){
                temp=arr[ocntr];
                arr[ocntr]= arr[ecntr];
                arr[ecntr]=temp;
                cnt++;
                bflag=0;
                gflag=0;
                ecntr+=2;
                ocntr+=2;
            }
            else if(bflag==1 && gflag==0)
                ocntr+=2;
            else if(gflag==1 && bflag==0)
                ecntr+=2;
            else{
                ocntr+=2;
                ecntr+=2;
            }
        }
        minm=cnt;

        cnt=0;
        ocntr=1;ecntr=2;
        bflag=0;gflag=0;
        while(ocntr<=(2*N-1) && ecntr<=2*N){
            if(tarr[ocntr]=='B'){
                bflag=1;
            }
            if(tarr[ecntr]=='G'){
                gflag=1;
            }
            if(bflag==1 && gflag==1){
                temp=tarr[ocntr];
                tarr[ocntr]= tarr[ecntr];
                tarr[ecntr]=temp;
                cnt++;
                bflag=0;
                gflag=0;
                ecntr+=2;
                ocntr+=2;
            }
            else if(bflag==1 && gflag==0)
                ecntr+=2;
            else if(gflag==1 && bflag==0)
                ocntr+=2;
            else{
                ocntr+=2;
                ecntr+=2;
            }
        }
        if(cnt<minm)
            printf("%d\n",cnt);
        else
            printf("%d\n",minm);
        T--;
        cnt=0;
        minm=0;
    }
    return 0;
}
