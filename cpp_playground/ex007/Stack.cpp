#include <iostream>
#include <cstring>

class Stack
{
  private:
    char *data_;
    int top_;

  public:
    // κατασκευαστής με προκαθορισμένη τιμή παραμέτρου
    Stack(size_t s = 10) : top_(-1), data_(new char[s])
    {
        std::cout << "Constructor Stack(size_t) called, created stack having size= " << s << std::endl;
    }
    ~Stack()
    {
        delete[] data_;
        std::cout << "Destructor ~Stack() called" << std::endl;
    }
    int empty() { return top_ == -1; }
    void push(char x) { data_[++top_] = x; }
    void pop() { --top_; }
    char top() { return data_[top_]; }
};

int main()
{
    char str[] = "ABCDE";
    Stack s(strlen(str));
    for (int i = 0; i < 5; i++)
        s.push(str[i]);

    while (!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    return 0;
}
