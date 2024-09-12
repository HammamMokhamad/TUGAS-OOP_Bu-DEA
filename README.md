1. Deskripsi
Proyek ini adalah simulasi sederhana dari game gaya Diner Dash di mana pemain bertugas mengelola pesanan pelanggan di sebuah restoran. Tugas utama pemain adalah menempatkan pelanggan di meja, mengambil pesanan mereka, mengirimkan pesanan ke dapur untuk diproses, dan kemudian mengantarkan pesanan yang sudah selesai kembali ke pelanggan. Seiring waktu, emosi pelanggan akan menurun jika mereka menunggu terlalu lama, tetapi akan kembali meningkat ketika pesanan mereka diantarkan.

Proyek ini menggunakan konsep pemrograman berorientasi objek (OOP) seperti enkapsulasi, abstraksi, dan penerapan Single Responsibility Principle (SRP). Setiap kelas dalam proyek ini memiliki tanggung jawab spesifik, sehingga kode menjadi lebih modular, bersih, dan mudah untuk dipelihara.

Fitur
1. Pelanggan
Setiap pelanggan dapat memesan makanan dan memiliki tingkat emosi (dari 1 hingga 5, dengan 5 menjadi paling bahagia).
Emosi pelanggan akan menurun seiring waktu jika mereka terlalu lama menunggu pesanan.
Ketika pesanan diantarkan, tingkat emosi pelanggan akan kembali menjadi 5.
2. Meja
Setiap meja dapat ditempati oleh seorang pelanggan.
Meja akan melacak status pesanan pelanggan (baik NotYetTaken, InKitchen, atau Served).
Status pesanan diperbarui sesuai dengan perkembangan game.
3. Pelayan
Pelayan bertanggung jawab untuk mengambil pesanan dari pelanggan di meja dan mengirimkannya ke dapur.
Pelayan juga mengantarkan pesanan yang sudah selesai dari dapur kembali ke pelanggan.
4. Dapur
Dapur menerima pesanan dari pelayan dan menyiapkan makanan dalam waktu tertentu (disimulasikan selama 5 detik).
Setelah makanan siap, dapur memberi tahu pelayan untuk mengantarkannya.
5. Alur Simulasi
Alur permainan berjalan sebagai berikut:

Pelanggan ditempatkan di meja dan memesan makanan.
Pelayan mengambil pesanan dan mengirimkannya ke dapur.
Dapur menyiapkan pesanan.
Pelayan mengantarkan pesanan ketika sudah siap, dan emosi pelanggan kembali ke tingkat maksimal.
Kelas dan Tanggung Jawab
Customer (Pelanggan): Mengelola data pelanggan seperti nama, pesanan, dan tingkat emosi mereka. Juga menangani perubahan emosi selama mereka menunggu pesanan.
Table (Meja): Melacak pelanggan yang ditempatkan di meja dan menampilkan status pesanan pelanggan.
Waiter (Pelayan): Mengambil pesanan dari meja, mengirimkannya ke dapur, dan mengantarkan pesanan yang telah selesai kepada pelanggan.
Kitchen (Dapur): Menyiapkan pesanan makanan dan memberi tahu pelayan ketika pesanan siap diantarkan.
Cara Menjalankan Proyek
Clone Repository:
git clone <repository-url>

Masuk ke Direktori Proyek:
cd diner-dash-simulation

Kompilasi Kode: Gunakan kompiler C++ seperti g++ untuk mengompilasi proyek:
g++ -std=c++11 diner_dash.cpp -o diner_dash

Jalankan Program:
./diner_dash

Contoh Output
Table 1 - Order: Pasta - Status: Not Yet Taken
Table 2 - Order: Pizza - Status: Not Yet Taken
Waiter has taken order from Table John and sent it to the kitchen: Pasta
Waiter has taken order from Table Anna and sent it to the kitchen: Pizza
Kitchen is preparing the order for John...
Kitchen is preparing the order for Anna...
Order for John is ready!
Order for Anna is ready!
Waiter has delivered the order to Table John: Pasta
John's Emotion: 5/5
Waiter has delivered the order to Table Anna: Pizza
Anna's Emotion: 5/5
Table 1 - Order: Pasta - Status: Served
Table 2 - Order: Pizza - Status: Served

Struktur Proyek
diner_dash_simulation/
├── diner_dash.cpp  // File kode utama
└── README.md       // File dokumentasi
CONTACT:
Hammam Mokhamad (5223600064)
Indrasta Widyadana (5223600064)

