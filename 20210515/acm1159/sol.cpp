#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;
int map[10005][10005];
string str1,str2;
int len1,len2;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    while(cin>>str1>>str2) {
        len1=str1.length();
        len2=str2.length();
 
        for(int i=0;i<=len1;i++) {
            for(int j=0;j<=len2;j++) {
                if(i==0||j==0) {map[i][j]=0;continue;}
                if(str1[i-1]==str2[j-1]) {
                    map[i][j]=map[i-1][j-1]+1;
                }
                else
                    map[i][j]=max(map[i-1][j],map[i][j-1]);
            }
        }
        printf("%d\n", map[len1][len2]);
    }
    return 0;
}