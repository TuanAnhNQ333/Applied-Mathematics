#include <iostream>
#include <string>
#include <map> // Bắt buộc phải có thư viện này để dùng map

using namespace std;

// Hàm kiểm tra số điện thoại
bool checkPhoneNumber(string pNum) {
    if (pNum.length() != 10) return false;
    for (auto a : pNum) {
        if (a < '0' || a > '9') {
            return false;
        }
    }
    return true;
}

// Hàm tính thời lượng cuộc gọi ra giây
int countTimeInt(string fTime, string eTime) {
    int start = 3600 * ((fTime[0] - '0') * 10 + fTime[1] - '0') +
                60 * ((fTime[3] - '0') * 10 + fTime[4] - '0') +
                ((fTime[6] - '0') * 10 + fTime[7] - '0');
    int end = 3600 * ((eTime[0] - '0') * 10 + eTime[1] - '0') +
              60 * ((eTime[3] - '0') * 10 + eTime[4] - '0') +
              ((eTime[6] - '0') * 10 + eTime[7] - '0');
    return end - start;
}

// KHAI BÁO MAP ĐÚNG
map<string, int> numberCalls;
map<string, int> timeCallFrom;

int checkPhone = 1; // Mặc định là đúng
int numCall = 0;

int main() {
    // Tối ưu tốc độ nhập xuất
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    string type;
    cin >> type;

    // PHẦN 1: ĐỌC DỮ LIỆU CUỘC GỌI (kết thúc khi gặp #)
    while (type == "call") {
        string fNum, tNum, date, fTime, eTime;
        cin >> fNum >> tNum >> date >> fTime >> eTime;

        // Kiểm tra tính hợp lệ (nếu sai thì đánh dấu checkPhone = 0)
        if (!checkPhoneNumber(fNum) || !checkPhoneNumber(tNum)) {
            checkPhone = 0;
        }

        // Cập nhật thống kê (Lưu ý: Thường bài toán yêu cầu thống kê tất cả cuộc gọi kể cả khi sđt sai định dạng)
        numCall++;
        numberCalls[fNum]++;
        timeCallFrom[fNum] += countTimeInt(fTime, eTime);

        cin >> type; // Đọc chỉ thị tiếp theo
    }

    // PHẦN 2: ĐỌC VÀ TRẢ LỜI TRUY VẤN (kết thúc khi gặp #)
    // Lúc này biến 'type' đang giữ giá trị "#" từ vòng lặp trên, cần đọc tiếp truy vấn đầu tiên
    cin >> type; 
    
    while (type != "#") {
        if (type == "?check_phone_number") {
            cout << checkPhone << "\n";
        } 
        else if (type == "?number_total_calls") {
            cout << numCall << "\n";
        } 
        else if (type == "?number_calls_from") {
            string num;
            cin >> num;
            cout << numberCalls[num] << "\n";
        } 
        else if (type == "?count_time_calls_from") {
            string num;
            cin >> num;
            cout << timeCallFrom[num] << "\n";
        }
        
        cin >> type; // Đọc truy vấn tiếp theo
    }

    return 0;
}