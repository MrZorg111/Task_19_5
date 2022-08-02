#include <iostream>
#include <string>
#include <fstream>



void rec (std::string r[13][2]) {
    std::fstream reader_ad_q, reader_ad_ans;
    std::string address_question, address_answer;
    reader_ad_q.open("P:\\WWW\\question.txt"), reader_ad_ans.open("P:\\WWW\\answer.txt");
    for (int i = 0; i < 13; i++) {
        reader_ad_q >> address_question, reader_ad_ans >> address_answer;

        r[i][0] = address_question, r[i][1] = address_answer;
    }
    reader_ad_ans.close(), reader_ad_q.close();
}
void replacement (std::string arr[13][2], int pos) {
    arr[pos][0] = "0";
}

int main() {
    std::string involved[13][2];
    rec(involved);
    int step, experts = 0, viewers = 0, a = 0;
    std::string  answer_user, pos, question, t_question, t_answer;
    std::fstream reader_q, reader_a;
    std::cout << "Enter the rotation step of the drum: ";
    std::cin >> step;

    while(involved[step - 1][0] == "0") {
        step++;
        if (step == 12) {
            step = 1;
        }
    }
    reader_q.open(involved[step - 1][0]);
    replacement(involved, step);
    while(!reader_q.eof()) {
        reader_q >> t_question;
        question += t_question + " ";
    }
    return 0;
}
