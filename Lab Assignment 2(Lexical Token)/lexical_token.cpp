#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    cout<<"GIVE THE s:"<<endl;
    string s;
    getline(cin>>ws,s);
    int n=s.length();
    //cout<<"s="<<s<<endl;
    for(int i=0;i<n;i++)
    {
        if(s[i]==' ')
        continue;
        else if(((s[i]>='a')&&(s[i]<='z'))||((s[i]>='A')&&(s[i]<='Z')))
        {
            if(s[i]=='i'&&s[i+1]=='f'&&s[i+2]==' ')
            {
                cout<<"(if,if)"<<endl;
                i=i+1;
            }
            else if(s[i]=='t'&&s[i+1]=='h'&&s[i+2]=='e'&&s[i+3]=='n'&&s[i+4]==' ')
            {
                cout<<"(then,then)"<<endl;
                i=i+3;
            }
            else if(s[i]=='e'&&s[i+1]=='l'&&s[i+2]=='s'&&s[i+3]=='e'&&s[i+4]==' ')
            {
                cout<<"(else,else)"<<endl;
                i=i+3;
            }
            else
            {  string l="";
               while(((s[i]>='a')&&(s[i]<='z'))||((s[i]>='A')&&(s[i]<='Z'))||s[i]>='0'&&s[i]<='9')
               {
                   l=l+s[i];
                   i++;
                   if(i==n)
                   break;
               }
               cout<<"(id,"<<l<<")"<<endl;
               if(i!=n-1)
               i--;
            }
            

        }
        else if((s[i]>='0')&&(s[i]<='9'))
        { string k= "";
            while((s[i]>='0')&&(s[i]<='9'))
            {
                k=k+s[i];
                i++;
                if(i==n)
                break;
            }
            cout<<"(number,"<<k<<")"<<endl;
            if(i!=n-1)
            i--;
        }
        else if(s[i]=='>'||s[i]=='<'||s[i]=='=')
        {
            if(s[i+1]=='=')
            {
                cout<<"(relop,"<<s[i]<<"=)"<<endl;
                i++;
            }
            else if(s[i+1]=='>')
            {
                cout<<"(relop,"<<s[i]<<">)"<<endl;
                i++;
            }
            else
            cout<<"(relop,"<<s[i]<<")"<<endl;
        }
        else
        {  string m; 
            while(!(((s[i]>='a')&&(s[i]<='z'))||((s[i]>='A')&&(s[i]<='Z'))||s[i]>='0'&&s[i]<='9'||s[i]=='>'||s[i]=='<'||s[i]=='='))
            {
               m=m+s[i];
               i++;
               if(i==n)
               break;
            }
            cout<<"(unidentified,"<<m<<")"<<endl;
            if(i!=n-1)
            i--;
        }
        
        

    }
    return 0;

}