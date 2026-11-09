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
    
    // Limitasi Jumlah Data Maksimum
    if (n >= MAX_DATA) {
        cout << "\n[!] Data penuh (maksimal " << MAX_DATA << " transaksi).\n";
        return;
    }
    transaksi t; 
    cout << "\n============ TAMBAH TRANSAKSI ============\n";

    // Input Kategori
    cout << "======== Pilih Kategori ========" << endl;
    for (int i = 0; i < NUM_CAT; i++) {
        cout << "  " << i + 1 << ". " << CATEGORIES[i] << endl;
    }

    int pilih;
    while (true) {
        cout << "Pilih kategori [1-" << NUM_CAT << "]: ";
        if (cin >> pilih && pilih >= 1 && pilih <= NUM_CAT) {
            cin.ignore(1000, '\n');
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[!] Pilihan tidak valid.\n";
    }
    t.kategori = CATEGORIES[pilih - 1];

    // Otomatisasi ID Berdasarkan Kategori
    char huruf = 'A' + (pilih - 1);
    int urutan = 1;
    for (int i = 0; i < n; i++) {
        if (data[i].kategori == t.kategori) {
            urutan++;
        }
    }
    t.ID = string(1, huruf);
    if (urutan < 10){ 
        t.ID += "0"; 
    }
    t.ID += to_string(urutan);


        // Input pengeluaran
    while (true) {
        cout << "Nominal pengeluaran (Rp): ";
        if (cin >> t.pengeluaran && t.pengeluaran > 0) {
            cin.ignore(1000, '\n');
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[!] Nominal harus berupa angka lebih dari 0.\n";
    }
    data[n] = t;
    n++;
    cout << "\n[OK] Transaksi berhasil ditambahkan.\n";
}

// Fungsi menampilkan data
void DisplayData(const transaksi data[], int n) {
    // TODO [Anggota 2]: Tampilkan semua daftar transaksi yang tersimpan
    if (n == 0) {
        cout << "\n[!] Belum ada transaksi yang tersimpan.\n";
        return;
    }

    cout << "\n==================== RIWAYAT TRANSAKSI ====================\n";
    for (int i = 0; i < n; i++) {
        cout << "TRANSAKSI NO: " << i+1 <<'\n';
        cout << "ID: " << data[i].ID << '\n';
        cout << "Kategori: " << data[i].kategori << '\n';
        cout << "Pengeluaran: Rp " << data[i].pengeluaran << '\n';
        if (i != n-1) {
            cout << '\n'; 
        }
    }
    cout << "-----------------------------------------------------------\n";
    cout << "Jumlah transaksi: " << n << endl;
}

// --- BAGIAN ANGGOTA 3: Perhitungan Modular & Rekursif ---

// Fungsi menghitung total, rata-rata, pengeluaran tertinggi, dan pengeluaran terendah
void CalculateSummary(const transaksi data[], int n) {
    // TODO [Anggota 3]: Hitung total, mean, max, dan min pengeluaran
    int Total_Pengeluaran = 0;
    float average = 0;
    int Index_Pengeluaran_Tertinggi = 0;
    int Index_Pengeluaran_Terendah = 0;
    int Pengeluaran_Tertinggi = data[0].pengeluaran;
    int Pengeluaran_Terendah = data[0].pengeluaran;
    for (int i = 0; i < n; i++) {
        Total_Pengeluaran += data[i].pengeluaran;
        if (data[i].pengeluaran > Pengeluaran_Tertinggi) {
            Pengeluaran_Tertinggi = data[i].pengeluaran;
            Index_Pengeluaran_Tertinggi = i;
        } else {
            if (data[i].pengeluaran < Pengeluaran_Terendah) {
                Pengeluaran_Terendah = data[i].pengeluaran;
                Index_Pengeluaran_Terendah = i;
            }
        }
    }
    average = float(Total_Pengeluaran)/ n;
    cout << "======== Ringkasan Keuangan ========" << endl;
    cout << "Total Pengeluaran = " << Total_Pengeluaran << endl;
    cout << "Rata-rata Pengeluaran = " << average << endl;
    cout << "===== Pengeluaran Tertinggi ===== " << endl;
    cout << "ID Transaksi = " << data[Index_Pengeluaran_Tertinggi].ID << endl;
    cout << "Kategori Transaksi = " << data[Index_Pengeluaran_Tertinggi].kategori << endl;
    cout << "Besar Pengeluaran = " << Pengeluaran_Tertinggi << endl;
    cout << "===== Pengeluaran Terendah ====== " << endl;
    cout << "ID Transaksi = " << data[Index_Pengeluaran_Terendah].ID << endl;
    cout << "Kategori Transaksi = " << data[Index_Pengeluaran_Terendah].kategori << endl;
    cout << "Besar Pengeluaran = " << Pengeluaran_Terendah << endl;
    cout << "\n--> [Fitur CalculateSummary: Sedang dikerjakan oleh Anggota 3]\n";
}

// Fungsi hitung total pengeluaran setiap kategori
void PengeluaranKategori(const transaksi data[], int n) {
    // TODO [Anggota 3]: Akumulasi pengeluaran per kategori & cari kategori terbesar
    int Total_Pengeluaran_Food = 0;
    int Total_Pengeluaran_Transportation = 0;
    int Total_Pengeluaran_Academic = 0;
    int Total_Pengeluaran_Entertainment = 0;
    int Total_Pengeluaran_Shopping = 0;
    int Total_Pengeluaran_Other = 0;
    for (int i = 0; i < n; i++) {
        if (data[i].kategori == "Food") {
            Total_Pengeluaran_Food += data[i].pengeluaran;
        } else if (data[i].kategori == "Transportation") {
            Total_Pengeluaran_Transportation += data[i].pengeluaran;
        } else if (data[i].kategori == "Academic") {
            Total_Pengeluaran_Academic += data[i].pengeluaran;
        } else if (data[i].kategori == "Entertainment") {
            Total_Pengeluaran_Entertainment += data[i].pengeluaran;
        } else if (data[i].kategori == "Shopping") {
            Total_Pengeluaran_Shopping += data[i].pengeluaran;
        } else  {
            if (data[i].kategori == "Other") {
                Total_Pengeluaran_Other += data[i].pengeluaran;
            } 
        } 
    }
    cout << "====== Total Pengeluaran Tiap Kategori ======" << endl;
    cout << "Total Pengeluaran Kategori Makanan = " << Total_Pengeluaran_Food << endl;
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
