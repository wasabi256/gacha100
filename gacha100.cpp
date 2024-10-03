#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h> // _kbhit() と _getch() を使用するためのヘッダ

std::random_device rd; // 非決定論的乱数生成器
std::mt19937 gen(rd()); // メルセンヌツイスタの初期化
std::uniform_int_distribution<> distrib(1, 100); // 1から100の一様分布

int gacha100(){
    int atari = 0;
    for(int i = 0;i < 100;i++){
        if(distrib(gen) == 1){
            ++atari;
        }
    }
    return atari;
}

int main(){

    SetConsoleOutputCP(CP_UTF8); // コンソール出力をUTF-8に設定

    long long kaisuu;
    std::cout << "[INFO]" << "試行回数を入力してください>";
    std::cin >> kaisuu; // ユーザーから試行回数を入力

    long long log = 1000000;
    long long n = kaisuu / log;
    long long amari = kaisuu % log;
    std::vector<long long> kekka(100,0);

    if(kaisuu <= 0){
        exit(1);
    }

    std::cout << "[INFO]" << "[START]" << log << "回区切りで実行" << std::endl;
    std::cout << "[INFO]" << "0/" << n + ((0 == amari) ? 0 : 1) << std::endl;

    for(long long i = 0;i < n;i++){
        for(long long j = 0; j < log;j++){
            ++kekka[gacha100()];
        }
        std::cout<< "[INFO]" << i + 1 << "/" << n + ((0 == amari) ? 0 : 1) << std::endl;
    }

    if(amari != 0){
        for (long long i = 0;i < amari;i++){
            ++kekka[gacha100()];
        }
        std::cout<< "[INFO]"  << n+1 << "/" << n+1 << std::endl;
    }

    while(!kekka.empty() && kekka.back() == 0){
        kekka.pop_back();
    }

    std::cout << "[RESULT]" << "-------------------------------------------------" << std::endl;
    std::cout << "[RESULT]" << "試行回数>" << kaisuu << "回" << std::endl;
    for(long long i = 0;i < kekka.size();i++){
        std::cout << "[RESULT]" << i << ":" << kekka[i] << std::endl;
    }

    std::cout << "Enterを押して終了>";
    while (true) {
        if (_kbhit()) { // キーが押されたかチェック
            char ch = _getch(); // 押されたキーを取得
            if (ch == '\r') { // エンターキーが押された
                break; // ループを終了
            }
        }
        // 任意の処理をここに書く
        Sleep(10); // CPU使用率を抑えるためのスリープ
    }
    return 0;
}

