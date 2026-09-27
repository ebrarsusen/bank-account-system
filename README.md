# Bank Account Management System

Basit, konsol tabanlı bir banka hesap yönetim sistemi. C++ ile yazılmıştır ve
nesne yönelimli programlama (OOP) prensiplerini pratik etmek amacıyla geliştirilmiştir.

## Özellikler

- Şifre korumalı giriş (3 deneme hakkı)
- Hesap bilgileri (hesap sahibi, hesap numarası, başlangıç bakiyesi)
- Para yatırma ve para çekme işlemleri
- Hatalı işlemlerde (negatif miktar, yetersiz bakiye) güvenli hata yönetimi
- Şüpheli işlem tespitinde hesabın otomatik bloke edilmesi
- Tüm işlemlerin `bank_log.txt` dosyasına otomatik kaydedilmesi

## Kullanılan Kavramlar

Bu proje, aşağıdaki C++ ve nesne yönelimli programlama kavramlarını
pekiştirmek için geliştirildi:

- **Encapsulation (Kapsülleme):** Hesap bilgileri (`private`) doğrudan
  dışarıdan erişilemez, sadece kontrollü `public` metodlar üzerinden değiştirilir.
- **Constructor:** Hesap nesnesi oluşturulurken bilgilerin otomatik atanması.
- **Exception Handling (throw / try / catch):** Hatalı işlemlerin
  (negatif tutar, yetersiz bakiye, yanlış şifre) güvenli şekilde ele alınması.
- **Dosya İşlemleri (fstream):** Programın her işlemi bir log dosyasına
  kalıcı olarak kaydetmesi.
- **static_cast:** C tarzı tip dönüşümü yerine, derleme zamanında kontrol
  sağlayan daha güvenli tip dönüşüm yönteminin kullanılması.
- **Header dosyaları ile bilgi ayırma:** Şifre gibi hassas bir bilgi, ana
  koddan (`main.cpp`) ayrı bir header dosyasında (`password.h`) tutulmuş ve bu
  dosya `.gitignore` ile GitHub'a gönderilmeyecek şekilde hariç tutulmuştur.
  *(Not: Gerçek bir üretim sisteminde şifreler bu şekilde açık tutulmaz, hash'lenerek
  saklanır. Burada proje kapsamını basit tutmak için bu yöntem tercih edilmiştir.)*

## Nasıl Çalıştırılır

Projeyi klonladıktan sonra, `main.cpp` ile aynı klasöre `password.h` adında bir
dosya oluşturup içine şunu ekleyin:

```cpp
int password = 1453;
```

Ardından derleyip çalıştırın:

```bash
g++ main.cpp -o main
./main
```

**Test için şifre: `1453`**

## Örnek Kullanım

```
**** Welcome to the Bank Account Management System! ****
Please enter the password: 1453
Password is correct. Access granted.
Account Owner: John Doe
Account Number: 123456
Account Balance: 1000.5 $

Enter your choice (you must enter 1, 2 or 3(exit)):
1. Deposit    2. Withdraw    3. Exit
1
Enter the amount you want to deposit: 500
Deposited: 500 $
New Balance: 1500.5 $
```