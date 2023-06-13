

#include <iostream>
#include <vector>

using namespace std;

void getChar(char& letter)
{
    while (true)
    {
        cin >> letter;
        cin.ignore();
        if(65 <= letter <=90)
            break;
    }
    
}

void getListLetter(vector<char>& listLetter)
{
    for (auto i = 0; i < listLetter.size(); i++)
    {
        getChar(listLetter[i]);
    }
    
}

vector<char>& getPassword(vector<char>& listLetter1, vector<char>& listLetter2)
{
    static vector<char> password(12);

    int i{0}, j{0};
    int idx {0};
    while ( i < 6 || j < 6)
    {
        if( i >= 6 || j >= 6)
        {
            if(i < 6)
            {
                password[idx] = listLetter1[i];
                i++;
                idx++;
            }
            
            if(j < 6)
            {
                password[idx] = listLetter2[j];
                j++;
                idx++;
            }
            continue;   
        }

        if(listLetter1[i] <= listLetter2[j])
        {
            password[idx] = listLetter1[i];
            i++;
            idx++;
        }
        else
        {
            password[idx] = listLetter2[j];
            j++;
            idx++;
        }
    }
    
    return password;
}

int main()
{
    int size_letter {6};
    vector<char> listLetter1(size_letter);
    vector<char> listLetter2(size_letter);
    
 
    getListLetter(listLetter1);
    getListLetter(listLetter2);
    
    vector<char>& password {getPassword(listLetter1, listLetter2)};

    for (auto i = 0; i < password.size(); i++)
    {
        cout << password[i];
    }
    
}
