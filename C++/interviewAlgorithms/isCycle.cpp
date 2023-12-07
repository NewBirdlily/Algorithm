#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class isCycle {
public:
    static Node* findMeetingPoint(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return slow;  // 返回相遇点
            }
        }
        return nullptr;  // 不存在环，返回nullptr
    }

    static Node* findEntrypoint(Node* head) {
        Node* meetingPoint = findMeetingPoint(head);

        if (meetingPoint == nullptr) {  // 不存在环，返回nullptr
            return nullptr;
        }

        Node* p1 = head;
        Node* p2 = meetingPoint;

        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;  // 返回入环点
    }

    static int calculateCycleLength(Node* head) {
        Node* meetingPoint = findMeetingPoint(head);

        if (meetingPoint == nullptr) {  // 不存在环，返回0
            return 0;
        }

        Node* p1 = meetingPoint;
        int length = 1;

        while (p1->next != meetingPoint) {
            p1 = p1->next;
            length++;
        }

        return length;  // 返回环的长度
    }
};

int main() {
    Node* node1 = new Node(5);
    Node* node2 = new Node(3);
    Node* node3 = new Node(7);
    Node* node4 = new Node(2);
    Node* node5 = new Node(6);
    Node* node6 = new Node(8);
    Node* node7 = new Node(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node4;

    Node* entryPoint = isCycle::findEntrypoint(node1);
    int cycleLength = isCycle::calculateCycleLength(node1);

    if (entryPoint != nullptr) {
        cout << "入环点为： " << entryPoint->data << endl;
        cout << "环的长度为： " << cycleLength << endl;
    }
    else {
        cout << "链表中不存在环" << endl;
    }
    return 0;
}
