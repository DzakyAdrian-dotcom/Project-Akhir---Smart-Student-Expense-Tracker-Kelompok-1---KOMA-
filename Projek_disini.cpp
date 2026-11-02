#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Batasan data sesuai Ketentuan Umum project
const int MAX_DATA = 100;
const int NUM_CAT = 6;
const string CATEGORIES[NUM_CAT] = {
    "Food", "Transportation", "Academic",
    "Entertainment", "Shopping", "Other"
};

// =========================================================================
// [ANGGOTA 2]: Struktur data utama (Mempertahankan draft struct Tristan)
// =========================================================================
struct transaksi {
    string ID;
    string kategori;
    int pengeluaran;
};

// =========================================================================
// IMPLEMENTASI FUNGSI MODULAR
// (Disiapkan dengan parameter agar setiap anggota tinggal mengisi logikanya)
// =========================================================================

// --- BAGIAN ANGGOTA 2: Input & Tampil Data ---

// Fungsi menambah transaksi
void AddData(transaksi data[], int &n) {
    // TODO [Anggota 2]: Masukkan data transaksi (ID, Kategori, Nominal Pengeluaran)
    cout << "\n--> [Fitur AddData: Sedang dikerjakan oleh Anggota 2]\n";
}

// Fungsi menampilkan data
void DisplayData(const transaksi data[], int n) {
    // TODO [Anggota 2]: Tampilkan semua daftar transaksi yang tersimpan
    cout << "\n--> [Fitur DisplayData: Sedang dikerjakan oleh Anggota 2]\n";
}


// --- BAGIAN ANGGOTA 3: Perhitungan Modular & Rekursif ---

// Fungsi menghitung total, rata-rata, pengeluaran tertinggi, dan pengeluaran terendah
void CalculateSummary(const transaksi data[], int n) {
    // TODO [Anggota 3]: Hitung total, mean, max, dan min pengeluaran
    cout << "\n--> [Fitur CalculateSummary: Sedang dikerjakan oleh Anggota 3]\n";
}

// Fungsi hitung total pengeluaran setiap kategori
void PengeluaranKategori(const transaksi data[], int n) {
    // TODO [Anggota 3]: Akumulasi pengeluaran per kategori & cari kategori terbesar
    cout << "\n--> [Fitur PengeluaranKategori: Sedang dikerjakan oleh Anggota 3]\n";
}

// Fungsi pembantu menghitung total pengeluaran secara rekursif (Wajib Rekursi)
int TotalRekursif(const transaksi data[], int n) {
    // Base case: jika tidak ada data
    if (n == 0) return 0;
    // Recursive case: amount data terakhir + total data sebelumnya
    return data[n - 1].pengeluaran + TotalRekursif(data, n - 1);
}

// Fungsi evaluasi status budget (safe <= 70%, warning 70%-90%, critical >= 90%)
string StatusBudget(double total, double budget) {
    if (budget <= 0) return "UNKNOWN";
    double percent = (total / budget) * 100.0;
    if (percent < 70.0) return "SAFE";
    else if (percent < 90.0) return "WARNING";
    else return "CRITICAL";
}

// Prosedur membaca input monthly budget dan menampilkan evaluasi status
void MenuBudget(const transaksi data[], int n, int &budget) {
    // TODO [Anggota 3]: Tampilkan budget, total, persentase, dan panggil StatusBudget
    if (budget <= 0) {
        cout << "\nMasukkan alokasi budget bulanan (Rp > 0): ";
        cin >> budget;
    }
    int total = TotalRekursif(data, n);
    double persentase = (budget > 0) ? ((double)total / budget * 100.0) : 0;
    string status = StatusBudget(total, budget);

    cout << "\n================= STATUS BUDGET BULANAN =================\n";
    cout << "  Budget Bulanan   : Rp " << budget << endl;
    cout << "  Total Pengeluaran: Rp " << total << endl;
    cout << "  Persentase Pakai : " << fixed << setprecision(1) << persentase << "%\n";
    cout << "  Status Evaluasi  : [" << status << "]\n";
    cout << "=========================================================\n";
}


// --- BAGIAN ANGGOTA 4: Algoritma Pengurutan & Pencarian Manual ---

// Fungsi urutkan transaksi (Manual Bubble Sort / Selection Sort)
void UrutkanTransaksi(transaksi data[], int n) {
    // TODO [Anggota 4]: Implementasikan algoritma sorting manual (by nominal/ID)
    cout << "\n--> [Fitur UrutkanTransaksi: Sedang dikerjakan oleh Anggota 4]\n";
}

// Fungsi cari transaksi (Manual Linear Search)
void CariTransaksi(const transaksi data[], int n) {
    // TODO [Anggota 4]: Implementasikan algoritma pencarian manual (by ID/Kategori)
    cout << "\n--> [Fitur CariTransaksi: Sedang dikerjakan oleh Anggota 4]\n";
}


// --- BAGIAN ANGGOTA 1: Sanitasi Input Menu (Helper) ---

// Fungsi membaca input menu agar tidak crash saat menerima input non-angka
int readMenuChoice() {
    int c;
    if (!(cin >> c)) {
        cin.clear();            // Reset status error stream
        cin.ignore(1000, '\n'); // Bersihkan sisa karakter di buffer
        return -1;              // Picu case default di switch
    }
    return c;
}


// =========================================================================
// [ANGGOTA 1]: ALGORITMA UTAMA & INTEGRASI MENU (main)
// =========================================================================
int main() {
    transaksi data[MAX_DATA];
    int n = 0;          // Jumlah record transaksi yang tersimpan
    int budget = 0;     // Alokasi budget bulanan
    int choice;

    do {
        cout << "\n=========================================\n";
        cout << "    SMART STUDENT EXPENSE TRACKER\n";
        cout << "          KELOMPOK 1 - KOMA\n";
        cout << "=========================================\n";
        cout << " 1. Tambah Transaksi\n";
        cout << " 2. Tampilkan Riwayat Transaksi\n";
        cout << " 3. Ringkasan Keuangan (Rata-rata/Max/Min)\n";
        cout << " 4. Total Pengeluaran per Kategori\n";
        cout << " 5. Budget Bulanan & Status Evaluasi\n";
        cout << " 6. Urutkan Transaksi (Sorting Manual)\n";
        cout << " 7. Cari Transaksi (Searching Manual)\n";
        cout << " 8. Hitung Total Pengeluaran (Rekursif)\n";
        cout << " 0. Keluar dari Program\n";
        cout << "-----------------------------------------\n";
        cout << "Pilih menu [0-8]: ";

        choice = readMenuChoice();

        switch (choice) {
            case 1:
                AddData(data, n);
                break;
            case 2:
                DisplayData(data, n);
                break;
            case 3:
                CalculateSummary(data, n);
                break;
            case 4:
                PengeluaranKategori(data, n);
                break;
            case 5:
                MenuBudget(data, n, budget);
                break;
            case 6:
                UrutkanTransaksi(data, n);
                break;
            case 7:
                CariTransaksi(data, n);
                break;
            case 8:
                cout << "\n[Rekursif] Total Pengeluaran: Rp " 
                     << TotalRekursif(data, n) << endl;
                break;
            case 0:
                cout << "\nTerima kasih telah menggunakan sistem ini. Sampai jumpa!\n\n";
                break;
            default:
                cout << "\n[!] Pilihan tidak valid. Silakan pilih menu angka 0 sampai 8.\n";
        }
    } while (choice != 0);

    return 0;
}
