#include<iostream>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<cmath>
#include<time.h>
#include<stdlib.h>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
// tao struct chuyen bay
struct chuyenbay
{
    string mscb;
    string hoten;
    string ngay;
    string thoigian;
    string noibay;
    string noiden;
};

// cau 1
// ham nhap thong tin chuyen bay
void Nhap_Thong_Tin_Chuyen_Bay(chuyenbay &x) {
    //nhap ma so chuyen bay
    do
    {
        cin.ignore();
        cout << "\nNhap ma chuyen bay: ";
        getline(cin, x.mscb);
        if (x.mscb.length() > 5)
        {
            cout << "\nThong tin ma chuyen bay ko hop le yeu cau nhap lai";

        }
        
    } while (x.mscb.length() > 5);
    
    // nhap ho ten hanh khach
    do
    {
        cin.ignore();
        cout << "\nNhap ho ten hanh khach co mat tren chuyen bay: ";
        getline(cin, x.hoten);
        if (x.hoten.length() > 30)
        {
            cout << "\nThong tin ho ten hanh khach ko hop le yeu cau nhap lai";

        }
        
    } while (x.hoten.length() > 30);

    // nhap ngay bay
    cin.ignore();
    cout << "\nNhap ngay bay cho chuyen bay: ";
    getline(cin, x.ngay);

    //nhap thoi gian bay
    cin.ignore();
    cout << "\nNhap thoi gian bay(vd 20:00:00): ";
    getline(cin, x.thoigian);

    // nhap noi di
    do
    {
        cin.ignore();
        cout << "\nNhap noi bay: ";
        getline(cin, x.noibay);
        if (x.noibay.length() > 20)
        {
            cout << "\nThong tin noi bay ko hop le yeu cau nhap lai";

        }
        
    } while (x.noibay.length() > 20);

    // nhap noi den
    do
    {
        cin.ignore();
        cout << "\nNhap noi den: ";
        getline(cin, x.noiden);
        if (x.noiden.length() > 20)
        {
            cout << "\nThong tin noi den ko hop le yeu cau nhap lai";

        }
        
    } while (x.noiden.length() > 20);
}

// ham xuat thong tin chuyen bay
void Xuat_Thong_Tin_Chuyen_Bay(chuyenbay x) {
    cout << "\nMa chuyen bay: " << x.mscb;
    cout << "\nHo ten hanh khach co mat tren chuyen bay: " << x.hoten;
    cout << "\nNgay bay: " << x.ngay;
    cout << "\nThoi gian bay: " << x.thoigian;
    cout << "\nNoi bay: " << x.noibay;
    cout << "\nNoi den: " << x.noiden;
}

struct list
{
    vector<chuyenbay> dscb;
    int n; // so luong chuyen bay ban dau can nhap thong tin

};

// cau 2
// ham nhap thong tin danh sach cho chuyen bay
void Nhap_Thong_Tin_Danh_Sach(list &ds) {
    cout << "\nNhap so luong chuyen bay can nhap thong tin: ";
    cin >> ds.n;
    ds.dscb.resize(ds.n);
    for (int i = 0; i < ds.n; i++)
    {
        cout << "\n==========NHAP THONG TIN CHUYEN BAY THU " << i + 1 << "==========";
        Nhap_Thong_Tin_Chuyen_Bay(ds.dscb[i]);
        ds.dscb.push_back(ds.dscb[i]);
    }
    
}

// ham xuat thong tin danh sach
void Xuat_Thong_Tin_Danh_Sach(list ds) {
    for (int i = 0; i < ds.n; i++)
    {
        cout << "\n==========THONG TIN CHUYEN BAY THU " << i + 1 << "===============";
        Xuat_Thong_Tin_Chuyen_Bay(ds.dscb[i]);
    }
    
}

// cau 3
// ham xoa 1 chuyen bay bat ki
void Xoa_1_Chuyen_Bay(list &ds, int vt) {
    for (int i = vt; i < ds.n; i++)
    {
        ds.dscb[i] = ds.dscb[i + 1];
    }
    ds.n--;
    ds.dscb.resize(ds.n);
    // c2:  ds.dscb.erase(ds.dscb.begin() + vt);
    // ds.dscb.resize(ds.n - 1);
    
}

// ham xoa chuyen bay theo ma code bat ki
void Xoa_Chuyen_Bay_Theo_Code(list &ds) {
    string codetemp;
    do
    {
        cin.ignore();
        cout << "\nNhap ma chuyen bay ban can xoa: ";
        getline(cin, codetemp);
        if (codetemp.length() > 5)
        {
            cout << "\n Ma so chuyen bay ko hop le yeu ca nhap lai";
        }
        
    } while (codetemp.length() > 5);

    for (int i = 0; i < ds.dscb.size(); i++)
    {
        if (strcmp(codetemp.c_str(), ds.dscb[i].mscb.c_str()) == 0) 
        {
            Xoa_1_Chuyen_Bay(ds, i);
            i--;
        }
        
    }
}

