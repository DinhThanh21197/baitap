#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include <sstream>
using namespace std;
// Dssv.txt   -> Dssv1.txt  
struct Sv
{
	string Name;
	string Id;
	string Gpa;
};
string Chuan_hoa_ten(string List_sv) {
	stringstream ss(List_sv); vector<string> s;
	string token, res;
	while (ss >> token)
	{
		s.push_back(token);
	}
	return s[s.size() - 1];
}
void Hoan_vi(Sv& a, Sv& b) {
	Sv tmp = a; a = b; b = tmp;
}
void Sap_xep(vector<Sv> &List_sv) {
	for (int i = 0; i < List_sv.size(); i++)
	{
		for (int j =i+1 ; j < List_sv.size() ; j++)
		{
			if (Chuan_hoa_ten(List_sv[i].Name)>Chuan_hoa_ten(List_sv[j].Name))
			{
				Hoan_vi(List_sv[i], List_sv[j]);
			}
		}
	}
}
void New_sv(vector<Sv> & List_sv) {
	cout << "nhap vao then cua sinh vien : ";
	Sv sv; cin.ignore(); getline(cin,sv.Name);
	cout << "nhap id sinh vien: ";
	cin >> sv.Id;
	cout<<"nhap gpa sinh vien: ";
	cin >> sv.Gpa;
	List_sv.push_back(sv);
}
void In_Dssv(vector<Sv> List_sv) {
	
	for (int i = 0; i < List_sv.size(); i++)
	{
		cout << i + 1 << ". " << " NAME: " << List_sv[i].Name << "  ID: " << List_sv[i].Id << "  GPA: " << List_sv[i].Gpa << endl;
	}
	
}
void Del_sv(vector<Sv>& List_sv) {
	cout << "nhap ten day du cua sinh vien muon xoa : ";
	string name; cin.ignore(); getline(cin, name);
	for (int i = 0; i < List_sv.size(); i++)
	{
		if (List_sv[i].Name==name)
		{
			 List_sv.erase( List_sv.begin() +i);
			 cout << "Da xoa sinh vien";
			 break;
		}
		
	}
}                 
void Search_sv(vector<Sv>& List_sv) {
	cout << "nhap ten day du cua sinh vien muon tim : ";
	string name; cin.ignore(); getline(cin, name);
	for (int i = 0; i < List_sv.size() ; i++)
	{
		if (List_sv[i].Name == name)
		{

			cout << "sinh vien co trong danh sach\n";
			break;
		}else
		 if (List_sv[List_sv.size() - 1].Name != name) {
			cout << "khong tim thay\n"; break;
		}
		

	}
}
void Read_file(vector<Sv>& List_sv) {
	fstream File_in;
	File_in.open("Dssv.txt", ios::in);
	while (File_in.eof() == false)
	{
		Sv sv; 
		
		getline(File_in, sv.Name,',');
		getline(File_in, sv.Id, ',');
		getline(File_in, sv.Gpa);
		List_sv.push_back(sv);
	}
	File_in.close();
}
void Export_file(vector<Sv> List_sv) {
	fstream File_out;
	File_out.open("Dssv1.txt", ios::out);	
	
	for (int i = 0; i < List_sv.size(); i++)
	{
		File_out  <<i+1<<". " << List_sv[i].Name << "," << List_sv[i].Id << "," << List_sv[i].Gpa << endl;
	}
	cout << " da cap nhat file Dssv1.txt\n";
	File_out.close();
}
void Menu() {
	
	cout << "\n------ MENU QUAN LY SINH VIEN------\n";
	cout << "1. Danh sach sinh vien\n";
	cout << "2. Them sinh vien\n";
	cout << "3. Xoa sinh vien \n";
	cout << "4. Tim kiem sinh vien\n";
	cout << "5. Sap xep danh sach\n";
	cout << "6. cap nhat file txt\n";
	cout << "0. Exit\n";
	cout << "-----------------------------------------\n";
}
int main(){
	vector<Sv> List_sv; int Lua_chon;
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
