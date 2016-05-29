#include<bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#define mp make_pair
#define pb push_back
using namespace std;

bool comparator (const pair<int,int> &A, const pair<int,int> &B){
    if(A.second >= B.second)
        return 1;
    else
        return 0;
}

float distance_bw_centres(int x1,int y1, int z1, int x2, int y2, int z2){
    return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))+((z1-z2)*(z1-z2)));
}

bool isValid(float d, int r1, int r2){
    if(d<((r1*1.0)+(r2*1.0)-0.001))
        return false;
    else
        return true;
}

int main(void){
    int N;
    scanf("%d", &N);
    int *r, *c;
    r= new int[N];
    c= new int[N];
    for(int i=0; i<N; i++){
        scanf("%d %d", &r[i], &c[i]);
    }
    vector<pair<int,int>> V;
    for(int i=0; i<N; i++){
        V.pb(mp(r[i],c[i]));
    }
    sort(V.begin(),V.end(),&comparator);
    int *x, *y, *z;
    x= new int[N];
    y= new int[N];
    z= new int[N];
    x[0]=0; y[0]=0; z[0]=0;
    float d; int j=0;
    int xflag=0, yflag=0, zflag=0;
    printf("%d %d %d\n", x[j], y[j], z[j]);
    for(int i=1; i<N; i++){
        if (xflag==0){
            x[i]= V[i].first+V[j].first+x[j];
            y[i]= y[j];
            z[i]= z[j];
            d= distance_bw_centres(x[i], y[i], z[i], x[j], y[j], z[j]);
            if(isValid(d, V[i].first, V[j].first)== true){
                xflag=1;
                printf("%d %d %d\n", x[i], y[i], z[i]);
                continue;
            }
        }
        if (yflag==0){
                x[i] = x[j];
                y[i] = V[i].first + V[j].first+ y[j];
                z[i] = z[j];
            d= distance_bw_centres(x[i], y[i], z[i], x[j], y[j], z[j]);
            if(isValid(d, V[i].first, V[j].first)== true){
                yflag=1;
                printf("%d %d %d\n", x[i], y[i], z[i]);
                continue;
            }
        }
        if (zflag==0){
            x[i] = x[j];
            y[i] = y[j];
            z[i] = V[i].first + V[j].first+ z[j];
            d= distance_bw_centres(x[i], y[i], z[i], x[j], y[j], z[j]);
            if(isValid(d, V[i].first, V[j].first)== true){
                zflag=1;
                printf("%d %d %d\n", x[i], y[i], z[i]);
            }
        }
        xflag=0; yflag=0; zflag=0;
        j++;
    }
    return 0;
}
