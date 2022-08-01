#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include <sstream>
using namespace std;
// Dssv.txt   -> Dssv3.txt
string Chuan_hoa_ten(string List_sv) {
	stringstream ss(List_sv); vector<string> s;
	string token, res;
	while (ss >> token)
	{
		s.push_back(token);
	}
	return s[s.size() - 1];
}
void Hoan_vi(string& a, string& b) {
	string tmp = a; a = b; b = tmp;
}
void Sap_xep(vector<string> &List_sv) {
	for (int i = 0; i < List_sv.size(); i++)
	{
		for (int j =i+1 ; j < List_sv.size() ; j++)
		{
			if (Chuan_hoa_ten(List_sv[i])>Chuan_hoa_ten(List_sv[j]))
			{
				Hoan_vi(List_sv[i], List_sv[j]);
			}
		}
	}
}
void New_sv(vector<string> & List_sv) {
	cout << "nhap vao then cua sinh vien : ";
	string name; cin.ignore(); getline(cin, name);
	List_sv.push_back(name);
}
void In_Dssv(vector<string> List_sv) {
	cout << "\t DANH SACH SINH VIEN \n";
	for (int i = 0; i < List_sv.size(); i++)
	{
		cout << i + 1 << ". " << List_sv[i] << endl;
	}
	
}
void Del_sv(vector<string>& List_sv) {
	cout << "nhap ten day du cua sinh vien muon xoa : ";
	string name; cin.ignore(); getline(cin, name);
	for (int i = 0; i < List_sv.size(); i++)
	{
		if (List_sv[i]==name)
		{
			 List_sv.erase( List_sv.begin() +i);
			 cout << "Da xoa sinh vien";
			 break;
		}
		
	}
}                 
void Search_sv(vector<string>& List_sv) {
	cout << "nhap ten day du cua sinh vien muon tim : ";
	string name; cin.ignore(); getline(cin, name);
	for (int i = 0; i < List_sv.size() ; i++)
	{
		if (List_sv[i] == name)
		{

			cout << "sinh vien co trong danh sach\n";
			break;
		}else
		 if (List_sv[List_sv.size() - 1] != name) {
			cout << "khong tim thay\n"; break;
		}
		

	}
}
void Read_file(vector<string>& List_sv) {
	fstream File_in;
	File_in.open("Dssv.txt", ios::in);
	while (File_in.eof() == false)
	{
		string name; getline(File_in, name);
		List_sv.push_back(name);
	}
	File_in.close();
}
void Export_file(vector<string> List_sv) {
	fstream File_out;
	File_out.open("Dssv3.txt", ios::out);
	File_out << "\t DANH SACH SINH VIEN ";
	for (int i = 0; i < List_sv.size(); i++)
	{
		File_out << i + 1 << ". " << List_sv[i] << "." << endl;
	}
	cout << " da xuat file Dssv2.txt";
	File_out.close();
}
void Menu() {

	cout << "------ MENU QUAN LY SINH VIEN------\n";
	cout << "1. Danh sach sinh vien\n";
	cout << "2. Them sinh vien\n";
	cout << "3. Xoa sinh vien \n";
	cout << "4. Tim kiem sinh vien\n";
	cout << "5. Sap xep danh sach\n";
	cout << "6. Xuat file txt\n";
	cout << "0. Exit\n";
	cout << "-----------------------------------------\n";
}
int main(){
	vector<string> List_sv; int Lua_chon;
	Read_file(List_sv);
	do
	{
		
		Menu();
		cin>> Lua_chon;
		switch (Lua_chon)
		{
		case 1:
               In_Dssv(List_sv); break;
		case 2:New_sv(List_sv); break;
		case 3:Del_sv(List_sv); break;
		case 4:Search_sv(List_sv); break;
		case 5: Sap_xep(List_sv); break;
		case 6:Export_file(List_sv); break;

		default:cout << "lua chon khong hop le";
			break;
		}
	} while (Lua_chon!=0);


}