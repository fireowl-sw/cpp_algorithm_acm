#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// 链表的定义
struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){} //节点的构造函数
    ListNode(int x) : val(x), next(nullptr){} //节点的构造函数
    ListNode(int x, ListNode* next) : val(x), next(next){} //节点的构造函数
};

// 定义算法函数
ListNode* removeElements(ListNode* head, int val){
    // 创建虚拟节点
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* cur = dummyHead;

    // 删除节点
    while(cur->next != nullptr){
        if(cur->next->val == val){
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        else{
            cur = cur->next;
        }
    }

    head = dummyHead->next;
    delete dummyHead;

    return head;
}


int main(){
/************************输入数据************************/
    string input;
    getline(cin, input); // 读取一行字符串, 最后一个为换行符

    input = input.substr(1, input.size()-2);
    for(char &c : input){
        if(c=='['||c==']'||c==','){
            c = ' ';
        }
    }
    // cout << input<<endl;

    istringstream ss(input);
    string token;
    ListNode dummy(0);
    ListNode* current = &dummy;

    int num;
    while(ss >> num){
        current -> next = new ListNode(num);
        current = current ->next;
    }

    // 读取目标整数
    int target;
    cin >> target;
    // cout << target <<endl;
/************************算法函数************************/
    ListNode* head = removeElements(dummy.next, target);
    if(head == nullptr){
        cout<<"[]";
    }
/************************打印输出************************/
    while(head != nullptr){ //从头开始循环
        cout << head->val << ' ';
        head = head->next;
    }
    
    return 0;
}