// cau 4
// ham them 1 chuyen bay vao danh sach
void Them_1_Chuyen_Bay(list &ds, chuyenbay &x) {
    Nhap_Thong_Tin_Chuyen_Bay(x);
    ds.dscb.push_back(x);
    ds.n++;
}

//cau 5
// ham hoan doi hai chuyen bay
void hoandoi(chuyenbay &x, chuyenbay &y) {
    chuyenbay temp;
    temp = x;
    x = y;
    y = temp; 
    
}

// ham cat nam
string Cat_Nam(string x) {
    string nam;
    for (int  i = x.length() - 1; i >= 0; i--)
    {
        if (x[i] != '/')
        {
            nam.insert(nam.begin() + 0, x[i]);
        }
        else {
            break;
        }
        
    }
    return nam;
}

// ham sap xep chuyen bay theo nam
void Sap_Xep_Chuyen_Bay_Theo_Nam(list &ds) {
    for (int i = 0; i < ds.n; i++)
    {
        for (int j = i + 1; j < ds.n; j++)
        {
            if (Cat_Nam(ds.dscb[i].ngay) > Cat_Nam(ds.dscb[j].ngay) )
            {
                hoandoi(ds.dscb[i], ds.dscb[j]);
            }
            
        }
        
    }
    
}

// cau 6
// ham cat ngay
string Cat_Ngay(string x) {
    string ngay;
    for (int  i = 0; i < x.length(); i++)
    {
        if (x[i] != '/')
        {
            ngay.insert(ngay.end() + 0, x[i]);
        }
        else {
            break;
        }
        
    }
    return ngay;
}

// ham tim kiem chuyen bay
void Tim_Kiem_Chuyen_Bay_Ngay_Bay(list &ds) {
    string ngay1;
    cin.ignore();
    cout << "\nNhap ngay cua chuyen bay ban muon tim kiem: ";
    getline(cin, ngay1);
    int k = 0; // bien dem so chuyen bay co cung ngay tim kiem
    for (int i = 0; i < ds.n; i++)
    {
        if (ngay1 == Cat_Ngay(ds.dscb[i].ngay))
        {
            cout << "\n==========THONG TIN CHUYEN BAY THU  " << k + 1 << " CO CUNG NGAY BAY TIM KIEM============= ";
            Xuat_Thong_Tin_Chuyen_Bay(ds.dscb[i]);
            k++;
        }
        
    }
    
}

// cau 7
// ham tim kiem chuyen bay theo ma chuyen bay bat ki
void Tim_Kiem_Chuyen_Bay_Voi_Ma_Chuyen_Bay(list &ds) {
    string mscb1;
    int k = 0; // bien dem so chuyen bay co cung ma so chuyen bay
    cin.ignore();
    cout << "\nNhap ma so chuyen bay can tim kiem: ";
    getline(cin, mscb1);
    for (int i = 0; i < ds.n; i++)
    {
        if (mscb1 == ds.dscb[i].mscb)
        {
            cout << "\n=================THONG TIN CHUYEN BAY CO MA SO CHUYUEN BAY CAN TIM THU " << k + 1 << "LA===========";
            Xuat_Thong_Tin_Chuyen_Bay(ds.dscb[i]);
            k++;
        }
        
    }
     
}

// cau 8 
// ham cat gio
string Cat_Gio(string s) {
    string hour;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ':')
        {
            hour.insert(hour.end() + 0, s[i]);
        }
        else{
            break;
        }
    }
    return hour;
}

// ham cat giay
string Cat_Giay(string s) {
    string sec;
    for (int i = s.length() - 1; i > 0; i--)
    {
        if (s[i] != ':')
        {
            sec.insert(sec.begin() + 0, s[i]);
        }
        else{
            break;
        }
    }
    return sec;
    
}

// ham cat phut
string Cat_Phut(string s) {
    string min;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i - 1] == ':')
        {
            min.insert(min.end() + 0, s.begin() + i, s.begin() + i + 2);
            break;
        }
        
    }
    return min;
    
}

