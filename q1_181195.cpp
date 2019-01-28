#include <iostream>
#include "Structure.h"
using namespace std;
bool Comparison(gitHubUser a, gitHubUser b)//This function compares two components of the 'gitHubUser' struct used by the editor
{
	int flag = 0;
	if(a.userName==b.userName)
		if(a.firstName==b.firstName)
			if(a.password==b.password)
				if(a.email==b.email)
					if(a.folderCount==b.folderCount)
						flag=1;
	if(flag==1)
		return true;
	return false;
}
bool exists(gitHubUser* arr, int size, string userName)// this checks wheather a string exists in an array or not
{
	for(int j=0 ; j<size ;j++)
	{
		if(userName==arr[j].userName)
		{
			return true;
		}
			
	}
	return false;
} 
void inputFromUser(gitHubUser* arr,int size)// This populates the User made from the struct
{
	for(int i=0; i<size ; i++)
	{
		cout<<"Enter the User name: ";
		cin>>arr[i].userName;
		for(int j=0 ; j<size ;j++)
		{
			if(arr[i].userName==arr[j+1].userName)
			{
				cout<<"This userName already exists, enter another userName";
				cin>>arr[i].userName;
				if(exists(arr,size,arr[i].userName)==true)
				{
					cout<<"This userName already exists, enter another userName";
					cin>>arr[i].userName;
				}
			}
			

		}
	}
}
gitHubUser* searchUser ( gitHubUser* users, int size, string userName)//This returns the address of the Username if it exists in the Username array
{
	for(int i=0 ; i<size ; i++)
	{
		if(users[i].userName==userName)
			return &users[i];
	}
} 
int main()
{
	gitHubUser* arr = new gitHubUser[4];
	inputFromUser(arr,4);
	searchUser(arr,4,"bilal");

	delete[] arr; 
}