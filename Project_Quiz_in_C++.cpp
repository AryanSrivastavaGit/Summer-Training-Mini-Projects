#include <iostream>
#include <string>
#include <limits> // For numeric_limits

using namespace std;

int Guess;
int Total;

class Question
{
private:
    string Question_Text;
    string Answer_1;
    string Answer_2;
    string Answer_3;
    string Answer_4;
    int Correct_Answer;
    int Question_Score;

public:
    void setValues(string, string, string, string, string, int, int);
    void askQuestion();
};

void Question::setValues(string q, string a1, string a2, string a3, string a4, int ca, int pa)
{
    Question_Text = q;
    Answer_1 = a1;
    Answer_2 = a2;
    Answer_3 = a3;
    Answer_4 = a4;
    Correct_Answer = ca;
    Question_Score = pa;
}

void Question::askQuestion()
{
    cout << endl;
    cout << Question_Text << endl;
    cout << "1. " << Answer_1 << endl;
    cout << "2. " << Answer_2 << endl;
    cout << "3. " << Answer_3 << endl;
    cout << "4. " << Answer_4 << endl;
    cout << endl;
    cout << "What is your answer? (Enter the number)" << endl;
    cin >> Guess;

    if (cin.fail()) {
        cin.clear(); // clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        cout << "Invalid input! Please enter a number." << endl;
        return;
    }

    if (Guess == Correct_Answer)
    {
        cout << endl;
        cout << "Correct!" << endl;
        Total += Question_Score;
        cout << "Score = " << Question_Score << " out of " << Question_Score << "!" << endl;
        cout << endl;
    }
    else
    {
        cout << endl;
        cout << "Wrong!" << endl;
        cout << "Score = 0 out of " << Question_Score << "!" << endl;
        cout << "Correct answer = " << Correct_Answer << "." << endl;
        cout << endl;
    }
}

int main()
{
    cout << "\n\n\t\t\t\tTHE DAILY QUIZ" << endl;
    cout << "\nPress Enter to start the quiz... " << endl;
    cin.ignore();

    string Name;
    int Age;

    cout << "What is your name?" << endl;
    cin >> Name;
    cout << endl;
    cout << "How old are you?" << endl;
    cin >> Age;
    cout << endl;

    string Respond;
    cout << "Are you ready to take the quiz " << Name << "? yes/no" << endl;
    cin >> Respond;
    if (Respond == "yes" || Respond == "Yes" || Respond == "YES")
    {
        cout << endl;
        cout << "Good Luck!" << endl;
    }
    else
    {
        cout << "Okay, Good Bye!" << endl;
        return 0;
    }

    Question q1, q2, q3, q4, q5, q6, q7, q8, q9, q10;

    q1.setValues("Where is the Taj Mahal located?", "Mathura", "Delhi", "Agra", "Kanpur", 3, 10);
    q2.setValues("What is the capital of France?", "Berlin", "Madrid", "Paris", "Lisbon", 3, 10);
    q3.setValues("What is 5 + 7?", "10", "11", "12", "13", 3, 10);
    q4.setValues("Who wrote 'Romeo and Juliet'?", "Mark Twain", "Jane Austen", "William Shakespeare", "Charles Dickens", 3, 10);
    q5.setValues("What is the chemical symbol for water?", "H2O", "CO2", "O2", "N2", 1, 10);
    q6.setValues("Which planet is known as the Red Planet?", "Earth", "Mars", "Jupiter", "Saturn", 2, 10);
    q7.setValues("What is the largest ocean on Earth?", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean", 4, 10);
    q8.setValues("Who painted the Mona Lisa?", "Vincent Van Gogh", "Leonardo da Vinci", "Pablo Picasso", "Claude Monet", 2, 10);
    q9.setValues("What is the hardest natural substance on Earth?", "Gold", "Iron", "Diamond", "Platinum", 3, 10);
    q10.setValues("How many continents are there?", "5", "6", "7", "8", 3, 10);

    q1.askQuestion();
    q2.askQuestion();
    q3.askQuestion();
    q4.askQuestion();
    q5.askQuestion();
    q6.askQuestion();
    q7.askQuestion();
    q8.askQuestion();
    q9.askQuestion();
    q10.askQuestion();

    cout << "Total Score = " << Total << " out of 100" << endl;

    if (Total >= 70)
    {
        cout << "Congrats, you passed the quiz!" << endl;
    }
    else
    {
        cout << "Alas! You failed the quiz." << endl;
        cout << "Better luck next time." << endl;
    }

    return 0;
}