#include <bits/stdc++.h>
#include "Trie.cpp"
#include "Utils.cpp"


using namespace std;


int main()
{

    string file_name;
    Trie T;
    vector<string> data;

   
    cout << "Enter File name to load data from. ( music | movies | words ) :\n";
    cin >> file_name;
    cerr << "loading ...";
    data = get_array_from_file("./data/" + file_name + ".txt");
    cerr << "Done.\n";
   

    for (auto word : data)
    {
        T.insert(word);
    }

    int choice;
    do
    {

        cout << "------------------------\n";
        cout << "MENU\n";
        cout << "1. Exact Search.\n";
        cout << "2. Prefix Search.\n";
        cout << "3. Universal Search.\n";
        cout << "0. Exit.\n";
        
        cout << "------------------------\n";

        cin >> choice;
        getchar(); // get the new line character

        string pattern;

        if (choice)
        {
            cout << "Enter Search Text (leave empty to list all) : ";
            getline(cin, pattern);
        }

        switch (choice)
        {
        case 1:

            if (T.exact_search(pattern))
            {   
                cout << "String Exists.\n";
            }

            else
            {

                cout << "NOT Found !!!\n";
            }

            break;

        case 2:
            for (string w : T.pre_search(pattern))
            {
                cout << w << "\n";
            }
            break;

        case 3:
            for (string w : search(data, pattern))
            {
                cout << w << "\n";
            }
            break;

        default:
            cout<<"!! Bye\n";
            break;
        }

        cout << "press any key to continue.";
        getchar();
        system("clear");

    } while(choice);

 

    return 0;
}
