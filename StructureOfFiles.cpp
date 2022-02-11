#include <iostream>
#include <vector>
#include <string>

using namespace std;
//Структура для дерева
struct TreeNode {
    string name;
    vector<TreeNode*> childs;
};

//Нахождение нужного узла дерева
TreeNode* isChildExisting(const TreeNode* treeNode, const string& name) {
    for (auto it: treeNode->childs) {
        if(it->name == name) return it;
    }
    return NULL;
}

//функция для добаления пути в дерево
void add_node(TreeNode* treeNode, string path) {
    if (path.length() == 0) return;
    size_t pos = 0;
    string token;
    if ((pos = path.find('\\')) != std::string::npos) {
        token = path.substr(0, pos);
        path.erase(0, pos + 1);
    }
    else {
        token = path;
        path = "";
    }
    TreeNode* newTreeNode = isChildExisting(treeNode, token);
    if (newTreeNode == NULL) {
        newTreeNode = new TreeNode();
        newTreeNode->name = token;
        add_node(newTreeNode, path);
        treeNode->childs.push_back(newTreeNode);
    }
    else {
        add_node(newTreeNode, path);
    }
}

//Компоратор для сортировки
bool cmp(TreeNode const* s1, TreeNode const* s2)
{
    return s1->name < s2->name;
}

// Печать итогового графа(дерева
void print_graph(TreeNode* treeNode, int rec) {
    for (int i = 0; i < rec; i++) cout<<' ';
    // Сортировка по имени
    sort(treeNode->childs.begin(), treeNode->childs.end(), cmp);
    if (treeNode->name != "\\") cout << treeNode->name << "\n";
    else rec = -1;
    if (!treeNode->childs.empty()) {
        for(auto child: treeNode->childs){
            print_graph(child, rec+1);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    auto *head = new TreeNode();
    head->name = "\\";
    for (int i = 0; i < n; i++) {
        string path;
        cin >> path;
        add_node(head, path);
    }
    print_graph(head, 0);

    return 0;
}
