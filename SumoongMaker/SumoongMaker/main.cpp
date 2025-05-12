#include <iostream>
#include <memory>
#include "Character.h"
#include "ActionFactory.h"

using namespace std;

int main() {
    // ĳ���� ����
    Character player("ȫ�浿");

    // ���� ���� �޽���
    cout << "������ �����մϴ�. "  << endl;

    // �ൿ ī�װ� ���
    cout << "\n������ �� �ִ� �ൿ ī�װ�:\n";
    cout << "1. �ŷ� (Charm)\n";
    cout << "2. ���� (Intelligence)\n";
    cout << "3. ü�� (Strength)\n";
    cout << "4. ���� (Art)\n";
    cout << "5. �޽� (Rest)\n";
    cout << "6. �Ƹ�����Ʈ (Work)\n";

    // ī�װ� ����
    int categoryInput;
    cout << "\nī�װ� ��ȣ�� �Է��ϼ���: ";
    cin >> categoryInput;

    ActCategory category;

    // ī�װ� �Է¿� �´� ActCategory ����
    switch (categoryInput) {
    case 1:
        category = ActCategory::Charm;
        break;
    case 2:
        category = ActCategory::Intelligence;
        break;
    case 3:
        category = ActCategory::Strength;
        break;
    case 4:
        category = ActCategory::Art;
        break;
    case 5:
        category = ActCategory::Rest;
        break;
    case 6:
        category = ActCategory::Work;
        break;
    default:
        cout << "�߸��� �Է��Դϴ�." << endl;
        return 1;
    }

    // �ش� ī�װ��� �ൿ ���
    cout << "\n������ �� �ִ� �ൿ��:\n";
    cout << "1. ù ��° �ൿ\n";
    cout << "2. �� ��° �ൿ\n";
    cout << "3. �� ��° �ൿ\n";

    // �ൿ ����
    int option;
    cout << "\n�ൿ ��ȣ�� �Է��ϼ���: ";
    cin >> option;

    // �ൿ ����
    unique_ptr<Act> act = ActionFactory::create(category, option);

    // ������ �ൿ ���
    cout << "\n������ �ൿ: " << act->getName() << endl;

    // �ൿ ����
    player.applyAct(*act);

    // ���� ���
    cout << "\n���� ����:\n";
    player.showStats();

    return 0;
}
