#include<iostream>
#include<string>
using namespace std;
void Xoa_Khoang_Trang_Thua_Dau_Va_Cuoi(string &str)
{
	// Bu?c 1: Xóa h?t t?t c? các kí t? kho?ng tr?ng th?a ? d?u chu?i
	// cho vòng l?p while l?p cho d?n khi nào ki?m tra kí t? d?u tiên - v? trí 0 không ph?i là kho?ng tr?ng thì d?ng
	while (str[0] == ' ')
	{
		str.erase(str.begin() + 0); // xóa kí t? t?i v? trí 0
	}


	// Bu?c 2: Xóa h?t t?t c? các kí t? kho?ng tr?ng th?a ? cu?i chu?i
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + str.length() - 1); // xóa kí t? t?i v? trí cu?i c?a chu?i
	}
}

// hàm xóa kho?ng tr?ng th?a ? gi?a các t?
void Xoa_Khoang_Trang_Giua_Cac_Tu(string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		// n?u 2 kí t? liên ti?p nhau mà là kho?ng tr?ng ==> xóa di 1 kí t?
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
}
int main()
{
	 /*tìm so luong tu cua chuoi a*/
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
