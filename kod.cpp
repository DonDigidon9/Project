#include <iostream>
#include <cmath>
#include <random>
using namespace std;

bool is_it_int(const string& str) {
    if (str.empty() and str[0] == '0' and str[0] == '-') return false;
    for (char ch : str) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

int main() {
    long double sum;
    double term_balance[5] = {10000, 1000, 1000, 1000, 1.5}, user_balance[5] = {1000000, 0, 0, 0, 0};
    double rub_to_usd = 90, rub_to_euro = 95, rub_to_btc = 4050000, usd_to_euro = 1.1, usd_to_btc = 45000, euro_to_btc = 40910;
    int answer = 0;
    string mas[5] = {"RUB", "USD", "USDT", "EURO", "BTC"};
    bool change_flag = 0;


    while (answer == 0) {
        string request_from, request_to, number;
        int int_request_from, int_request_to;
        long double int_number;
        bool fl = 1;
        change_flag = 0;
        cout << "Текущий курс:" << endl << "RUB : USD = RUB : USDT = " << rub_to_usd << endl;
        cout << "RUB : EURO = 1 : " << rub_to_euro << endl;
        cout << "RUB : BTC = 1 : " << rub_to_btc << endl;
        cout << "USD : USDT = 1 : 1" << endl;
        cout << "USD : EURO = USDT : EURO = 1 : " << usd_to_euro << endl;
        cout << "USD : BTC = USDT : BTC = 1 : " << usd_to_btc << endl;
        cout << "EURO : BTC = 1 : " << euro_to_btc << endl << endl;
        cout << "Для запуска программы с начала в любой момент введите 'again'" << endl;
        cout << "Для завершения программы в любой момент введите 'end'" << endl << endl;
        cout << endl << "Ваш баланс:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << user_balance[i] << " " << mas[i] << endl;
        }
        cout << endl << "Баланс терминала:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << term_balance[i] << " " << mas[i] << endl;
        }
        cout << endl;
        while (fl != 0) {
            cout << "Какую валюту вы хотите обменять?" << endl << "1 - RUB" << endl << "2 - USD" << endl << "3 - USDT" << endl << "4 - EURO" << endl << "5 - BTC" << endl;
            cin >> request_from;
            if (request_from == "end") {
                answer = 1;
                cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << endl << "Всего хорошего!";
                break;
            } else if (request_from == "again") {
                answer = 2;
                cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl  << endl;
                break;
            } else {
                if (is_it_int(request_from) and request_from.length() == 1) {
                    if (request_from.length() == 1 and (stoi(request_from) <= 5) and (stoi(request_from) >= 1)) fl = 0;
                    else cout << "Неверный ввод, попробуйте ещё раз" << endl << endl;
                } else cout << "Неверный ввод, попробуйте ещё раз" << endl << endl;
            }
        }
        if (answer == 1) break;
        if (answer == 0) {
            int_request_from = stoi(request_from);
            fl = 1;
            while (fl != 0) {
                cout << "На какую валюту вы хотите обменять?" << endl << "1 - RUB" << endl << "2 - USD" << endl << "3 - USDT" << endl << "4 - EURO" << endl << "5 - BTC" << endl;
                cin >> request_to;
                if (request_to == "end") {
                    answer = 1;
                    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << endl << "Всего хорошего!";
                    break;
                } else if (request_to == "again") {
                    answer = 2;
                    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    break;
                } else {
                    if (is_it_int(request_to) and request_to.length() == 1) {
                        if (request_to.length() == 1 and (stoi(request_to) <= 5) and (stoi(request_to) >= 1) and (stoi(request_to) != int_request_from)) fl = 0;
                        else cout << "Неверный ввод, попробуйте ещё раз" << endl;
                    } else cout << "Неверный ввод, попробуйте ещё раз" << endl;
                }
            }
            if (answer == 1) break;
            fl = 1;
            if (answer == 0) {
                int_request_to = stoi(request_to);
                while (fl != 0) {
                    cout << "Какую сумму " << mas[int_request_to - 1] << " вы хотите получить?" << endl;
                    cin >> number;
                    if (number == "end") {
                        answer = 1;
                        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << endl << "Всего хорошего!";
                        break;
                    } else if (number == "again") {
                        answer = 2;
                        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        break;
                    } else {
                        if (is_it_int(number) and number.length() <= 9 and number != "0") {
                            int_number = stoi(number);
                            if (int_request_from == 1 and int_request_to == 2) {
                                sum = int_number * rub_to_usd;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 1 and int_request_to == 3) {
                                sum = int_number * rub_to_usd;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 1 and int_request_to == 4) {
                                sum = int_number * rub_to_euro;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 1 and int_request_to == 5) {
                                sum = int_number * rub_to_btc;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 2 and int_request_to == 1) {
                                sum = int_number / rub_to_usd;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 2 and int_request_to == 3) {
                                sum = int_number;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 2 and int_request_to == 4) {
                                sum = int_number * usd_to_euro;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 2 and int_request_to == 5) {
                                sum = int_number * usd_to_btc;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 3 and int_request_to == 1) {
                                sum = int_number / rub_to_usd;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 3 and int_request_to == 2) {
                                sum = int_number;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 3 and int_request_to == 4) {
                                sum = int_number * usd_to_euro;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 3 and int_request_to == 5) {
                                sum = int_number * usd_to_btc;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 4 and int_request_to == 1) {
                                sum = int_number / rub_to_euro;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 4 and int_request_to == 2) {
                                sum = int_number / usd_to_euro;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 4 and int_request_to == 3) {
                                sum = int_number / usd_to_euro;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 4 and int_request_to == 5) {
                                sum = int_number * euro_to_btc;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 5 and int_request_to == 1) {
                                sum = int_number / rub_to_btc;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 5 and int_request_to == 2) {
                                sum = int_number / usd_to_btc;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 5 and int_request_to == 3) {
                                sum = int_number / usd_to_btc;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            } else if (int_request_from == 5 and int_request_to == 4) {
                                sum = int_number / euro_to_btc;
                                if (user_balance[int_request_from - 1] >= sum) {
                                    if (term_balance[int_request_to - 1] >= int_number) {
                                        fl = 0;
                                    } else cout << "Недостаточно средств в терминале, введите сумму повторно" << endl << endl;
                                } else cout << "Недостаточно средств на балансе, введите сумму повторно" << endl << endl;
                            }

                            cout << "Вы хотите приобрести " << int_number << " " << mas[int_request_to - 1] << endl;
                            cout << "Стоимость: " << sum << " " << mas[int_request_from - 1] << endl;
                            cout << "Ваш баланс: " << user_balance[int_request_from - 1] << " " << mas[int_request_from - 1] << endl << endl;
                        } else cout << "Неверный ввод, попробуйте ещё раз" << endl  << endl;
                    }
                }
                if (answer == 1) break;
                if (answer == 0) {
                    fl = 1;
                    while (fl != 0) {
                        cout << "Подтвердите транзакцию:" << endl << "0 - Да, произвести обмен" << endl << "1 - Нет, отменить обмен" << endl;
                        string approvement;
                        cin >> approvement;
                        if (approvement == "end") {
                            answer = 1;
                            cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            cout << endl << "Всего хорошего!";
                            break;
                        } else if (approvement == "again") {
                            answer = 2;
                            cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl  << endl;
                            break;
                        } else if (approvement == "1") {
                            fl = 0;
                            break;
                        } else if (approvement == "0") {
                            user_balance[int_request_from - 1] -= sum;
                            term_balance[int_request_from - 1] += sum;
                            user_balance[int_request_to - 1] += int_number;
                            term_balance[int_request_from - 1] -= int_number;
                            cout << "Успешно!" << endl;
                            cout << endl << "Ваш баланс:" << endl;
                            for (int i = 0; i < 5; i++) {
                                cout << user_balance[i] << " " << mas[i] << endl;
                            } cout << endl;
                            change_flag = 1;
                            fl = 0;
                        } else cout << "Неверный ввод, повторите попытку" << endl << endl;
                    }
                    if (change_flag) {
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<> distrib(0, 1);
                        int random_bit = distrib(gen);
                        if (random_bit == 1) rub_to_usd * 1.05;
                        else rub_to_usd * 0.95;
                        random_bit = distrib(gen);
                        if (random_bit == 1) usd_to_btc * 1.05;
                        else usd_to_btc * 0.95;
                        random_bit = distrib(gen);
                        if (random_bit == 1) rub_to_euro * 1.05;
                        else rub_to_euro * 0.95;
                        random_bit = distrib(gen);
                        if (random_bit == 1) rub_to_btc * 1.05;
                        else rub_to_btc * 0.95;
                        random_bit = distrib(gen);
                        random_bit = distrib(gen);
                        if (random_bit == 1) usd_to_euro * 1.05;
                        else usd_to_euro * 0.95;
                        random_bit = distrib(gen);
                        if (random_bit == 1) euro_to_btc * 1.05;
                        else euro_to_btc * 0.95;
                    }
                    if (answer == 1) break;
                    else if (answer == 2) answer = 0;
                    else {
                        cout << "Продолжить обмен:" << endl << "0 - Да" << endl << "1 - Нет" << endl;
                        cin >> answer;
                    }
                }
            }
        }
    }


}
