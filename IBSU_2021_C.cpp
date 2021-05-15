#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll kmp[1000006],m[1006],m1[1006],m2[1006];
ll w[1006],w1[1006],w2[1006];
ll p[1000006],p1[1000006],p2[1000006],np[1000006];
ll n,n1,n2,nn,nn1,nn2,nnn,nnn1,nnn2;
ll b,bbb,bbbb,dz1,dz2,dz;
string s1,s2;
void outt(int u)
{
	if (u<=9)
		cout<<u;
	else
		cout<<(char)(u-10+'A');
	return;
}
void ckmp(int N)
{
    int id=0, i=1;
    while (i<N)
	{
        if (p[i]==p[id]) 
		{
            id++;
            kmp[i]=id;
            i++;
        }
        else
		{
            if (id!=0) 
                id=kmp[id-1];
            else
			{
                kmp[i]=id;
                i++;
            }
        }
    }
    return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>b;
	getline(cin,s1);
	getline(cin,s1);
	getline(cin,s2);
	
	//mteli
	
	for (int i=0; i<s1.size(); i++)
	{
		if (s1[i]=='.')
		{
			n1=i;
			break;
		}
		if (i==s1.size()-1)
			n1=s1.size();
		if (s1[i]>='0' && s1[i]<='9')
			m1[i]=(int)(s1[i]-'0');
		else
			m1[i]=10+(int)(s1[i]-'A');
	}
	reverse(m1,m1+n1);
	
	for (int i=0; i<s2.size(); i++)
	{
		if (s2[i]=='.')
		{
			n2=i;
			break;
		}
		if (i==s2.size()-1)
			n2=s2.size();
		if (s2[i]>='0' && s2[i]<='9')
			m2[i]=(int)(s2[i]-'0');
		else
			m2[i]=10+(int)(s2[i]-'A');
	}
	reverse(m2,m2+n2);
	
	//wiladi
	
	for (int i=n1+1; i<s1.size(); i++)
	{
		if (s1[i]=='(')
		{
			nn1=i-n1-1;
			break;
		}
		if (i==s1.size()-1)
			nn1=s1.size()-n1-1;
		if (s1[i]>='0' && s1[i]<='9')
			w1[i-n1-1]=(int)(s1[i]-'0');
		else
			w1[i-n1-1]=10+(int)(s1[i]-'A');
	}
	
	for (int i=n2+1; i<s2.size(); i++)
	{
		if (s2[i]=='(')
		{
			nn2=i-n2-1;
			break;
		}
		if (i==s2.size()-1)
			nn2=s2.size()-n2-1;
		if (s2[i]>='0' && s2[i]<='9')
			w2[i-n2-1]=(int)(s2[i]-'0');
		else
			w2[i-n2-1]=10+(int)(s2[i]-'A');
	}
	
	//periodi
	
	for (int i=n1+1+nn1+1; i<s1.size(); i++)
	{
		if (s1[i]==')')
		{
			nnn1=i-n1-1-nn1-1;
			break;
		}
		if (s1[i]>='0' && s1[i]<='9')
			p1[i-n1-1-nn1-1]=(int)(s1[i]-'0');
		else
			p1[i-n1-1-nn1-1]=10+(int)(s1[i]-'A');
	}
	
	for (int i=n2+1+nn2+1; i<s2.size(); i++)
	{
		if (s2[i]==')')
		{
			nnn2=i-n2-1-nn2-1;
			break;
		}
		if (s2[i]>='0' && s2[i]<='9')
			p2[i-n2-1-nn2-1]=(int)(s2[i]-'0');
		else
			p2[i-n2-1-nn2-1]=10+(int)(s2[i]-'A');
	}
	
	//wiladebis gatanabreba
	nn=max(nn1,nn2);
	if (nn1>=nn2)
	{
		dz2=(nn1-nn2)%nnn2;
		for (int i=0; i<nn1-nn2; i++)
			w2[nn2+i]=p2[i%nnn2];
	}
	else
	{
		dz1=(nn2-nn1)%nnn1;
		for (int i=0; i<nn2-nn1; i++)
			w1[nn1+i]=p1[i%nnn1];
	}
	reverse(w1,w1+nn);
	reverse(w2,w2+nn);
	
	for (int i=0; i<nnn1; i++)
		np[(i-dz1+nnn1)%nnn1]=p1[i];
	for (int i=0; i<nnn1; i++)
		p1[i]=np[i];
	for (int i=0; i<nnn2; i++)
		np[(i-dz2+nnn2)%nnn2]=p2[i];
	for (int i=0; i<nnn2; i++)
		p2[i]=np[i];
	reverse(p1,p1+nnn1);
	reverse(p2,p2+nnn2);
	
	//periodebis gatanabreba
	if (nnn1==0)
		nnn1=1;
	if (nnn2==0)
		nnn2=1;
	nnn=nnn1*nnn2/__gcd(nnn1,nnn2);
	for (int i=nnn1; i<nnn; i++)
		p1[i]=p1[i%nnn1];
	for (int i=nnn2; i<nnn; i++)
		p2[i]=p2[i%nnn2];
	
	
	
	//mtelebis gatanabreba
	n=max(n1,n2);
	
	//jami periodebis
	bbb=0;
	for (int i=0; i<nnn; i++)
	{
		p[i]=(p1[i]+p2[i]+bbb)%b;
		bbb=(p1[i]+p2[i]+bbb)/b;
	}
	bbbb=bbb;
	for (int i=0; i<nnn; i++)
	{
		if (!bbb)
			break;
		p[i]=(p[i]+bbb)%b;
		bbb=(p[i]+bbb)/b;
	}
	
	//periodis shemokleba
	if (nnn!=1)
	{
		ckmp(nnn);
	    bbb=nnn-1;
	    while (kmp[bbb]!=0)
	        bbb-=kmp[bbb];
	    nnn=bbb+1;	
	}
	
    
    //jami wiladebis
    bbb=bbbb;
	for (int i=0; i<nn; i++)
	{
		w[i]=(w1[i]+w2[i]+bbb)%b;
		bbb=(w1[i]+w2[i]+bbb)/b;
	}
	bbbb=bbb;
	
	//wiladis shemokleba
	dz=nnn-1;
	for (int i=nn-1; i>=0; i--)
	{
		if (w[i]==p[dz])
		{
			dz--;
			dz=(dz+nnn)%nnn;
			nn--;
		}
		else
			break;
	}
	for (int i=0; i<nnn; i++)
		np[(i+nnn-1-dz+nnn)%nnn]=p[i];
	for (int i=0; i<nnn; i++)
		p[i]=np[i];
	
	
	//kerdzo shemtxvevebi
	if (nnn==1 && p[0]==0)
	{
		nnn=0;
		bbb=0;
	}
	if (nnn==1 && p[0]==b-1)
	{
		nnn=0;
		bbb=1;
	}
	
	for (int i=0; i<nn; i++)
	{
		if (!bbb)
			break;
		w[i]=(w[i]+bbb)%b;
		bbb=(w[i]+bbb)/b;
	}
	bbbb+=bbb;
	
	//jami mtelebis
	bbb=bbbb;
	for (int i=0; i<n; i++)
	{
		m[i]=(m1[i]+m2[i]+bbb)%b;
		bbb=(m1[i]+m2[i]+bbb)/b;
	}
	bbbb=bbb;
	
	//mtelis shemokleba
	if (!bbbb)
	{
		for (int i=n-1; i>=0; i--)
		{
			if (m[i]==0)
				n--;
			else
				break;
		}
	}
	
	//gamotana mtelis
	if (bbbb==1)
		outt(bbbb);
	for (int i=n-1; i>=0; i--)
		outt(m[i]);
	
	if (nn>0 || nnn>0)
		cout<<'.';
	
	//gamotana wiladis
	for (int i=nn-1; i>=0; i--)
		outt(w[i]);
	
	//gamotana periodis
	if (nnn>0)
		cout<<'(';
	for (int i=nnn-1; i>=0; i--)
		outt(p[i]);
	if (nnn>0)
		cout<<')';
	cout<<endl;
	return 0;
}
