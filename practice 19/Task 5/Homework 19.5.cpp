#include <iostream>
#include <fstream>
#include <string>



std::string getPath(const std::string& const filename,const int& const last_pos) {
    int current_line{ 0 };
    std::string newstr;
    char* st[400];
    std::ifstream inFile;
    inFile.open(filename);
    for (; current_line <= last_pos; ++current_line) {
        std::getline(inFile, newstr, '\n');
    }
    inFile.close();
    return newstr;
}

std::string getAnswer() {
    std::string answer;
    std::cout << "\nEnter your answer: \n";
    std::cin >> answer;
    return answer;
}

bool checkAnswer(std::string& const answer, const std::string& const answer_filename,const int& const last_pos) {
    return (getPath(answer_filename,last_pos) == answer);
}

void printQuestions(const std::string& const question_filename,const int& const last_pos) {
    std::cout << getPath(question_filename,last_pos);
}

void initialization(bool question[]) {
    for (int j = 0; j < 13; ++j) {
        question[j] = true;
    }
}

int enterOfset() {
    int enter{ 0 };
    std::cout << "Enter sector shift's: ";
    std::cin >> enter;
    return enter;
}


void game(int ofset, int& const last_pos, bool questions[13]) {
    int co{ 0 };
    last_pos += ofset;
    while (last_pos < 0) {
        last_pos += 13;
    }
    last_pos %= 13;
    do {
        if (questions[last_pos]) {
            return;
        }
        ++co; ++last_pos;
        if (last_pos >= 12) {
            last_pos = 0;
        }
    } while (co < 13);
}


int main()
{
    std::cout << "\t\tWhat? Where? When?\n\n";
    bool question[13] = { true,};
    int last_pos{ 0 };
    int score_player{ 0 }, score_viewer{ 0 };
    std::string answer;

    initialization(question);
    do {
        game(enterOfset(),last_pos,question);
        std::cout << "" << last_pos << std::endl;
        printQuestions("question.txt", last_pos);
        question[last_pos] = false;
        answer = getAnswer();
        if (checkAnswer(answer, "answer.txt", last_pos)) {
            ++score_player;
        }else {
            ++score_viewer;
        }
        std::cout << "Player score: " << score_player << "\n Viewer's score: " << score_viewer<<std::endl;
    } while (score_player < 6 && score_viewer < 6);
    if (score_player >= 6) {
        std::cout << "\n\t\tYou Win!\n";
    }else {
        std::cout << "\n\t\tViewer's Win's!\n";
    }
    
    return 0;
}