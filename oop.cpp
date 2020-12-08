#include<iostream>
#include<string>
#include<list>
using namespace std;
class SinhVien {
private: 
	int maSV;
	string hoTen;
public:
	SinhVien() {
		maSV = -1;
		hoTen = "";
	}
	SinhVien(int ma, string ten) {
		maSV = ma;
		hoTen = ten;
	}
	int getMaSV() {
		return maSV;
	}
	string getTen() {
		return hoTen;
	}
	void nhap() {
		cout << "Nhap ma sv: "; cin >> maSV;
		cin.ignore(1);
		cout << "Nhap ten sv: "; getline(cin, hoTen);
	}
	void xem() {
		cout << "Ma SV: " << maSV << "\t-\tTen SV: " << hoTen << endl;
	}
};
bool compareByCode(SinhVien a, SinhVien b) {
	return a.getMaSV() < b.getMaSV();
}
class Lop {
private:
	list<SinhVien> listSV;
public:
	list<SinhVien> getListSV() {
		return listSV;
	}
	void nhap() {
		int x;
		cout << "Nhap tong so sinh vien: "; cin >> x;
		SinhVien sv;
		for (int i = 0; i < x; i++) {
			sv.nhap();
			listSV.push_back(sv);
		}
		cout << "Nhap thanh cong!" << endl;
	}
	void xem() {
		cout << "Tong so sv: " << listSV.size() << endl;
		for (list<SinhVien> ::iterator it = listSV.begin(); it != listSV.end();it++) {
			it->xem();
		}
	}
	void sxTheoMa() {
		listSV.sort(compareByCode);
	}
};
class DiemSV : public SinhVien {
private:
	int diemThi;
	string ketQua;
public:
	DiemSV() {}
	DiemSV(int ma, string ten) : SinhVien(ma, ten) {
		diemThi = -1;
	}
	DiemSV(int ma, string ten, int diem, string ketQua) : SinhVien(ma, ten) {
		diemThi = diem;
		this->ketQua = ketQua;
	}
	string getKetQua() {
		return ketQua;
	}
	int getDiemThi() {
		return diemThi;
	}
	void nhap() {
		cout << "Nhap diem thi cua " << getTen() << ": "; cin >> diemThi;
		if (diemThi >= 5) ketQua = "Qua";
		else ketQua = "Thi lai";
	}
	void xem() {
		SinhVien::xem();
		cout << "Diem Thi: " << diemThi << endl;
		cout << "Ket Qua: " << ketQua << endl;
	}
};
class BangDiemThi {
private:
	string tenMonHoc;
	int tsQua, tsThiLai;
	list<DiemSV> listDiemSV;
public:
	BangDiemThi() {	}
	BangDiemThi(Lop l) {
		list<SinhVien> listSV = l.getListSV();
		list<SinhVien> :: iterator it;
		for (it = listSV.begin(); it != listSV.end();it++) {
			DiemSV diemSV(it->getMaSV(), it->getTen());
			listDiemSV.push_back(diemSV);
		}
	}
	BangDiemThi(string tenMonHoc, int tsQua, int tsThiLai, list<DiemSV> listDiemSV) {
		this->tenMonHoc = tenMonHoc;
		this->tsQua = tsQua;
		this->tsThiLai = tsThiLai;
		this->listDiemSV = listDiemSV;
	}
	void nhap() {
		cout << "Nhap ten mon hoc: "; getline(cin, tenMonHoc);
		for (list<DiemSV> ::iterator it = listDiemSV.begin(); it != listDiemSV.end(); it++) {
			it->nhap();
			if (it->getKetQua() == "Qua") tsQua++;
			else tsThiLai++;
		}
		cout << "Nhap thanh cong!" << endl;
	}
	void xem() {
		cout << "Ten mon hoc: " << tenMonHoc << endl;
		cout << "Tong so Qua: " << tsQua << endl;
		cout << "Tong so thi lai: " << tsThiLai << endl;
		for (list<DiemSV> ::iterator it = listDiemSV.begin(); it != listDiemSV.end(); it++) {
			it->xem();
		}
	}
};
int main() {
	Lop l;
	l.nhap();
	l.sxTheoMa();
	l.xem();

	BangDiemThi bangDiem(l);
	bangDiem.nhap();
    bangDiem.xem();
	return 0;
}