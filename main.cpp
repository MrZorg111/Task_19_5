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
int check_step (std::string a[13][2], int b) {
    if (a[b][0] == "0") {
        do {
            if (b == 12) {
                b = -1;
            }
            b++;

        }while(a[b][0] == "0");
        return b;
    }
    else {
        return b;
    }
}

int main() {
    std::string involved[13][2];
    rec(involved);
    int step, experts = 0, viewers = 0;
    std::string  answer_user, pos, question, t_question, t_answer;
    std::fstream reader_q, reader_a;
    while(experts < 6 && viewers < 6) {
        std::cout << "Enter the rotation step of the drum: ";
        std::cin >> step;
        step = check_step(involved, step - 1);
        reader_q.open(involved[step][0]);
        replacement(involved, step);
        while (!reader_q.eof()) {
            reader_q >> t_question;
            question += t_question + " ";
        }
        reader_q.close();
        std::cout << question << "\n";
        question = "";

        std::cout << "Enter your answer: ";
        std::cin >> answer_user;

        reader_a.open(involved[step][1]);
        reader_a >> t_answer;
        reader_a.close();
        if (answer_user == t_answer) {
            std::cout << "Viewers get a point! \n";
            viewers++;
        } else {
            std::cout << "Experts get a point! \n";
            experts++;
        }
    }
    if (viewers == 6) {
        std::cout << "Viewers win!!!";
    }else {
        std::cout << "Experts win!!!";
    }

    return 0;
}