// ham tim kiem chuyen bay theo khoang thoi gian bat ki
void Tim_Kiem_Chuyen_Bay_Theo_Thoi_Gian(list &ds) {
    string time1, time2;
    cout << "\nNhap khoang thoi gian ban muon tim kiem ";
    cin.ignore();
    cout << "\nNhap thoi gian dau(vd:20:00:23 ): ";
    getline(cin, time1);
    cin.ignore();
    cout << "\nNhap thoi gian cuoi(vd:20:00:23 ): ";
    getline(cin, time2);
    int k = 0; // bien dem cac chuyen bay co thoi gian can tim
    for (int i = 0; i < ds.n; i++)
    {
        if ((Cat_Gio(ds.dscb[i].thoigian) > Cat_Gio(time1)) && (Cat_Gio(ds.dscb[i].thoigian) < Cat_Gio(time2)))
        {
            cout << "\n===========THONG TIN CUA CHUYEN BAY CAN TIM THU " << k + 1 << "============";
            Xuat_Thong_Tin_Chuyen_Bay(ds.dscb[i]);
            k++;
            system("pause");
        }
        if ((Cat_Gio(ds.dscb[i].thoigian) == Cat_Gio(time1)) && (Cat_Gio(ds.dscb[i].thoigian) == Cat_Gio(time2)))
        {
            if ((Cat_Phut(ds.dscb[i].thoigian) > Cat_Phut(time1)) && (Cat_Phut(ds.dscb[i].thoigian) < Cat_Phut(time2)))
            {
                cout << "\n===========THONG TIN CUA CHUYEN BAY CAN TIM THU " << k + 1 << "============";
                Xuat_Thong_Tin_Chuyen_Bay(ds.dscb[i]);
                k++;
                system("pause");
                
            }
            if ((Cat_Phut(ds.dscb[i].thoigian) == Cat_Phut(time1)) && (Cat_Phut(ds.dscb[i].thoigian) == Cat_Phut(time2)))
            {
                if ((Cat_Giay(ds.dscb[i].thoigian) > Cat_Giay(time1)) && (Cat_Giay(ds.dscb[i].thoigian) < Cat_Giay(time2)))
                {
                    cout << "\n===========THONG TIN CUA CHUYEN BAY CAN TIM THU " << k + 1 << "============";
                    Xuat_Thong_Tin_Chuyen_Bay(ds.dscb[i]);
                    k++;
                    system("pause");
                }
                
            }
            
            
        }
        else {
            cout << "\nKhong co gio bay trong khoang thoi gian ("<< time1 <<","<< time2 <<")";
            break;
        }
        
    }
    
}

void Menu(list &ds) {
    int luachon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t================QUAN LI CHUYEN BAY====================";
        cout << "\n\n\t1. NHAP DANH SACH THONG TIN CHUYEN BAY";
        cout << "\n\n\t2. XUAT THONG TIN CAC CHUYEN BAY";
        cout << "\n\n\t3. XOA CHUYEN BAY CO MA CHUYEN BAY BAT KI";
        cout << "\n\n\t4. THEM CHUYEN BAY BAT KI VAO DANH SACH";
        cout << "\n\n\t5. SAP XEP CHUYEN BAY THEO THU TU TANG DAN THEO NAM BAY";
        cout << "\n\n\t6. TIM KIEM CAC CHUYEN BAY VOI NGAY BAY BAT KI";
        cout << "\n\n\t7. TIM KIEM CAC CHUYEN BAY CO MA CHUYEN BAY BAT KI";
        cout << "\n\n\t8. TIM KIEM CAC CHUYEN BAY NAM TRONG KHOANG THOI GIAN (X, Y)";
        cout << "\n\n\t\t================THANK YOU =============================";

        cout << "\n Moi ban nhap lua chon: ";
        cin >> luachon;

        if (luachon == 1)
        {
            Nhap_Thong_Tin_Danh_Sach(ds);
            system("pause");
        }

        else if (luachon == 2)
        {
            Xuat_Thong_Tin_Danh_Sach(ds);
            system("pause");
        }
        
        else if (luachon == 3)
        {
            Xoa_Chuyen_Bay_Theo_Code(ds);
            system("pause");
        }
        
        else if (luachon == 4)
        {
            chuyenbay x;
            Them_1_Chuyen_Bay(ds, x);
            system("pause");
        }
        
        else if (luachon == 5)
        {
            Sap_Xep_Chuyen_Bay_Theo_Nam(ds);
            system("pause");
        }
        
        else if (luachon == 6)
        {
            Tim_Kiem_Chuyen_Bay_Ngay_Bay(ds);
            system("pause");
        }

        else if (luachon == 7)
        {
            Tim_Kiem_Chuyen_Bay_Voi_Ma_Chuyen_Bay(ds);
            system("pause");
        }

        else if (luachon == 8)
        {
            Tim_Kiem_Chuyen_Bay_Theo_Thoi_Gian(ds);
            system("pause");
        }
        
        
        
    }
    
}


int main() {
    list dscb;
    Menu(dscb);
    
    return 0;
}