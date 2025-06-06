#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // �� min_element
#include <iterator>  // �� distance

using namespace std;

int main() {
    // �򥻰Ѽ�
    double t_s = 0.08;  // �M�D�ɶ�
    double t_l = 0.02;  // ����ɶ�
    double t_s_plus_t_l = t_s + t_l;  // t_s + t_l = 0.1 ��
    int m = 64;  // �Ĥ@�����ͪ� run �ƶq
    int n = 200000;  // �`���ȼ�
    int S = 2000;  // �t�Ψæ��
    double t_t = 0.001;  // �C�ӥ��Ȫ��ǿ�ɶ��A1ms = 0.001��

    // K �Ƚd��
    vector<int> k_values;
    for (int k = 2; k <= 600; k++) {
        k_values.push_back(k);
    }

    // �p��������` input �ɶ�
    vector<double> tinput_total_values;
    for (int k : k_values) {
        // �p��X�ֽ���: log_k(m) = log(m)/log(k)
        double merge_rounds = log(static_cast<double>(m)) / log(static_cast<double>(k));

        // �p�⤽��: t_input = ((ceil((n/m)/(S/(k+1))) * (t_s + t_l) + (n * t_t)) * log_k(m)
        double batch_size = static_cast<double>(S) / (k + 1);
        double batches = ceil((static_cast<double>(n) / m) / batch_size);
        double tinput_total = ((batches * t_s_plus_t_l) + (n * t_t)) * merge_rounds;
        tinput_total_values.push_back(tinput_total);
    }

    // ���L����ƭ�
    vector<int> key_points = { 2, 4, 8, 16, 32, 50, 100, 200, 300, 400, 500, 600 };
    cout << "����K�Ȫ��p�⵲�G:" << endl;
    cout << "----------------------------------------" << endl;
    for (int k : key_points) {
        auto it = find(k_values.begin(), k_values.end(), k);
        if (it != k_values.end()) {
            size_t idx = distance(k_values.begin(), it); // �ϥ� distance �p�����
            double merge_rounds = log(static_cast<double>(m)) / log(static_cast<double>(k));
            double batch_size = static_cast<double>(S) / (k + 1);
            double batches = ceil((static_cast<double>(n) / m) / batch_size);
            double tinput_total = ((batches * t_s_plus_t_l) + (n * t_t)) * merge_rounds;
            cout << "K=" << k << ": �X�ֽ���=" << merge_rounds << ", �妸��="
                << static_cast<int>(batches) << ", �`Input�ɶ�=" << tinput_total << "��" << endl;
        }
    }

    // ��X���u K �ȡ]�`�ɶ��̵u�^
    auto min_it = min_element(tinput_total_values.begin(), tinput_total_values.end());
    size_t min_idx = distance(tinput_total_values.begin(), min_it); // �ϥ� distance �p�����
    int optimal_k = k_values[min_idx];
    double min_time = tinput_total_values[min_idx];
    cout << "\n���uK��: K=" << optimal_k << ", �`Input�ɶ�=" << min_time << "��" << endl;

    return 0;
}