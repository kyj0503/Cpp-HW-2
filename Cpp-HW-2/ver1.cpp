#include <iostream>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()
#include <string>

using namespace std;

// Player Ŭ���� ����
class Player {
    string name;
public:
    Player(string name) : name(name) {}
    string getName() { return name; }
    bool turn() {
        cout << name << "�� �����Դϴ�. <Enter> Ű�� �Է��ϼ���.";
        cin.ignore(); // Enter Ű �Է� ���
        int numbers[3];
        // 3���� ���� ���� ���� (0 ~ 2)
        for (int i = 0; i < 3; i++) {
            numbers[i] = rand() % 3;
        }
        // ������ ���� ���
        cout << numbers[0] << "\t" << numbers[1] << "\t" << numbers[2] << endl;
        // 3���� ���ڰ� ��� ������ Ȯ��
        if (numbers[0] == numbers[1] && numbers[1] == numbers[2]) {
            cout << name << "���� �¸��Ͽ����ϴ�!!" << endl;
            return true;  // �¸� �� true ��ȯ
        }
        else {
            cout << "�ƽ�����!" << endl;
            return false; // �¸� ���� �� false ��ȯ
        }
    }
};

// GamblingGame Ŭ���� ����
class GamblingGame {
    Player* player1;
    Player* player2;
public:
    GamblingGame(string name1, string name2) {
        player1 = new Player(name1);
        player2 = new Player(name2);
    }
    ~GamblingGame() {
        delete player1;
        delete player2;
    }
    void start() {
        cout << "***** ���� ������ �����մϴ�. *****" << endl;
        while (true) {
            if (player1->turn()) break;  // player1�� ����
            if (player2->turn()) break;  // player2�� ����
        }
    }
};

int main() {
    srand((unsigned)time(0)); // ���� �õ� ����

    string name1, name2;
    cout << "ù��° ���� �̸�>>";
    getline(cin, name1);
    cout << "�ι�° ���� �̸�>>";
    getline(cin, name2);

    // ���� ���� ����
    GamblingGame game(name1, name2);
    game.start();

    return 0;
}
