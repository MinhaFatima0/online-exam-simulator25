#include <iostream>
#include <vector>
#include <map>
#include <cctype> // Added for toupper function
using namespace std;

struct Question {
    string questionText;
    vector<string> options;
    char correctAnswer;
};

class ExamSimulator {
private:
    map<string, string> users; // Username, Password
    vector<Question> questions;
    string currentUser;
    int score;

public:
    ExamSimulator() {
        users["student"] = "password"; // Sample login
        initializeQuestions();
    }

    void login() {
        string username, password;
        cout << "\nEnter username: "; cin >> username;
        cout << "Enter password: "; cin >> password;

        if (users.find(username) != users.end() && users[username] == password) {
            currentUser = username;
            cout << "Login successful!\n";
        } else {
            cout << "Invalid credentials. Try again.\n";
            login();
        }
    }

    void initializeQuestions() {
        Question q1;
        q1.questionText = "What is 2 + 2?";
        q1.options.push_back("A. 3");
        q1.options.push_back("B. 4");
        q1.options.push_back("C. 5");
        q1.options.push_back("D. 6");
        q1.correctAnswer = 'B';
        questions.push_back(q1);

        Question q2;
        q2.questionText = "Which language is used for system programming?";
        q2.options.push_back("A. Python");
        q2.options.push_back("B. Java");
        q2.options.push_back("C. C++");
        q2.options.push_back("D. Ruby");
        q2.correctAnswer = 'C';
        questions.push_back(q2);
    }

    void takeExam() {
        char answer;
        score = 0;
        cout << "\nStarting Exam...\n";
        for (size_t i = 0; i < questions.size(); i++) {
            cout << "\nQ" << (i + 1) << ": " << questions[i].questionText << "\n";
            for (size_t j = 0; j < questions[i].options.size(); j++) {
                cout << questions[i].options[j] << "\n";
            }
            cout << "Your answer: ";
            fflush(stdin); // Clear input buffer
            cin >> answer;
            answer = toupper(answer);
            if (answer == questions[i].correctAnswer) {
                score++;
            }
        }
        showResult();
    }

    void showResult() {
        cout << "\nExam Completed!";
        cout << "\nTotal Score: " << score << "/" << questions.size() << "\n";
        system("pause"); // To keep the console open in Dev-C++
    }
};

int main() {
    ExamSimulator simulator;
    simulator.login();
    simulator.takeExam();
    return 0;
}
