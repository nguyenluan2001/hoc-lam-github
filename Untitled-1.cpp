#include<iostream>
#include<string>
using namespace std;
void Xoa_Khoang_Trang_Thua_Dau_Va_Cuoi(string &str)
{
	// Bu?c 1: X�a h?t t?t c? c�c k� t? kho?ng tr?ng th?a ? d?u chu?i
	// cho v�ng l?p while l?p cho d?n khi n�o ki?m tra k� t? d?u ti�n - v? tr� 0 kh�ng ph?i l� kho?ng tr?ng th� d?ng
	while (str[0] == ' ')
	{
		str.erase(str.begin() + 0); // x�a k� t? t?i v? tr� 0
	}


	// Bu?c 2: X�a h?t t?t c? c�c k� t? kho?ng tr?ng th?a ? cu?i chu?i
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + str.length() - 1); // x�a k� t? t?i v? tr� cu?i c?a chu?i
	}
}

// h�m x�a kho?ng tr?ng th?a ? gi?a c�c t?
void Xoa_Khoang_Trang_Giua_Cac_Tu(string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		// n?u 2 k� t? li�n ti?p nhau m� l� kho?ng tr?ng ==> x�a di 1 k� t?
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
}
int main()
{
	 /*t�m so luong tu cua chuoi a*/
	string a;
	fflush(stdin);
	getline(cin,a);
	if(a.length()==0)
	{
		cout<<"Chuoi rong.";
	}
	else
	{
		Xoa_Khoang_Trang_Thua_Dau_Va_Cuoi(a);
		Xoa_Khoang_Trang_Giua_Cac_Tu(a);
		int dem=0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]==' ')
		{
			dem++;
		}
	}
	/*gan chuoi con cua chuoi a cho moi phan tu chuoi b*/
	string b[dem+1];
	int k=0;
	int m=0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]==' ')
		{
			b[m]=a.substr(k,i-k);
			k=i+1;
			m++;
              
		};
	} 

    b[dem]=a.substr(k,a.length()-k);
   
    /*tim phan tu rieng biet trong mang chuoi b*/
    string c[100];
    int n=0;
    c[n]=b[0];
    n++;
    for(int k=1;k<dem+1;k++)
    {
    	    int count=0;

    	for(int l=k-1;l>=0;l--)
    	{
    		if(b[l]==b[k])
    		{
    			count++;
			}
		}
		if(count==0)
		{
			c[n]=b[k];
			n++;
		}
	}
	
	/*tan suat xuat hien cac tu trong chuoi a*/
	for(int e=0;e<n;e++)
	{    int dem1=0;
		for(int r=0;r<dem+1;r++)
		{
			if(c[e]==b[r])
			{
				dem1++;
			}
		}
		cout<<c[e]<<": "<<dem1<<endl<<endl;
	}
   
	}
    
    
	
	return 0;
}
