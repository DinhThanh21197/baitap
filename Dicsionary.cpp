#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<sstream>
#include<algorithm>
//#include<io.h>
//#include<fcntl.h>
using namespace std;
void Read_file(map<string, string> &Dicsionary) {
	fstream File_in;
	File_in.open("dic.txt", ios::in);
	while (File_in.eof() == false)
	{
		
		string key; string value;
		getline(File_in, key ); // File_in-> key -> 
		
		getline(File_in, value, '@');
		
		Dicsionary.insert({ key,value });		// chuyen txt->    <map> Dicsionary
		cout << key<<endl;
	}
	File_in.close();
}
void Search(map<string, string> Dicsionary)
	{
	string Key_word;  
	cout << " nhap tu tieng anh can tim : "; cin >> Key_word;
	
	if (Dicsionary.find(Key_word) != Dicsionary.end())
	{
		cout << Dicsionary[Key_word]; 
		auto it = Dicsionary.find(Key_word);
		pair<string,string> x = *it;
		cout << Dicsionary[x.first];                                          //hàm tìm kiếm cchuooxi chưa hoàn thiện
	}
	else
	{
		cout << "NOT FOUD ";
	}
	
	}

int main() {
	map<string, string> Dicsionary; int choose;
	//_setmode(_fileno(stdin), _O_U16TEXT);  // chuan hoa tieng viet
	//_setmode(_fileno(stdout), _O_U16TEXT);
	cout << "-------------TU DIEN ANH - VIET--------------\n";
	cout << "Loading data, Please wait....................\n";
	Read_file(Dicsionary);
	cout << "so luong keyword la : " << Dicsionary.size()<<endl;
	do
	{
		cout << "1. tra tu \n";
		cout << "0. EXIT\n";
		cout << "nhap lua chon : \n";
		cin >> choose;
		switch (choose)
		{
		case 1:Search( Dicsionary); break;

		default:
			break;
		}

	} while (choose!=0);
	Search(Dicsionary);
	
	return 0;
}