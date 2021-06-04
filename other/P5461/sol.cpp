#include <cstdio>
#include <iostream>
using namespace std;
int n,i,j;
long long a[3][3],b[5][5],c[9][9],d[17][17],e[33][33],f[65][65],g[129][129],h[257][257],k[513][513],l[1025][1025];
int main(){
     cin>>n;
     a[1][1]=0;
     a[1][2]=1;
     a[2][1]=1;
     a[2][2]=1;
     for(i=1;i<=2;i++)
        for(j=3;j<=4;j++)
            b[i][j]=a[i][j-2];
     for(i=3;i<=4;i++)
        for(j=1;j<=2;j++)
            b[i][j]=a[i-2][j];
     for(i=3;i<=4;i++)
        for(j=3;j<=4;j++)
            b[i][j]=a[i-2][j-2];
     for(i=1;i<=4;i++)
        for(j=5;j<=8;j++)
            c[i][j]=b[i][j-4];
     for(i=5;i<=8;i++)
        for(j=1;j<=4;j++)
            c[i][j]=b[i-4][j];
     for(i=5;i<=8;i++)
        for(j=5;j<=8;j++)
            c[i][j]=b[i-4][j-4];
     for(i=1;i<=8;i++)
        for(j=9;j<=16;j++)
            d[i][j]=c[i][j-8];
     for(i=9;i<=16;i++)
        for(j=1;j<=8;j++)
            d[i][j]=c[i-8][j];
     for(i=9;i<=16;i++)
        for(j=9;j<=16;j++)
            d[i][j]=c[i-8][j-8];
     for(i=1;i<=16;i++)
        for(j=17;j<=32;j++)
            e[i][j]=d[i][j-16];
     for(i=17;i<=32;i++)
        for(j=1;j<=16;j++)
            e[i][j]=d[i-16][j];
     for(i=17;i<=32;i++)
        for(j=17;j<=32;j++)
            e[i][j]=d[i-16][j-16];
     for(i=1;i<=32;i++)
        for(j=33;j<=64;j++)
            f[i][j]=e[i][j-32];
     for(i=33;i<=64;i++)
        for(j=1;j<=32;j++)
            f[i][j]=e[i-32][j];
     for(i=33;i<=64;i++)
        for(j=33;j<=64;j++)
            f[i][j]=e[i-32][j-32];
     for(i=1;i<=64;i++)
        for(j=65;j<=128;j++)
            g[i][j]=f[i][j-64];
     for(i=65;i<=128;i++)
        for(j=1;j<=64;j++)
            g[i][j]=f[i-64][j];
     for(i=65;i<=128;i++)
        for(j=65;j<=128;j++)
            g[i][j]=f[i-64][j-64];
     for(i=1;i<=128;i++)
        for(j=129;j<=256;j++)
            h[i][j]=g[i][j-128];
     for(i=129;i<=256;i++)
        for(j=1;j<=128;j++)
            h[i][j]=g[i-128][j];
     for(i=129;i<=256;i++)
        for(j=129;j<=256;j++)
            h[i][j]=g[i-128][j-128];
     for(i=1;i<=256;i++)
        for(j=257;j<=512;j++)
            k[i][j]=h[i][j-256];
     for(i=257;i<=512;i++)
        for(j=1;j<=256;j++)
            k[i][j]=h[i-256][j];
     for(i=257;i<=512;i++)
        for(j=257;j<=512;j++)
            k[i][j]=h[i-256][j-256];
     for(i=1;i<=512;i++)
        for(j=513;j<=1024;j++)
            l[i][j]=k[i][j-512];
     for(i=513;i<=1024;i++)
        for(j=1;j<=512;j++)
            l[i][j]=k[i-512][j];
     for(i=513;i<=1024;i++)
        for(j=513;j<=1024;j++)
            l[i][j]=k[i-512][j-512];

     if(n==1){
        for(i=1;i<=2;i++){
            for(j=1;j<=2;j++){
                cout<<a[i][j]<<' ';
            }
            cout<<endl;
        }
        return 0;
     }
     else if(n==2){
        for(i=1;i<=4;i++){
            for(j=1;j<=4;j++){
                cout<<b[i][j]<<' ';
            }
            cout<<endl;
        }
        return 0;
     }
     else if(n==3){
        for(i=1;i<=8;i++){
            for(j=1;j<=8;j++){
                cout<<c[i][j]<<' ';
            }
            cout<<endl;
        }
        return 0;
     }
     else if(n==4){
        for(i=1;i<=16;i++){
            for(j=1;j<=16;j++){
                cout<<d[i][j]<<' ';
            }
            cout<<endl;
        }
        return 0;
     }
     else if(n==5){
        for(i=1;i<=32;i++){
            for(j=1;j<=32;j++){
                cout<<e[i][j]<<' ';
            }
            cout<<endl;
        }
        return 0;
     }
     else if(n==6){
        for(i=1;i<=64;i++){
            for(j=1;j<=64;j++){
                cout<<f[i][j]<<' ';
            }
            cout<<endl;
        }
        return 0;
     }
     else if(n==7){
        for(i=1;i<=128;i++){
            for(j=1;j<=128;j++){
                cout<<g[i][j]<<' ';
            }
            cout<<endl;
        }
        return 0;
     }
     else if(n==8){
        for(i=1;i<=256;i++){
            for(j=1;j<=256;j++){
                cout<<h[i][j]<<' ';
            }
            cout<<endl;
        }
        return 0;
     }
     else if(n==9){
        for(i=1;i<=512;i++){
            for(j=1;j<=512;j++){
                cout<<k[i][j]<<' ';
            }
            cout<<endl;
        }
        return 0;
     }
     else if(n==10){
        for(i=1;i<=1024;i++){
            for(j=1;j<=1024;j++){
                cout<<l[i][j]<<' ';
            }
            cout<<endl;
        }
        return 0;
     }
}