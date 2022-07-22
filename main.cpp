#include <iostream>
#include <string>
#include <fstream>

int main() {
    int step = 0, experts = 0, viewers = 0;
    std::string text, answer, answer_user, pos, book = " ", t_question, t_answer;
    std::fstream reader_f, reader_s, reader_q, reader_a;
    while(experts != 6 && viewers != 6) {
        std::cout << "Please spin the top: " << std::endl;
        std::cin >> step;
        reader_f.open("P:\\WWW\\question.txt");
        reader_s.open("P:\\WWW\\answer.txt");
        for (int i = 1; i <= step; i++) {
            reader_f >> text;
            reader_s >> answer;
        }
        std::cout << answer << "\n";
        reader_q.open(text);
        reader_a.open(answer);
        while (!reader_q.eof()) {
            reader_q >> t_question;
            book += t_question + " ";
        }
        std::cout << book << "\n";
        book = " ";
        std::cout << "Enter you answer: ";
        std::cin >> answer_user;
        reader_a >> t_answer;
        if (answer_user == t_answer) {
            experts++;
            std::cout << "Experts get a score!\n";
        } else {
            viewers++;
            std::cout << "Viewers get a score!\n";
        }
        reader_q.close(), reader_a.close(), reader_f.close(), reader_s.close();
    }
    if (experts == 6) {
        std::cout << "Experts win!!!";
    }else {
        std::cout << "Viewers win!!!";
    }
    return 0;
}
