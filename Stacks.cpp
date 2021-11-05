//Copyright Christine Coomans 2021

//Necessary libraries
#include <iomanip>
#include <iostream>
#include <stack>
#include <algorithm>
#include <array>
using namespace std;

//sorting function for stack one
bool nam(string a, string b)
{
    return a < b;
}

//sorting function for stack two
bool surn(string a, string b)
{
    return a > b;
}

//Main CPP Function
int main() {
    //Name and Surname Array 
    string Names[] = { "Sam Williams", "John Phoenix", "Simon Johnson", "Sarah Khosa", "Mat Jackon", "Nick Roberts", "Isaac Wayne", "Anna Mishima", "Daniel Rose", "Aaron Black", "Jack Mohamed", "Kathrine Bruckner" };
    //Score Array
    int Score[] = { 60, 85, 75, 81, 38, 26, 74, 34, 64, 83, 27, 42 };
    //Variable decleration needed for if statements
    int l;
    //Calculates array size
    l = sizeof(Names) / sizeof(Names[0]);

    //------------------------------- Stack One ----------------------------------//
    //var declaration
    stack <string> Stack1;
    stack <int> Score1;
    cout << "Stack One" << endl;

    //sort stack one alphabetically by name
    sort(Names, Names + l, nam);

    //whilst our Names array is not empty, we will push it into the stack
    for (int i = 0; i < l; i++) {
        //pushes Names, Surnames and Scores to first stack
        Stack1.push(Names[i]);
        Score1.push(Score[i]);
        //prints Names, Surnames and Scores for the first stack
        while (!Stack1.empty()) {
            cout << "\t" << setw(20) << Stack1.top() << "\t" << Score1.top() << endl;
            //stops the printing from printing in an endless loop
            Stack1.pop();
            Score1.pop();
        }
    }
    //------------------------------- Stack Two ---------------------------------//
    //var declaration
    stack <string> Stack2;
    stack <int> Score2;
    cout << "Stack Two" << endl;

    //sorts the stack in alphabetical order
    sort(Names, Names + l, surn);
    //whilst our Names array is not empty, we will push it into the stack
    for (int i = 0; i < l; i++)
    {
        //variable declaration to identify surname
        string x = Names[i];
        string surname = "";

        //whilst our Names array is not empty, we will remove Names whose surname starts with the alphabets ‘R’, ‘J’ and ‘M’
        for (int j = 0; j < x.length(); j++)
        {
            char f = x[j];
            //firstname
            if (f == ' ')
                surname = "";
            //surname
            else
                surname = surname + f;
        }
        //we will add Students whose Surname starts with the alphabet ‘J’
        if (surname[0] == 'J') {
            Stack2.push(Names[i]);
            Score2.push(Score[i]);

        }
        //we will add Students whose surname starts with the alphabet ‘M’
        if (surname[0] == 'M') {
            Stack2.push(Names[i]);
            Score2.push(Score[i]); 
        }
        //we will add Students whose Surname starts with the alphabet ‘R’
        if (surname[0] == 'R') {
            Stack2.push(Names[i]);
            Score2.push(Score[i]);
        }
        //prints Names, Surnames and Scores for the second stack
        while (!Stack2.empty()) {
            cout << "\t" << setw(20) << Stack2.top() << "\t" << Score2.top() << endl;
            //stops the printing from printing in an endless loop
            Stack2.pop();
            Score2.pop();
        }
    }
    //------------------------------- Stack Three -------------------------------//
    //var declaration
    stack <string> Stack3;
    stack <int> Score3;
    cout << "Stack Three" << endl;
    //whilst our names array is not empty, we will push it into the stack
    for (int i = 0; i < l; i++)
    {
        //var declaration for scores
        int n = Score[i];
        //sorts the Stack in descending order
        sort(begin(Score), end(Score), greater<>());
        //if the student score is under 50, add them to our stack
        if (n < 50)
        {
            Stack3.push(Names[i]);
            Score3.push(Score[i]);
        }
        //prints Names, Surnames and Scores for the third stack
        while (!Stack3.empty()) {
            cout << "\t" << setw(20) << Stack3.top() << "\t" << Score3.top() << endl;
            //stops the printing from printing in an endless loop
            Stack3.pop();
            Score3.pop();
        }
    }
    return 0;
}
