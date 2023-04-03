// some string methods
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using std::string;

const int NUM = 26;
const string wordlist[NUM] = {"apiary", "beetle", "cereal",
    "danger", "ensign", "florid", "garage", "health", "insult",
    "jackal", "keeper", "loaner", "manage", "nonce", "onset",
    "plaid", "quilt", "remote", "stolid", "train", "useful",
    "valid", "whence", "xenon", "yearn", "zippy"
};

int main()
{
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;

    std::srand(std::time(0));
    char play;
    cout << "Will you play a word game? <y/n>";
    cin >> play;
    play = tolower(play);
    while (play == 'y')
    {
        string target = wordlist[std::rand() % NUM]; // 从数组里取随机的元素：字符串
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6; // 猜测次数限制
        cout << "Guess my secret word. It has " << length
            << " letters, and you guess\n"
            << "one letter at a time. You get " << guesses
            << " wrong guesses.\n";
        cout << "Your word: " << attempt << endl;
        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if (badchars.find(letter) != string::npos // string::npos常量==size_type类型的最大值
            || attempt.find(letter) != string::npos // string.find(letter)返回从string中找到letter的位置
            ) 
            {
                cout << "You already guessed that. Try again.\n";
                continue;
            }
            int loc = target.find(letter);
            cout << loc;
            if (loc == string::npos)
            {
                cout << "Oh, bad guess!\n"; // 猜对不减次数，猜错才减
                --guesses;
                badchars += letter; // add to string
            }
            else 
            {
                cout << "Good guess!\n";
                attempt[loc] = letter;
                // check if letter appears again
                loc = target.find(letter, loc + 1); // 从指定位置开始查找
                while (loc != string ::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1); // 将目标字符串中指定字符全部找出来，并复制到attempt中(位置相同)
                }
            }
            cout << "Your word: " << attempt << endl;
            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left\n";
            }
        }
        if (guesses > 0)
            cout << "That's right!\n";
        else 
            cout << "Sorry, the word is " << target << ".\n";
            cout << "Will you play another <y/n> ";
            cin >> play;
            play = tolower(play);
    }
    cout << "Bye.\n";
    return 0;
}