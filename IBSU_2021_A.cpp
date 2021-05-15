#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll b,n,a[10100],c[10100],bbb,bb,N;
void outt(int u)
{
	if (u<=9)
		cout<<u;
	else
		cout<<(char)(u-10+'A');
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>b;
	getline(cin,s);
	for (int t=0; t<4; t++)
	{
		getline(cin,s);
		n=s.size();
		for (int i=0; i<n; i++)
		{
			if (s[i]>='0' && s[i]<='9')
				a[i]=(int)(s[i]-'0');
			else
				a[i]=10+(int)(s[i]-'A');
		}
		reverse(a,a+n);
		for (int k=1; k<b; k++)
		{
			c[0]=k;
			bbb=0;
			bb=0;
			for (int i=0; i<10011; i++)
			{
				if (i<n)
				{
					c[i+1]=(c[i]-a[i]-bbb+b)%b;
					if (c[i]-a[i]-bbb<0)
						bbb=1;
					else
						bbb=0;
				}
				else
				{
					if (bbb==1)
					{
						c[i+1]=(c[i]-bbb+b)%b;
						if (c[i]-bbb<0)
							bbb=1;
						else
							bbb=0;
					}
					else
					{
						if (c[i]==k)
						{
							N=i;
							bb=1;
							break;
						}
						else
							break;
					}
				}
			}
			if (bb)
			{
				outt(k);
				for (int j=N-1; j>0; j--)
					outt(c[j]);
				cout<<endl;
				break;
			}
		}
		if (!bb)
		{
			cout<<0<<endl;
			continue;
		}
	}
	return 0;
}
